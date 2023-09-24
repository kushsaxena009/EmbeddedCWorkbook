#include "Algorithm.h"

typedef unsigned short uint16;
typedef unsigned char uint8;

uint16 hash(uint16 seed,uint8 bit)
{
	return (seed & 0x7FFF) | ((uint16)bit << 15u);
}

uint16 hashAlgo(uint16 seed,uint16 key)
{
	uint16 state=0x72EB;
	uint8 bit;

	int index;
	for(index=0;index < 16;index++)
	{
		bit = (seed & 1u) ^ (state & 1u);
		state = hash(state >> 1,bit);
		seed = seed >> 1;
	}

	for(index=0;index < 16;index++)
	{
		bit = (key & 1u) ^ (state & 1u);
		state = hash(state >> 1,bit);
		key = key >> 1;
	}

	return ((state & 0xFF) << 8u) | ((state & 0xFF00) >> 8u);

}
