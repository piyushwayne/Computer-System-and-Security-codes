#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int key,keyI; char plain[100],cipher[100]; char trial[100];
void encrypt(char plaintext[100])
{
	int i=0,a;char ciphertext[100];
	while(plaintext[i]!='\0')
	{
		if(plaintext[i]==' ')
		{
			ciphertext[i] =' ';
			i=i+1;
			continue;
		}
		a = plaintext[i];
		a=a-97;
		a*=key;
		a=(a%26)+97;
		ciphertext[i] = a;
		cipher[i] = a;
		a=0;
		i=i+1;
	}
	ciphertext[i]='\0';
	printf("The Cipher text is: ");
	printf("%s",ciphertext);
	printf("\n");
}
void dcrypt(char plaintext[100])
{
	int i=0,a;char ciphertext[100];
	while(plaintext[i]!='\0')
	{
		if(plaintext[i]==' ')
		{
			ciphertext[i] =' ';
			i=i+1;
			continue;
		}
		a = plaintext[i];
		a=a-97;
		a=a*keyI;
		a=(a%26)+97;
		ciphertext[i] = a;
		a=0;
		i=i+1;
	}
	ciphertext[i]='\0';
	printf("The plain text generated is: ");
	printf("%s",ciphertext);	
	printf("\n");
	i=0;
}
void main()
{
	int i;
	printf("Enter the plain text\n");
	gets(plain);
   	printf("Enter the key\n");
	scanf("%d",&key);
	encrypt(plain);
	for(i=1;i<26;i++)
	{
		if((i*key)%26==1){
			keyI=i;
			break;
		}
		
	}
	printf("%d",keyI);
	printf("Enter the cipher text: ");
	for(i=0;i<6;i++)
		scanf("%c",&trial[i]);
	
	dcrypt(trial);
	
}
