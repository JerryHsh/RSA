#include"my_rsa.h"

long my_storage_1;       //shang
long my_storage_2;       //yu

long big_exponent_module(long a,long b,long m)          //module a big exponent num a^b%m
{
        long i;
        long answer=1;
        for(i=0;i<b;i++)
        {
                answer=((answer%m)*(a%m))%m;
        }
        return answer;
}

char convert(int a)             //convert a num into a letter
{
        char c;
        c='a'-1+a;
        return c;
}

status InitList(O_Linklist &L)
{
        O_Lnode *newbase;
        if((newbase=(O_Lnode *)malloc(sizeof(O_Lnode)))==NULL)
                return OVERFLOW;
        newbase->next=NULL;
        L.head=newbase;
        L.length=0;
        return OK;
}

status Oujilide_decompose(long a,long b,O_Linklist &L)  
{
        my_storage_1=a/b;
        my_storage_2=a%b;
        if(!my_storage_2)
                return OK;//zhengchu OK
        O_Lnode *newbase;
        if((newbase=(O_Lnode *)malloc(sizeof(O_Lnode)))==NULL)
                return OVERFLOW;
        newbase->devider=b;
        newbase->devision=a;
        newbase->p=my_storage_1;
        newbase->q=my_storage_2;
        newbase->next=L.head->next;
        L.head->next=newbase;
        if((Oujilide_decompose(b,my_storage_2,L))==OK)
                return OK;
        else 
                return ERROR;
}

status inverse_solution(O_Linklist L,long & Ans,long x)
{
        O_Lnode *p;
        p=L.head->next;
        if(p==NULL)
                return ERROR;
        else if(p->q!=1)
                return ERROR;
        Ans_Lnode answer;
        Ans_Lnode answer_tep;
        answer.gcd=p->q;
        answer.a1=p->devision;
        answer.a2=p->devider;
        answer.c1=1;
        answer.c2=(-1)*p->p;
        //cout<<answer.gcd<<"="<<answer.c1<<"*"<<answer.a1<<"+"<<answer.c2<<"*"<<answer.a2<<endl;
        while(p->next!=NULL)
        {
                p=p->next;
                answer_tep=answer;
                answer.a1=p->devision;
                answer.c1=answer_tep.c2;
                answer.a2=answer_tep.a1;
                answer.c2=answer_tep.c1-answer_tep.c2*p->p;
        //        cout<<answer.gcd<<"="<<answer.c1<<"*"<<answer.a1<<"+"<<answer.c2<<"*"<<answer.a2<<endl;
        }

        if(x==answer.a1)
        {
                Ans=answer.c1;
                Ans+=answer.a2;
                Ans%=answer.a2;
        }
        else if(x==answer.a2)
        {
                Ans=answer.c2;
                Ans+=answer.a1;
                Ans%=answer.a1;
        }
        else
                return ERROR;
        return OK;
}


status generate_private_key(long &Private_key,long prime1,long prime2,long e)
{
        O_Linklist L;
        InitList(L);
        long OulaFunc_num;
        OulaFunc_num=(prime1-1)*(prime2-1);
        if(Oujilide_decompose(OulaFunc_num,e,L)!=OK)
                return ERROR;
        if(inverse_solution(L,Private_key,e)!=OK)
                return ERROR;
        return OK;
}