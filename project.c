#include<stdio.h>
#include<stdlib.h>
struct process
{
 int pid;
int runt;
float prior;
};
main()
{
  
   printf("\nEnter the no. of process");
  int n;
  scanf("%d",&n);
int a[n];
  struct process p[n];
p[0].pid=0;
for(int i=1;i<n;i++)
{
   p[i].pid=p[i-1].pid+1;

}
printf("\nEnter the process run time");
  for(int i=0;i<n;i++)
{
  printf("\nProcess %d st :",i);
  scanf("%d",&p[i].runt);
}
int temp;
for(int i=0;i<n;i++)
{
   a[i]=p[i].runt;
}

for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
         if(a[j]>a[j+1])
	{
	    temp=a[j];
	     a[j]=a[j+1];
	     a[j+1]=temp;
	}
    }
}
for(int i=0;i<n;i++)
{
   printf("\n%d",a[i]);
}
int t=0;
for(int i=0;i<n;i++)
{
 for(int j=0;j<n;j++)
{
   if(a[i]==p[j].runt)
{   
	t++;
    p[j].prior=t;
}
}
}
for(int i=0;i<n;i++)
{
  printf("\nprocess :%d process priority:%d",p[i].pid,p[i].prior);
}
}





















    



























  
  
