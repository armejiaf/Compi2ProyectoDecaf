#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <limits.h>
#include "ast.h"

map<string, VValue> vars;
map<string, VValue> localvars;
map<string, VValue> params;
map<string, MethodStatement *> methodList;
map<string, int> breakContinue;

const char *tempsS[] = {"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7"};
const char *temps[] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
#define TEMP_COUNT (sizeof(temps)/sizeof(temps[0]))
#define TEMPS_COUNT (sizeof(tempsS)/sizeof(tempsS[0]))
map<string, int> tempMap;
map<string, int> tempMapS;
map<string, int> varsMipsAssign;
set<string> varsMips;
set<string> var_char;
set<string> var_string;

int label;
string newTempS()
{
    int i;
    for (i=0; i<TEMPS_COUNT; i++) {
        if (tempMap.find(tempsS[i]) == tempMapS.end()) {
            tempMapS[tempsS[i]] = 1;
            return string(tempsS[i]);
        }
    }
    return string("");
}

string newTemp()
{
    int i;
    
    for (i=0; i<TEMP_COUNT; i++) {
        if (tempMap.find(temps[i]) == tempMap.end()) {
            tempMap[temps[i]] = 1;
            
            return string(temps[i]);
        }
    }
    
    return string("");
}

string newLabel()
{
    string s="Label"; 
    stringstream ss;
    ss << s << label++;
    return ss.str();
}


void releaseTemp(string temp)
{
	tempMap.erase(temp);
}
void releaseTempS(string temp)
{
	tempMapS.erase(temp);
}

#define IMPLEMENT_RELATIONAL_EVALUATE(CLASS, OP)   \
    VValue CLASS::evaluate()            \
    {                                   \
	if(expr1 != 0 && expr2 != 0)      \
        {                                   \
		VValue value1 = expr1->evaluate();  \
        	VValue value2 = expr2->evaluate();  \
		if((value1.type == value2.type) && (value1.type==INT || value1.type== BOOLEAN)) \
		{						      \
		   	VValue result;                                \
			result.type = BOOLEAN;                        \
			if(value1.type == INT)                        \
			{                                             \
				result.u.bvalue = value1.intValue() OP value2.intValue(); \
			}			                                          \
			else                                                              \
			{                                                                 \
				result.u.bvalue = value1.boolValue() OP value2.boolValue(); \
			}                                                                   \
    			return result;                                                      \
		}							                    \
		throw invalid_argument("Error: Tipos incompatible." );                      \
    	}                                                                                   \
    	throw invalid_argument("Error: Imposible evaluar la expresion." );                  \
    }
    
#define IMPLEMENT_ANDOR_EVALUATE(CLASS, OP)   \
    VValue CLASS::evaluate()            \
    {                                   \
	if(expr1 != 0 && expr2 != 0)    \
        {                                   \
		VValue value1 = expr1->evaluate();  \
        	VValue value2 = expr2->evaluate();  \
		if((value1.type == value2.type) && value1.type== BOOLEAN) \
		{						      \
		   	VValue result;                                \
			result.type = BOOLEAN;                        \
			result.u.bvalue = value1.boolValue() OP value2.boolValue(); \
			return result;                                                      \
		}							                    \
		throw invalid_argument("Error: Tipos incompatible. ");                      \
    	}                                                                                   \
    	throw invalid_argument("Error: Imposible evaluar la expresion. ");                  \
    }

#define IMPLEMENT_ARITHMETIC_EVALUATE(CLASS, OP)    \
    VValue CLASS::evaluate()                \
    {                                       \
	if(expr1 != 0 && expr2 != 0)        \
        {                                   \
		VValue value1 = expr1->evaluate();  \
        	VValue value2 = expr2->evaluate();  \
		if((value1.type == value2.type) && value1.type==INT)  \
		{						      \
		   	VValue result;                                \
			result.type = INT;                            \
			result.u.ivalue = value1.intValue() OP value2.intValue(); \
			return result;                                                      \
		}							                    \
		throw invalid_argument("Error: Tipos incompatible." );                      \
    	}                                                                                   \
    	throw invalid_argument("Error: Imposible evaluar la expresion." );                  \
    }


VValue NotExpr::evaluate()                
{
	if(expr!= 0) 
        {
		VValue value = expr->evaluate();                                    
		if(value.type == BOOLEAN)  
		{						                                
			VValue result;                                
			result.type = BOOLEAN;                            
			result.u.bvalue = ! value.boolValue();
			return result;     
		}							                    
		throw invalid_argument("Error: Tipos incompatible." );                       
    	}                                                                                   
    	throw invalid_argument("Error: Imposible evaluar la expresion. ");                   
}            
    
