#ifndef _AST_H_ 
#define _AST_H_

#include <string>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

enum DataType {INT, BOOLEAN , VOID};

struct VValue {
   bool boolValue() {
	return u.bvalue;
    }
    
    int intValue() {
        return u.ivalue;
    }
    
    DataType type;
    
    union {
        int ivalue;
	int *iarray;
        bool bvalue;
    } u;
};
extern map<string, VValue> vars;
extern map<string, VValue> localvars;
extern map<string, VValue> params;


enum ExprKind {
  LT_EXPR,
  LTE_EXPR,
  GT_EXPR,
  GTE_EXPR,
  NE_EXPR,
  EQ_EXPR,
  ADD_EXPR,
  SUB_EXPR,
  MULT_EXPR,
  MOD_EXPR,
  AND_EXPR,
  OR_EXPR,
  NOT_EXPR,
  ROT_EXPR,
  RSHIFT_EXPR,
  LSHIFT_EXPR,
  DIV_EXPR,
  NUM_EXPR,
  CHAR_EXPR,
  BOOL_EXPR,
  ID_EXPR,
  STRING_EXPR,
  METHODCALL_EXPR
};
typedef list<string> IdList;

class Expr {
public:
    virtual VValue evaluate() = 0;
    virtual int getKind() = 0;
    virtual string generateCode(string &place) = 0;
    bool isA(int kind) { return (getKind() == kind); }
};
typedef vector<Expr*> ExprVector;
typedef list<Expr*> ExprList;


class BinaryExpr: public Expr {
public:
    BinaryExpr(Expr *expr1, Expr *expr2) {
        this->expr1 = expr1;
        this->expr2 = expr2;
    }
    
    Expr *expr1;
    Expr *expr2;
};

class UnaryExpr: public Expr {
public:
    UnaryExpr(Expr *expr) {
        this->expr = expr;
    }
    
    Expr *expr;
};

class NotExpr: public UnaryExpr {
public:
    NotExpr(Expr *expr): UnaryExpr(expr) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return NOT_EXPR; }
};


class AndExpr: public BinaryExpr {
public:
    AndExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return AND_EXPR; }
};

class OrExpr: public BinaryExpr {
public:
    OrExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return OR_EXPR; }
};

class RShiftExpr: public BinaryExpr {
public:
    RShiftExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return OR_EXPR; }
};

class LShiftExpr: public BinaryExpr {
public:
    LShiftExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return OR_EXPR; }
};

class RotExpr: public BinaryExpr {
public:
    RotExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return OR_EXPR; }
};

class LTExpr: public BinaryExpr {
public:
    LTExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return LT_EXPR; }
};

class GTExpr: public BinaryExpr {
public:
    GTExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return GT_EXPR; }
};

class LTEExpr: public BinaryExpr {
public:
    LTEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return LTE_EXPR; }
};

class GTEExpr: public BinaryExpr {
public:
    GTEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return GTE_EXPR; }
};

class NEExpr: public BinaryExpr {
public:
    NEExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return NE_EXPR; }
};

class EQExpr: public BinaryExpr {
public:
    EQExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return NE_EXPR; }
};

class AddExpr: public BinaryExpr {
public:
    AddExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return ADD_EXPR; }
};

class SubExpr: public BinaryExpr {
public:
    SubExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return SUB_EXPR; }
};

class MultExpr: public BinaryExpr {
public:
    MultExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return MULT_EXPR; }
};

class DivExpr: public BinaryExpr {
public:
    DivExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return DIV_EXPR; }
};

class ModExpr: public BinaryExpr {
public:
    ModExpr(Expr *expr1, Expr *expr2): BinaryExpr(expr1, expr2) {}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return MOD_EXPR; }
};

class NumExpr: public Expr {
public:
    NumExpr(int value) { this->value.u.ivalue = value;this->value.type= INT; }
    string generateCode(string &place);
    VValue evaluate() { return value; }
    int getKind() { return NUM_EXPR; }  
    VValue value;
};

