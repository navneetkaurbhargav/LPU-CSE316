#include<stdio.h>
#include<stdlib.h>
struct process
{
 int pid;
int runt;
float prior;
int waitt;
int remt;
};
void priorAssign(struct process* pp,int n)
{
  for(int i=0;i<n;i++)
{
  pp[i].prior=1.0+((float)pp[i].waitt/pp[i].runt);
 printf("prior with pid :%d=%d\n",pp[i].pid,pp[i].prior);

}
}
void assignWait(struct process*pp,int n)
{
 for(int i=0;i<n;i++)
{
 pp[i].waitt++;
}
}

int processAssign(struct process*pp,int n)
{
float max;

 for( int j=0;j<n;j++)
{
  if(pp[j].runt!=0)
{
  max=pp[j].prior;
 break;
}
}
  for(int i=0;i<n;i++)
{
 if(pp[i].runt!=0)
{
   if(pp[i].runt>max)
     max=pp[i].prior;
}
}
for(int i=0;i<n;i++)
{
 if(pp[i].prior==max)
    return i; 
}
}
  
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
for(int i=0;i<n;i++)
{
  p[i].waitt=0;
}

printf("\nEnter the process run time");
  for(int i=0;i<n;i++)
{
  printf("\nProcess %d :",i);
  scanf("%d",&p[i].runt);
}
int temp;
for(int i=0;i<n;i++)
{
   a[i]=p[i].runt;
}

 priorAssign(p,n);

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
    if(a[0]==p[j].runt)
{   
p[j].remt=p[j].runt;
   while((p[j].remt)--)
 {
  sleep(1);
printf("process running with process id %d:%d\n",p[j].pid,p[j].remt);
assignWait(p,n);
priorAssign(p,n);
    	
 }
p[j].runt=0; 
}
}
int x;
//n--;
while(n)
{
x=processAssign(p,n);

p[x].remt=p[x].runt;
   while((p[x].remt)--)
   {
     sleep(1);
     printf("process running with process id %d:%d\n",p[x].pid,p[x].remt);
     assignWait(p,n);
     priorAssign(p,n);
   }
p[x].runt=0;
n=n-1;
} 


}





















    



























  
  