IMPLEMENT_ANDOR_EVALUATE(AndExpr, &&)
IMPLEMENT_ANDOR_EVALUATE(OrExpr, ||)

IMPLEMENT_ARITHMETIC_EVALUATE(RShiftExpr, >>)   
IMPLEMENT_ARITHMETIC_EVALUATE(LShiftExpr, <<)      

VValue RotExpr::evaluate()                
{
	 
	if(expr1 != 0 && expr2 != 0) 
        {  
		VValue value1 = expr1->evaluate();  
        	VValue value2 = expr2->evaluate();                                  
		if((value1.type == value2.type) && value1.type==INT)  
		{		
			VValue result;                                
			result.type = INT;               
			result.u.ivalue = (value1.u.ivalue << value2.u.ivalue) | ( (unsigned) value1.u.ivalue >> (-value2.u.ivalue & (sizeof(int) * CHAR_BIT - 1))); 
			return result;                                                      
		}							                    
		throw invalid_argument("Error: Tipos incompatible." );                       
    	}                                                                                   
    	throw invalid_argument("Error: Imposible evaluar la expresion. ");                   
}         


IMPLEMENT_RELATIONAL_EVALUATE(LTExpr, <)
IMPLEMENT_RELATIONAL_EVALUATE(GTExpr, >)
IMPLEMENT_RELATIONAL_EVALUATE(LTEExpr, <=)
IMPLEMENT_RELATIONAL_EVALUATE(GTEExpr, >=)
IMPLEMENT_RELATIONAL_EVALUATE(NEExpr, !=)
IMPLEMENT_RELATIONAL_EVALUATE(EQExpr, ==)

IMPLEMENT_ARITHMETIC_EVALUATE(AddExpr, +)
IMPLEMENT_ARITHMETIC_EVALUATE(SubExpr, -)
IMPLEMENT_ARITHMETIC_EVALUATE(MultExpr, *)
IMPLEMENT_ARITHMETIC_EVALUATE(DivExpr, /)    
IMPLEMENT_ARITHMETIC_EVALUATE(ModExpr, %)
                
 
VValue IdExpr::evaluate(){

	if(params.find(id) != params.end())	
		return params[id];
	else if(localvars.find(id) != localvars.end())
		return localvars[id];
	else
		return vars[id]; 
	      
}

VValue MethodCallExpr::evaluate()
{
	if( methodList.find(id)==methodList.end() )
	     	throw invalid_argument("Metodo "+ id +" no existe.");
	MethodStatement * method = methodList[id];
        if(method->type == VOID)
		throw invalid_argument("Metodo "+ id +" no retorna un tipo.");
	if(parameters.size() != method->parameters.size())
	     	throw invalid_argument("Numero de parametros incorrectos en la llamada del metodo "+id+".");
	if(parameters.size() != 0){
	    list<ParameterDefinitionStatement*>::iterator it = method->parameters.begin();
    	    int i = 0;
	    while (it != method->parameters.end()) {
		ParameterDefinitionStatement* param = *it;
                VValue paramValue = parameters[i]->evaluate();
		if(param->type != paramValue.type)
                     throw invalid_argument("Parametro incompatible en la llamada del metodo "+id+".");
		VValue newValue;
		newValue.type = param->type;
		if(param->type == INT){
		    newValue.u.ivalue =paramValue.intValue();
		}else if(param->type == BOOLEAN){
		    newValue.u.bvalue =paramValue.boolValue();
		}
		params[param->id] = newValue;
		i++;
		it++;
	    }   
	}
	method->blockM->execute();
	VValue returnValue = localvars["return"];
	if(returnValue.type != method->type)
		 throw invalid_argument("El tipo de la variable de retorno es incompatible con el metodo "+id+".");
	params.clear();
	localvars.clear();
	return returnValue;
}

string RotExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "rol " << place << ", " << place1 << ", " << place2 << endl;
    return ss.str();    
}
string AndExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "and "<< place << ", " << place1 << ", " << place2 << endl;
    return ss.str();
}
string OrExpr::generateCode(string &place)
{ 
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "or "<< place <<", "<< place1 <<", "<< place2 << endl;
    return ss.str();

}
string RShiftExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "srlv " << place << ", " << place1 << ", " << place2 << endl;
    return ss.str();

}
string LShiftExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;

    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();

    ss << code1 << endl <<
    code2 << endl <<
    "sllv " << place << ", " << place1 << ", " << place2 << endl;
    return ss.str();
}