class CharExpr: public Expr {
public:
    CharExpr(char character) { this->character = character; }
    string generateCode(string &place);
    VValue evaluate() { VValue v; return v; }
    int getKind() { return CHAR_EXPR; }
    char character;
};

class BoolExpr: public Expr {
public:
    BoolExpr(bool boolean) { this->boolean.u.bvalue = boolean; this->boolean.type= BOOLEAN; }
    string generateCode(string &place);
    VValue evaluate() { return boolean; }
    int getKind() { return BOOL_EXPR; }
    VValue boolean;
};

class IdExpr: public Expr {
public:
    IdExpr(string id, Expr * position) { 
						this->id = id;
						this->position = position;
					}
    string generateCode(string &place);
    VValue evaluate();
    int getKind() { return ID_EXPR; }
    string id;
    Expr * position;
};

class StringExpr: public Expr {
public:
    StringExpr(string str) { this->str = str; }
    string generateCode(string &place);
    VValue evaluate() { VValue v; return v; }
    int getKind() { return STRING_EXPR; }
    string str;
};

class MethodCallExpr : public Expr {
public:
	MethodCallExpr(string id, vector<Expr*>parameters){this->id=id; this->parameters=parameters;}
	string generateCode(string &place);     	
	VValue evaluate();
    	int getKind() { return METHODCALL_EXPR; }
        string id;
	vector<Expr*> parameters;
};

enum StatementKind {
    BLOCK_STATEMENT,
    PRINT_STATEMENT,
    ASSIGN_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    LOCALDECLARATION_STATEMENT,
    GLOBALDECLARATION_STATEMENT,
    GLOBALIDDECLARATION_STATEMENT,
    GLOBALDECLARATIONASSIGN_STATEMENT,
    READ_STATEMENT,
    CLASS_STATEMENT,
    METHODCALL_STATEMENT,
    RETURN_STATEMENT,
    CONTINUE_STATEMENT,
    BREAK_STATEMENT,
    PARAMETERDEFINITION_STATEMENT,
    METHOD_STATEMENT
};

class Statement {
public:
    virtual void execute() = 0;
    virtual StatementKind getKind() = 0;
    virtual string generateCode(string label1, string label2)=0;
};
typedef list<Statement*> StatementList;


class ClassStatement : public Statement{
public: 
   ClassStatement(string classname,Statement *decls,Statement *methods){this->classname=classname;this->decls=decls;this->methods=methods;}
     	void execute();
	string generateCode(string label1, string label2);    	
	StatementKind getKind() { return CLASS_STATEMENT; }
	string classname;
	Statement * decls; 
	Statement * methods;
};

class MethodCallStatement : public Statement {
public:	
	MethodCallStatement(string id, vector<Expr*>parameters){this->id=id; this->parameters=parameters;}
     	void execute();
	string generateCode(string label1, string label2);    	
	StatementKind getKind() { return METHODCALL_STATEMENT; }
        string id;
	vector<Expr*> parameters;
};

class GlobalIdDeclarationStatement : public Statement{
public:
	GlobalIdDeclarationStatement( string id, int dimensions) {this->id=id;this->dimensions=dimensions; }
    	void execute();
	string generateCode(string label1, string label2);    
	StatementKind getKind() { return GLOBALIDDECLARATION_STATEMENT; }
    	string id;
    	int dimensions;
};
typedef list<GlobalIdDeclarationStatement*> GlobalIdList; 

class GlobalDeclarationStatement: public Statement {
public:
    GlobalDeclarationStatement(DataType type, list<GlobalIdDeclarationStatement *> listIdentifiers) 
    {
	this->type=type;
	this->listIdentifiers=listIdentifiers; 

    }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return GLOBALDECLARATION_STATEMENT; }
    
    list<GlobalIdDeclarationStatement *> listIdentifiers;
    DataType type;
};

class GlobalDeclarationAssignStatement: public Statement{
public:
    GlobalDeclarationAssignStatement(DataType type, string id, Expr* constant) { 
									this->id = id; 
									this->constant =constant;
									this->type = type;
								}
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return GLOBALDECLARATIONASSIGN_STATEMENT; }
    string id;
    DataType type;
    Expr * constant;
};

