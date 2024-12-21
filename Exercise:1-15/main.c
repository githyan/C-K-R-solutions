/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 *
 * */

#include <stdio.h>

float temp_conversion(int a);
int main()
{
  int fahr, result = 0;
  for (fahr = 0; fahr <= 300; fahr = fahr + 20){
    printf("%3d %6.1f\n", fahr, temp_conversion((float) fahr));
  }
}

float temp_conversion(int fahr)
{
  return (5.0 / 9.0) * ((float)fahr - 32.0);
}
