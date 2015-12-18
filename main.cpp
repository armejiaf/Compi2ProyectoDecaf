#include <cstdio>
#include <fstream>
#include <iostream>
#include "ast.h"
#include "tokens.h"

using namespace std;
extern Statement *input;

int main()
{
    yyparse();  
    try{
	string lbl1 ,lbl2;
    	//input->execute();
	cout << ".data" << endl
	     << "newLine: .asciiz \"\\n\"" << endl;
	string code = input->generateCode(lbl1,lbl2);
        cout <<".text\n"<< code << endl;  
    }catch (exception& e){
        cout<<e.what()<<"\n";
    }
}
