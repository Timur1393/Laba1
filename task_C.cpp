#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>

void trapezoid() 
{
    float a, b, c, d;
    printf("\n¬ведите основани€ и боковые стороны трапеции (a b c d): ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) 
    {
        printf("\nќшибка: стороны должны быть положительными!\n");
        return;
    }

    float perimeter = a + b + c + d;
    float midLine = (a + b) / 2;
    printf("\n“рапеци€:\nѕериметр: %.2f\n—редн€€ лини€: %.2f\n", perimeter, midLine);
}
