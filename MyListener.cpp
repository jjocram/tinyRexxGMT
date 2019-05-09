// Generated from tinyrexx.g4 by ANTLR 4.7
#include <iostream>
#include <typeinfo>
#include "MyListener.h"

using namespace std;

MyListener::MyListener(const std::set<std::string> &ids) {
  vars = ids;
}


void MyListener::enterProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
    // Dichiara le variabili usate in tutto il programma:w
    for (auto name : vars) {
        cout << string(indent, ' ') << "int " << name << " = 0;" << endl;
    }

}

void MyListener::exitProgram(tinyrexxParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::enterStatement(tinyrexxParser::StatementContext * ctx) {
	if (dynamic_cast<tinyrexxParser::If_stContext*>(ctx->parent) != nullptr)
		cout << "{" << endl;
}

void MyListener::exitStatement(tinyrexxParser::StatementContext *ctx) {
	if (dynamic_cast<tinyrexxParser::If_stContext*>(ctx->parent) != nullptr){
		cout << "}";
		if (ctx->getRuleIndex() == 0 && ctx == (dynamic_cast<tinyrexxParser::If_stContext*>(ctx->parent))->statement()[0])
			cout << "else {" << endl;
	}
}

void MyListener::enterAssign(tinyrexxParser::AssignContext * ctx) {
    string name = ctx->ID()->getText(); // che variabile stiamo assegnando?
    cout << string(indent, ' ') << name << " = " ; //scrive rientrato di n spazzi 'var =' 
}

void MyListener::exitAssign(tinyrexxParser::AssignContext * ctx) {
    cout << ";" << endl;
}

void MyListener::enterPrint(tinyrexxParser::PrintContext * ctx) {
    cout << string(indent, ' ') << "cout << " ;    
}

void MyListener::exitPrint(tinyrexxParser::PrintContext * ctx) {
    cout << " << endl;" << endl;
}


void MyListener::exitInput(tinyrexxParser::InputContext * ctx) {
    string name = ctx->ID()->getText();
    cout << string(indent, ' ') << "cin >> " << name << ";" << endl;
}


void MyListener::enterA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
        cout << ctx->ID()->getText();//scrivo l'ID
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
        cout << ctx->NUMBER()->getText();//scrivo il valore numerico semlplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
        cout << "-" ; //scrivo il carattere '-'
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da enterA_op
    } else {
        // caso parentesi
        cout << "(" ; //scrivo il carattere '('
    }
}

void MyListener::exitA_expr(tinyrexxParser::A_exprContext * ctx) {
    // controllo in quale caso sono
    if(ctx->ID() != NULL) {
        // caso ID semplice
    } else if(ctx->NUMBER() != NULL) {
        // caso valore numerico semplice
    } else if(ctx->MINUS() !=  NULL) {
        // caso operatore - unario
    } else if(ctx->a_op() != NULL) {
        // caso operatore binario: gestito da exitA_op
    } else {
        // caso parentesi
        cout << ")" ; //unica differenza de enterA_expr che chiude la parentesi aperta
    }
}


//in questo caso basta implementare solo l'exit 
void MyListener::exitA_op(tinyrexxParser::A_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->PLUS() != NULL) {
        cout << " + ";
    } else if(ctx->MINUS() != NULL) {
        cout << " - ";
    } else if(ctx->MUL() != NULL) {
        cout << " * ";
    } else if(ctx->DIV() != NULL) {
        cout << " / ";
    }
}

void MyListener::exitR_op(tinyrexxParser::R_opContext * ctx) {
    // controllo operatore aritmetico
    if(ctx->EQUAL() != NULL) {
        cout << " == ";
    } else if(ctx->LT() != NULL) {
        cout << " < ";
    } else if(ctx->LEQ() != NULL) {
        cout << " <= ";
    } else if(ctx->GT() != NULL) {
        cout << " > ";
    } else if(ctx->GEQ() != NULL) {
        cout << " >= ";
    }
}


void MyListener::enterW_loop(tinyrexxParser::W_loopContext * ctx){
    cout << string(indent, ' ') << "while";
    indent += 4;
}


void MyListener::exitW_loop(tinyrexxParser::W_loopContext * ctx){
    indent -= 4;
    cout << string(indent, ' ') << "}" << endl;
}


void MyListener::enterTest(tinyrexxParser::TestContext * ctx){
    cout << "(";
}

void MyListener::exitTest(tinyrexxParser::TestContext * ctx){
    cout << ")" << endl;
}


void MyListener::enterTerminate(tinyrexxParser::TerminateContext * ctx){
	cout << string(indent, ' ') << "return ";
}

void MyListener::exitTerminate(tinyrexxParser::TerminateContext * ctx){
	cout << ";" << endl;
}

void MyListener::enterIf_st(tinyrexxParser::If_stContext * ctx){
	cout << string(indent, ' ') << "if";
}

void MyListener::exitIf_st(tinyrexxParser::If_stContext * ctx){
}

void MyListener::enterDo_loop(tinyrexxParser::Do_loopContext * ctx){
}

void MyListener::exitDo_loop(tinyrexxParser::Do_loopContext * ctx){

}

void MyListener::exitB_op(tinyrexxParser::B_opContext * ctx){
	if(ctx->AND() != NULL) {
        	cout << " && ";
    	} else if(ctx->OR() != NULL) {
        	cout << " || ";
    	}
}
