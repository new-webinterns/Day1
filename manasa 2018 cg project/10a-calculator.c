#include<stdio.h>
void main()
{
char operator;
float num1=0,num2=0,result=0;
printf("\n Simulation of a simple calculator\n");
printf("*****************************************\n");
printf("Enter the two numbers :");
scanf("%f%f",&num1,&num2);
fflush(stdin);
printf("Enter the operator[+,-,*,/] :");
scanf("%s",&operator);
switch(operator)
{
case '+':result=num1+num2;
printf("\n %5.2f%c%5.2f=%5.2f\n",num1,operator,num2,result);
break;
case '-':result=num1-num2;
printf("\n %5.2f%c%5.2f=%5.2f\n",num1,operator,num2,result);
break;
case '*':result=num1*num2;
printf("\n %5.2f%c%5.2f=%5.2f\n",num1,operator,num2,result);
break;
case '/':result=num1/num2;
printf("\n %5.2f%c%5.2f=%5.2f\n",num1,operator,num2,result);
break;
default:printf("error in operator\n");
break;
}
}