string NotExpr:: generateCode(string &place)
{
    string place1;
    string code = expr->generateCode(place1);
    stringstream ss;

    releaseTemp(place1);
    place = newTemp();

    
    ss << code << endl <<
    "seq " << place << "," << place1 << ", " << "$zero" << endl;
    return ss.str();    
}

string AddExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
          code2 << endl <<
          "add " << place << ", " << place1 << ", " << place2;
          
    return ss.str();
}
string SubExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "sub " << place << ", " << place1 << ", " << place2;
    
    return ss.str();
}
string MultExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "mult " << place1 << ", " << place2 << endl <<
    "mflo " << place;
    
    return ss.str();
}

string DivExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "div " << place1 << ", " << place2 << endl <<
    "mflo " << place;
    
    return ss.str();
}

string ModExpr::generateCode(string &place)
{
    string place1, place2;
    string code1 = expr1->generateCode(place1);
    string code2 = expr2->generateCode(place2);
    stringstream ss;
    
    releaseTemp(place1);
    releaseTemp(place2);
    place = newTemp();
    
    ss << code1 << endl <<
    code2 << endl <<
    "div " << place1 << ", " << place2 << endl <<
    "mfhi " << place << endl;
    
    return ss.str();	
}

string LTExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;

	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	ss << "#LT"<<endl<<code1 << code2 << endl
        << "slt " << place << ", " << place1 << ", " << place2 << endl;
	return ss.str();

}
string GTExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;

	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	ss <<"#GT"<<endl<< code1 << code2 << endl
        << "slt " << place << ", " << place2 << ", " << place1;
	return ss.str();
}
string LTEExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;
	
	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	ss <<"#LTE"<<endl<<code1 << code2 << endl
        << "slt " << place << ", " << place1 << ", " << place2 << endl 
	<< "nor " << place << ", " << place << ", " << place << endl 
	<< "addi " << place << ", " << place << ", 1" << endl ;	
	return ss.str();
}

string GTEExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;

	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	ss <<"#GTE"<<endl<< code1 << code2 << endl
        << "slt " << place << ", " << place2 << ", " << place1 << endl 
	<< "nor " << place << ", " << place << ", " << place << endl 
	<< "addi " << place << ", " << place << ", 1" << endl ;
	return ss.str();	
}
string NEExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;

	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	
	ss << "#NE"<<endl<<code1 << code2 << endl <<
	"bne " << place1 << ", " << place2 <<", "<< ltrue << endl
        << "li " << place << ", 0\n" 
        << "j " << lend << endl
        << ltrue << ":\n" 
        << "li " << place << ", 1\n"
        << lend << ":\n" ;
	releaseTemp(place);
	return ss.str();

}
string EQExpr::generateCode(string &place)
{
	string ltrue = newLabel();
	string lend = newLabel();
	string place1, place2;
    	string code1 = expr1->generateCode(place1);
    	string code2 = expr2->generateCode(place2);
    	stringstream ss;

	releaseTemp(place1);
    	releaseTemp(place2);
    	place = newTemp();
	
	ss << "#EQ"<<endl<<code1 << code2 << endl <<
	"beq " << place1 << ", " << place2 <<", "<< ltrue << endl
        << "li " << place << ", 0\n" 
        << "j " << lend << endl
        << ltrue << ":\n" 
        << "li " << place << ", 1\n"
        << lend << ":\n" ;
	releaseTemp(place);
	return ss.str();
}
string IdExpr::generateCode(string &place)
{
	if(varsMips.find(id) == varsMips.end())
	{
		if(varsMipsAssign.find(id)==varsMipsAssign.end()){
			printf("Id %s no existe!\n",id.c_str());
			exit(0);
		}
	}
	stringstream ss;

	place = newTemp();
        
	ss << "la " << place << ", " << id << endl <<
	"lw " << place << ", " << "0("<< place << ")" << endl;

	return ss.str();
		
}
string NumExpr::generateCode(string &place)
{
    stringstream ss;
    
    place = newTemp();
    
    ss << "li " << place << ", " << value.intValue() << endl;
    
    return ss.str();
}
string CharExpr::generateCode(string &place)
{
	string charstring;	
	stringstream s;
	s << character;
	s >> charstring;	
	if (var_char.find(charstring) == var_char.end()) {
		var_char.insert(charstring);
		cout << character << ": .asciiz " << "\"" <<character<<"\"" << endl;
    	}	

	stringstream ss;
    	place = newTemp();	
	ss << "la " << place << ", " << character << endl;
	return ss.str();
}
string StringExpr::generateCode(string &place)
{
	if (var_string.find(str) == var_string.end()) {
		var_string.insert(str);
		cout << str << ": .asciiz " << "\"" << str<<"\"" << endl;
    	}	

	stringstream ss;
    	place = newTemp();	
	ss << "la " << place << ", " << str << endl;
	return ss.str();
}
string BoolExpr::generateCode(string &place)
{
    stringstream ss;
    place = newTemp();
    if(boolean.boolValue())
    	ss << "li " << place << ", 1" << endl;
    else
	ss << "li " << place << ", 0" << endl;
    return ss.str();
}
string MethodCallExpr::generateCode(string &place)
{
     if( methodList.find(id)==methodList.end() )
	     	throw invalid_argument("Metodo "+ id +" no existe.");
     stringstream ss;
     if(!parameters.empty()){
       vector<Expr*>::iterator it = parameters.begin(); 
       int params = parameters.size();
       ss << "addi " << "$sp, $sp, " << (-1 * (params*4)) << endl;
       int index = 0;
       while(it != parameters.end())
       {   
           Expr * ex = *it;
	   string code = ex->generateCode(place);
           ss << "sw " << place << ", " << (index * 4) << "($sp)"<< endl;
           releaseTemp(place);
	   index++;
           it++;
       }
     }
     ss << "jal " << id << endl;
     return ss.str();
	
}
void ClassStatement::execute()
{
	breakContinue["break"]=0;
	breakContinue["continue"]=0;
	if(decls != 0)    
		decls->execute();
    	if(methods != 0)
		methods->execute();
	if(methodList.find("main")!=methodList.end()){
		MethodStatement * method = methodList["main"];
         	if(method->type != VOID)  
			throw invalid_argument("Metodo main no debe retornar un tipo.");
		if(method->parameters.size() != 0)
			throw invalid_argument("Metodo main no debe tener parameteros.");
		method->blockM->execute();
		delete method;
        }
}
string BlockStatement::generateCode (string label1, string label2)
{
	stringstream ss;
	list<Statement *>::iterator it = stList.begin();
    
    	while (it != stList.end()) {
        	Statement *st = *it;
        
        	ss << st->generateCode(label1,label2) << endl;
        	it++;
        }   
	return ss.str();

}
string IfStatement::generateCode(string label1, string label2)
{
	string place1;
    	string code = cond->generateCode(place1);
        string end_l = newLabel();
    	string false_l = newLabel();
    	stringstream ss;

    	releaseTemp(place1);

    	string trueCode = trueBlock->generateCode(label1, label2);
    	string falseCode = "";
    	if (falseBlock != 0)
		falseCode = falseBlock->generateCode(label1, label2);

    	ss <<   "#If"<< endl << 
    	code << endl <<
    	"beq " << place1 << ", " << "$zero" << ", " << false_l << "\n" <<
    	trueCode << endl <<
    	"j " << end_l << endl <<
    	false_l << ": \n" <<
    	falseCode << endl <<
    	end_l << ":\n";
	return ss.str();	
}   
string WhileStatement::generateCode(string label1, string label2)
{
	string place1;
	string code = cond->generateCode(place1);
	label1=newLabel();
	label2=newLabel();
	string bcode = blockW->generateCode(label1,label2);
	stringstream ss;
	ss << "#While" << endl <<
        label1 <<":\n" << 
        code << endl <<
    	"beq " <<place1 <<", "<<" $zero"<< ", "<< label2 << endl <<
	bcode  << endl <<
	"j " << label1 << endl <<
        label2 <<  ":\n";
        return ss.str(); 
}
string BreakStatement::generateCode(string label1, string label2) {
    stringstream ss;
    if(!label1.empty()){
        ss << "#Break" << endl <<
	"j " << label2 << "\n";
    }else{
        throw invalid_argument("Break no es parte de un ciclo.\n");
    }
    return ss.str();
}

