#include"my_rsa.h"

FILE *fp;

int main()
{
        long  code,private_key,n;
        fp=fopen("./encrpted_original_num","r");
        fscanf(fp,"%ld",&code);
        fclose(fp);
        fopen("./private_key","r");
        fscanf(fp,"%ld",&private_key);
        fclose(fp);
        fopen("./public_key","r");
        fscanf(fp,"%ld",&n);
        fclose(fp);
        fopen("./original_num","w");
        code=big_exponent_module(code,private_key,n);
        fprintf(fp,"%ld",code);
        fclose(fp);
        return 0;
}