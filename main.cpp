#include<iostream>
#include<stdlib.h>
#include"my_rsa.h"


int main()
{
        system("clear");
        int n,e;
        cout<<"Input the secret key please"<<endl;
        cout<<"n:";
        cin>>n;
        cout<<'\t';
        cout<<"e:";
        cin>>e;
        cout<<endl;
        cout<<"Input the decryption num prime1 prime2"<<endl;
        int prime1,prime2;
        cin>>prime1;
        cin>>prime2;
        //give the key of decryption
        O_Linklist L;
        InitList(L);
        int store_c_p; //p-1*q-1
        store_c_p=(prime1-1)*(prime2-1);
        Oujilide_decompose(store_c_p,e,L);
        O_Lnode *p=L.head;
        while(p->next!=NULL)
        {
                p=p->next;
                cout<<p->devision<<"="<<p->p<<"*"<<p->devider<<"+"<<p->q<<endl;
        }
        int answer;
        inverse_solution(L,answer,e);
        cout<<"your key is :"<<answer<<endl;
        //begin to secrete;
        cout<<"Input the number you want to secret"<<endl;
        int original_num;
        cin>>original_num;
        int crypted_num;
        crypted_num=modlous(original_num,e,n);
        cout<<crypted_num<<endl;
        cout<<"Input your key"<<endl;
        int key;
        cin>>key;
        int decrpted_num;
        store_c_p=prime1*prime2;
        decrpted_num=modlous(crypted_num,key,store_c_p);
        cout<<"this is the decrypted num"<<decrpted_num<<endl;
        return 0;
}
