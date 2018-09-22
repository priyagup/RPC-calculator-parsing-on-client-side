/*
 * @author: Priya Gupta
 * RPC Assignment 1 Arithmetic Calculator Using RPC 
 * L20444930
 */

#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * In case we need to convert the values returned by the server to string for printing
 */

#define STR_SIZE_INT ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)
#define STR_SIZE_FLOAT ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)

/*
 * Function that takes a float and checks if it's an int.
 * Requires -lm option while linking
 */
int
intchecker(float x)
{
    if (floor(x)==x && ceilf(x)==x) {
        return 1;
    }
    else {
        return 0;
    }

}

/*
 * Integer program version
 */

int
calculate_prog_1(char *host,int n1,int n2,char opr,CLIENT *clnt)
{
	int  *result_1;
	int_inputs  add_1_arg;
	int  *result_2;
	int_inputs  sub_1_arg;
	int  *result_3;
	int_inputs  mul_1_arg;
	int  *result_4;
	int_inputs  div_1_arg;
	int  *result_5;
	int_inputs  sub_v2_nonnegative_1_arg;

	if(opr=='+'){ 
	
        add_1_arg.num1=n1;
        add_1_arg.num2=n2;
        add_1_arg.operator=opr;
  
        result_1 = add_1(&add_1_arg, clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
        return *result_1;
  }
 
    else if(opr=='-'){
 
			if(n1>n2){
					sub_1_arg.num1=n1;
					sub_1_arg.num2=n2;
					sub_1_arg.operator=opr;
			  
					result_2 = sub_1(&sub_1_arg, clnt);
					if (result_2 == (int *) NULL) {
						clnt_perror (clnt, "call failed");
					}
					return *result_2;
			}
			else{
				
					sub_v2_nonnegative_1_arg.num1=n1;
					sub_v2_nonnegative_1_arg.num2=n2;
					sub_v2_nonnegative_1_arg.operator=opr;
			  
					result_5 = sub_v2_nonnegative_1(&sub_v2_nonnegative_1_arg, clnt);
					if (result_5 == (int *) NULL) {
						clnt_perror (clnt, "call failed");
					}
					return *result_5;
				
			}
			
	
   }
 
    else if(opr=='*'){
 
        mul_1_arg.num1=n1;
        mul_1_arg.num2=n2;
        mul_1_arg.operator=opr;
  
        result_3 = mul_1(&mul_1_arg, clnt);
		if (result_3 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
        return *result_3;
    }

 
    else if(opr=='/'){
 
        div_1_arg.num1=n1;
        div_1_arg.num2=n2;
        div_1_arg.operator=opr;
  
        if(n2 == 0){
            printf("ERROR: Division by zero.\n");
            return (-1);
        }else{
  
            result_4 = div_1(&div_1_arg, clnt);
			if (result_4 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}		
            return *result_4;
        }
    }	
}

/*
 * Float program version
 */

float
calculate_prog_2(char *host,float n1,float n2,char opr,CLIENT *clnt)
{
	float  *result_1;
	float_inputs  fadd_2_arg;
	float  *result_2;
	float_inputs  fsub_2_arg;
	float  *result_3;
	float_inputs  fmul_2_arg;
	float  *result_4;
	float_inputs  fdiv_2_arg;
	float  *result_5;
	float_inputs fsub_v2_nonnegative_2_arg;

	if(opr=='+'){ 
        fadd_2_arg.num1=n1;
        fadd_2_arg.num2=n2;
        fadd_2_arg.operator=opr;
  
        result_1 = fadd_2(&fadd_2_arg, clnt);
		if (result_1 == (float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
        return *result_1;
    }
 
    else if(opr=='-'){
 
			if(n1>n2){
				fsub_2_arg.num1=n1;
				fsub_2_arg.num2=n2;
				fsub_2_arg.operator=opr;
		  
				result_2 = fsub_2(&fsub_2_arg, clnt);
				if (result_2 == (float *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				return *result_2;
	}
	
	else{
		
		fsub_v2_nonnegative_2_arg.num1=n1;
        fsub_v2_nonnegative_2_arg.num2=n2;
        fsub_v2_nonnegative_2_arg.operator=opr;
  
        result_5 = fsub_v2_nonnegative_2(&fsub_v2_nonnegative_2_arg, clnt);
		if (result_5 == (float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
        return *result_5;
		}
    }
 
    else if(opr=='*'){
 
        fmul_2_arg.num1=n1;
        fmul_2_arg.num2=n2;
        fmul_2_arg.operator=opr;
  
        result_3 = fmul_2(&fmul_2_arg, clnt);
		if (result_3 == (float *) NULL) {
			clnt_perror (clnt, "call failed");
		}
        return *result_3;
    }

 	/*
 	 * Shows error in case of division by zero
	 * but execution continues
 	 */
    else if(opr=='/'){
 
        fdiv_2_arg.num1=n1;
        fdiv_2_arg.num2=n2;
        fdiv_2_arg.operator=opr;
  
        if(n2 == 0){
            printf("ERROR: Division by zero\n");
            return (-1);
        }else{
  
            result_4 = fdiv_2(&fdiv_2_arg, clnt);
			if (result_4 == (float *) NULL) {
				clnt_perror (clnt, "call failed");
			}
            return *result_4;
        }
    }
	
	else if (opr !='+' && opr!='-' &&  opr!='*' &&  opr!='/') {
		printf("ERROR: ******* Operator not supported *******Please use correct operator like + , - , * ,  /.\n");
	}
}
/*
Input file optional and distinguish between floats and int 
Needs space between numbers and operand
 */

int
main (int argc, char *argv[])
{
	char *host;
	CLIENT *intclient;
	CLIENT *floatclient;

	float fValnum1, fValnum2;
	int iValnum1, iValnum2;
    char op;

	if (argc < 2) {
		printf ("USAGE: %s <Server_HOSTNAME> <OPTIONAL: Input File>\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	
	/*
	 * Create the client handles used for 
 	 * calling CALCULATE_PROG on the server
	 * from the command line.
	 */

	intclient = clnt_create (host, CALCULATE_PROG, INT_CALCULATE_VER, "udp");
	if (intclient == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	floatclient = clnt_create (host, CALCULATE_PROG, FLOAT_CALCULATE_VER, "udp");
	if (floatclient == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	/*
	 * In case of error in establishing connection
     * with server, Print error message and die.
	 */

	/*
	 * Check if an input file was supplied
	 * If not, then call the required remote procedure
	 * on the server
	 */

	if (argv[2] == NULL){
		scanf("%f %s %f", &fValnum1, &op, &fValnum2);

		/*
		 * Checking if input values are floats or integers
		 * If even one value is float, shift execution
		 * to FLOAT_CALCULATE_VER
		 */

		if (intchecker(fValnum1) == 1 && intchecker(fValnum2) == 1){
			iValnum1 = (int) fValnum1;
			iValnum2 = (int) fValnum2;

			printf("Total: %d\n",calculate_prog_1 (host,iValnum1,iValnum2,op,intclient));
		}

		else{
			printf("Total: %f\n",calculate_prog_2 (host,fValnum1,fValnum2,op,floatclient));
		}
				
	}

	else{
		FILE * fp;
    	char * line = NULL;
    	size_t length = 0;
    	ssize_t readfile;
    	fp = fopen(argv[2], "r");
    	if (fp == NULL)
        	exit(EXIT_FAILURE);
    	while ((readfile = getline(&line, &length, fp)) != -1) {
			
			 /* Parse each line in file to the format <number1 operand <number2> */
			sscanf(line, "%f %s %f", &fValnum1, &op, &fValnum2);
			printf("\nOperation needs perform: %s", line); 
		     /* Checking which version of program needs to call float(FLOAT_CALCULATE_VER) or int(INT_CALCULATE_VER) 
				If even one value is float, shift execution to FLOAT_CALCULATE_VER
		 	 */
        	if (intchecker(fValnum1) == 1 && intchecker(fValnum2) == 1){
				iValnum1 = (int) fValnum1;
				iValnum2 = (int) fValnum2;
				printf("Total: %d\n",calculate_prog_1 (host,iValnum1,iValnum2,op,intclient));
			}
			else{
				printf("Total: %f\n",calculate_prog_2 (host,fValnum1,fValnum2,op,floatclient));
			}
    	}
    	fclose(fp);
	}
	clnt_destroy (intclient);
	clnt_destroy (floatclient);
	exit (EXIT_SUCCESS);
}
