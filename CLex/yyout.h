//
// Created by MAC on 2023/11/30.
//

#ifndef UNTITLED_YYOUT_H
#define UNTITLED_YYOUT_H

/*         token                   value                    lexeme          */
#define    _EOI                     0                        /*输入结束标志*/
#define    NAME                     1                        /*变量名 int a;*/
#define    STRING                   2                        /*字符串常量 char* c="abc";*/
#define    ICON                     3                        /*整型常量或字符串常量 1,2,3 'a', 'b', 'c';*/
#define    FCON                     4                        /*浮点数常量*/
#define    PLUS                     5                        /* + */
#define    MINUS                    6                        /* - */
#define    START                    7                        /* * */
#define    AND                      8                        /* & */
#define    QUEST                    9                        /* ? */
#define    COLON                    10                       /* ? */
#define    ANDAND                   11                       /* && */
#define    OROR                     12                       /* ||  */
#define    RELOP                    13                       /* > >= < <= */
#define    EQUOP                    14                       /* == != */
#define    DIVOP                    15                       /* / % */
#define    OR                       16                       /* |  */
#define    XOR                      17                       /* ^ */
#define    SHIFTOP                  18                       /* >> << */
#define    INCOP                    19                       /* ++ -- */
#define    UNOP                     20                       /* ! ~  */
#define    STRUCTOP                 21                       /* . -> */
#define    TYPE                     22                       /* int float char long ...*/
#define    CLASS                    23                       /* extern static typedef ...*/
#define    STRUCT                   24                       /* struct union */
#define    RETURN                   25                       /* return */
#define    GOTO                     26                       /* goto */
#define    IF                       27                       /* if */
#define    ELSE                     28                       /* else */
#define    SWITCH                   29                       /* switch */
#define    BREAK                    30                       /* break */
#define    CONTINUE                 31                       /* continue */
#define    WHILE                    32                       /* while */
#define    DO                       33                       /* do */
#define    FOR                      34                       /* for */
#define    DEFAULT                  35                       /* default */
#define    CASE                     36                       /* case */
#define    SIZEOF                   37                      /* sizeof */
#define    LP                       38                       /* (  左括号 */
#define    RP                       39                       /* ) 右括号 */
#define    LC                       40                       /* { 左大括号 */
#define    RC                       41                       /* } 右大括号 */
#define    LB                       42                       /* [ 左中括号 */
#define    RB                       43                       /* } 右中括号 */
#define    COMMA                    44                       /* , */
#define    SEMI                     45                       /* ; */
#define    EQUAL                    46                       /* = */
#define    ASSIGNOP                 47                       /* += -= */
#endif //UNTITLED_YYOUT_H
