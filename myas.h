#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// complete this header file
typedef enum what{reg, mem_abs, mem_rel, mem_disp, imm} what;
typedef struct data{
	char* op; 
	what type;//mem or reg
}data;

int instr_trans(char *op, char *args, char *mcode);
int is_valid(char *op, char *args);
