#include<stdio.h>
#include<string.h>
void main()
{
int a[20],b[30],i,j,k,count,n;
printf("Enter Frame length :");
//gets(n);
scanf("%d",&n);
printf("Enter input frame (0's & 1's only): "); //enter the length of frame
for(i=0;i<n;i++)
scanf("%d",&a[i]);
i=0;
count=1;
j=0;
while(i<n)
{ //count=0;
if(a[i]==1) //check if the data is '1’
{
b[j]=a[i];
for(k=i+1;a[k]==1 && k<n && count<5;k++)
{
j++;
b[j]=a[k];
count++; //increment and count the number of 1's
if(count==5)
{
j++;
b[j]=0;
}
i=k;
}
}
else
{
b[j]=a[i];
}
i++;
j++;
count=1;

}
printf("After stuffing the frame is:");
printf("01111110"); //append 01111110 at the begining of the data
for(i=0;i<j;i++)
printf("%d",b[i]);
printf("01111110"); //append 01111110 at the end of the data
//getch();
}

