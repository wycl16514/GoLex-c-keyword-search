%{
    /*
    C 语言语法解析,yyout.h 用于定义字符串标签值，search.h 定义关键字表的查询接口
    */
#include "yyout.h"
#include "search.h"
#include<string.h>
#include <stdio.h>
#include <stdarg.h>
void handle_comment();
void yyerror(char* fmt, ...);
int id_or_keyword(char* lex);
%}

let     [_a-zA-z]
alnum   [_a-zA-Z0-9]
h       [0-9a-fA-F]
o       [0-7]
d       [0-9]
suffix  [UulL]
white   [\x00-\s]
%%
"/*"        {handle_comment();}
\"(\\.|[^\"])*\"  {printf("this is a string: %s\n", yytext); /*return STRING*/;}
\"(\\.|[^\"])*[\r|\n]   yyerror("Adding missing \" to string constant\n");
{white}   {; /*忽略空格*/}
(\r|\n)*  {; /*忽略回车换行*/}

'.'|
'\\.'|
'\\{o}({o}{o}?)?'|
0{o}*{suffix}?|
0x{h}+{suffix}?|
[1-9]{d}*{suffix}?  {printf("find ICON: %s\n", yytext); /*return ICON;*/}
({d}+|{d}+\.{d}*|{d}*\.{d}+)([eE]\-?\+?{d}+)?[fF]?  {printf("find FCON: %s\n",yytext); /*return FCON;*/}

"("    {printf("it is LP\n"); /*return LP;*/}
")"    {printf("it is RP\n"); /*return RP;*/}
"{"    {printf("it is LC\n"); /*return LC;*/}
"}"    {printf("it is RC\n"); /*return RC;*/}
"["    {printf("it is LB\n"); /*return LB;*/}
"]"    {printf("it is RB\n"); /*return RB;*/}

"->"|
"."    {printf("struct operator:%s\n", yytext); /*return STRUCTOP;*/}

"++"|
"--"    {printf("INCOP: %s\n", yytext); /*return INCOP;*/}
"*"     {printf("START OP\n"); /*return START;*/}
[~!]    {printf("UNOP:%s\n", yytext); /*return UNOP;*/}
"*"     {printf("START OP\n"); /*return START;*/}
[/%]     {printf("DIVOP: %s\n", yytext); /*return DIVOP;*/}
"+"     {printf("PLUS\n"); /*return PLUS;*/}
"-"     {printf("MINUS\n"); /*return MINUS;*/}
<<|>>   {printf("SHIFTOP: %s\n",yytext); /*return SHIFTOP;*/}
[<>]=?  {printf("RELOP: %s\n", yytext); /*return RELOP;*/}
[!=]=   {printf("EQUOP: %s\n", yytext); /*return EQUOP;*/}
[*/%+-&|^]=|
(<<|>>)=  {printf("ASSIGN OP: %s\n", yytext); /*return ASSIGNOP;*/}
"="     {printf("EQUAL: %s\n", yytext); /*return EQUAL;*/}
"&"     {printf("AND: %s\n", yytext); /*return AND;*/}
"^"     {printf("XOR: %s\n", yytext); /*return XOR;*/}
"|"     {printf("OR: %s\n", yytext); /*return OR;*/}
"&&"    {printf("ANDAND: %s\n", yytext); /*return ANDAND;*/}
"||"    {printf("OROR: %s\n", yytext); /*return OROR;*/}
"?"     {printf("QUEST: %s\n", yytext); /*return QUEST;*/}
":"     {printf("COLON: %s\n", yytext); /*return COLON;*/}
","     {printf("COMMA: %s\n", yytext); /*return COMMA;*/}
";"     {printf("SEMI: %s\n", yytext); /*return SEMI;*/}
{let}{alnum}*  {return id_or_keyword(yytext);}
.        {yyerror("Illegal character<%s>\n", yytext);}
%%
//用于表示关键字表中的一个字段
typedef struct {
    char* name;
    int val;
} KWORD;

KWORD Ktab[] = {
    {"auto", CLASS},
    {"break", BREAK},
    {"case", CASE},
    {"char", TYPE},
    {"continue", CONTINUE},
    {"default", DEFAULT},
    {"do",  DO},
    {"double", TYPE},
    {"else", ELSE},
    {"extern", CLASS},
    {"float", TYPE},
    {"for", FOR},
    {"goto", GOTO},
    {"if", IF},
    {"int", TYPE},
    {"long", TYPE},
    {"register", CLASS},
    {"return", RETURN},
    {"short", TYPE},
    {"sizeof", SIZEOF},
    {"static", CLASS},
    {"struct", STRUCT},
    {"switch", SWITCH},
    {"typedef", CLASS},
    {"union", STRUCT},
    {"unsigned", TYPE},
    {"void", TYPE},
    {"while", WHILE}
};

int cmp(KWORD*a, KWORD* b) {
    return strcmp(a->name, b->name);
}

int id_or_keyword(char* lex) {
    KWORD* p;
    KWORD  dummy;
    dummy.name = lex;
    p = (KWORD*)bsearch(&dummy, Ktab, sizeof(Ktab)/sizeof(KWORD), sizeof(KWORD),cmp);
    if (p) {
        printf("find keyword: %s\n", yytext);
        return p->val;
    }

    printf("find variable :%s\n", yytext);
    return NAME;
}

void yyerror(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "ERROR on line %d, near <%s>\n", yylineno, yytext);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void handle_comment() {
    int i;
    while (i = ii_input()) {
        if (i < 0)
            ii_flushbuf();  //放弃当前识别的字符串
        else if (i == '*' && ii_lookahead(1) == '/') {
            //识别到注释末尾
            ii_input();
            printf("at the end of comment...\n");
            break;
        }
    }

    if (i == 0) {
        yyerror("End of file in comment\n");
    }
}

void main() {
    ii_newfile("/Users/my/Documents/CLex/input.txt");
    yylex();
}
