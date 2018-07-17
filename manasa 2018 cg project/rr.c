#include<stdio.h>
#include<stdlib.h>
int x[20],wt[20],tt[20],bt[20];
void display(int n)
{
int i;
int sumwt=0,sumtt=0;
float avgwt,avgtt;
printf("\n process_no\tburst time\t waiting time\tturn around time\n");
for(i=0;i<n;i++)
{
printf("\n p%d\t\t %d\t\t %d \t\t %d",i,x[i],wt[i],tt[i]);
sumwt+=wt[i];
sumtt+=tt[i];
}
avgwt=(float)sumwt/n;
avgtt=(float)sumtt/n;
printf("\n avg wait time=%f",avgwt);
printf("\n avg turn around time=%f",avgtt);
}
void srtf(int n)
{
int i,at[20],small,end;
int time,count=0;
printf("\n enter arrival time:\n");
for(i=0;i<n;i++)
{
printf("\n p%d",i);
scanf("%d",&at[i]);
}
bt[9]=999;
for(time=0;count!=n;time++)
{
small=9;
for(i=0;i<n;i++)
{
if(at[i]<=time&&bt[i]<bt[small]&&bt[i]>0)
small=i;
}
bt[small]--;
if(bt[small]==0)
{
++count;
end=time+1;
wt[small]=-x[small]+end-at[small];
tt[small]=wt[small]+x[small];
}
}
display(n);
}

void rr(int n)
{
int tq,i,count=0,temp,sq=0;
printf("enter time quantum:");
scanf("%d",&tq);
while(1)
{
for(i=0,count=0;i<n;i++)
{
temp=tq;
if(bt[i]==0)
{
count++;
continue;
}
else if(bt[i]>=tq)
bt[i]=bt[i]-tq;
else if(bt[i]>0)
{
temp=bt[i];
bt[i]=0;
}
sq=sq+temp;
tt[i]=sq;
}
if(n==count)
break;
}
for(i=0;i<n;i++)
{
wt[i]=tt[i]-x[i];
}
display(n);
}void main()
{
int ch,i,n;
while(1)
{
printf("\n\n\n1)SRTF\n2)RR\nEnter yourchoice?\n");
scanf("%d",&ch);
if(ch!=3)
{
printf("\n Enter the no of processes:\n");
scanf("%d",&n);
printf("\n Enter burst time:\n");
for(i=0;i<n;i++)
{
printf("\n p%d:",i);
scanf("%d",&bt[i]);
x[i]=bt[i];
tt[i]=0;
wt[i]=0;
}
}
switch(ch)
{
case 1:srtf(n);
break;
case 2:rr(n);
break;
default :exit(0);
}
}
}
