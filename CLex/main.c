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








#ifdef __NEVER__
/*------------------------------------------------
DFA (start state is 0) is :
 *
* State 0 [nonaccepting]

 * goto 1 on \00\01\02\03\04\05\06\07\b\t
 * goto 38 on \n
 * goto 1 on \0b\f
 * goto 49 on \r
 * goto 1 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f
 * goto 2 on !
 * goto 3 on "
 * goto 40 on #$
 * goto 4 on %
 * goto 5 on &
 * goto 50 on \'
 * goto 6 on (
 * goto 7 on )
 * goto 8 on *
 * goto 9 on +
 * goto 10 on ,
 * goto 11 on -
 * goto 12 on .
 * goto 41 on /
 * goto 13 on 0
 * goto 43 on 123456789
 * goto 14 on :
 * goto 15 on ;
 * goto 16 on <
 * goto 17 on =
 * goto 44 on >
 * goto 18 on ?
 * goto 40 on @
 * goto 19 on ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * goto 20 on [
 * goto 19 on \\
 * goto 21 on ]
 * goto 22 on ^
 * goto 19 on _`abcdefghijklmnopqr
 * goto 55 on s
 * goto 19 on tuvwxyz
 * goto 23 on {
 * goto 24 on |
 * goto 25 on }
 * goto 39 on ~
 * goto 40 on 
* State 1 [accepting, line 0, <   {; /*忽略空格*/}>]

* State 2 [accepting, line 0, <    {printf("UNOP:%s\n", yytext); /*return UNOP;*/}>]

 * goto 27 on =
