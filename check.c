#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	if(strcmp(op, "mov")!=0) return 0;
	else{
		int count =1;
		char *ptr = strtok(args, ",");
		while(ptr!=NULL){
			count++;
			ptr = strtok(NULL, ",");
		}	

		if(count!=2) return 0;
		else{
			
		}

	} 	
	return 1;
}
