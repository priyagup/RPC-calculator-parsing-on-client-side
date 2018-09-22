/*
 * @author: Priya Gupta
 * RPC Assignment 1 Arithmetic Calculator Using RPC 
 * L20444930
 */

#include "calculator.h"



int *
add_1_svc(int_inputs *argp, struct svc_req *rqstp)
{
	static int  result;

    result = (argp->num1) + (argp->num2);
    printf("Addition of Integer %d %d\n",argp->num1,argp->num2);
 
	return &result;
}

int *
sub_1_svc(int_inputs *argp, struct svc_req *rqstp)
{
	static int  result;

    result = (argp->num1) - (argp->num2);
	printf("*****************************Version 1*************************************\n");
    printf("Subtraction of Integer %d %d\n",argp->num1,argp->num2);
   
	return &result;
}

int *
mul_1_svc(int_inputs *argp, struct svc_req *rqstp)
{
	static int  result;

    result = (argp->num1) * (argp->num2);
    printf("Multiplication of Integer %d %d\n",argp->num1,argp->num2);
   
	return &result;
}

int *
div_1_svc(int_inputs *argp, struct svc_req *rqstp)
{
	static int  result;

    result = (argp->num1) / (argp->num2);
    printf("Division of Integer %d %d\n",argp->num1,argp->num2);
    

	return &result;
}

int *
sub_v2_nonnegative_1_svc(int_inputs *argp, struct svc_req *rqstp)
{
	static int result;
	
	result = (argp->num1) - (argp->num2);
	printf("*****************************Version 2*************************************\n");
	printf("Subtraction of Integer %d %d\n",argp->num1,argp->num2);
	return (&result);
}



float *
fadd_2_svc(float_inputs *argp, struct svc_req *rqstp)
{
	static float  result;

    result = (argp->num1) + (argp->num2);
    printf("Addition of Float  %f %f\n",argp->num1,argp->num2);

	return &result;
}

float *
fsub_2_svc(float_inputs *argp, struct svc_req *rqstp)
{
	static float  result;

    result = (argp->num1) - (argp->num2);
	printf("*****************************Version 1*************************************\n");
    printf("Subtraction of Float %f %f\n",argp->num2,argp->num1);
 

	return &result;
}

float *
fmul_2_svc(float_inputs *argp, struct svc_req *rqstp)
{
	static float  result;

    result = (argp->num1) * (argp->num2);
    printf("Multiplication of Float %f %f\n",argp->num1,argp->num2);
	
	return &result;
}

float *
fdiv_2_svc(float_inputs *argp, struct svc_req *rqstp)
{
	static float  result;

    result = (argp->num1) / (argp->num2);
    printf("Division of Float %f %f\n",argp->num1,argp->num2);

	return &result;
}

float *
fsub_v2_nonnegative_2_svc(float_inputs *argp, struct svc_req *rqstp)
{
	static float result;

	result = (argp->num1) - (argp->num2);
	printf("*****************************Version 2*************************************\n");
	printf("Subtraction of Float %d %d\n",argp->num1,argp->num2);
	return (&result);
}