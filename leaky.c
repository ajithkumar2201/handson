#include<stdio.h>
#include<stdlib.h>
#define bucketsize 500
#define n 5

void bucketoutput(int *bucket,int op)
{
	if(*bucket>0&&*bucket>op)
	{
		*bucket=*bucket-op;
		printf("\n%d - outputed remaining is %d",op,*bucket);
	}
	else if(*bucket>0)
	{
		printf("\nRemaining data output is %d",*bucket);
		*bucket=0;
	}
	
}
int main()
{
	int op,newpack,oldpack=0,wt,i,j,bucket=0;
	printf("Enter the output rate\n");
	scanf("%d",&op);
	
	for(i=1;i<=n;i++)
	{
		newpack=rand()%500;
		printf("Newpacket size is %d",newpack);
		newpack= newpack+oldpack;
		
		wt=rand()%5;
		if(newpack<bucketsize)
			bucket=newpack;
		else
		{
			printf("\n the new packet and old packet is greater than bucket size reject\n",newpack);
			bucket=oldpack;
			
		}
		printf("\n data in cuket is %d",bucket);
		printf("\n next packet will arrive at %d",wt);
		for(j=0;j<wt;j++)
		{
			bucketoutput(&bucket,op);
			sleep(1);
			
		}
		oldpack = bucket;
		
	}
	while(bucket>0)
		bucketoutput(&bucket,op);
	return 0;
}
