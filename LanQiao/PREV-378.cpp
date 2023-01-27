/*
 * hint:
 * * C/C++ 用 3 Byte 表示中文字符
 * * 未解决
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define MAXN 100
#define ANS_LEN 12

using namespace std;

char cube[2][2][2][ANS_LEN], operations[MAXN]="";

void init()
{
    strcpy(cube[0][0][0], "篮橙白");
    strcpy(cube[0][0][1], "红绿白");
    strcpy(cube[0][1][0], "");
    strcpy(cube[0][1][1], "篮红黄");
    strcpy(cube[1][0][0], "绿白橙");
    strcpy(cube[1][0][1], "绿红白");
    strcpy(cube[1][1][0], "绿橙黄");
    strcpy(cube[1][1][1], "绿黄红");
}

void x_op()
{
    char s[ANS_LEN]="";
    strcpy(s, cube[1][0][0]);
    strcpy(cube[1][0][0], cube[1][1][0]);
    strcpy(cube[1][1][0], cube[1][1][1]);
    strcpy(cube[1][1][1], cube[1][0][1]);
    strcpy(cube[1][0][1], s);
}

void y_op()
{
    char s[ANS_LEN]="";
    strcpy(s, cube[1][0][1]);
    strcpy(cube[1][0][1], cube[1][1][1]);
    strcpy(cube[1][1][1], cube[0][1][1]);
    strcpy(cube[0][1][1], cube[0][0][1]);
    strcpy(cube[0][0][1], s);
}

void z_op()
{
    char s[ANS_LEN]="";
    strcpy(s, cube[0][0][0]);
    strcpy(cube[0][0][0], cube[1][0][0]);
    strcpy(cube[1][0][0], cube[1][0][1]);
    strcpy(cube[1][0][1], cube[0][0][1]);
    strcpy(cube[0][0][1], s);
}

int transform(char *op)
{
    int l = strlen(op);
    for (int i = 0; i < l; i++)
        if (op[i] == 'x') x_op();
        else if (op[i] == 'y') y_op();
        else if (op[i] == 'z') z_op();
        else return 0;
    return 1;
}

int main()
{
    init();
    cin.getline(operations, MAXN);
    if(transform(operations))
        printf("%s\n", cube[1][0][1]);
    else
        printf("Error\n");
    return 0;
}