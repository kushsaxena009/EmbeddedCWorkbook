#include <stdio.h>

#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS) //bits in integer

// Use to print the data in binary format
void PrintInBinary(unsigned n)
{
	short int iPos;
	
	for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
	{
	  (n & (1 << iPos))? printf("1"): printf("0");	
	}
	printf("\n");	
}

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
void count_set_bits(int num);
void left_rotate_bits(int num, unsigned int bit);
void right_rotate_bits(int num, unsigned int bit);
void compute_min_max(int a,int b);
void swap_numbers(int num1, int num2);
void clear_bits_from_MSB(int num1, int bit);
void clear_bits_from_LSB(int num1, int bit);

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
    printf("\tEnter  0 to exit application \n");
    printf("\tEnter  1 to check signed of number \n");
    printf("\tEnter  2 to check polarity of two numbers \n");
    printf("\tEnter  3 to check power of two \n");
    printf("\tEnter  4 to set bit of any number \n");
    printf("\tEnter  5 to clear bit of any number \n");
    printf("\tEnter  6 to check particular bit of any number is set or clear \n");
    printf("\tEnter  7 to toggle particular bit of any number \n");
    printf("\tEnter  8 to reverse bits of any number \n");
    printf("\tEnter  9 to count set bits of any number \n");
    printf("\tEnter 10 to rotate bits left \n");
    printf("\tEnter 11 to rotate bits right \n");
    printf("\tEnter 12 to find min and max of 2 numbers \n");
    printf("\tEnter 13 to swap 2 numbers \n");
    printf("\tEnter 14 to clear bits from MSB \n");
    printf("\tEnter 15 to clear bits from LSB \n");
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
        case 9 :
        printf("Enter number to count it's set bits\n");
        scanf("%d",&val1);
        count_set_bits(val1);
        case 10 :
        printf("Enter number to rotate with how much bits to rotate left\n");
        scanf("%d %d",&val1,&val2);
        left_rotate_bits(val1,val2);
        case 11 :
        printf("Enter number to rotate with how much bits to rotate right\n");
        scanf("%d %d",&val1,&val2);
        right_rotate_bits(val1,val2);
        break;
        case 12 :
        printf("Enter two numbers to find minimum and maximum\n");
        scanf("%d %d",&val1,&val2);
        compute_min_max(val1,val2);
        break;
        case 13 :
        printf("Enter two numbers to swap\n");
        scanf("%d %d",&val1,&val2);
        swap_numbers(val1,val2);
        break;
        case 14 :
        printf("Enter number and bit position to clear from MSB\n");
        scanf("%d %d",&val1,&val2);
        clear_bits_from_MSB(val1,val2);
        break;
        case 15 :
        printf("Enter number and bit position to clear from LSB\n");
        scanf("%d %d",&val1,&val2);
        clear_bits_from_LSB(val1,val2);
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
    unsigned int iLoop = 0;
    unsigned int tmp = 0;         //  Assign num to the tmp
    int iNumberLopp = INT_BITS;
    printf("Number entered in binary is\n");
    PrintInBinary(num);
    for(; iLoop < iNumberLopp; ++iLoop)
    {
        if((num & (1 << iLoop))) // check set bits of num
        {
            tmp |= 1 << ((INT_BITS - 1) - iLoop); //putting the set bits of num in tmp
        }
    }
    printf("After reverse bits number is 0X%x\n",tmp);
    PrintInBinary(tmp);
}

void count_set_bits(int num)
{
    int count_num=num,bit_check,s_bit=0;
    bit_check = (sizeof(num)*8);
    printf("Number in Binary formt\n");
    PrintInBinary(num);
    for(int i = 0; i< bit_check ; i++)
    {
        if(num & 1)
        s_bit++;
        num >>= 1;
    }
    
    printf("Number of set bits in number  0X%x : %d\n",count_num,s_bit);
}

void left_rotate_bits(int num, unsigned int bit)
{
    int count_num=num,bit_check,s_bit=0;
    bit_check = (sizeof(num)*8);
    printf("Number in Binary formt\n");
    PrintInBinary(num);
    if(bit>INT_BITS)
    {
        printf("Please enter valid range between 0 to INT_BITS\n");
    }
    else
    {
       count_num = ((num<<bit) | (num>> (INT_BITS-bit))); 
    }
    
    printf("Number after left rotate is  0X%x :\n",count_num);
    printf("Number in Binary formt\n");
    PrintInBinary(count_num);
}

void right_rotate_bits(int num, unsigned int bit)
{
    int count_num=num,bit_check,s_bit=0;
    bit_check = (sizeof(num)*8);
    printf("Number in Binary formt\n");
    PrintInBinary(num);
    if(bit>INT_BITS)
    {
        printf("Please enter valid range between 0 to INT_BITS\n");
    }
    else
    {
       count_num = ((num>>bit) | (num<< (INT_BITS-bit))); 
    }
    
    printf("Number after right rotate is  0X%x :\n",count_num);
    printf("Number in Binary formt\n");
    PrintInBinary(count_num);
}

void compute_min_max(int a,int b)
{
    int min_res, max_res;
    printf("Number in Binary formt\n");
    PrintInBinary(a);
    PrintInBinary(b);
    min_res = (b ^ ((a ^ b) & -(a < b))); // min(a, b)
    max_res = (a ^ ((a ^ b) & -(a < b))); // max(a, b)
    printf("Minimum number is %d\n",min_res);
    printf("Maximum number is %d\n",max_res);
}

void swap_numbers(int num1, int num2)
{
    printf("Numbers before swap are \t%d\t%d\n",num1,num2);
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    // num1 = num1 + num2;
    // num2 = num1 - num2;
    // num1 = num1 - num2;
    printf("Numbers after swap are  \t%d\t%d\n",num1,num2);
}

void clear_bits_from_MSB(int num1, int bit)
{
    int mask = 0;
    printf("Number in binary format\n");
    PrintInBinary(num1);
    if(bit>INT_BITS)
    {
        printf("Please enter valid range between 0 to INT_BITS\n");
    }
    else
    {
        mask = (1<<(bit))-1;
        num1 = num1 & mask;
    }
    printf("Numbers after clear bits  \t%d\n",num1);
    PrintInBinary(num1);
}

void clear_bits_from_LSB(int num1, int bit)
{
    int mask = 0;
    printf("Number in binary format\n");
    PrintInBinary(num1);
    if(bit>INT_BITS)
    {
        printf("Please enter valid range between 0 to INT_BITS\n");
    }
    else
    {
        mask = (1<<(bit))-1;
        num1 = num1 & ~mask;
    }
    printf("Numbers after clear bits  \t%d\n",num1);
    PrintInBinary(num1);
}
