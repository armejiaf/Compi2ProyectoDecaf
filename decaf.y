%{
#include <cstdio>
#include <string>
#include "ast.h"

using namespace std;

extern int line;

int yylex();

void yyerror(const char *str)
{
    printf("Line %d: %s\n", line, str);
}

#define YYERROR_VERBOSE 1
Statement *input;
%}

%union {
    char *id_t;
    int  num_t;
    char char_t;
    ExprList * exprList_t;
    ExprVector * exprvect_t;
    IdList * idList_t;
    GlobalIdList * gIdList_t;
    ParameterDefList * pdeflist_t;
    Expr * expr_t;
    Statement *statement_t;
    DataType type_t;
}

%token<num_t> INT_CONSTANT 
%token<char_t> CHAR_CONSTANT
%token<id_t> ID
%token<id_t> STRING_CONSTANT
%token KW_CLASS KW_BREAK KW_READ KW_PRINT KW_CONTINUE KW_EXTENDS KW_ELSE KW_WHILE KW_FOR KW_IF KW_INT KW_NEW KW_NULL KW_RETURN KW_TRUE 
%token KW_FALSE KW_VOID KW_BOOL
%token OP_LT OP_GT OP_LTE OP_GTE OP_NE OP_EQ OP_ROT OP_NOT OP_OR OP_AND OP_SHIFT_LEFT OP_SHIFT_RIGHT
%type<expr_t> bool_constant constant factor lvalue expr term expras module shift relational equality expra opt_array argument opt_expr  
%type<exprList_t> print_list read_list
%type<exprvect_t> opt_call_arg_list call_arg_list
%type<statement_t> field opt_field_decl field_decls opt_method_decl method_decl method block opt_var_decl
%type<statement_t> opt_statements statements statement var_decl assign opt_else method_call assign_list var_decls 
%type<statement_t> arg id_decl_global
%type<type_t> type
%type<idList_t> id_list_local
%type<gIdList_t> id_list_global 
%type<pdeflist_t> arg_list opt_arg_list

%expect 4

%%
input: KW_CLASS ID '{' opt_field_decl opt_method_decl '}'  {input = new ClassStatement($2,$4,$5);}
;


opt_field_decl: field_decls { $$ = $1; }
	      |             { $$ = 0; }
;


field_decls: field_decls field { 
				        if ($1->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)$1;
				            
				            block->stList.push_back($2);
				            
				            $$ = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back($1);
				            l.push_back($2);
				            
				            $$ = new BlockStatement(l);
				        }
		               }
	   | field             { $$ = $1; }
;


field: type id_list_global ';'  { $$ = new GlobalDeclarationStatement($1,*$2);delete $2;}
     | type ID '=' constant ';' { $$ = new GlobalDeclarationAssignStatement($1, $2, $4); }
;

id_list_global: id_list_global ',' id_decl_global {
							$$ = $1;
					    		$$->push_back((GlobalIdDeclarationStatement*)$3);
						  }
	| id_decl_global                          {
							$$ = new GlobalIdList;
					    		$$->push_back((GlobalIdDeclarationStatement*)$1);
						  }
;

id_decl_global: ID                      { $$ = new GlobalIdDeclarationStatement($1, 0); }
	      | ID '[' INT_CONSTANT ']' { $$ = new GlobalIdDeclarationStatement($1, $3); }
;

opt_method_decl: method_decl  { $$ = $1;}
		|             { $$ = 0;}
;
method_decl: method_decl method { 
				        if ($1->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)$1;
				            
				            block->stList.push_back($2);
				            
				            $$ = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back($1);
				            l.push_back($2);
				            
				            $$ = new BlockStatement(l);
				        }
		            }
	    |method         { $$ = $1; }
;

method: type ID '(' opt_arg_list ')' block      { $$ = new MethodStatement($1, $2, *$4, $6);delete $4; }
       | KW_VOID  ID '(' opt_arg_list ')' block { $$ = new MethodStatement(VOID, $2, *$4, $6);delete $4; }
;

opt_arg_list: arg_list { $$ = $1; }
	     |         { $$ = new ParameterDefList; }
;

arg_list: arg_list ',' arg { 
				       $$ = $1;
				       $$->push_back((ParameterDefinitionStatement*)$3);
		            }
	 | arg              {
				$$ = new ParameterDefList;
			        $$->push_back((ParameterDefinitionStatement*)$1);
			    }
;

arg: type ID  { $$ = new ParameterDefinitionStatement($1, $2); }
;

block:'{' opt_var_decl opt_statements '}' { 
				            list<Statement *> l;
				            if($2 != 0)
				            	l.push_back($2);
					    if($3 != 0)
				            	l.push_back($3);
				            $$ = new BlockStatement(l);
					  }
;

opt_var_decl: var_decls { $$ = $1; }
	     |          { $$ = 0; }
; 
var_decls: var_decls var_decl { 
				        if ($1->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)$1;
				            
				            block->stList.push_back($2);
				            
				            $$ = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back($1);
				            l.push_back($2);
				            
				            $$ = new BlockStatement(l);
				        }
		              }
          | var_decl          { $$ = $1; }
;
var_decl: type id_list_local ';' { $$ = new LocalDeclarationStatement($1, *$2);delete $2; }
;
id_list_local: id_list_local ',' ID {
					    $$ = $1;
					    $$->push_back($3);
				    }
	| ID {
		    $$ = new IdList;
		    $$->push_back($1);
	     }
;
type:  KW_INT  { $$ = INT;}
     | KW_BOOL { $$ = BOOLEAN;}
;

opt_statements: statements { $$ = $1; }
		|          { $$ = 0; }
