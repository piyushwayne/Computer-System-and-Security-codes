#include<stdio.h>

void main()
{
	int A[100][100],B[100][100],result[100][100];
	int i,j,m,n,p,k;
	printf("Enter the no of rows of the first array");
	scanf("%d",&m);
	printf("Enter the no of column of the first array");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	}
	printf("Enter the no of column of the second array");
	scanf("%d",&p);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			scanf("%d",&B[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			result[i][j]=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			for(k=0;k<n;k++){
				result[i][j]+= A[i][k]*B[k][j];
			}
			
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
			printf("%d\t",result[i][j]);
		printf("\n");
	}
}
