#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// complete this header file
typedef enum{reg, mem_abs, mem_rel, mem_disp, imm} type;
typedef struct data{
	char op; 
	type ty;
}
