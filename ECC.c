#include<stdio.h>
int x1,x2,y,y2,a,b,p,m1,m2,d,cx1,cx2,cy,cy2,r;
int modInverse(int a, int m)
{
	int x;
	a = a%m;
	for (x=1; x<m; x++)
		if ((a*x) % m == 1)
			return x;
}

int addInv(int a,int m)
{
	if(a>0)
		return(a%m);
	else
	{
		while(a<0)
			a+=m;
		return(a);
	}
}
void generateE2()
{
	
	int l;
	if(x1==x2 && y==y2)
	{
		l = ((3*x1*x1+a)*modInverse(2*y,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		x2 = l*l-x1-x2;
		x2 = addInv(x2,p);
		printf("\tx3 is %d\n",x2);
		y2 = l*(x1-x2)-y;
		y2 = addInv(y2,p);
		printf("\ty3 %d\n",y2);
	}
	else
	{
		l = ((y2-y)*modInverse(x2-x1,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		x2 = l*l-x1-x2;
		x2 = addInv(x2,p);
		printf("\tx3 is %d\n",x2);
		y2 = l*(x1-x2)-y;
		y2 = addInv(y2,p);
		printf("\ty3 %d\n",y2);
	}
}
void generateC1()
{
	
	int l;
	if(x1==cx1 && y==cy)
	{
		l = ((3*x1*x1+a)*modInverse(2*y,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx1 = l*l-x1-cx1;
		cx1 = addInv(cx1,p);
		printf("\tcx1 is %d\n",cx1);
		cy = l*(x1-cx1)-y;
		cy = addInv(cy,p);
		printf("\ty3 %d\n",cy);
	}
	else
	{
		l = ((cy-y)*modInverse(cx1-x1,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx1 = l*l-x1-cx1;
		cx1 = addInv(cx1,p);
		printf("\tcx1 is %d\n",cx1);
		cy = l*(x1-cx1)-y;
		cy = addInv(cy,p);
		printf("\ty3 %d\n",cy);
	}
}
void generateC21()
{
	
	int l;
	if(x2==cx2 && y2==cy2)
	{
		l = ((3*x2*x2+a)*modInverse(2*y2,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx2 = l*l-x2-cx2;
		cx2 = addInv(cx2,p);
		printf("\tcx2 is %d\n",cx1);
		cy2 = l*(x2-cx2)-y2;
		cy2 = addInv(cy2,p);
		printf("\tcy2 %d\n",cy2);
	}
	else
	{
		l = ((cy2-y2)*modInverse(cx2-x2,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx2 = l*l-x2-cx2;
		cx2 = addInv(cx2,p);
		printf("\tcx2 is %d\n",cx2);
		cy2 = l*(x2-cx2)-y2;
		cy2 = addInv(cy2,p);
		printf("\tcy2 %d\n",cy2);
	}
}
void generateC22()
{
	
	int l;
	if(m1==cx2 && m2==cy2)
	{
		l = ((3*m1*m1+a)*modInverse(2*m2,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx2 = l*l-m1-cx2;
		cx2 = addInv(cx2,p);
		printf("\tcx2 is %d\n",cx1);
		cy2 = l*(m1-cx2)-m2;
		cy2 = addInv(cy2,p);
		printf("\tcy2 %d\n",cy2);
	}
	else
	{
		l = ((cy2-m2)*modInverse(cx2-m1,p));
		l = addInv(l,p);
		printf("\tLambda is %d\n",l);
		cx2 = l*l-m1-cx2;
		cx2 = addInv(cx2,p);
		printf("\tcx2 is %d\n",cx2);
		cy2 = l*(m1-cx2)-m2;
		cy2 = addInv(cy2,p);
		printf("\tcy2 %d\n",cy2);
	}
}
main()
{
	int i;
	printf("Enter a\n");
	scanf("%d",&a);
	printf("Enter b\n");
	scanf("%d",&b);
	printf("Enter p\n");
	scanf("%d",&p);
	printf("Enter x1\n");
	scanf("%d",&x1);
	printf("Enter y\n");
	scanf("%d",&y);
	printf("Enter d\n");
	scanf("%d",&d);
	printf("Enter m1\n");
	scanf("%d",&m1);
	printf("Enter m2\n");
	scanf("%d",&m2);
	printf("Enter r\n");
	scanf("%d",&r);
	x2=x1;
	y2=y;
	cx1 = x1;
	cy = y;
	printf("Inside generateE2\n");
	for(i=0;i<d;i++)
	{
		generateE2();
	}
	printf("Inside generateC1\n");
	for(i=0;i<r;i++)
		generateC1();
	printf("Inside generateC21\n");
	generateC21();
	printf("Inside generateC22\n");
	generateC22();
	
}