class ParameterDefinitionStatement : public Statement {
public:
	ParameterDefinitionStatement(DataType type, string id )
    	{ 
		this->id =id;
		this->type = type;
     	}
	string generateCode(string label1, string label2);    	
	void execute();
   	DataType type;
    	StatementKind getKind() { return PARAMETERDEFINITION_STATEMENT; }
    	string id;
};
typedef list<ParameterDefinitionStatement*> ParameterDefList;


class MethodStatement : public Statement {
public:	
	MethodStatement(DataType type, string id,list<ParameterDefinitionStatement*>parameters, Statement* blockM)
	{
		this->type = type;
		this->id=id; 
		this->parameters=parameters;
		this->blockM = blockM;
	}
	string generateCode(string label1, string label2);     	
	void execute();
    	StatementKind getKind() { return METHOD_STATEMENT; }
	DataType type;        
	string id;
	list<ParameterDefinitionStatement*> parameters;
	Statement * blockM;
};
extern map<string, MethodStatement *> methodList;


class LocalDeclarationStatement: public Statement {
public:
    LocalDeclarationStatement( DataType type, list<string> listIds )
    { 
	this->listIds =listIds;
        this->type = type;
     }
    string generateCode(string label1, string label2);
    void execute();
    DataType type;
    StatementKind getKind() { return LOCALDECLARATION_STATEMENT; }
    list<string> listIds;
};
class BlockStatement: public Statement {
public:
    BlockStatement(list<Statement *> stList) { this->stList = stList; }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return BLOCK_STATEMENT; }
    
    list<Statement *> stList;
};

class PrintStatement: public Statement {
public:
    PrintStatement(list<Expr*> listExpr) { this->listExpr = listExpr; }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return PRINT_STATEMENT; }
    
    list<Expr*> listExpr;
};
class ReadStatement: public Statement {
public:
    ReadStatement(list<Expr*> listExpr) { this->listExpr = listExpr; }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return READ_STATEMENT; }
    
    list<Expr*> listExpr;
};
class ReturnStatement: public Statement {
public:
    ReturnStatement(Expr * expr) { this->expr = expr; }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return RETURN_STATEMENT; }
    
    Expr* expr;
};
class BreakStatement: public Statement {
public:
    BreakStatement() { }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return BREAK_STATEMENT; }
};
class ContinueStatement: public Statement {
public:
    ContinueStatement() { }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return CONTINUE_STATEMENT; }
    
};


class AssignStatement: public Statement {
public:
    AssignStatement(Expr* id, Expr *expr) { 
        this->id = id;
        this->expr = expr; 
    }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return ASSIGN_STATEMENT; }
    
    Expr * id;
    Expr *expr;
};

class IfStatement: public Statement {
public:
    IfStatement(Expr *cond, Statement *trueBlock, Statement *falseBlock) { 
        this->cond = cond; 
        this->trueBlock = trueBlock;
        this->falseBlock = falseBlock;
    }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return IF_STATEMENT; }
    
    Expr *cond;
    Statement *trueBlock;
    Statement *falseBlock;
};

class WhileStatement: public Statement {
public:
    WhileStatement(Expr *cond, Statement *blockW) { 
        this->cond = cond; 
        this->blockW = blockW;
       
    }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return WHILE_STATEMENT; }
    
    Expr *cond;
    Statement *	blockW;
    
};

class ForStatement: public Statement {
public:
    ForStatement(Statement *asignacion,Expr *cond,Statement *asignacion2,Statement *blockF) { 
	this->asignacion = asignacion;
	this->asignacion2 = asignacion2;       
	this->cond = cond; 
       
        this->blockF = blockF;
       
    }
    string generateCode(string label1, string label2);
    void execute();
    StatementKind getKind() { return FOR_STATEMENT; }
    
    Expr *cond;
    Statement * asignacion;
    Statement *asignacion2;
    Statement *	blockF;
    
};

#endif

