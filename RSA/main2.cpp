#include"my_rsa.h"

FILE *fp;

int main()
{
        long  n,e,store_num;
        fp=fopen("./public_key","r");
        fscanf(fp,"%ld",&n);
        fscanf(fp,"%ld",&e);      
        fclose(fp);
        cout<<"Input the number you want to encryted"<<endl;
        cin>>store_num;
        store_num=big_exponent_module(store_num,e,n);
        fp=fopen("encrpted_original_num","w");
        fprintf(fp,"%ld",store_num);
        fclose(fp);
        return 0;
}
