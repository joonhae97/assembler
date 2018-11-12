#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");
		
	data src;
	data dest;
	/******tokenizing******/
	src.op = strtok(args, ",");
	dest.op = strtok(NULL, ",");
	/*******src set type**************/
	if(src.op[0]=='$') src.type = imm; 
        else if(src.op[0]=='%') src.type = reg;
        else if(src.op[0]=='-') src.type = mem_disp;
        else if(src.op[0]=='0'){
                if(strchr(src.op, '(')==NULL) src.type = mem_abs;
                else src.type = mem_disp;
        }
        else if(src.op[0]=='(') src.type = mem_rel;
	/********************************/

	/*********dest set type***********/
	if(dest.op[0]=='$') dest.type = imm; 
        else if(dest.op[0]=='%') dest.type = reg;
        else if(dest.op[0]=='-') dest.type = mem_disp;
        else if(dest.op[0]=='0'){
                if(strchr(dest.op, '(')==NULL) dest.type = mem_abs;
                else dest.type = mem_disp;
        }
        else if(dest.op[0]=='(') dest.type = mem_rel;

	/*********************************/
	if(src.type == reg){
		//1. reg to reg
		if(dest.type == reg) strcpy(mcode,"89");
		//5. reg(eax) to mem
		else if(dest.type==mem_abs||dest.type==mem_rel||dest.type==mem_disp) strcpy(mcode, "a3");
	}
	//6. immediate to reg
	else if(src.type == imm){
		if(strcmp(dest.op, "%eax")==0) strcpy(mcode,"b8");
		else if(strcmp(dest.op, "%ecx")==0) strcpy(mcode, "b9");
		else if(strcmp(dest.op, "%edx")==0) strcpy(mcode, "ba");
		else if(strcmp(dest.op, "%ebx")==0) strcpy(mcode, "bb");
		else if(strcmp(dest.op, "%esp")==0) strcpy(mcode, "bc");
		else if(strcmp(dest.op, "%ebp")==0) strcpy(mcode, "bd");
		else if(strcmp(dest.op, "%esi")==0) strcpy(mcode, "be");
		else if(strcmp(dest.op, "%edi")==0) strcpy(mcode, "bf");
	}
		
	else if(dest.type == reg){
		//3.mem(disp) to reg
		if(src.type == mem_disp) strcpy(mcode, "8b");
		else{
			//4. mem to reg(eax)
			if(strcmp(dest.op, "%eax")==0) strcpy(mcode, "a1");
			//2. mem to reg
			else strcpy(mcode, "8b");
		}
	}
	return 1;	
}

