#include<stdio.h>
#include<stdlib.h>
int clock,flag=0;
struct process
{
 int pid;
int runt;
float prior;
int waitt;
int remt;
int arrival;
};
void priorAssign(struct process* pp,int n)
{
  for(int i=0;i<n;i++)
{
  if(pp[i].waitt<0)
pp[i].prior=-1;

 else if(pp[i].runt!=0)
{
  pp[i].prior=1.0+(((float)pp[i].waitt)/pp[i].runt);
 printf("priority of process with pid %d: %.1f\n",pp[i].pid,pp[i].prior);
}
}
}
void assignWait(struct process*pp,int n,int x)
{
 for(int i=0;i<n;i++)
{
if(i!=x)
 pp[i].waitt++;
}
}

int processAssign(struct process*pp,int n)
{
float max=pp[0].prior;
float temp;
int m=n,i=0,count=0;
while(m)
{
  if(pp[i].waitt<0)
count++;
i=i+1;
m--;
}
if(count==n)
return -1;
else
{
flag++;
count=0;
 for( int j=0;j<n;j++)
{
  if(pp[j].prior>max)
 {
  max=pp[j].prior;
  temp=j;
 }
}
return temp;
}

}
void firstProcessAssign(struct process*pp,int n)
{
int a[n],temp;
for(int i=0;i<n;i++)
{
   a[i]=pp[i].runt;
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

for(int j=0;j<n;j++)
{
    if(a[0]==pp[j].runt && pp[j].waitt>=0)
{   
pp[j].remt=pp[j].runt;
   while((pp[j].remt)--)
 {
  sleep(1);
printf("********process running with process id %d: %d********\n",pp[j].pid,pp[j].remt);
assignWait(pp,n,j);
priorAssign(pp,n);
    	
 }
pp[j].runt=0; 
pp[j].prior=-1;
}
}

}
  
main()
{
  
  printf("\nEnter the no. of process");
  int n;
  scanf("%d",&n);

  struct process p[n];
p[0].pid=0;
for(int i=1;i<n;i++)
{
   p[i].pid=p[i-1].pid+1;

}

printf("\nEnter the process run time");    //run time assign
  for(int i=0;i<n;i++)
{
  printf("\nProcess %d :",i);
  scanf("%d",&p[i].runt);
}
int temp;
printf("\nEnter the arrival time");        //arrival time assign

  for(int i=0;i<n;i++)
{
  printf("\nProcess %d :",i);
  scanf("%d",&p[i].arrival);
}

for(int i=0;i<n;i++)                      //Wait assign
{
  p[i].waitt=-p[i].arrival;
}

 priorAssign(p,n);


//n--;
int m=n;
int x;
clock=0;
while(m)
{
int count=0;
for(int i=0;i<n;i++)
{
  if(p[i].runt==0)
   count++;
}
if(count==n)
 break;
x=processAssign(p,n);
if(x==-1)
{
clock++;
printf("CLOCK:%d\n\n",clock);
printf("**********CPU is idle************\n\n");
sleep(1);
assignWait(p,n,-1);
priorAssign(p,n);
}

else
{

if(flag==1)
firstProcessAssign(p,n);

p[x].remt=p[x].runt;
   while((p[x].remt)--)
   {
clock++;
printf("CLOCK:%d\n\n",clock);
     sleep(1);
     printf("********process timer with process id %d: %d********\n\n",p[x].pid,p[x].remt);
     assignWait(p,n,x);
     priorAssign(p,n);
   }
p[x].runt=0;
p[x].prior=-1;
m=m-1;
}
} 
}






















    



























  
  
