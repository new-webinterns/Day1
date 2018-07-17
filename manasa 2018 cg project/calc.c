#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a,b;
int c;
float rs;
void main()
{
printf("enter the value of a :");
scanf("%d",&a);
printf("enter the value of b :");
scanf("%d",&b);
printf("enter the choice:\n 1:Addition \n2:Subtraction \n3:Multiplication \n 4:Divison \n:");
scanf("%d",&c);
switch(c)
{
case 1:rs=a+b;
break;
case 2:rs=a-b;
break;
case 3:rs=a*b;
break;
case 4:if(b==0)
{
printf("error");
}
else
{
rs=(float)a/b;
}
break;
default:printf("invalid");
break;
}

printf("the result is =%f",rs);
}

