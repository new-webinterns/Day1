#include<stdio.h>
#include<stdlib.h>
int main()
{
int max[10][10],need[10][10],alloc[10][10],avail[10],completed[10],selfseqence[10];
int p,r,i,j,process,count;
count=0;
printf("enter the no of process:");
scanf("%d",&p);
for(i=0;i<p;i++)
completed[i]=0;
printf("enter the no of resource:");
scanf("%d",&r);
printf("enter the matrix for each process:\n");
for(i=0;i<p;i++)
{
printf("for process %d:",i+1);
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("enter the aloocation for each process:\n");
for(i=0;i<p;i++)
{
printf("process %d:",i+1);
for(j=0;j<r;j++)
{
scanf("%d",&alloc[i][j]);
}
}
printf("enter the available resorces:");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
for(i=0;i<p;i++)
 for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
do
{
printf("\nmax matrix\tallocation matrix:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d",max[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d",alloc[i][j]);
printf("\n");
}
process=-1;
for(i=0;i<p;i++)
{
if(completed[i]==0)
 {
process=i;
for(j=0;j<r;j++)
{
if(avail[j]<need[i][j])
{
process=-1;
break;
}
}
}
if(process!=-1)
break;
}
if(process!=-1)
{
printf("process runs to completion %d\n",process+1);
selfseqence[count]=process+1;
count++;
for(j=0;j<r;j++)
{
avail[j]+=alloc[process][j];
alloc[process][j]=0;
max[process][j]=0;
completed[process]=1;
}}}
while(count!=p && process!=-1);
if(count==p)
{
printf("The system in a safestate");
printf("safe sequence:");
for(i=0;i<p;i++)
{
printf("%d",selfseqence[i]);
printf(">\n");
}
}
else
printf("file system is in unsafe state");
}
