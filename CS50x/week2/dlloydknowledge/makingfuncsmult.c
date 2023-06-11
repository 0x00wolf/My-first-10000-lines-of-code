//making functions

//return-type NAME(argument-list);

//return-type: if multiplying an integer by an integer return type is.. int


//name functions obviously

//NAMING CONVENTIONS - FUNCTION Definitions
    //example add 2 ints
    // int add_two-ints(int a, int b);
    //names are given so that they can be used within the function.

//ex A function to multiply two floating point numbers
float mult_floats(float a, float b);
//semi-colon means that it is a function declaration


//the function version 1:
float mult_floats(float a, float b)
{
    float product = x * y;
    return product;
}


//the function version 2:
float multiply_floats(float a, float b);
//...
float multiply_floats(float a, float b)
{
    return a * b;
}


//ex: Function definition + function for adding two ints
int add_two_ints(int a, int b);

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}


//Variable scope - local and global variables
//local variables can only be used within the function they are created
//global variables can be used by all functions in a program by defining them outside the scope of any function
//local variables in C are passed by value in function calls


