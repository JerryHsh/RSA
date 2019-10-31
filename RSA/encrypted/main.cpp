#include"my_rsa.h"

FILE *fp;

int main()
{
        system("clear");
        long  prime1,prime2,n,e,private_key;
        cout<<"Input two Prime please"<<endl;
        cin>>prime1,cin>>prime2;
        n=prime1*prime2;
        cout<<"Input the number which is comprime with (prime1-1)*(prime2-1)"<<endl;
        cin>>e;
        if(generate_private_key(private_key,prime1,prime2,e)!=OK)
        cout<<"ERROR"<<endl;
        else
        {
                fp=fopen("./private_key","w");
                fprintf(fp,"%ld",private_key);
                fclose(fp);
                fp=fopen("./public_key","w");
                fprintf(fp,"%ld\t%ld",n,e);
                fclose(fp);
        }
        return 0;
}
