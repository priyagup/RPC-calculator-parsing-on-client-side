struct int_inputs{
    int num1;
    int num2;
    char operator;
};

struct float_inputs{
    float num1;
    float num2;
    char operator;
};
 
program CALCULATE_PROG{
    version INT_CALCULATE_VER{
        int ADD(int_inputs)     = 1;
        int SUB(int_inputs)     = 2;
        int MUL(int_inputs)     = 3;
        int DIV(int_inputs)     = 4;
	int SUB_v2_NONnegative(int_inputs) = 5;
    } = 1;
    version FLOAT_CALCULATE_VER{
        float FADD(float_inputs) = 1;
        float FSUB(float_inputs) = 2;
        float FMUL(float_inputs) = 3;
        float FDIV(float_inputs) = 4;
	float FSUB_v2_NONnegative(float_inputs) = 5;
		
    } = 2;
} = 0x31415926;