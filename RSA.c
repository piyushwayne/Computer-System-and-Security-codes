#include<stdio.h>
#include<math.h>
void main()
{
	int p,q,n,phin,e,d,i,m,c;
	long int reM;
	c=1;
	printf("Enter Prime No p\n");
	scanf("%d",&p);
	printf("Enter Prime No q\n");
	scanf("%d",&q);
	n= p*q;
	phin = (p-1)*(q-1);
	printf("Enter Prime No e between 1 and %d\n",phin);
	scanf("%d",&e);
	for(i=0;i<phin;i++)
	{
		if((e*i)%phin==1)
		{
			d=i;
			break;
		}
	}
	printf("the value of d is %d\n",d);
	printf("Enter the message M\n");
	scanf("%d",&m);
	c=pow(m,e);
	c=c%n;
	printf("The cipher text is %d\n",c);
	reM = pow(c,d);
	reM = reM%n;
	printf("The generated plaintext text is %ld\n",reM);
		
}
