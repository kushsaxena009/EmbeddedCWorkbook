#include <stdio.h>

int flag = 99;
void menu(void);
void compute_sign(int num);
void check_opposite_signs(int a,int b);
void check_powerOftwo(int num);
void set_particularBit(int num,int bit);
void clear_particularBit(int num,int bit);

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
    printf("\tEnter 0 to exit application \n");
    printf("\tEnter 1 to check signed of number \n");
    printf("\tEnter 2 to check polarity of two numbers \n");
    printf("\tEnter 3 to check power of two \n");
    printf("\tEnter 4 to set bit of any number \n");
    printf("\tEnter 5 to clear bit of any number \n");
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
        case 3 :
        printf("Please enter a number to check its power \n");
        scanf("%d",&val1);
        check_powerOftwo(val1);
        break;
        case 4 :
        printf("Enter number to set particular bit and also enter set bit\n");
        scanf("%d %d",&val1, &val2);
        set_particularBit(val1,val2);
        break;
        case 5 :
        printf("Enter number to clear particular bit and also enter set bit\n");
        scanf("%d %d",&val1, &val2);
        clear_particularBit(val1,val2);
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

void check_powerOftwo(int num)
{
    int sizecheck;
    sizecheck = sizeof(num);
    for(int i=0;i<(sizecheck*8);i++)
    {
        if(num == 1<<i)
        printf("Given number %d is power of two\n",num);
        else
        printf("Given number %d is not a power of two\n",num);
    }
}

void set_particularBit(int num,int bit)
{
    int bit_check;
    bit_check = (sizeof(num)*8);
    if((bit >= bit_check) || (bit<0))
    {
        printf("Please enter valid bit size which is in range from 0 to %d\n",(bit_check-1));
    }
    else
    {
        num|= (1<<bit);
        printf("Number after bit set is 0X%X\n",num);
    }
}

void clear_particularBit(int num,int bit)
{
    int bit_check;
    bit_check = (sizeof(num)*8);
    if((bit >= bit_check) || (bit<0))
    {
        printf("Please enter valid bit size which is in range from 0 to %d\n",(bit_check-1));
    }
    else
    {
        num&= ~(1<<bit);
        printf("Number after bit clear is 0X%X\n",num);
    }
}
