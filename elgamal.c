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
int primitivegroup(int p)
{
	int i,j,k,x;int arr[p];
	for(k=0;k<p;k++)
		arr[p]=0;
	for(i=1;i<p;i++)
	{
		for(j=0;j<p;j++)
		{
			x = pow(i,j);
			x = x%p;
			if(arr[x]==0)
				arr[x]=1;
			else
				break;
			if(j==p-2)
				return(i);
		}
		for(k=0;k<p;k++)
			arr[k]=0;
			
	}
}
void main()
{
	int p,d,e1,e2,r,m,c1,c2,mm,temp;
	printf("Enter a prime no:\n");
	scanf("%d",&p);
	
	e1=primitivegroup(p);
	printf("e1 = %d\n",e1);
	printf("Enter a d:\n");
	scanf("%d",&d);
	e2 = pow(e1,d);
	e2 = e2%p;
	printf("Enter a random no r:\n");
	scanf("%d",&r);
	printf("Enter message m:\n");
	scanf("%d",&m);
	c1 = pow(e1%p,r);
	c1 = c1%p;
	temp = pow(e2%p,r);
	temp = temp%p;
	c2 = ((m%p)*(temp))%p;
	printf("c1 = %d\n",c1);
	printf("c2 = %d\n",c2);
	temp = pow(c1,d);
	temp = modInverse(temp,p);
	mm = ((c2%p)*(temp))%p;
	printf("Returned message is %d\n",mm);
	
}
