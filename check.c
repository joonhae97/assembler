#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	char temp[256];
	strcpy(temp, args);

	char *src= strtok(temp, ",");
	char *dest = strtok(NULL, ",");;
	
	if(dest[0]=='$') return 0;
	if((src[0]=='0'||src[0]=='-'||src[0]=='(')&&(dest[0]=='0'||dest[0]=='-'||dest[0]=='(')) return 0;

	return 1;
}
