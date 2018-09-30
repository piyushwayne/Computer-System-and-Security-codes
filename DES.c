#include<stdio.h>
int text[16][64];
int inipermut(int data[64])
{
	int i;
	int answer[64];
	int initialPermutation[64] = {58,50,42,34,26,18,10,02,60,52,44,36,28,20,12,04,62,54,46,38,30,22,14,06,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,01,59,51,43,35,27,19,11,03,61,53,45,37,29,21,13,05,63,55,47,39,31,23,15,07};
	for(i=0;i<64;i++)
		answer[i] = data[initialPermutation[i]-1];
	
	return answer;
}
int finpermut(int data[64])
{
	int i;
	int answer[64];
	int finalPermutation[64] = {40,8,48,16,56,24,64,32,39,07,47,15,55,23,63,31,38,06,46,14,54,22,62,30,37,05,45,13,53,21,61,29,36,04,44,12,52,20,60,28,35,03,43,11,51,19,59,27,34,02,42,10,50,18,58,26,33,01,41,9,49,17,57,25};
	for(i=0;i<64;i++)
		answer[i] = data[finalPermutation[i]-1];
	
	return answer;
}
void data(int data[64],int round)
{
	int answer[64],left[32],right[32];
	int i;
	for(i=0;i<32;i++)
	{
		right[i]= data[32+i];
		answer[i]=data[32+i];
	}
	int funcAns[32] = function(right,round)
	for(i=0;i<32;i++)
		answer[i] = data[i]^funcAns[i]
	for(i=0;i<64;i++)
	{
		data[i]=answer[i];
		text[round][i]=answer[i];
	}
}
int ExpansionPBox(int key[32])
{
	int i;
	int returnKey[48];
	returnKey[0]=key[31];
	returnKey[47]=key[0];
	for(i=0;i<32;i++)
	{
		if((i+1)%4==0)
		{
			returnKey[((i+1)/2)*3]=key[i];
		}
		else if(i%4==0)
		{
			returnKey[((i/2)*3)-1]=key[i]
		}
		else
			
	
	}
}
int function(int right[32],int round)
{
	int afterExpanPBox[48] = ExpansionPBox(right);
	int afterXORWithKey[48];
	int afterSBoxes[32];
	int afterStraightPBoxes[32];
	for(i=0;i<48;i++)
	{
		afterXORWithKey[i]= afterExpanPBox[i]^Key[round][i];
	}
	afterSBoxes = Sboxes(afterXORWithKey);
	afterStraightPBoxes = StraightPBox(afterSBoxes);
}
void main()
{
	int plaintext[64] =  {0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0};
	for(i=0;i<64;i++)
		data[i] = plaintext[i];
	
	data = inipermut(data);
	for(i=0;i<16;i++)
	{
		round(data,i);
	}	
}
