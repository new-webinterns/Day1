#include<stdio.h>
#include<stdlib.h>
void FIFO(char[],char[],int,int);
void lru(char[],char[],int,int);
void optimal();
//void opt(char[],char[],int,int);
int main()
{
int ch,YN=1,i,l,f;
char F[10],s[25];
printf("\n\n\tEnter the number of empty frames:");
scanf("%d",&f);
printf("\n\n\tEnter the length of the string:");
scanf("%d",&l);
printf("\n\n\tEnter the string:");
scanf("%s",s);
for(i=0;i<f;i++)
F[i]=-1;
do
{
printf("\n\n\t*****MENU*****\n");
printf("\t1.FIFO\n\t2.LRU\n\t3.optimal");
printf("\n\n\tEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:for(i=0;i<f;i++)
{
F[i]=-1;
}
FIFO(s,F,l,f);
break;
case 2:for(i=0;i<f;i++)
{
F[i]=-1;
}
lru(s,F,l,f);
break;
case 3:optimal();
break;
default:exit(0);
}
printf("\n\n\tDo you want to continue If YES press 1\n\n\tIf NO press 0:");
scanf("%d",&YN);
}while(YN=1);
return(0);
}
void FIFO(char s[],char F[],int l,int f)
{
int i,j=0,k,flag=0,cnt=0;
printf("\n\tPAGE\tFRAMES\tFAULTS");
for(i=0;i<l;i++)
{
for(k=0;k<f;k++)
{
if(F[k]==s[i])
flag=1;
}
if(flag==0)
{
printf("\n\t%c\t",s[i]);
F[j]=s[i];
j++;
for(k=0;k<f;k++)
{
printf("%c",F[k]);
}
printf("\tPage-fault %d",cnt);
cnt++;
}
else
{
flag=0;
printf("\n\t%c\t",s[i]);
for(k=0;k<f;k++)
{
printf("%c",F[k]);
}
printf("\tNo page-fault");
}
if(j==f)
j=0;
}
}
void lru(char s[],char F[],int l,int f)
{
int i,j=0,k,m,flag=0,cnt=0,top=0;
printf("\n\tPAGE\tFRAMES\tFAULTS");
for(i=0;i<l;i++)
{
for(k=0;k<f;k++)
{
if(F[k]==s[i])
{
flag=1;
break;
}
}
printf("\n\t%c\t",s[i]);
if(j!=f && flag!=1)
{
F[top]=s[i];
j++;
if(j!=f)
top++;
}
else
{
if(flag!=1)
{
for(k=0;k<top;k++)
{
F[k]=F[k+1];
}
F[top]=s[i];
}
if(flag==1)
{
for(m=k;m<top;m++)
{
F[m]=F[m+1];
}
F[top]=s[i];
}
}
for(k=0;k<f;k++)
{
printf(" %c",F[k]);
}
if(flag==0)
{
printf("\tPage-fault %d",cnt);
cnt++;
}
else
printf("\tNo page-fault");
flag=0;
}

}
void optimal()
{
      int reference_string[25], frames[25], interval[25];
      int pages, total_frames, page_faults = 0;
      int m, n, temp, flag, found;
      int position, maximum_interval, previous_frame = -1;
      printf("\nEnter Total Number of Pages:\t"); 
      scanf("%d", &pages);
      printf("\nEnter Values of Reference String\n"); 
      for(m = 0; m < pages; m++)
      { 
            printf("Value No.[%d]:\t", m + 1);
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames:\t"); 
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)   
      {
            frames[m] = -1;
      }
      for(m = 0; m < pages; m++)  
      {
            flag = 0;
            for(n = 0; n < total_frames; n++) 
            {
                  if(frames[n] == reference_string[m]) 

                  {
                        flag = 1;
                        printf("\t");
                        break;
                  }
            }
            if(flag == 0)  
            {
                  if (previous_frame == total_frames - 1)
                  {
                        for(n = 0; n < total_frames; n++)
                        {      
                              for(temp = m + 1; temp < pages; temp++) 
                              {      
                                    interval[n] = 0; 
                                    if (frames[n] == reference_string[temp]) 


                                    {      
                                          interval[n] = temp - m;
                                          break;
                                    }
                              }
                        }
                        found = 0;
                        for(n = 0; n < total_frames; n++) 
                        {
                              if(interval[n] == 0)
                              {                 
                                    position = n;
                                    found = 1;
                                    break;
                              }            
                        }
                  }
                  else   //no page fault.
                  {
                        position = ++previous_frame;
                        found = 1;
                  }
                  if(found == 0) 
                  {
                        maximum_interval = interval[0];
                        position = 0;
                        for(n = 1; n < total_frames; n++)
                        {
                              if(maximum_interval < interval[n])
                              {
                                    maximum_interval = interval[n];
                                    position = n;
                              }
                        }
                   }     
                   frames[position] = reference_string[m]; 
                   printf("FAULT\t");
                   page_faults++;
            }
            for(n = 0; n < total_frames; n++)
            {
                  if(frames[n] != -1) 
                  {
                        printf("%d\t", frames[n]);
                  }
            }
            printf("\n");
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_faults);
     }