string ContinueStatement::generateCode(string label1, string label2) {
    stringstream ss;
    if(!label1.empty()){
        ss << "#Continue" << endl << 
        "j " << label1 << "\n";
    }else{
        throw invalid_argument("Continue no es parte de un ciclo.\n");
    }
    return ss.str();
}
string ReturnStatement::generateCode(string label1, string label2){
    
    stringstream ss;
    if(expr != 0){
	    string place;
	    string code = expr->generateCode(place);
	    ss << code << endl <<
	    "move "<< "$v0" <<" , "<< place << endl << 
	    "jr " << "$ra" << endl;
    }else 
	 ss << "jr " << "$ra" << endl;
    return ss.str();
}
string ForStatement::generateCode(string label1,string label2){
	string place;
	string code = cond->generateCode(place);
	string initCode = asignacion->generateCode(label1,label2);
	string incrCode = asignacion2->generateCode(label1,label2);
	
	label1=newLabel();
	label2=newLabel();
	
	string blockCode = blockF->generateCode(label1,label2);
	
	stringstream ss;
	ss << "#For" << endl <<
	initCode << endl <<
        label1 <<":\n" << 
        code << endl <<
    	"beq " <<place <<", "<<" $zero"<< ", "<< label2 << endl <<
	blockCode  << endl <<
	incrCode << endl <<
	"j " << label1 << endl <<
        label2 <<  ":\n";
        
	return ss.str(); 
}
string PrintStatement::generateCode(string label1, string label2){
   
    list<Expr *>::iterator it= listExpr.begin();
    string place;	
    stringstream ss;
    while(it != listExpr.end())
    { 
        Expr *expr = *it;
	string code = expr->generateCode(place);
        ss <<"#Print"<<endl << 
	code << endl;

        
	if(expr->isA(ID_EXPR))
	{
	    ss << "move " << "$a0"<<", " << place << endl <<
	    "li " << "$v0" <<", "<< "1" << endl <<
            "syscall" << endl <<
	    "la $a0, newLine" << endl <<
	    "li $v0, 4" << endl <<
	    "syscall" << endl;
	}
	else if(expr->isA(CHAR_EXPR))
	{
	    ss << "move " << "$a0" <<", "<< place << endl <<
	    "li " << "$v0" <<", "<< "4" << endl <<
            "syscall" << endl <<
	    "la $a0, newLine" << endl <<
	    "li $v0, 4" << endl <<
	    "syscall" << endl;
	}
        else if(expr->isA(STRING_EXPR))
        {
	    ss << "move " << "$a0" <<", "<< place << endl <<
            "li " << "$v0" <<", "<< "4" << endl <<
            "syscall" << endl <<
	    "la $a0, newLine" << endl <<
	    "li $v0, 4" << endl <<
	    "syscall" << endl;
        }
	else
        {
            ss << "move " << "$a0"<<", " << place << endl <<
	    "li " << "$v0" <<", "<< "1" << endl <<
            "syscall" << endl <<
	    "la $a0, newLine" << endl <<
	    "li $v0, 4" << endl <<
	    "syscall" << endl;
        }
        it++;
    }

    return ss.str();
}
string ClassStatement::generateCode(string label1, string label2){	
	string codeDcl = decls ->generateCode(label1,label2);
	string codeMet = methods->generateCode(label1,label2);
	if( methodList.find("main")==methodList.end() )
	     	throw invalid_argument("Metodo main no existe.\nDebe existir el metedo main.");
	map<string, MethodStatement *> :: iterator it = methodList.begin();
	tempMap.clear();
	stringstream ss;
	ss << classname << ":" << endl <<
	"jal " << "main" << endl <<
	"li $v0, 10" << endl <<
	"syscall" << endl;

	while(it != methodList.end())
	{
		MethodStatement * method = (*it).second;
		string funlabel = method->id;
		string codefunc = method->blockM->generateCode(label1,label2);
		
		ss << funlabel << ":" << endl <<
		"#Prologo" << endl <<
		"addi $sp, $sp, -32 " << endl;
		for(int i=0;i < 8; i++)
			ss << "sw $s" << i << ", " << (i*4) << "($sp)" << endl;
		ss <<"addi " << "$sp, " << "$sp, " << "-8"<<endl <<
        	"sw $ra, 0($sp)"<<endl <<
        	"sw $fp, 4($sp)"<<endl <<  
		codefunc << endl <<
		"#Epilogo" << endl <<
		"lw $ra, 0($sp)"<< endl <<
		"lw $fp, 4($sp)"<< endl <<
		"addi $sp, $sp, 8"<< endl;
		for (int i = 0; i < 8; i++) {
		    ss << "lw $s" << i << ", " << (i*4) << "($sp)" << endl;
		}
		ss << "addi $sp, $sp, 32" << endl;
		if(method->id == "main")
			ss << "jr $ra" << endl;
		it++; 
	}
	
	return ss.str();

}
string AssignStatement::generateCode(string label1, string label2){
	if(!id->isA(ID_EXPR))
		throw invalid_argument("El objeto al que se le asigna valor no es id.");	
	IdExpr * idEx = (IdExpr*)id;
	if (varsMips.find(idEx->id) == varsMips.end()) {
		if(varsMipsAssign.find(idEx->id)==varsMipsAssign.end())
			throw invalid_argument("Id "+idEx->id+" no existe.");
    	}
    	
	string place, temp;
    	stringstream ss;
	
	string code = expr->generateCode(place);
	
	temp = newTemp();
	
	ss << code << endl <<
	"la " << temp << ", " << idEx->id << endl <<
	 "sw " << place << ", 0(" << temp << ")";
	   
	releaseTemp(place);
	releaseTemp(temp);
	
	return ss.str();	
}
string ReadStatement::generateCode(string label1, string label2){
	list<Expr *>::iterator it= listExpr.begin();
   	string place;	
    	stringstream ss;
	string temp;
	temp = newTemp();
	string place1;
	
    	while(it != listExpr.end())
    	{ 
        	Expr *expr = *it;
		string code = expr->generateCode(place);
        	ss << "#READ"<< endl <<code << endl <<
		"li "<< "$v0, " << "5" << endl <<
		"syscall" << endl <<
		"move " << place << ", " << "$v0" << endl;
		IdExpr * idEx = (IdExpr*)expr;
		ss <<"la " << temp << ", " << idEx->id << endl <<
	 	"sw " << place << ", 0(" << temp << ")";
		
		it++; 
	}	
	return ss.str();
}
string MethodCallStatement::generateCode(string label1, string label2){
     if( methodList.find(id)==methodList.end() )
	     	throw invalid_argument("Metodo "+ id +" no existe.");
     stringstream ss;
     if(!parameters.empty()){
       vector<Expr*>::iterator it = parameters.begin();; 
       int params = parameters.size();
       ss << "addi " << "$sp, $sp, " << (-1 * (params*4)) << endl;
       int index = 0;
       while(it != parameters.end())
       {   
           Expr * ex = *it;
	   string place;
	   string code = ex->generateCode(place);
           ss << "sw " << place << ", " << (index * 4) << "($sp)"<< "\n";
           releaseTemp(place);
	   index++;
           it++;
       }
     }
     ss << "jal " << id << endl;
     return ss.str();
}
string GlobalIdDeclarationStatement::generateCode(string label1, string label2){
return ("");
}
string GlobalDeclarationStatement::generateCode(string label1, string label2){
	list<GlobalIdDeclarationStatement *>::iterator it = listIdentifiers.begin();
    	while (it != listIdentifiers.end()) {
		 GlobalIdDeclarationStatement * idDcl = *it;
		if( varsMips.find(idDcl->id)!=varsMips.end() )
	     		throw invalid_argument("ID "+ idDcl->id +" ya existe.");
		varsMips.insert(idDcl->id);
		cout << idDcl->id << ": .word 0" << endl;
		it++;
	}
	return ("");
}
string GlobalDeclarationAssignStatement::generateCode(string label1, string label2){
	VValue value = constant->evaluate();
	 if(type != value.type)
	     	throw invalid_argument("Tipos incompatibles en asignacion inmediata.");
	if(varsMipsAssign.find("id") != varsMipsAssign.end())
		throw invalid_argument("Variable "+id+" ya existe.");
	if(type == INT){
	 	varsMipsAssign[id] = value.intValue();
		cout << id << ": .word " << value.intValue() << endl;
	}
	else{
		 varsMipsAssign[id] = value.boolValue();
		 cout << id << ": .word " << value.boolValue() << endl;
	}
	return ("");
}
string ParameterDefinitionStatement::generateCode(string label1, string label2){
	string places = newTempS();	
	stringstream ss;	
		
	return ("");
}
string MethodStatement::generateCode(string label1, string label2){
	if( methodList.find(id)!=methodList.end() )
		throw invalid_argument("Metodo "+id+" ya existe.");
	methodList[id] = this; 
	return ("");    
}
string LocalDeclarationStatement::generateCode(string label1, string label2){
	string places = newTempS();	
	stringstream ss;
	
	return ("");
}

