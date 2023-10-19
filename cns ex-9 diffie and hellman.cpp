#include<stdio.h>
#include<math.h>

int main()
{
	int a,XA,q,XB,YA,YB,i,c,f,g,k1,k2,d;
	printf("enter the q value");
	scanf("%d",&q);
	printf("enter the alpha value");

	scanf("%d",&a);
   
    printf("enter the private key  XA");
    scanf("%d",&XA);
    
     printf("enter the private key  XB");
    scanf("%d",&XB);
    
    c=pow(a,XA);
    d=pow(a,XB);
    YA=c % q;
    
    YB=d % q;
    
    printf(" YA AND YB  ARE %d  %d\n",YA,YB);
    f=pow(YB,XA);
    k1=f%q;
    g=pow(YA,XB);
    k2=g%q;
    printf( "users key  %d  and %d\n" ,k1,k2);
    return 0;


}
