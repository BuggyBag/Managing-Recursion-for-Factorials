#include <stdio.h>
#include <stdlib.h>

#define UPPER 12
#define BASE 0     

//base case is 0

typedef struct {  
    int parameter_n; // factorial to be calculated
} TempReg;          // define a type that will sotre the parameter and the address

TempReg stack[16]; //create a stack to store the values that will be returned with recursion
int top = -1; // initialize the top value before the 0 position to increase with every entry
int fact = 1; // constant for the base case factorial

void push(TempReg returnValue) {
    stack[++top] = returnValue; //push to the stack while top moves to the next position
}    //no need to print the full stack

TempReg pop() {
    return stack[top--];  //pop from the stack while top returns 1 position
}

unsigned long long factorial(int *n) {
    TempReg TEMP_REG;
    
    baseCase: // base case for the factorial
    TEMP_REG.parameter_n = *n;
    push(TEMP_REG);  //the last element is being pushed to the stack
    
    if (*n == BASE) {
        TEMP_REG = pop(); // if BaseCase then pop elements to multiply and start recursion
        goto baseCheck;
    } else {
        (*n)--; // if !BaseCase then keep decreasing n until BaseCase
        goto baseCase;
    }
    
    recursion: 
    TEMP_REG = pop();      // pop the next value in the stack to be multiplied
    *n = TEMP_REG.parameter_n;
    fact = *n * fact;            // factorial process

    baseCheck:
    if (top != -1) {                                 // check if the number being
        goto recursion;                             // computed is part of the stack [0,n-1]
    }                                              
                                                         
    return fact;
}

int main() {

  printf("\n\n\t Factorial managing recursion\n\n");
  
  int n;

  do{
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
  
    // Check if the input is negative
    if (n > UPPER) {
      printf("\n Range for this program is [0, 12]. ");
    } else if (n < 0) {
      printf("\n Factorial is not defined for negative numbers.\n\n");
    }
  } while(n < 0 || n > UPPER);


  unsigned long long result = factorial(&n);
  printf("\n Factorial of %d is: %Lu\n", n, result);

  return 0;
}