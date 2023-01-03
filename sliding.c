#include<stdio.h>
#include<stdlib.h>
#define RTT 5

int main()
{
	int windowsize,i,f,frames[50];
	printf("Enter the window size");
	scanf("%d",&windowsize);
	
	printf("enter the no. of frames ");
	scanf("%d",&f);
	
	printf("Enter %d frames",f);
	
	for(i=1;i<=f;i++)
	scanf("%d",&frames[i]);
	
	printf("\n After sending %d frames, Sender waits for ACK",windowsize);
	printf("\n Sending frames in the following manner\n\n");

	for(i=1;i<=f;i++)
	{
		if(i%windowsize!=0)
		{
		
			printf(" %d",frames[i]);
		}
		else
		{
			printf(" %d",frames[i]);
			printf("Sender:Waiting for ACK...\n\n");
			sleep(RTT/2);
			printf("Receiver:Frames received, ACK sent\n");
			printf("\n___________________");
			sleep(RTT/2);
			printf("\nACK received,Sending next frames\n\n");
		}	
	}
		if(f%windowsize!=0)
		{
			printf("Sender:Waiting for ACK...\n\n");
			sleep(RTT/2);
			printf("Receiver:Frames received, ACK sent\n");
			printf("___________________");
			sleep(RTT/2);
			printf("ACK received");	
			
		}
	return 0;
}
