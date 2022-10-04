#include <stdio.h>
/************************  typedef  ************************/
typedef unsigned char uint8;
typedef long long int longint32;

typedef struct signal_s
{
    uint8 signal_position;
    uint8 signal_length;
}signal_t;

/*Unit Test - Set A - classic CAN 8 byte pay load */
uint8 payload_1[8]={
   229,  /* 1 1 1 0   0 1 0 1 */
   72,   /* 0 1 0 0   1 0 0 0 */
   14,   /* 0 0 0 0   1 1 1 0 */
   250,  /* 1 1 1 1   1 0 1 0 */
   228,  /* 1 1 1 0   0 1 0 0 */
   248,  /* 1 1 1 1   1 0 0 0 */
   128,  /* 1 0 0 0   0 0 0 0 */
   130   /* 1 0 0 0   0 0 1 0 */
};

/*Unit Test - Set B - classic CAN 8 byte pay load */
uint8 payload_2[8]={
   229,  /* 1 1 1 0   0 1 0 1 */
   72,   /* 0 1 0 0   1 0 0 0 */
   46,   /* 0 0 1 0   1 1 1 0 */
   250,  /* 1 1 1 1   1 0 1 0 */
   237,  /* 1 1 1 0   1 1 0 1 */
   248,  /* 1 1 1 1   1 0 0 0 */
   191,  /* 1 0 1 1   1 1 1 1 */
   130   /* 1 0 0 0   0 0 1 0 */
};

/*Set A - Signals start bit and length */
signal_t sig_ary_1[7]=
{
    /*signal position, signal length*/
    {5 , 8},/*Signal 1 = 169*/
    {20,14},/*Signal 2 = 15339*/
    {34, 2},/*Signal 3 = 2*/
    {37, 3},/*Signal 4 = 4*/
    {40, 8},/*Signal 5 = 248*/
    {48, 2},/*Signal 6 = 2*/
    {56, 7} /*Signal 7 = 65*/
};

/*Set B - Signals start bit and length */
signal_t sig_ary_2[7]=
{
    /*signal position, signal length*/
    { 2,12},/*Signal 1 = 2386*/
    {18,16},/*Signal 2 = 48107*/
    {34, 3},/*Signal 3 = 5*/
    {37, 2},/*Signal 4 = 2*/
    {39, 9},/*Signal 5 = 504*/
    {48, 7},/*Signal 6 = 95*/
    {55, 8} /*Signal 7 = 193*/
};


/* *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This function will use to determine signal value using signal starting position and signal complete length in bits  *
 * from CAN 8 byte pay load.                                                                                           *
 * Parameter used                                                                                                      *
 *      1- Starting address to access first byte of CAN buffer                                                         *
 *      2- Starting bit of signal position                                                                             *
 *      3- Total length of signal in bits                                                                              *
 * Return value                                                                                                        *
 *      1- Extracted signal from CAN buffer                                                                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * */
longint32 signal_value(uint8* payload, uint8 position, uint8 length)
{
    /* Extract signal value*/
   uint8 i, str_byte, end_byte, str_bit,end_bit;
   longint32 cur_signal;
   str_byte = position / 8; /*To determine start byte from CAN buffer to extract signal value*/
   end_byte = ((position+length)%8?
                                  (position+length)/8:
                                  ((position+length)/8-1)
               ); /*To determine last byte from CAN buffer to extract signal value*/
   str_bit = ((position>7)?
                          ((position % 8)+1):
                          (position+1)
           ); /*To determine start bit of start byte from CAN buffer to extract signal value*/

   end_bit =  (((position+length)>7)?
                                    (((position+length) % 8)?
                                                             ((position+length) % 8):
                                                             (8)):
                                    (position+length)
               ); /*To determine end bit of start byte from CAN buffer to extract signal value*/

   /************************************  bit calculations  *************************************/
   /************************************  for first byte  ***************************************/
   /************************  first byte of signal from can buffer extracted  *******************/
   if(str_byte == end_byte) /* when start byte and end byte for signal extraction are same*/
   {
       cur_signal  = *(payload + str_byte) & (0xff>> (str_bit-1)); /*from start position bit extraction*/
       cur_signal  = cur_signal >> (8-end_bit); /*until end position bit extraction */
   }
   else
   {
       cur_signal  = *(payload + str_byte) & (0xff>> (str_bit-1)); /*from start position bit extraction*/
   }
   /************  for next byte until signal end ***************/
   for(i=(str_byte+1); i<=end_byte; i++)
   {
      if( i == end_byte) /*when current byte and end byte are same*/
      {
        cur_signal = (cur_signal << end_bit) + (*(payload + i) >> (8-end_bit)); /*last byte from CAN buffer, signal extraction*/
      }
      else
      {
        cur_signal  = (cur_signal << 8) + *(payload + i); /*next byte from CAN buffer, signal extraction*/
      }
   }
   return cur_signal; /*final extracted signal*/
}

int main()
{
    longint32 sig_val_1[7],sig_val_2[7]; /*Taken example for two can pay load with different signal*/
    printf("*****************CAN PayLoad Solution***************** \n Assuming system stores value as BigEndian order\n\n");
    printf("Signals extraction from classic CAN 8 Byte buffer for signal set A\n\n");
    for(uint8 i=0;i<=6;i++)
    {
        sig_val_1[i]=signal_value(payload_1, sig_ary_1[i].signal_position,sig_ary_1[i].signal_length);
        printf("Set A : Signal %d = %llu \n",i+1,sig_val_1[i]);
    }
    printf("Signals extraction from classic CAN 8 Byte buffer for signal set B\n\n");
    for(uint8 i=0;i<=6;i++)
    {
        sig_val_2[i]=signal_value(payload_2, sig_ary_2[i].signal_position,sig_ary_2[i].signal_length);
        printf("Set B : Signal %d = %llu \n",i+1,sig_val_2[i]);
    }
    return 0;
}

