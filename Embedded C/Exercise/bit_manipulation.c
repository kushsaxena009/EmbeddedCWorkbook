/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int flag = 99;
void menu(void);
void compute_sign(int num);
void check_opposite_signs(int a,int b);

int main()
{
    printf("welcome to bit manipulation coding stream !!! \n");
    while(flag!=0)
    {
        menu();
    }

    return 0;
}

void menu(void)
{
    int val1, val2, opt = 0;
    printf("*************************************************\n");
    printf("\tEnter 1 to check signed of number \n");
    printf("\tEnter 2 to check polarity of two numbers \n");
    printf("\tEnter 0 to exit application \n\t_______________\n");
    printf("*************************************************\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 0:
        printf("\tExiting application\n");
        flag = 0;
        break;
        case 1 :
        printf("Please enter a number to check \n");
        scanf("%d",&val1);
        compute_sign(val1);
        break;
        case 2 :
        printf("Please enter two numbers to check \n");
        scanf("%d %d",&val1, &val2);
        check_opposite_signs(val1, val2);
        break;
        default:
        printf("Please enter valid option \n");
    }
}

void compute_sign(int num)
{
    int check = 0;
    check = (unsigned int)((num>>31) == 0);
    if(check)
    printf("Number is positive \n");
    else
    printf("Number is negative \n");
}

void check_opposite_signs(int a,int b)
{
    int check=0;
    check = (((a>>31) & 1) ^ ((b>>31) & 1));
    if(check)
    printf("Both numbers are different polarity\n");
    else
    printf("Both numbers are same polarity\n");
}
