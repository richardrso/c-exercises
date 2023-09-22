#include <stdio.h>
#include <math.h>

int main()
{

    double side1, side2, hypo;
    printf("Enter the length of side 1: ");
    scanf("%lf", &side1);
    printf("Enter the length of side 2: ");
    scanf("%lf", &side2);

    hypo = sqrt(side1 * side1 + side2 * side2);

    printf("The lengh of the hypotenuse is: %.2lf", hypo);

    return 0;
}