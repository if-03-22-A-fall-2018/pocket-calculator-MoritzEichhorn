/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 2
 * Title:			Pocket Calculator
 * Author:			Eichhorn Moritz
 * ----------------------------------------------------------
 * Description:
 * It's a caclulator with the four basic calculus.
 * ----------------------------------------------------------
 */

#include <stdio.h>
#include <float.h>

void printMenu(){
  printf("Choose one of the following operations: \n");
  printf("  Add (1)\n");
  printf("  Subtract (2)\n");
  printf("  Multiply (3)\n");
  printf("  Divide (4)\n");
  printf("  Stop program (-1)\n");
  printf("Enter your choice: ");
}

void readDecision(int* decision){
  do {
    scanf("%d", decision);
    if((*decision < -1)||(*decision > 4)||(*decision == 0))
    {
      printf("Input not allowed, please try again\n\n");
      printMenu();
    }
  } while((*decision < -1)||(*decision > 4)||(*decision == 0));
}

void readOperands(double* operand_1, double* operand_2){
  printf("Please enter the first operand: ");
  scanf("%lf",operand_1);
  printf("Please enter the second operand: ");
  scanf("%lf",operand_2);
}

void printResult(double operand_1, double operand_2,double result, char computeSign){
  printf("%lf %c %lf = %lf\n\n",operand_1, computeSign, operand_2, result);
}

void add(double operand_1, double operand_2){
  if((operand_1 > 0) && (operand_2 > 0) && ((DBL_MAX - operand_1) < operand_2))
  {
    printf("Number owerflow\n");
  }
  else if((operand_1 < 0) && (operand_2 < 0) && ((DBL_MIN - operand_1) > operand_2))
  {
    printf("Number underflow\n");
  }
  else
  {
    printResult(operand_1, operand_2, operand_1 + operand_2, '+');
  }
}

void subtract(double operand_1, double operand_2){
  if((operand_1 > 0) && (operand_2 < 0) && ((DBL_MAX + operand_2) < operand_1))
  {
    printf("Number owerflow\n");
  }
  else if((operand_1 < 0) && (operand_2 > 0) && ((DBL_MIN + operand_2) > operand_1))
  {
    printf("Number underflow\n");
  }
  else
  {
    printResult(operand_1, operand_2, operand_1 - operand_2, '-');
  }
}

void multiply(double operand_1, double operand_2)
{
  if(((operand_1 < 0) && (operand_2 < 0)) || ((operand_1 < 0) && (operand_2 > 0)))
  {
    operand_1 *= -1;
    operand_2 *= -1;
  }

  if((operand_1 > 0) && (operand_2 > 0) && ((DBL_MAX / operand_1) < operand_2))
  {
    printf("Number owerflow\n");
  }
  else if((operand_1 > 0) && (operand_2 < -1) && ((DBL_MIN / operand_1) > operand_2))
  {
    printf("Number underflow\n");
  }
  else
  {
    printResult(operand_1, operand_2, operand_1 * operand_2, '*');
  }
}

void divide(double operand_1, double operand_2)
{
  if(operand_2 != 0)
  {
    if(((operand_1 <= 0)&&(operand_2 < 0))||((operand_1 <= 0)&&(operand_2 > 0)))
    {
      operand_1 *= -1;
      operand_2 *= -1;
    }

    if(((operand_2 > 0) && (operand_2 < 1)) && ((DBL_MAX * operand_2) < operand_1))
    {
      printf("Number owerflow\n");
    }
    else if(((operand_2 < 0) && (operand_2 > -1)) && ((DBL_MIN * operand_2) > operand_1))
    {
      printf("Number underflow\n");
    }
    else
    {
      printResult(operand_1, operand_2, operand_1 / operand_2, '/');
    }
  }
  else
  {
    printf("Division by zero\n\n");
  }
}

void performOperations(double operand_1, double operand_2, int decision){
  switch (decision) {
    case 1:
      add(operand_1, operand_2);
      break;
    case 2:
      subtract(operand_1, operand_2);
      break;
    case 3:
      multiply(operand_1, operand_2);
      break;
    case 4:
      divide(operand_1, operand_2);
      break;
  }
}

int main(int argc, char const *argv[]) {
  int decision;
  double operand_1;
  double operand_2;

  while(decision != -1)
  {
    printMenu();
    readDecision(&decision);
    if(decision != -1)
    {
      readOperands(&operand_1, &operand_2);
      performOperations(operand_1, operand_2, decision);
    }
  }
  return 0;
}
