#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[]="10001000000100001";
int a,i,j;

void xor()
{
	for(j=0;j<N-1;j++)
	cs[j]=((cs[j]==g[j])?'0':'1');
}

void crc()
{
	for(i=0;i<N;i++)
	cs[i]=t[i];
	do
	{
		if(cs[0]=='1')
		xor();
		for(j=0;j<N-1;j++)
			cs[j]=cs[j+1];
		cs[j]=t[i++];
		
	}while(i<=a+N-1);
}
int main()
{
	printf("\nMessage to be transmitted");
	scanf("%s",t);
	printf("\n___________________________________________");
	printf("\nGenerating polynomial is %s",g);
	
	a=strlen(t);
	for(i=a;i<a+N-1;i++)
	t[i]='0';
	printf("\n____________________________________________");
	
	printf("\nAfter appending 0's to message : %s",t);
	printf("\n____________________________________________");
	crc();
	printf("\nChecksum is : %s",cs);
	
	for(i=a;i<a+N-1;i++)
	t[i]=cs[i-a];
	printf("\n_______________________________________________");
	printf("\nFinal codeword to be transmitted is %s",t);
	
	printf("\n________________________________________________");
	printf("\nEnter the received message");
	scanf("%s",t);
	crc();
	
	printf("\nRemainder = %s",cs);
	for(i=0;(i<N-1)&&(cs[i]!='1');i++);
	if(i<N-1)
	printf("\nError detected");
	else
	printf("\nNo error detected");
	printf("\n__________________________________________________");
	return 0;
}
