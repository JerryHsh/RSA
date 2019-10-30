#include<iostream>

using namespace std;

int modlous(int a,int b,int m);

int main()
{
        int a=1,b,m;
        while(a)
        {
                system("clear");
                cout<<"Input the original num exponent and module num"<<endl;
                cin>>a;
                cin>>b;
                cin>>m;
                cout<<modlous(a,b,m)<<endl;
                cout<<"more1/0"<<endl;
                cin>>a;
        }
        while(1)
        {
                cout<<"Input the num"<<endl;
                cin>>a;
                printf("%c\n",'a'-1+a);
        }
        return 0;
}

int modlous(int a,int b,int m)
{
        int i;
        int answer=1;
        for(i=0;i<b;i++)
        {
                answer=((answer%m)*(a%m))%m;
        }
        return answer;
}