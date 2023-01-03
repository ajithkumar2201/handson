#include<stdio.h>
#include<stdlib.h>
#define RTT 4
#define TIMEOUT 4
#define TOT_FRAMES 7

enum {NO,YES} ACK;
int main()
{
	int waittime,i=1;
	ACK = YES;
	for(;i<=TOT_FRAMES;)
	{
		if(ACK==YES && i!=1)
		{
			printf("\nSENDER:ACK for Frame %d Received\n",i-1);
		}
		printf("\nSENDER:Frame %d Sent,Waiting for ACK...\n",i);
		ACK = NO;
		waittime=rand()%4+1;
		if(waittime==TIMEOUT)
		{
			printf("\nSENDER:ACK not received for frame %d <=TIMEOUT,Resending frame",i);
		}
		else
		{
			sleep(RTT);
			printf("\nRECEIVER:Frame %d received,ACK sent",i);
			printf("\n________________\n");
			ACK=YES;
			i++;
		}
	}
	return 0;
}