* State 3 [accepting, line 0, <        {yyerror("Illegal character<%s>\n", yytext);}>]

 * goto 37 on \00\01\02\03\04\05\06\07\b\t
 * goto 28 on \n
 * goto 37 on \0b\f
 * goto 28 on \r
 * goto 37 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f !
 * goto 29 on "
 * goto 37 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *                [
 * goto 48 on \\
 * goto 37 on ]_`abcdefghijklm
 * goto 45 on n
 * goto 37 on opq
 * goto 45 on r
 * goto 37 on stuvwxyz{
 * goto 45 on |
 * goto 37 on }~
* State 4 [accepting, line 0, <     {printf("DIVOP: %s\n", yytext); /*return DIVOP;*/}>]

 * goto 30 on =
* State 5 [accepting, line 0, <     {printf("AND: %s\n", yytext); /*return AND;*/}>]

 * goto 31 on &
* State 6 [accepting, line 0, <    {printf("it is LP\n"); /*return LP;*/}>]

* State 7 [accepting, line 0, <    {printf("it is RP\n"); /*return RP;*/}>]

* State 8 [accepting, line 0, <     {printf("START OP\n"); /*return START;*/}>]

 * goto 30 on =
* State 9 [accepting, line 0, <     {printf("PLUS\n"); /*return PLUS;*/}>]

 * goto 32 on +
 * goto 30 on =
* State 10 [accepting, line 0, <     {printf("COMMA: %s\n", yytext); /*return COMMA;*/}>]

* State 11 [accepting, line 0, <     {printf("MINUS\n"); /*return MINUS;*/}>]

 * goto 32 on -
 * goto 42 on >
* State 12 [accepting, line 0, <    {printf("struct operator:%s\n", yytext); /*return STRUCTOP;*/}>]

 * goto 33 on 0123456789
* State 13 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

 * goto 33 on .
 * goto 51 on 01234567
 * goto 47 on 89
 * goto 60 on E
 * goto 53 on F
 * goto 56 on LU
 * goto 60 on e
 * goto 53 on f
 * goto 56 on lu
 * goto 62 on x
* State 14 [accepting, line 0, <     {printf("COLON: %s\n", yytext); /*return COLON;*/}>]

* State 15 [accepting, line 0, <     {printf("SEMI: %s\n", yytext); /*return SEMI;*/}>]

* State 16 [accepting, line 0, <  {printf("RELOP: %s\n", yytext); /*return RELOP;*/}>]

 * goto 35 on <
 * goto 52 on =
* State 17 [accepting, line 0, <     {printf("EQUAL: %s\n", yytext); /*return EQUAL;*/}>]

 * goto 27 on =
* State 18 [accepting, line 0, <     {printf("QUEST: %s\n", yytext); /*return QUEST;*/}>]

* State 19 [accepting, line 0, <  {return id_or_keyword(yytext);}>]

 * goto 19 on 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrst
 *                uvwxyz
* State 20 [accepting, line 0, <    {printf("it is LB\n"); /*return LB;*/}>]

 * goto 19 on 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrst
 *                uvwxyz
* State 21 [accepting, line 0, <    {printf("it is RB\n"); /*return RB;*/}>]

 * goto 19 on 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrst
 *                uvwxyz
* State 22 [accepting, line 0, <     {printf("XOR: %s\n", yytext); /*return XOR;*/}>]

 * goto 19 on 0123456789
 * goto 30 on =
 * goto 19 on ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz
* State 23 [accepting, line 0, <    {printf("it is LC\n"); /*return LC;*/}>]

* State 24 [accepting, line 0, <     {printf("OR: %s\n", yytext); /*return OR;*/}>]

 * goto 30 on =
 * goto 36 on |
* State 25 [accepting, line 0, <    {printf("it is RC\n"); /*return RC;*/}>]

* State 26 [accepting, line 0, <  {; /*忽略回车换行*/}>]

 * goto 63 on \n
 * goto 64 on \r
* State 27 [accepting, line 0, <   {printf("EQUOP: %s\n", yytext); /*return EQUOP;*/}>]

* State 28 [accepting, line 0, <   yyerror("Adding missing \" to string constant\n");>]

* State 29 [accepting, line 0, <  {printf("this is a string: %s\n", yytext); /*return STRING*/;}>]

* State 30 [accepting, line 0, <  {printf("ASSIGN OP: %s\n", yytext); /*return ASSIGNOP;*/}>]

* State 31 [accepting, line 0, <    {printf("ANDAND: %s\n", yytext); /*return ANDAND;*/}>]

* State 32 [accepting, line 0, <    {printf("INCOP: %s\n", yytext); /*return INCOP;*/}>]

* State 33 [accepting, line 0, <  {printf("find FCON: %s\n",yytext); /*return FCON;*/}>]

 * goto 33 on 0123456789
 * goto 60 on E
 * goto 53 on F
 * goto 60 on e
 * goto 53 on f
* State 34 [accepting, line 0, <        {handle_comment();}>]

* State 35 [accepting, line 0, <   {printf("SHIFTOP: %s\n",yytext); /*return SHIFTOP;*/}>]

 * goto 30 on =
* State 36 [accepting, line 0, <    {printf("OROR: %s\n", yytext); /*return OROR;*/}>]

* State 37 [nonaccepting]

 * goto 37 on \00\01\02\03\04\05\06\07\b\t
 * goto 28 on \n
 * goto 37 on \0b\f
 * goto 28 on \r
 * goto 37 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f !
 * goto 29 on "
 * goto 37 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *                [
 * goto 48 on \\
 * goto 37 on ]_`abcdefghijklm
 * goto 45 on n
 * goto 37 on opq
 * goto 45 on r
 * goto 37 on stuvwxyz{
 * goto 45 on |
 * goto 37 on }~
* State 38 [accepting, line 0, <   {; /*忽略空格*/}>]

 * goto 26 on n
* State 39 [accepting, line 0, <    {printf("UNOP:%s\n", yytext); /*return UNOP;*/}>]

* State 40 [accepting, line 0, <        {yyerror("Illegal character<%s>\n", yytext);}>]

* State 41 [accepting, line 0, <     {printf("DIVOP: %s\n", yytext); /*return DIVOP;*/}>]

 * goto 34 on *
 * goto 30 on =
* State 42 [accepting, line 0, <    {printf("struct operator:%s\n", yytext); /*return STRUCTOP;*/}>]

* State 43 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

 * goto 33 on .
 * goto 43 on 0123456789
 * goto 60 on E
 * goto 53 on F
 * goto 56 on LU
 * goto 60 on e
 * goto 53 on f
 * goto 56 on lu
* State 44 [accepting, line 0, <  {printf("RELOP: %s\n", yytext); /*return RELOP;*/}>]

 * goto 52 on =
 * goto 35 on >
