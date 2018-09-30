#include<stdio.h>
#include<math.h>
int modInverse(int a, int m)
{
	int x;
	a = a%m;
	for (x=1; x<m; x++)
		if ((a*x) % m == 1)
			return x;
}
int crt(int a,int b,int p,int q)
{
	int M = p*q;
	int M1 = M/p;
	int M2 = M/q;
	int M1inv = modInverse(M1,p);
	int M2inv = modInverse(M2,q);
	int x = a*M1*M1inv + b*M2*M2inv;
	x = x % M;
	return x;
}

main()
{
	int p,q,n,m,c,a1,a2,b1,b2,p1,p2,p3,p4;
	printf("Enter prime no 'p' of form 4n+3\n");
	scanf("%d",&p);
	printf("Enter prime no 'q' of form 4n+3\n");
	scanf("%d",&q);
	n = p*q;
	printf("Enter the message\n");
	scanf("%d",&m);
	c = (m*m)%n;
	printf("Cipher text is %d\n",c);
	a1 = pow(c,(p+1)/4);
	a1 = a1%p;
	printf("a1 is %d\n",a1);
	a2 = p-a1;
	printf("a2 is %d\n",a2);
	b1 = pow(c,(q+1)/4);
	b1 = b1%q;
	printf("b1 is %d\n",b1);
	b2 =q-b1;
	printf("b2 is %d\n",b2);
	p1 = crt(a1,b1,p,q);
	p2 = crt(a1,b2,p,q);
	p3 = crt(a2,b1,p,q);
	p4 = crt(a2,b2,p,q);
	printf("The series of plain Texts are\n\n");
	printf("P1 is %d\n",p1);
	printf("P2 is %d\n",p2);
	printf("P3 is %d\n",p3);	
	printf("P4 is %d\n",p4);
}
