%option noyywrap

%{
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include "ast.h"
#include "tokens.h"

int line = 1;

%}

DIGIT [0-9]
LETTER [a-zA-Z]
HEX [0-9a-fA-F]

%%
"=" { return '='; }
"!" { return '!'; }
"+" { return '+'; }
"-" { return '-'; }
"*" { return '*'; }
"/" { return '/'; }
"(" { return '('; }
")" { return ')'; }
"{" { return '{'; }
"}" { return '}'; }
"[" { return '['; }
"]" { return ']'; }
";" { return ';'; }
"." { return '.'; }
"," { return ','; }
"%" { return '%'; }
"||" { return OP_OR; }
"&&" { return OP_AND; }
">>" { return OP_SHIFT_RIGHT; }
"<<" { return OP_SHIFT_LEFT; }
"rot" {return OP_ROT; }
"==" { return OP_EQ; }
"<" { return OP_LT; }
">" { return OP_GT; }
"<=" { return OP_LTE; }
">=" { return OP_GTE; }
"!=" { return OP_NE; }
"bool" { return KW_BOOL; }
"break" { return KW_BREAK; }
"print" { return KW_PRINT; }
"read" { return KW_READ; }
"continue" { return KW_CONTINUE; }
"class" { return KW_CLASS; }
"else" { return KW_ELSE; }
"extends" { return KW_EXTENDS; }
"false" { return KW_FALSE; }
"for" { return KW_FOR; }
"if" { return KW_IF; }
"int" { return KW_INT; }
"new" { return KW_NEW; }
"null" { return KW_NULL; }
"return" { return KW_RETURN; }
"true" { return KW_TRUE; }
"void" { return KW_VOID; }
"while" { return KW_WHILE; }
"'"([ -~]|\\.)"'" {yytext[yyleng-1] = '\0'; yylval.char_t = yytext[1];return CHAR_CONSTANT; }
\"(\\.|[^"])*\" { yytext[yyleng-1] = '\0'; yylval.id_t = strdup(&yytext[1]); return STRING_CONSTANT; }
(_|{LETTER})(_|{LETTER}|{DIGIT})* { yylval.id_t = strdup(yytext); return ID; }
0x{HEX}+ {
			stringstream ss;
			ss << hex << yytext;   
		        ss >> yylval.num_t;
			return INT_CONSTANT;
	   }
{DIGIT}+ { yylval.num_t = atoi(yytext); return INT_CONSTANT; }
[ \t] 
\n  { line++; }
"//"[^\n]*
.   {  printf("Line %d: Invalid symbol '%c'\n", line, yytext[0]); }
%%