void MethodCallStatement::execute()
{
	if( methodList.find(id)==methodList.end() )
	     	throw invalid_argument("Metodo "+ id +" no existe.");
	MethodStatement * method = methodList[id];
        if(method->type != VOID)
		throw invalid_argument("Metodo "+ id +" retorna un tipo.");
	if(parameters.size() != method->parameters.size())
	     	throw invalid_argument("Numero de parametros incorrectos en la llamada del metodo "+id+".");
	if(parameters.size() != 0){
	    list<ParameterDefinitionStatement*>::iterator it = method->parameters.begin();
    	    int i = 0;
	    while (it != method->parameters.end()) {
		ParameterDefinitionStatement* param = *it;
                VValue paramValue = parameters[i]->evaluate();
		if(param->type != paramValue.type)
                     throw invalid_argument("Parametro incompatible en la llamada del metodo "+id+".");
		VValue newValue;
		newValue.type = param->type;
		if(param->type == INT){
		    newValue.u.ivalue =paramValue.intValue();
		}else if(param->type == BOOLEAN){
		    newValue.u.bvalue =paramValue.boolValue();
		}
		params[param->id] = newValue;
		i++;
		it++;
	    }   
	}
	method->blockM->execute();
	params.clear();
	localvars.clear();
}

void GlobalIdDeclarationStatement::execute(){
	//Nada
}

