#include<stdio.h>
#include<string.h>
void main()
{
	char key[5][5]={{'L','G','D','B','A'},
			{'Q','M','H','E','C'},
			{'U','R','N','I','F'},
			{'X','V','S','O','K'},
			{'Z','Y','W','T','P'}};
	char plaintext[100],ciphertext[100],plaintext1[100],plaintext2[100];
	char flag;
	int n,i,j,p,k,row1,row2,col1,col2;
	printf("Enter the length of the String\n");
	scanf("%d",&n);
	printf("Enter the String\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p);
		flag=p+65;
		if(flag==plaintext[i-1] && i>0)
		{
			plaintext[i]='X';
			plaintext[i+1]=flag;
			i+=1;
			n+=1;
		}
		else
			plaintext[i]=flag;
	}
	if(n%2!=0)
	{
		plaintext[i]='X';
		n+=1;
	}
	printf("Plaintext is: ");
	for(i=0;i<n;i++){
		printf("%c",plaintext[i]);
	}
	for(i=0;i<n;i+=2)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(plaintext[i]==key[j][k])
				{
					row1=j;
					col1=k;
					break;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(plaintext[i+1]==key[j][k])
				{
					row2=j;
					col2=k;
					break;
				}
			}
		}
		if(row1==row2)
		{
			ciphertext[i]=key[row1][(col1%4)+1];
			ciphertext[i+1]=key[row2][(col2%4)+1];
		}
		else if(col1==col2)
		{
			ciphertext[i]=key[(row1%4)+1][col1];
			ciphertext[i+1]=key[(row2%4)+1][col2];
		}
		else
		{
			ciphertext[i]=key[row1][col2];
			ciphertext[i+1]=key[row2][col1];
		}
	
	}
	printf("\nCiphertext is: ");
	for(i=0;i<n;i++){
		printf("%c",ciphertext[i]);
	}
	printf("\n");
	for(i=0;i<n;i+=2)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(ciphertext[i]==key[j][k])
				{
					row1=j;
					col1=k;
					break;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(ciphertext[i+1]==key[j][k])
				{
					row2=j;
					col2=k;
					break;
				}
			}
		}
		if(row1==row2)
		{
			plaintext1[i]=key[row1][col1-1];
			plaintext1[i+1]=key[row2][col2-1];
		}
		else if(col1==col2)
		{
			plaintext1[i]=key[(row1)-1][col1];
			plaintext1[i+1]=key[(row2)-1][col2];
		}
		else
		{
			plaintext1[i]=key[row1][col2];
			plaintext1[i+1]=key[row2][col1];
		}
	
	}
	
	printf("\nReturn Plaintext is: ");
	for(i=0;i<n;i++){
		printf("%c",plaintext1[i]);
	}
}
