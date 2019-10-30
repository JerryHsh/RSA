#include<iostream>
#include<stdlib.h>

#ifndef MY_RSA
#define MY_RSA

const int ERROR=0;
const int OK=1;
const int OVERFLOW=-1;

typedef int status;

typedef struct Node
{
        int a1;//add element
        int a2;
        int c1; //coefficent
        int c2;
        struct Node *next;
}Ans_Lnode;

typedef struct Node2
{
        int devider;//chuhsu
        int devision; //beichushu
        int p; //shang
        int q; //yu
        struct Node2 *next;
}O_Lnode;

typedef struct List   //a list which is filo
{
        Ans_Lnode * head;
        int length;
}Ans_Linklist;

typedef struct List2
{
        O_Lnode *head;
        int length;
}O_Linklist;



int modlous(int a,int b,int m);
char convert(int a);
status InitList(O_Linklist &L);
status Oujilide_decompose(int a,int b,O_Linklist &L);

extern int my_storage_1;       //shang
extern int my_storage_2;       //yu

#endif // !MY_RSA