* State 45 [accepting, line 0, <   yyerror("Adding missing \" to string constant\n");>]

 * goto 37 on \00\01\02\03\04\05\06\07\b\t
 * goto 28 on \n
 * goto 37 on \0b\f
 * goto 28 on \r
 * goto 37 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f !
 * goto 29 on "
 * goto 37 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *                [
 * goto 48 on \\
 * goto 37 on ]_`abcdefghijklm
 * goto 45 on n
 * goto 37 on opq
 * goto 45 on r
 * goto 37 on stuvwxyz{
 * goto 45 on |
 * goto 37 on }~
* State 46 [accepting, line 0, <  {printf("this is a string: %s\n", yytext); /*return STRING*/;}>]

 * goto 37 on \00\01\02\03\04\05\06\07\b\t
 * goto 28 on \n
 * goto 37 on \0b\f
 * goto 28 on \r
 * goto 37 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f !
 * goto 29 on "
 * goto 37 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *                [
 * goto 48 on \\
 * goto 37 on ]_`abcdefghijklm
 * goto 45 on n
 * goto 37 on opq
 * goto 45 on r
 * goto 37 on stuvwxyz{
 * goto 45 on |
 * goto 37 on }~
* State 47 [accepting, line 0, <  {printf("find FCON: %s\n",yytext); /*return FCON;*/}>]

 * goto 33 on .
 * goto 47 on 0123456789
 * goto 60 on E
 * goto 53 on F
 * goto 60 on e
 * goto 53 on f
* State 48 [nonaccepting]

 * goto 37 on \00\01\02\03\04\05\06\07\b\t
 * goto 28 on \n
 * goto 37 on \0b\f
 * goto 28 on \r
 * goto 37 on \0e\0f\10\11\12\13\14\15\16\17\18\19\1a\1b\1c\1d\1e\1f !
 * goto 46 on "
 * goto 37 on #$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *                [
 * goto 48 on \\
 * goto 37 on ]^_`abcdefghijklm
 * goto 45 on n
 * goto 37 on opq
 * goto 45 on r
 * goto 37 on stuvwxyz{
 * goto 45 on |
 * goto 37 on }~
* State 49 [accepting, line 0, <   {; /*忽略空格*/}>]

 * goto 26 on r
* State 50 [accepting, line 0, <        {yyerror("Illegal character<%s>\n", yytext);}>]

 * goto 54 on \00\01\02\03\04\05\06\07\b\t\0b\f\0e\0f\10\11\12\13\14\15
 *                \16\17\18\19\1a\1b\1c\1d\1e\1f !"#$%&\'()*+,-./0123456789
 *                :;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[
 * goto 58 on \\
 * goto 54 on ]^_`abcdefghijklmnopqrstuvwxyz{|}~
* State 51 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

 * goto 33 on .
 * goto 51 on 01234567
 * goto 47 on 89
 * goto 60 on E
 * goto 53 on F
 * goto 56 on LU
 * goto 60 on e
 * goto 53 on f
 * goto 56 on lu
* State 52 [accepting, line 0, <  {printf("RELOP: %s\n", yytext); /*return RELOP;*/}>]

* State 53 [accepting, line 0, <  {printf("find FCON: %s\n",yytext); /*return FCON;*/}>]

* State 54 [nonaccepting]

 * goto 56 on \'
* State 55 [accepting, line 0, <   {; /*忽略空格*/}>]

 * goto 19 on 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrst
 *                uvwxyz
* State 56 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

* State 57 [accepting, line 0, <  {printf("find FCON: %s\n",yytext); /*return FCON;*/}>]

 * goto 57 on 0123456789
 * goto 53 on Ff
* State 58 [nonaccepting]

 * goto 54 on \00\01\02\03\04\05\06\07\b\t\0b\f\0e\0f\10\11\12\13\14\15
 *                \16\17\18\19\1a\1b\1c\1d\1e\1f !"#$%&
 * goto 59 on \'
 * goto 54 on ()*+,-./
 * goto 65 on 01234567
 * goto 54 on 89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmno
 *                pqrstuvwxyz{|}~
* State 59 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

 * goto 56 on \'
* State 60 [nonaccepting]

 * goto 66 on +
 * goto 67 on -
 * goto 57 on 0123456789
* State 61 [accepting, line 0, <  {printf("find ICON: %s\n", yytext); /*return ICON;*/}>]

 * goto 61 on 0123456789ABCDEF
 * goto 56 on LU
 * goto 61 on abcdef
 * goto 56 on lu
