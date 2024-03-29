/* WAP to decode a given 32bit packet information and print the values of different fields.
 * Create a structure with member elements as packet fields as shown below
 *     ADD_MODE   SHORT ADDR   LONG_ADDR   SENSOR     BAT    PAYLOAD  STATUS    CRC 
 *  |--------------------------------------------------------------------------------| 
 *  |  1 Bit   |   2 Bits  |   8 Bits   | 3 Bits | 3 Bits | 12 Bits | 1 Bit | 2 Bits |
 *  |--------------------------------------------------------------------------------|
 *
 *  struct packet
 *  {
 *    crc;
 *    status;
 *    payload;
 *    bat;
 *    sensor;
 *    longAddr;
 *    shortAddr;
 *    addrMode;
 *   }
 *   >> Given o/p is in 32 bits data like 0XFFEEAACC and then fields must be set based on given structure.
 */
#include <stdio.h>
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

typedef struct
{
 uint8_t crc           ;
 uint8_t status        ;
 uint16_t payload      ;
 uint8_t bat           ;
 uint8_t sensor        ;
 uint8_t longAddr      ;
 uint8_t shortAddr     ;
 uint8_t addrMode      ;
}Packet_t;

typedef struct
{
 uint32_t crc           :2;
 uint32_t status        :1;
 uint32_t payload       :12;
 uint32_t bat           :3;
 uint32_t sensor        :3;
 uint32_t longAddr      :8;
 uint32_t shortAddr     :2;
 uint32_t addrMode      :1;
}Packet1_t;

typedef union
{
    uint32_t PacketValue;
    struct{
         uint32_t crc           :2;
         uint32_t status        :1;
         uint32_t payload       :12;
         uint32_t bat           :3;
         uint32_t sensor        :3;
         uint32_t longAddr      :8;
         uint32_t shortAddr     :2;
         uint32_t addrMode      :1;
    }packet;
 
}U_Packet_t;


int main()
{
    uint32_t value=0X0;
    Packet_t dataPack;
    Packet1_t dataPack1;
    U_Packet_t data;
    printf("Enter 32 bit value\n");
    scanf("%x",&value);
    data.PacketValue=value;
    printf("Entered 32 bit value is %#X\n",value);
    dataPack.crc      = (uint8_t)(value  & 0x00000003);//11
    dataPack.status   = (uint8_t)((value  & 0x00000008)>>3);//1000
    dataPack.payload  = (uint16_t)((value & 0x00007FF8)>>3);//111111111111000
    dataPack.bat      = (uint8_t)((value  & 0x00038000)>>15);//111000000000000000
    dataPack.sensor   = (uint8_t)((value  & 0x001C0000)>>18);//111000000000000000000
    dataPack.longAddr = (uint8_t)((value  & 0x1FE00000)>>21);//11111111000000000000000000000
    dataPack.shortAddr= (uint8_t)((value  & 0x60000000)>>29);//1100000000000000000000000000000
    dataPack.addrMode = (uint8_t)((value  & 0x80000000)>>31);//10000000000000000000000000000000
    
    
    
    dataPack1.crc      = (uint8_t)(value & 0x3);
    dataPack1.status   = (uint8_t)((value >> 2) & 1);
    dataPack1.payload  = (uint16_t)((value >> 3) & 0XFFF);
    dataPack1.bat      = (uint8_t)((value >> 15) & 0X7);
    dataPack1.sensor   = (uint8_t)((value >> 18) & 0X7);
    dataPack1.longAddr = (uint8_t)((value >> 21) & 0XFF);
    dataPack1.shortAddr= (uint8_t)((value >> 29) & 0X3);
    dataPack1.addrMode = (uint8_t)((value >> 31) & 0X1);
    
    printf("\nFormat 1 using anding then bitwise shifting\n");
    printf("crc         :%#X\n",dataPack.crc);
    printf("status      :%#X\n",dataPack.status);
    printf("payload     :%#X\n",dataPack.payload);
    printf("bat         :%#X\n",dataPack.bat);
    printf("sensor      :%#X\n",dataPack.sensor);
    printf("longAddr    :%#X\n",dataPack.longAddr);
    printf("shortAddr   :%#X\n",dataPack.shortAddr);
    printf("addrMode    :%#X\n",dataPack.addrMode);
    
    printf("\nFormat 2 using bitwise shifting then anding\n");
    printf("crc         :%#X\n",dataPack1.crc);
    printf("status      :%#X\n",dataPack1.status);
    printf("payload     :%#X\n",dataPack1.payload);
    printf("bat         :%#X\n",dataPack1.bat);
    printf("sensor      :%#X\n",dataPack1.sensor);
    printf("longAddr    :%#X\n",dataPack1.longAddr);
    printf("shortAddr   :%#X\n",dataPack1.shortAddr);
    printf("addrMode    :%#X\n",dataPack1.addrMode);
    
    printf("\nFormat 3 using Union method of bit extraction\n");
    printf("crc         :%#X\n",data.packet.crc);
    printf("status      :%#X\n",data.packet.status);
    printf("payload     :%#X\n",data.packet.payload);
    printf("bat         :%#X\n",data.packet.bat);
    printf("sensor      :%#X\n",data.packet.sensor);
    printf("longAddr    :%#X\n",data.packet.longAddr);
    printf("shortAddr   :%#X\n",data.packet.shortAddr);
    printf("addrMode    :%#X\n",data.packet.addrMode);    
    printf("Size of structure 1 is : %lu\n",sizeof(dataPack));
    printf("Size of structure 2 is : %lu\n",sizeof(dataPack1));
    printf("Size of union 1 is : %lu\n",sizeof(data));

    return 0;
}
