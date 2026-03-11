#include <string>
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14156265
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <format>

using namespace std;

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

double squareOfSectorOfCircle (int radius, int alpha = 360){
    double square = radius * radius * alpha * PI /360;
    return square;
}

double lenghtOfCircle (int radius){
    double len = radius * 2 * PI;
    return len;
} 

void circle () {
    double radius;
    double sector;
    cout << "Введите радиус окружности: " << endl;
    if (cin >> radius){
        if (radius <= 0){
            cout << "Радиус должен быть положительным" << endl;
            return;
        }
    } else {
        cout << "Радиус должен быть числом" << endl;
        return;
    }
    cout << "Введите угол сектора в градусах: " << endl;
    if (cin >> sector){
        if (sector <= 0){
            cout << "Сектор должен быть положительным" << endl;
            return;
        }
    } else {
        cout << "Сектор должен быть числом" << endl;
        return;
    }
    double square_Of_Circle = squareOfSectorOfCircle(radius);
    double square_Of_Sector = squareOfSectorOfCircle(radius, sector);
    double lenght_Of_Circle = lenghtOfCircle(radius);
    cout << "Длина окружности = " + to_string(lenght_Of_Circle) + "\nПлощадь сектора (" + to_string(sector) + " градусов) = " + to_string(square_Of_Sector) + "\nПлощадь круга"+to_string(square_Of_Circle) <<endl;
}   

int main() {
    setlocale(LC_ALL, "");
    int choice;

    do {
        printf("\n=== Выберите фигуру ===\n");
        printf("1. Прямоугольник\n");
        printf("2. Треугольник\n");
        printf("3. Трапеция\n");
        printf("4. Окружность\n");
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
        case 4:
            circle();
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