* State 62 [nonaccepting]

 * goto 61 on 0123456789ABCDEFabcdef
* State 63 [nonaccepting]

 * goto 26 on n
* State 64 [nonaccepting]

 * goto 26 on r
* State 65 [nonaccepting]

 * goto 56 on \'
 * goto 68 on 01234567
* State 66 [nonaccepting]

 * goto 57 on 0123456789
* State 67 [nonaccepting]

 * goto 66 on +
 * goto 57 on 0123456789
* State 68 [nonaccepting]

 * goto 56 on \'
 * goto 54 on 01234567
*/

#endif
/*
YY_TTYPE 是宏定义，用于 DFA 状态转换表Yy_nxt[],它将会在下面进行定义。 宏定义YYF表示错误的状态跳转，当状态机跳转到错误状态时
模板代码会自动进行相应处理.DFA 状态机的起始状态为 0，同时宏定义 YYPRIVATE 也会在本模板文件中定义
*/
#ifndef YYPRIVATE
#define YYPRIVATE  static
#endif
#include <stdio.h>
#include <errno.h>
#include"debug.h"
#include"l.h"
#ifndef YYPRIVATE
#define YYPRIVATE static
#endif
#ifdef YYDEBUG
int yydebug = 0;
#define YY_D(x) if(yydebug){x;}else
#else
#define YY_D(x)
#endif
typedef unsigned char YY_TTYPE;
#define YYF  ((YY_TTYPE)(-1))
unsigned char* ii_text();

/*--------------------------------------
* The Yy_cmap[] and Yy_rmap arrays are used as follows:
*
*  next_state= Yydtran[ Yy_rmap[current_state] ][ Yy_cmap[input_char] ];
*
* Character positions in the Yy_cmap array are:
*
*    ^@  ^A  ^B  ^C  ^D  ^E  ^F  ^G  ^H  ^I  ^J  ^K  ^L  ^M  ^N  ^O
*    ^P  ^Q  ^R  ^S  ^T  ^U  ^V  ^W  ^X  ^Y  ^Z  ^[  ^\  ^]  ^^  ^_
*         !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
*     0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
*     @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
*     P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
*     `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
*     p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   DEL
*/

static unsigned char Yy_cmap[128]=
        {
                0,0,0,0,0,0,0,0,0,0,
                1,0,0,2,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,3,4,5,5,6,7,8,
                9,10,11,12,13,14,15,16,17,18,
                18,18,18,18,18,18,19,19,20,21,
                22,23,24,25,5,26,26,26,26,27,
                28,29,29,29,29,29,30,29,29,29,
                29,29,29,29,29,30,29,29,29,29,
                29,31,32,33,34,29,35,26,26,26,
                26,27,28,29,29,29,29,29,30,29,
                36,29,29,29,37,38,29,30,29,29,
                39,29,29,40,41,42,43,5
        };

static  unsigned char  Yy_rmap[69]=
        {
                0,1,2,3,4,5,1,1,4,6,
                1,7,8,9,1,1,10,2,1,11,
                11,11,12,1,13,1,14,1,1,1,
                1,1,1,15,1,4,1,3,16,1,
                1,17,1,18,19,3,3,20,21,22,
                23,24,1,1,25,11,1,26,27,25,
                28,29,30,16,22,31,32,33,34
        };

