#include<stdio.h>
#include<string.h>
#include<math.h>
void main()
{
	char plaintext[100],ciphertext[100],plaintext1[100];
	int n,i,j,p,k,column,row2,col1,col;
	gets(plaintext);
	int len = strlen(plaintext);
	
	printf("Enter the no of the Column\n");
	scanf("%d",&column);
	char buffer[(len/column)+1][column];
	for(i=0;i<len;i++)
			buffer[i/column][i%column]=plaintext[i];
	j=0;
	for(i=0;i<(len/column)+1;i++)
	{
		for(j=0;j<column;j++)
		{
			printf("%c\t",buffer[i][j]);
		}
		printf("\n");
			
	}
	for(i=0;i<(len/column)+1;i++)
	{
		if(col>len-1)
			break;	
		for(j=0;j<=column;j++)
		{
			ciphertext[col++]=plaintext[column*j+i];
		}
			
	}
	printf("\nCiphertext is: ");
	for(i=0;i<len;i++)
		printf("%c",ciphertext[i]);
	printf("\n");
	col=0;
	for(i=0;i<(len/column)+1;i++)
	{
		if(col>len-1)
			break;	
		for(j=0;j<=column;j++)
		{
			plaintext1[col++]=ciphertext[column*j+i];
		}		
	}
	printf("\nReturn Plain  is: ");
	for(i=0;i<len;i++)
		printf("%c",plaintext1[i]);
	
}
