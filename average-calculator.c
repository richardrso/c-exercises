#include <stdio.h>
int main()
{
    float num1, num2;
    printf("Enter the first number:");
    scanf("%f", &num1);
    printf("Enter the second number:");
    scanf("%f", &num2);
    float average = (num1 + num2) / 2;
    printf("The arithmetic mean is: %.2f", average);
    return 0;
}