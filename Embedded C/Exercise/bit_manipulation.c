#include <stdio.h>

int flag = 99;
void menu(void);
void compute_sign(int num);
void check_opposite_signs(int a,int b);
void check_powerOftwo(int num);
void set_particularBit(int num,int bit);
void clear_particularBit(int num,int bit);
void check_particularBit(int num,int bit);
void toggle_particularBit(int num,int bit);
void reverse_bits(int num);

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
    printf("\tEnter 6 to check particular bit of any number is set or clear \n");
    printf("\tEnter 7 to toggle particular bit of any number \n");
    printf("\tEnter 8 to reverse bits of any number \n");
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
        case 6 :
        printf("Enter number to check particular bit set or clear and also enter desired bit\n");
        scanf("%d %d",&val1, &val2);
        check_particularBit(val1,val2);
        break;
        case 7 :
        printf("Enter number to toggle particular bit\n");
        scanf("%d %d",&val1, &val2);
        toggle_particularBit(val1,val2);
        break;
        case 8 :
        printf("Enter number to reverse it's bits\n");
        scanf("%d",&val1);
        reverse_bits(val1);
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

void check_particularBit(int num,int bit)
{
    int bit_check,res=0;
    bit_check = (sizeof(num)*8);
    if((bit >= bit_check) || (bit<0))
    {
        printf("Please enter valid bit size which is in range from 0 to %d\n",(bit_check-1));
    }
    else
    {
        res = ((num>>bit) & 1);
        (res==1) ? (printf("Particular bit of 0X%x is set\n",num)) : (printf("Particular bit of 0X%x is clear\n",num)) ;
    }
}

void toggle_particularBit(int num,int bit)
{
    int bit_check,res=0;
    bit_check = (sizeof(num)*8);
    if((bit >= bit_check) || (bit<0))
    {
        printf("Please enter valid bit size which is in range from 0 to %d\n",(bit_check-1));
    }
    else
    {
        num^= 1<<bit;
        printf("After toggle number is 0X%x\n",num);
    }
}

void reverse_bits(int num)
{
    printf("After reverse bits number is 0X%x\n",(num^0xFFFF));
}
