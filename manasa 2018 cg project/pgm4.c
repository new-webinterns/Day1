 #include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
puts("grammar is E-E+E\nE-E*E\nE-(E)\nE-id");
puts("enter input string");
scanf("%s",a);
c=strlen(a);
strcpy(act,"SHIFT->");
puts("stack \t input \t action");
for(k=0,i=0;j<c;k++,i++,j++)
{
if(a[j]=='i'&& a[j+1]=='d')
{
stk[i]=a[j];
stk[i+1]=a[j+1];
stk[i+2]='\0';
a[j]=' ';
a[j+1]=' ';
printf("\n$%s\t%s$\t%sid",stk,a,act);
check();
}
else
{
stk[i]=a[j];
stk[i+1]='\0';
a[j]=' ';
printf("\n$%s\t%s$\t%sid",stk,a,act);
check();
}
}
if (stk[i-1]=='E'&& a[0]==' ')
printf("\nAccepted\n");
else
printf("\n Rejected\n");
}

void check()
{
strcpy(ac,"reduce to E");
for(z=0;z<c;z++)
 if(stk[z]=='i'&&stk[z+1]=='d')
{
stk[z]='E';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%sid",stk,a,ac);
j++;
}
for(z=0;z<c;z++)
 if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='E')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("\n$%s\t%s$\t%sid",stk,a,ac);
i=i-2;
}
for(z=0;z<c;z++)
 if(stk[z]=='E'&&stk[z+1]=='*'&&stk[z+2]=='E')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("\n$%s\t%s$\t%sid",stk,a,ac);
i=i-2;
}
for(z=0;z<c;z++)
 if(stk[z]=='('&&stk[z+1]=='E'&&stk[z+2]==')')
{
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("\n$%s\t%s$\t%sid",stk,a,ac);
i=i-2;
}
}




