#include<iostream>
#include<stdlib.h>
#include"my_rsa.h"

using namespace std;


int main()
{
        O_Linklist L;
        InitList(L);
        Oujilide_decompose(662,414,L);
        O_Lnode *p=L.head;
        while(p->next!=NULL)
        {
                p=p->next;
                cout<<p->devision<<"="<<p->p<<"*"<<p->devider<<"+"<<p->q<<endl;
        }
        return 0;
}
