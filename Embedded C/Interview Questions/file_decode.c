#include <stdlib.h>
#include <string.h>
#include <fstream>


int main(int argc, char **argv)
{
	FILE * in = fopen(argv[1],"rb");
	FILE * out = fopen(argv[2],"wb");
	unsigned char data;
	while(!feof(in))
	{
		char line_content[50]; 
		char * pData;
		fread(&data, sizeof(data), 1, in);
		pData = (unsigned char *)malloc( data + 1);
		for(int i=0; i<data; i++)
		{
			fread(&line_content[i], sizeof(line_content), 1, in);
			line_content[i] ^= 0xAA;
			pData = line_content;
		}
		
		for(int i=0; i<data; i++)
			fwrite(&line_content[i], sizeof(line_content), 1, in);
		
		pData = NULL;
	}
	
	in = NULL;
	out = NULL;
	return 0;
}
