#include<iostream>
#include<stdlib.h>
#include"my_rsa.h"


int main()
{
        O_Linklist L;
        InitList(L);
        Oujilide_decompose(3120,17,L);
        O_Lnode *p=L.head;
        while(p->next!=NULL)
        {
                p=p->next;
                cout<<p->devision<<"="<<p->p<<"*"<<p->devider<<"+"<<p->q<<endl;
        }
        int answer;
        inverse_solution(L,answer,17);
        cout<<answer<<endl;
        return 0;
}
