#include <iostream>
#include <cmath>
#include <clocale>
#include <limits>

using namespace std;

const double PI = 3.14159265358979323846;

// ---------- Вспомогательная функция для безопасного ввода числа ----------
template<typename T>
bool inputNumber(T& value, const string& prompt) {
    cout << prompt;
    if (cin >> value) {
        return true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: введите число.\n";
        return false;
    }
}

// ---------- Прямоугольник ----------
void rectangle() {
    double a, b;
    if (!inputNumber(a, "Введите стороны прямоугольника (a b): ")) return;
    if (!inputNumber(b, "")) return;

    if (a <= 0 || b <= 0) {
        cout << "Ошибка: стороны прямоугольника должны быть положительными!\n";
        return;
    }

    double perimeter = 2 * (a + b);
    double area = a * b;
    double diagonal = sqrt(a * a + b * b);

    cout << "\nПрямоугольник:\n"
         << "Периметр: " << perimeter << "\n"
         << "Площадь: " << area << "\n"
         << "Диагональ: " << diagonal << "\n";
}

// ---------- Трапеция ----------
void trapezoid() {
    double a, b, c, d;
    cout << "Введите основания и боковые стороны трапеции (a b c d): ";
    if (!(cin >> a >> b >> c >> d)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: введите четыре числа.\n";
        return;
    }

    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        cout << "Ошибка: стороны должны быть положительными!\n";
        return;
    }

    double perimeter = a + b + c + d;
    double midLine = (a + b) / 2;

    cout << "\nТрапеция:\n"
         << "Периметр: " << perimeter << "\n"
         << "Средняя линия: " << midLine << "\n";
}

// ---------- Треугольник ----------
void triangle() {
    double a, b, c;
    cout << "Введите стороны треугольника: ";
    if (!(cin >> a >> b >> c)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: введите три числа.\n";
        return;
    }

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Ошибка: стороны треугольника должны быть положительными!\n";
        return;
    }

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Ошибка: треугольника с такими сторонами не бывает!\n";
        return;
    }

    double perimeter = a + b + c;
    double semiperimeter = perimeter / 2;
    double area = sqrt(semiperimeter * (semiperimeter - a) *
                      (semiperimeter - b) * (semiperimeter - c));

    bool isIsosceles = (a == b || a == c || b == c);

    cout << "\nТреугольник\n"
         << "Периметр: " << perimeter << "\n"
         << "Площадь (по формуле Герона): " << area << "\n"
         << (isIsosceles ? "Треугольник равнобедренный.\n" : "Треугольник не равнобедренный.\n");
}

// ---------- Круг ----------
double squareOfSectorOfCircle(double radius, double angleDegrees = 360.0) {
    return radius * radius * angleDegrees * PI / 360.0;
}

double lengthOfCircle(double radius) {
    return 2.0 * PI * radius;
}

void circle() {
    double radius;
    if (!inputNumber(radius, "Введите радиус окружности: ")) return;
    if (radius <= 0) {
        cout << "Радиус должен быть положительным.\n";
        return;
    }

    double angle;
    if (!inputNumber(angle, "Введите угол сектора в градусах (0 < угол < 360): ")) return;
    if (angle <= 0 || angle >= 360) {
        cout << "Угол должен быть в интервале (0, 360).\n";
        return;
    }

    double fullCircleArea = squareOfSectorOfCircle(radius);
    double sectorArea = squareOfSectorOfCircle(radius, angle);
    double circumference = lengthOfCircle(radius);

    cout << "\nДлина окружности = " << circumference << "\n"
         << "Площадь круга = " << fullCircleArea << "\n"
         << "Площадь сектора (" << angle << "°) = " << sectorArea << "\n";
}

// ---------- Главное меню ----------
int main() {
    setlocale(LC_ALL, "");
    int choice;

    do {
        cout << "\n=== Выберите фигуру ===\n"
             << "1. Прямоугольник\n"
             << "2. Треугольник\n"
             << "3. Трапеция\n"
             << "4. Круг\n"
             << "0. Выход\n"
             << "Ваш выбор: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Введите число от 0 до 4.\n";
            continue;
        }

        switch (choice) {
            case 1: rectangle(); break;
            case 2: triangle();  break;
            case 3: trapezoid(); break;
            case 4: circle();    break;
            case 0: cout << "Выход из программы.\n"; break;
            default: cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
