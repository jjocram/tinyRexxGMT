grammar tinyrexx;

program   : statement+;
          
statement : assign | print | input | w_loop | terminate | if_st | do_loop;

assign    : ID '=' a_expr ;
print     : 'say' a_expr ;
input     : 'pull' ID ;
test	  : '(' test ')' | test b_op test | a_expr | NOT test | test r_op test;
w_loop    : 'do' 'while' test statement+ 'end' ;
do_loop	  : 'do' assign 'to' a_expr statement+ 'end';
if_st	  : 'if' test 'then' 'do' statement+ 'end' 'else' 'do' statement+ 'end' | 'if' test 'then' 'do' statement+ 'end';
a_expr    : ID | NUMBER | '(' a_expr ')' | a_expr a_op a_expr | MINUS a_expr ;
a_op      : MINUS | PLUS | MUL | DIV ;
r_op      : EQUAL | LT | LEQ | GT | GEQ ;
b_op	  : AND | OR;
terminate : 'exit' a_expr;

MINUS     : '-' ;
PLUS      : '+' ;
MUL       : '*' ;
DIV       : '/' ;
EQUAL     : '==' ;
LT        : '<' ;
LEQ       : '<=' ;
GT        : '>' ;
GEQ       : '>=' ;
AND	  : '&';
OR	  : '|';
NOT	  : '\\'; //sarebbe il \ ovvero il diverso
ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
ErrorChar : . ;

//test      : '(' test ')' | test b_op test | b_expr;
//b_expr  : '(' b_expr ')' | b_expr b_op b_expr | a_expr | NOT b_expr; // ridondante , a_expr r_op a_expr