void GlobalDeclarationStatement::execute()
{
    list<GlobalIdDeclarationStatement *>::iterator it = listIdentifiers.begin();
    while (it != listIdentifiers.end()) {
         GlobalIdDeclarationStatement * id = (GlobalIdDeclarationStatement*)*it;
	 if( vars.find(id->id)!=vars.end() )
	     	throw invalid_argument("ID "+ id->id +" ya existe.");
         VValue newVariable;
	 newVariable.type = type;
	 if(id->dimensions != 0 ){
	 	newVariable.u.iarray= (int*)malloc (sizeof (int) * id->dimensions);
		vars[id->id] = newVariable;
         }else{
		 if(type == INT)
		     newVariable.u.ivalue = 0;
		 else if(type == BOOLEAN)
		     newVariable.u.bvalue = false;
		 vars[id->id] = newVariable;
	 }
        it++;
    }   
   
}

void GlobalDeclarationAssignStatement::execute(){
	 VValue newVariable;
         VValue value = constant->evaluate(); 
	 if(type != value.type)
	     	throw invalid_argument("Tipos incompatibles en asignacion inmediata.");
	 newVariable.type = type;
	 if(type == INT)
	 {
	    newVariable.u.ivalue = value.intValue();
	 }else if(type == BOOLEAN){
	    newVariable.u.bvalue = value.boolValue();
         }
	 
        vars[id] = newVariable;
}

void ParameterDefinitionStatement::execute(){
	//Nada
}

void MethodStatement::execute(){
	if( methodList.find(id)!=methodList.end() )
		throw invalid_argument("Metodo "+id+" ya existe.");
	methodList[id] = this;
}

void LocalDeclarationStatement::execute()
{
    list<string>::iterator it = listIds.begin();
    
    while (it != listIds.end()) {
        string nombre = *it;
        VValue newValue;
        newValue.type = type;
        if(type == INT){
            newValue.u.ivalue =0;
        }else if(type == BOOLEAN){
            newValue.u.bvalue =false;
        }
        localvars[nombre] = newValue;
        it++;
    }   
}

void BlockStatement::execute()
{
    list<Statement *>::iterator it = stList.begin();
    
    while (it != stList.end()) {
        Statement *st = *it;
        st->execute();
        it++;
    }   
}

void PrintStatement::execute() 
{
    list<Expr *>::iterator it = listExpr.begin();
    
    while (it != listExpr.end()) {
      Expr *expr = *it;
      
      if (expr->isA(STRING_EXPR)) {
	printf("%s", ((StringExpr*)expr)->str.c_str());
      } else if(expr->isA(CHAR_EXPR)) {
	printf("%c", ((CharExpr*)expr)->character);
      } else if(expr->isA(ID_EXPR)){
	      IdExpr *id = (IdExpr*)expr;
	      if(id->position != 0){
		VValue pos = id->position->evaluate();
		VValue idPrint = id->evaluate();
		if(pos.type != INT)
			throw invalid_argument("Error: La posicion del arreglo debe ser de tipo entero. ");
		
		if(idPrint.type == INT)
			printf("%d\n",idPrint.u.iarray[pos.intValue()]);
		else
			printf("%s\n", idPrint.u.iarray[pos.intValue()] ? "true" : "false");	
	      }else{
              	 VValue result = id->evaluate();
		 if(result.type == INT)
          		printf("%d\n", result.u.ivalue);
        	 else
            		printf("%s\n", result.u.bvalue ? "true" : "false");
              }
      }else{
          	VValue result = expr->evaluate();
		if(result.type == INT)
		    printf("%d\n", result.u.ivalue);
		else
		    printf("%s\n", result.u.bvalue ? "true" : "false");
      } 
      it++;
    }
     printf("\n");
}
void ReadStatement::execute() 
{
    list<Expr *>::iterator it = listExpr.begin();
    int tmp = 0;
    while (it != listExpr.end()) {
      scanf("%d",&tmp);
      Expr *expr =*it;
      if(expr->isA(ID_EXPR)){
	      IdExpr *id = (IdExpr*)expr;
	      if(id->position != 0){
                 	VValue pos = id->position->evaluate();
			VValue idRead = id->evaluate();
			if(pos.type != INT)
				throw invalid_argument("Error: La posicion del arreglo debe ser de tipo entero. ");		
			idRead.u.iarray[pos.intValue()]=tmp;
			vars[id->id]=idRead;
			 
	      }else{
              	 VValue idRead = id->evaluate();
		 if(idRead.type == INT){
			idRead.u.ivalue = tmp;
		 }
		 else{		
			idRead.u.bvalue = tmp;
		 }
	         vars[id->id]=idRead;
              }
      }
      else
	      throw invalid_argument("Error: Debe ser un id para poder leer. ");   
      it++;  			
    }
    printf("\n");
}