;

statements: statements statement { 
				        if ($1->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)$1;
				            
				            block->stList.push_back($2);
				            
				            $$ = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back($1);
				            l.push_back($2);
				            
				            $$ = new BlockStatement(l);
				        }
				 }
	   |statement            { $$ = $1; }
;

statement: assign ';'                                                  { $$ = $1; }
	  | method_call ';'                                            { $$ = $1; }
	  | KW_IF '(' expr ')' block opt_else                          { $$ = new IfStatement($3,$5,$6); }
	  | KW_WHILE '(' expr ')' block                                { $$ = new WhileStatement($3,$5); }
	  | KW_FOR '(' assign_list ';' expr ';' assign_list ')' block  { $$ = new ForStatement($3,$5,$7,$9);}
	  | KW_RETURN opt_expr ';'                                     { $$ = new ReturnStatement($2); }
	  | KW_BREAK ';'                                               { $$ = new BreakStatement(); }
	  | KW_CONTINUE ';'                                            { $$ = new ContinueStatement(); }
	  | block                                                      { $$ = $1; }
;
assign_list: assign_list ',' assign  { 
				        if ($1->getKind() == BLOCK_STATEMENT) {
				            BlockStatement *block = (BlockStatement*)$1;
				            
				            block->stList.push_back($3);
				            
				            $$ = block;
				        } else {
				            list<Statement *> l;
				            
				            l.push_back($1);
				            l.push_back($3);
				            
				            $$ = new BlockStatement(l);
				        }
				    }
	    |assign                 { $$ = $1; }
;
opt_else: KW_ELSE block { $$ = $2; }
	 |              { $$ = 0; }
;
opt_expr: expr { $$ = $1; }
	 |     { $$ = 0; }
;
assign: lvalue '=' expr { $$ = new AssignStatement($1,$3); }
;
method_call: ID '(' opt_call_arg_list ')' {  $$ = new MethodCallStatement($1, *$3);delete $3; }
	    | KW_PRINT print_list  { $$ = new PrintStatement(*$2);delete $2; }
	    | KW_READ read_list    { $$ = new ReadStatement(*$2);delete $2; }
;
opt_call_arg_list: call_arg_list { $$ = $1; }
		  | { $$ = new ExprVector; }
;
call_arg_list: call_arg_list ',' expr {
					    $$ = $1;
					    $$->push_back($3);
				       }
	      | expr { 
			    $$ = new ExprVector;
			    $$->push_back($1);
		     }
;
print_list: print_list ',' argument {
					    $$ = $1;
					    $$->push_back($3);
				    }
	   | argument { 
			    $$ = new ExprList;
			    $$->push_back($1);
		      }
;
read_list: read_list ',' lvalue {
					    $$ = $1;
					    $$->push_back($3);
				}
	  | lvalue { 
			    $$ = new ExprList;
			    $$->push_back($1);
		   }
;
argument: STRING_CONSTANT { $$ = new StringExpr($1); }
	 | expr           { $$ = $1; }
;
lvalue: ID opt_array     { $$ = new IdExpr($1, $2); }
;
opt_array: '[' expr ']'  { $$ = $2; }
	   |             { $$ = 0; }
;

expr: expr OP_OR expra {  $$ = new OrExpr($1, $3);  }
     | expra           {  $$ = $1; }
;
expra: expra OP_AND equality { $$ = new AndExpr($1, $3); }
      | equality	     { $$ = $1; }
;
equality: equality OP_EQ relational  { $$ = new EQExpr($1, $3); }
	 | equality OP_NE relational { $$ = new NEExpr($1, $3); }
	 | relational                { $$ = $$; }
;
relational: relational OP_GT shift   { $$ = new GTExpr($1, $3); }
	   | relational OP_LT shift  { $$ = new LTExpr($1, $3); }
	   | relational OP_LTE shift { $$ = new LTEExpr($1, $3); }
	   | relational OP_GTE shift { $$ = new GTEExpr($1, $3); }
	   | shift                   { $$ = $1; }
;
shift:shift OP_SHIFT_RIGHT module    { $$ = new RShiftExpr($1, $3); }
      | shift OP_SHIFT_LEFT module   { $$ = new LShiftExpr($1, $3); }
      | shift OP_ROT module          { $$ = new RotExpr($1,$3); }
      | module                       { $$ = $1; }
;
module: module '%' expras            { $$ = new ModExpr($1, $3); }
	|expras			     { $$ = $1; }
;
expras: expras '+' term 	     { $$ = new AddExpr($1, $3); }
	| expras '-' term	     { $$ = new SubExpr($1, $3); }
        | term 			     { $$ = $1; }
;
term: term '*' factor  		     { $$ = new MultExpr($1, $3); }
      | term '/' factor		     { $$ = new DivExpr($1, $3); }
      | factor                       { $$ = $1; }
;
factor: '-' factor		       { $$ = new MultExpr(new NumExpr(-1), $2); }
	| '!' factor		       { $$ = new NotExpr($2); }
	| lvalue                       { $$ = $1; }
	| ID '(' opt_call_arg_list ')' { $$ = new MethodCallExpr($1,*$3);delete $3; }
	| constant                     { $$ = $1; }
	| '(' expr ')'		       { $$ = $2; }
;
constant:INT_CONSTANT                { $$ = new NumExpr($1); }
	| CHAR_CONSTANT  	     { $$ = new CharExpr($1); }
	| bool_constant              { $$ = $1; }
;
bool_constant: KW_TRUE               { $$ = new BoolExpr(true); }
 	      | KW_FALSE             { $$ = new BoolExpr(false); }
;

%%
