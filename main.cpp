#include<iostream>
#include<stdlib.h>
#include"my_rsa.h"


int main()
{
        system("clear");
        long n,e;
        long prime1,prime2;
        long store_c_p; //(p-1)*(q-1)
        long private_key;
        long key;
        long decrpted_num;
        O_Linklist L;
        O_Lnode *p=L.head;
        cout<<"Input the public key please"<<endl;
        cout<<"n:"<<endl;
        cin>>n;
        cout<<"e:"<<endl;
        cin>>e;
        cout<<endl;
        cout<<"Input the prime factors of prime1 prime2"<<endl;
        cin>>prime1;
        cin>>prime2;
        //give the key of decryption
        InitList(L);
        store_c_p=(prime1-1)*(prime2-1);
        Oujilide_decompose(store_c_p,e,L);
        /*
        while(p->next!=NULL)
        {
                p=p->next;
                cout<<p->devision<<"="<<p->p<<"*"<<p->devider<<"+"<<p->q<<endl;
        }
        */
        inverse_solution(L,private_key,e);
        cout<<"your private_key is :"<<private_key<<endl;
        //begin to secrete;
        cout<<"Input the number you want to secret"<<endl;
        long original_num;
        cin>>original_num;
        long crypted_num;
        crypted_num=modlous(original_num,e,n);
        cout<<crypted_num<<endl;
        cout<<"Input your private_key"<<endl;
        cin>>key;
        store_c_p=prime1*prime2;
        decrpted_num=modlous(crypted_num,key,store_c_p);
        cout<<"this is the decrypted num"<<decrpted_num<<endl;
        return 0;
}
