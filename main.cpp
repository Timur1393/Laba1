#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>

void rectangle() {
    float a, b;
    printf("\nВведите стороны прямоугольника (a b): ");
    scanf("%f %f", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("\nОшибка: стороны прямоугольника должны быть положительными!\n");
        return;
    }

    float perimeter = 2 * (a + b);
    float area = a * b;
    float diagonal = sqrt(a * a + b * b);
    printf("\nПрямоугольник:\nПериметр: %.2f\nПлощадь: %.2f\nДиагональ: %.2f\n", perimeter, area, diagonal);
}
void trapezoid() 
{
    float a, b, c, d;
    printf("\nВведите основания и боковые стороны трапеции (a b c d): ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) 
    {
        printf("\nОшибка: стороны должны быть положительными!\n");
        return;
    }

    float perimeter = a + b + c + d;
    float midLine = (a + b) / 2;
    printf("\nТрапеция:\nПериметр: %.2f\nСредняя линия: %.2f\n", perimeter, midLine);
}
int main() {
    setlocale(LC_ALL, "");
    int choice;

    do {
        printf("\n=== Выберите фигуру ===\n");
        printf("1. Прямоугольник\n");
        printf("2. Треугольник\n");
        printf("3. Трапеция\n");
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            rectangle();
            break;
        case 2:
            triangle();
            break;
        case 3:
            trapezoid();
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}