void ReturnStatement::execute()
{
	if(expr != 0){
		VValue returnValue = expr->evaluate();
		localvars["return"] = returnValue;
	}
}

void ContinueStatement::execute()
{
	
     breakContinue["continue"]=1;
}

void BreakStatement::execute()
{
     breakContinue["break"]=1;
}


void AssignStatement::execute()
{
    if(id->isA(ID_EXPR)){
            IdExpr * idEx = (IdExpr*)id; 
	    if(params.find(idEx->id)!=params.end())
	    {
		if( idEx->position != 0){
		    	VValue result = expr->evaluate();
		    	VValue idType = params[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
			VValue position = idEx->position->evaluate();
			if(position.type != INT)
				throw invalid_argument("Error: La posicion en el arreglo debe ser de tipo entero. ");
			if(result.type==INT)			
				idType.u.iarray[position.intValue()]= result.intValue();
			else
				idType.u.iarray[position.intValue()]= result.boolValue();
			params[idEx->id]=idType;
	    	}else{
			VValue result = expr->evaluate();
		    	VValue idType = params[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
		    	params[idEx->id] = result;
	    	}
	    }
	    else if(localvars.find(idEx->id)!=localvars.end())
	    {	
		if( idEx->position != 0){
		    	VValue result = expr->evaluate();
		    	VValue idType = localvars[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
			VValue position = idEx->position->evaluate();
			if(position.type != INT)
				throw invalid_argument("Error: La posicion en el arreglo debe ser de tipo entero. ");
			if(result.type==INT)			
				idType.u.iarray[position.intValue()]= result.intValue();
			else
				idType.u.iarray[position.intValue()]= result.boolValue();
			localvars[idEx->id]=idType;
	    	}else{
			VValue result = expr->evaluate();
		    	VValue idType = localvars[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
		    	localvars[idEx->id] = result;
		}
	    }
	    else if( vars.find(idEx->id)!=vars.end() )
            {
	     	if( idEx->position != 0){
		    	VValue result = expr->evaluate();
		    	VValue idType = vars[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
			VValue position = idEx->position->evaluate();
			if(position.type != INT)
				throw invalid_argument("Error: La posicion en el arreglo debe ser de tipo entero. ");
			
			if(result.type==INT)			
				idType.u.iarray[position.intValue()]= result.intValue();
			else
				idType.u.iarray[position.intValue()]= result.boolValue();
			vars[idEx->id]=idType;
	    	}else{
			VValue result = expr->evaluate();
		    	VValue idType = vars[idEx->id];
			if(result.type != idType.type)
				throw invalid_argument("Error: Tipos incompatibles en asignacion. "); 
		    	vars[idEx->id] = result;
		}
            }
	    else
		throw invalid_argument("ID "+ idEx->id +" no existe.");
	    
     }else 
	throw invalid_argument("Error: Debe ser un id en la asignacion. "); 
    
}

void IfStatement::execute()
{
    VValue result = cond->evaluate();
    if(result.type != BOOLEAN)
	throw invalid_argument("Error: La condicion del if debe ser de tipo boolean. ");
    if (result.boolValue()) {
        trueBlock->execute();
    } else if (falseBlock != 0) {
        falseBlock->execute();
    }
}

void WhileStatement::execute()
{

    VValue result = cond->evaluate();
    if(result.type != BOOLEAN)
	throw invalid_argument("Error: La condicion del while debe ser de tipo boolean. ");
    while (result.boolValue()) {

        blockW->execute();
	if(breakContinue["break"])
		break;
	else if(breakContinue["continue"]){
		result = cond->evaluate();
		breakContinue["continue"]=0;		
		continue;
	}
	result = cond->evaluate();
    }
    breakContinue["break"]=0;
    breakContinue["continue"]=0;
}

void ForStatement::execute()
{
    if(cond->evaluate().type != BOOLEAN)
	throw invalid_argument("Error: La condicion del for debe ser de tipo boolean. ");
    
    for( asignacion->execute(); cond->evaluate().boolValue();asignacion2->execute()){
	blockF->execute();
	if(breakContinue["break"])
		break;
	else if(breakContinue["continue"]){
		breakContinue["continue"]=0;
		continue;
	}
    }
    breakContinue["break"]=0;
    breakContinue["continue"]=0;
}