static unsigned char Yy_nxt[35][44]=
        {
/*  0 */ {1, 38, 49, 2, 3, 40, 4, 5, 50, 6,
                 7, 8, 9, 10, 11, 12, 41, 13, 43, 43,
                 14, 15, 16, 17, 44, 18, 19, 19, 19, 19,
                 19, 20, 19, 21, 22, 19, 19, 19, 55, 19,
                 23, 24, 25, 39
         },
/*  1 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  2 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 27, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  3 */ {37, 28, 28, 37, 29, 37, 37, 37, 37, 37,
                 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                 37, 37, 48, 37, -1, 37, 45, 45, 37, 37,
                 37, 45, 37, 37
         },
/*  4 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 30, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  5 */ {-1, -1, -1, -1, -1, -1, -1, 31, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  6 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, 32, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 30, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  7 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, 32, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, 42, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  8 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 33, 33, 33,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  9 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, 33, -1, 51, 51, 47,
                 -1, -1, -1, -1, -1, -1, -1, 60, 53, -1,
                 56, -1, -1, -1, -1, -1, -1, -1, -1, 62,
                 -1, -1, -1, -1
         },
/*  10 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, 35, 52, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  11 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 19, 19, 19,
                 -1, -1, -1, -1, -1, -1, 19, 19, 19, 19,
                 19, -1, -1, -1, -1, -1, 19, 19, 19, 19,
                 -1, -1, -1, -1
         },
/*  12 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 19, 19, 19,
                 -1, -1, -1, 30, -1, -1, 19, 19, 19, 19,
                 19, -1, -1, -1, -1, -1, 19, 19, 19, 19,
                 -1, -1, -1, -1
         },
/*  13 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 30, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, 36, -1, -1
         },
/*  14 */ {-1, 63, 64, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  15 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 33, 33, 33,
                 -1, -1, -1, -1, -1, -1, -1, 60, 53, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  16 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, 26, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  17 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, 34, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 30, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  18 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, 33, -1, 43, 43, 43,
                 -1, -1, -1, -1, -1, -1, -1, 60, 53, -1,
                 56, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  19 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, 52, 35, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  20 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, 33, -1, 47, 47, 47,
                 -1, -1, -1, -1, -1, -1, -1, 60, 53, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  21 */ {37, 28, 28, 37, 46, 37, 37, 37, 37, 37,
                 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                 37, 37, 48, 37, 37, 37, 45, 45, 37, 37,
                 37, 45, 37, 37
         },
/*  22 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 26, -1, -1,
                 -1, -1, -1, -1
         },
/*  23 */ {54, -1, -1, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 58, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 54, 54
         },
/*  24 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, 33, -1, 51, 51, 47,
                 -1, -1, -1, -1, -1, -1, -1, 60, 53, -1,
                 56, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  25 */ {-1, -1, -1, -1, -1, -1, -1, -1, 56, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  26 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 57, 57, 57,
                 -1, -1, -1, -1, -1, -1, -1, -1, 53, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  27 */ {54, -1, -1, 54, 54, 54, 54, 54, 59, 54,
                 54, 54, 54, 54, 54, 54, 54, 65, 65, 54,
                 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 54, 54, 54, 54, 54, 54, 54, 54,
                 54, 54, 54, 54
         },
/*  28 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, 66, -1, 67, -1, -1, 57, 57, 57,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  29 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 61, 61, 61,
                 -1, -1, -1, -1, -1, -1, 61, 61, 61, -1,
                 56, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  30 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 61, 61, 61,
                 -1, -1, -1, -1, -1, -1, 61, 61, 61, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  31 */ {-1, -1, -1, -1, -1, -1, -1, -1, 56, -1,
                 -1, -1, -1, -1, -1, -1, -1, 68, 68, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  32 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, 57, 57, 57,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  33 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, 66, -1, -1, -1, -1, 57, 57, 57,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         },
/*  34 */ {-1, -1, -1, -1, -1, -1, -1, -1, 56, -1,
                 -1, -1, -1, -1, -1, -1, -1, 54, 54, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1
         }
        };

/*--------------------------------------
* yy_next(state,c) is given the current state number and input
* character and evaluates to the next state.
*/

#define yy_next(state, c) (Yy_nxt[Yy_rmap[state]][Yy_cmap[c]])

/*--------------------------------------
 * 输出基于 DFA 的跳转表,首先我们将生成一个 Yyaccept数组，如果 Yyaccept[i]取值为 0，
	那表示节点 i 不是接收态，如果它的值不是 0，那么节点是接受态，此时他的值对应以下几种情况：
	1 表示节点对应的正则表达式需要开头匹配，也就是正则表达式以符号^开始，2 表示正则表达式需要
	末尾匹配，也就是表达式以符号$结尾，3 表示同时开头和结尾匹配，4 表示不需要开头或结尾匹配
 */

YYPRIVATE YY_TTYPE Yyaccept[]=
        {
                0  ,  /*State 0  */
                4  ,  /*State 1  */
                4  ,  /*State 2  */
                4  ,  /*State 3  */
                4  ,  /*State 4  */
                4  ,  /*State 5  */
                4  ,  /*State 6  */
                4  ,  /*State 7  */
                4  ,  /*State 8  */
                4  ,  /*State 9  */
                4  ,  /*State 10 */
                4  ,  /*State 11 */
                4  ,  /*State 12 */
                4  ,  /*State 13 */
                4  ,  /*State 14 */
                4  ,  /*State 15 */
                4  ,  /*State 16 */
                4  ,  /*State 17 */
                4  ,  /*State 18 */
                4  ,  /*State 19 */
                4  ,  /*State 20 */
                4  ,  /*State 21 */
                4  ,  /*State 22 */
                4  ,  /*State 23 */
                4  ,  /*State 24 */
                4  ,  /*State 25 */
                4  ,  /*State 26 */
                4  ,  /*State 27 */
                4  ,  /*State 28 */
                4  ,  /*State 29 */
                4  ,  /*State 30 */
                4  ,  /*State 31 */
                4  ,  /*State 32 */
                4  ,  /*State 33 */
                4  ,  /*State 34 */
                4  ,  /*State 35 */
                4  ,  /*State 36 */
                0  ,  /*State 37 */
                4  ,  /*State 38 */
                4  ,  /*State 39 */
                4  ,  /*State 40 */
                4  ,  /*State 41 */
                4  ,  /*State 42 */
                4  ,  /*State 43 */
                4  ,  /*State 44 */
                4  ,  /*State 45 */
                4  ,  /*State 46 */
                4  ,  /*State 47 */
                0  ,  /*State 48 */
                4  ,  /*State 49 */
                4  ,  /*State 50 */
                4  ,  /*State 51 */
                4  ,  /*State 52 */
                4  ,  /*State 53 */
                0  ,  /*State 54 */
                4  ,  /*State 55 */
                4  ,  /*State 56 */
                4  ,  /*State 57 */
                0  ,  /*State 58 */
                4  ,  /*State 59 */
                0  ,  /*State 60 */
                4  ,  /*State 61 */
                0  ,  /*State 62 */
                0  ,  /*State 63 */
                0  ,  /*State 64 */
                0  ,  /*State 65 */
                0  ,  /*State 66 */
                0  ,  /*State 67 */
                0     /*State 68 */
        };

/*--------------------------------------
*  语法解析器使用的全局变量放到这里，在词法解析器阶段，这里可以忽略
*/
char*  yytext;  /*指向当前正在读取的字符串*/
int    yyleng;  /*当前读取字符串的长度*/
int    yylineno;  /*当前读取字符串所在的行*/
FILE*  yyout = NULL;  /*默认情况下输入从控制台读取*/
#define output(c)  putc(c, yyout)
#define ECHO       fprintf(yyout, "%s", yytext)
#ifndef YYERROR
#define YYERROR  printf
#endif
#define  yymore() yymoreflg = 1
#define unput(c)   (ii_unput(c), --yyleng)
#define yyless(n) (ii_unterm(), yyleng -= ii_pushback(n) ? n : yyleng), ii_term() )
int input(void) {
    int c;
    if ((c = ii_input()) && (c != -1)) {
        yytext = (char*) ii_text();
        yylineno = ii_lineno();
        ++yyleng;
    }
    return c;
}
/*--------------------------------*/
void yy_init_lex() {
    //做一些初始化工作，默认什么都不做
}
int yywrap() {
    //默认不要打开新文件
    if (ii_console()) {
        //如果输入来自控制台，那么程序不要返回
        ii_newfile(NULL);
        return 0;
    }
    return 1;
}
int yylex() {
    int  yymoreflg;
    static  int yystate = -1;
    int  yylastaccept;
    int  yyprev;
    int yynstate;
    int yylook;
    int  yyanchor;
    if (yystate == -1) {
        //函数第一次执行时进入这里进行初始化
        yy_init_lex();
        ii_advance();
        ii_pushback(1);
    }
    yystate = 0;
    yylastaccept = 0;
    yymoreflg = 0;
    ii_unterm();
    ii_mark_start();
    while(1) {
        /*
        首先检测当前读入的文件是否已经到了末尾。如果是，并且当前有没有处理的接收状态,yylastaccept 的值就不是 0
        ，那么此时就先执行对应接收状态的代码，如果在到了文件末尾还没有遇到过接收状态，那么尝试打开新的输入文件，
        如果新文件打开失败则返回
        */
        while(1) {
            if((yylook = ii_look(1)) != EOF) {
                yynstate = yy_next(yystate, yylook);
                break;
            } else {
                if (yylastaccept) {
                    yynstate = YYF;
                    break;
                } else if (yywrap()) {
                    //yywrap 打开新的输入文件,进入到这里说明没有新的文件要打开
                    yytext = "";
                    yyleng = 0;
                    return 0;
                } else {
                    //这里说明打开了新的输入文件
                    ii_advance(); //读取数据到缓冲区
                    ii_pushback(1);
                }
            }
        }
        if (yynstate != YYF) {
            YY_D(printf("    Transition from state %d", yystate));
            YY_D(printf(" to state %d on <%c>\n", yystate, yylook));
            if (ii_advance() < 0) {
                YYERROR("Line %d, lexeme too long. Discarding extra characters.\n", ii_lineno());
                ii_flush(1);
            }
            if (yyanchor = Yyaccept[yynstate]) {
                //当前状态是接收状态
                yyprev = yystate;
                yylastaccept = yynstate;
                ii_mark_end();
            }
            yystate = yynstate;
        } else {
            //在这里意味着当前状态机接收字符后进入错误状态，于是我们处理之前进入的接收状态
            if (!yylastaccept) {
                //此前没有进入过接收状态
                YYERROR("Ignoring bad input\n");
                ii_advance();
            } else {
                //处理之前进入的接收状态
                ii_to_mark();
                if (yyanchor & 2) {
                    //末尾匹配，先将当前回车字符放回缓冲区
                    ii_pushback(1);
                }
                if (yyanchor & 1) {
                    //开头匹配，忽略掉当前输入字符串开头的回车字符
                    ii_move_start();
                }
                ii_term();  //将当前输入字符串的末尾添加\0 符号
                yytext = (char*)ii_text();
                yyleng = ii_length();
                yylineno = ii_lineno();
                YY_D(printf("Accepting state %d, ", yylastaccept));
                YY_D(printf("line %d: <%s>\n", yylineno, yytext));
                switch(yylastaccept) {
                    case 1:					/* State 1   */
                    {; /*忽略空格*/}
                        break;
                    case 2:					/* State 2   */
                    {printf("UNOP:%s\n", yytext); /*return UNOP;*/}
                        break;
                    case 3:					/* State 3   */
                    {yyerror("Illegal character<%s>\n", yytext);}
                        break;
                    case 4:					/* State 4   */
                    {printf("DIVOP: %s\n", yytext); /*return DIVOP;*/}
                        break;
                    case 5:					/* State 5   */
                    {printf("AND: %s\n", yytext); /*return AND;*/}
                        break;
                    case 6:					/* State 6   */
                    {printf("it is LP\n"); /*return LP;*/}
                        break;
                    case 7:					/* State 7   */
                    {printf("it is RP\n"); /*return RP;*/}
                        break;
                    case 8:					/* State 8   */
                    {printf("START OP\n"); /*return START;*/}
                        break;
                    case 9:					/* State 9   */
                    {printf("PLUS\n"); /*return PLUS;*/}
                        break;
                    case 10:					/* State 10  */
                    {printf("COMMA: %s\n", yytext); /*return COMMA;*/}
                        break;
                    case 11:					/* State 11  */
                    {printf("MINUS\n"); /*return MINUS;*/}
                        break;
                    case 12:					/* State 12  */
                    {printf("struct operator:%s\n", yytext); /*return STRUCTOP;*/}
                        break;
                    case 13:					/* State 13  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    case 14:					/* State 14  */
                    {printf("COLON: %s\n", yytext); /*return COLON;*/}
                        break;
                    case 15:					/* State 15  */
                    {printf("SEMI: %s\n", yytext); /*return SEMI;*/}
                        break;
                    case 16:					/* State 16  */
                    {printf("RELOP: %s\n", yytext); /*return RELOP;*/}
                        break;
                    case 17:					/* State 17  */
                    {printf("EQUAL: %s\n", yytext); /*return EQUAL;*/}
                        break;
                    case 18:					/* State 18  */
                    {printf("QUEST: %s\n", yytext); /*return QUEST;*/}
                        break;
                    case 19:					/* State 19  */
                    {return id_or_keyword(yytext);}
                        break;
                    case 20:					/* State 20  */
                    {printf("it is LB\n"); /*return LB;*/}
                        break;
                    case 21:					/* State 21  */
                    {printf("it is RB\n"); /*return RB;*/}
                        break;
                    case 22:					/* State 22  */
                    {printf("XOR: %s\n", yytext); /*return XOR;*/}
                        break;
                    case 23:					/* State 23  */
                    {printf("it is LC\n"); /*return LC;*/}
                        break;
                    case 24:					/* State 24  */
                    {printf("OR: %s\n", yytext); /*return OR;*/}
                        break;
                    case 25:					/* State 25  */
                    {printf("it is RC\n"); /*return RC;*/}
                        break;
                    case 26:					/* State 26  */
                    {; /*忽略回车换行*/}
                        break;
                    case 27:					/* State 27  */
                    {printf("EQUOP: %s\n", yytext); /*return EQUOP;*/}
                        break;
                    case 28:					/* State 28  */
                        yyerror("Adding missing \" to string constant\n");
                        break;
                    case 29:					/* State 29  */
                    {printf("this is a string: %s\n", yytext); /*return STRING*/;}
                        break;
                    case 30:					/* State 30  */
                    {printf("ASSIGN OP: %s\n", yytext); /*return ASSIGNOP;*/}
                        break;
                    case 31:					/* State 31  */
                    {printf("ANDAND: %s\n", yytext); /*return ANDAND;*/}
                        break;
                    case 32:					/* State 32  */
                    {printf("INCOP: %s\n", yytext); /*return INCOP;*/}
                        break;
                    case 33:					/* State 33  */
                    {printf("find FCON: %s\n",yytext); /*return FCON;*/}
                        break;
                    case 34:					/* State 34  */
                    {handle_comment();}
                        break;
                    case 35:					/* State 35  */
                    {printf("SHIFTOP: %s\n",yytext); /*return SHIFTOP;*/}
                        break;
                    case 36:					/* State 36  */
                    {printf("OROR: %s\n", yytext); /*return OROR;*/}
                        break;
                    case 38:					/* State 38  */
                    {; /*忽略空格*/}
                        break;
                    case 39:					/* State 39  */
                    {printf("UNOP:%s\n", yytext); /*return UNOP;*/}
                        break;
                    case 40:					/* State 40  */
                    {yyerror("Illegal character<%s>\n", yytext);}
                        break;
                    case 41:					/* State 41  */
                    {printf("DIVOP: %s\n", yytext); /*return DIVOP;*/}
                        break;
                    case 42:					/* State 42  */
                    {printf("struct operator:%s\n", yytext); /*return STRUCTOP;*/}
                        break;
                    case 43:					/* State 43  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    case 44:					/* State 44  */
                    {printf("RELOP: %s\n", yytext); /*return RELOP;*/}
                        break;
                    case 45:					/* State 45  */
                        yyerror("Adding missing \" to string constant\n");
                        break;
                    case 46:					/* State 46  */
                    {printf("this is a string: %s\n", yytext); /*return STRING*/;}
                        break;
                    case 47:					/* State 47  */
                    {printf("find FCON: %s\n",yytext); /*return FCON;*/}
                        break;
                    case 49:					/* State 49  */
                    {; /*忽略空格*/}
                        break;
                    case 50:					/* State 50  */
                    {yyerror("Illegal character<%s>\n", yytext);}
                        break;
                    case 51:					/* State 51  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    case 52:					/* State 52  */
                    {printf("RELOP: %s\n", yytext); /*return RELOP;*/}
                        break;
                    case 53:					/* State 53  */
                    {printf("find FCON: %s\n",yytext); /*return FCON;*/}
                        break;
                    case 55:					/* State 55  */
                    {; /*忽略空格*/}
                        break;
                    case 56:					/* State 56  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    case 57:					/* State 57  */
                    {printf("find FCON: %s\n",yytext); /*return FCON;*/}
                        break;
                    case 59:					/* State 59  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    case 61:					/* State 61  */
                    {printf("find ICON: %s\n", yytext); /*return ICON;*/}
                        break;
                    default:
                        YYERROR("INTERNAL ERROR, yylex: Unkonw accept state %d.\n", yylastaccept);
                        break;
                }
            }
            ii_unterm();
            yylastaccept = 0;
            if (!yymoreflg) {
                yystate = 0;
                ii_mark_start();
            } else {
                yystate = yyprev; //记录上一次遇到的状态
                yymoreflg = 0;
            }
        }
    }
    return -1;
}
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
