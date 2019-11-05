#include<iostream>
#include<stdlib.h>

#ifndef MY_RSA
#define MY_RSA

using namespace std;

const int ERROR=0;
const int OK=1;
const int OVERFLOW=-1;

typedef int status;

typedef struct Node
{      long gcd; //greatest common devisor
        long a1;//add element
        long a2;
        long c1; //coefficent
        long c2;
}Ans_Lnode;

typedef struct Node2
{
        long devider;//chuhsu
        long devision; //beichushu
        long p; //shang
        long q; //yu
        struct Node2 *next;
}O_Lnode;

typedef struct List2
{
        O_Lnode *head;
        int length;
}O_Linklist;



long big_exponent_module(long a,long b,long m);
char convert(int a);
status InitList(O_Linklist &L);
status Oujilide_decompose(long a,long b,O_Linklist &L);
status inverse_solution(O_Linklist L,long &Ans,long x);
status generate_private_key(long &Private_key,long prime1,long prime2,long e);

extern long my_storage_1;       //shang
extern long my_storage_2;       //yu

#endif // !MY_RSA
