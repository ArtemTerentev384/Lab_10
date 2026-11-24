#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "Source.h"

void NumberOne();
double fa(double x);
double fb(double x);

void NumberTwo();
double tan_n(double x, int N);
double tan_eps(double x, double eps);

void HomeWork();
float area_figure(float a, float b, float c, float d);
void print_definition();
void draw_figure(int a, int b, int c, int d, char symbol);


int main() {
    setlocale(LC_ALL, "RUS");

    //NumberOne();
    //NumberTwo();
    HomeWork();

    return 0;
}

void NumberOne()
{
    double x, val_fa, val_fb;
    int choice;

    printf("Введите значение x: ");
    scanf_s("%lf", &x);

    val_fa = fa(x);
    val_fb = fb(x);

    // 4. Добавьте в программу меню для выбора расчета
    printf("\n--- Меню ---\n");
    printf("1. Рассчитать значение функции F1(x)\n");
    printf("2. Рассчитать значение функции F2(x)\n");
    printf("3. Рассчитать произведение, разность квадратов и удвоенную сумму\n");
    printf("Выберите пункт (1-3): ");
    scanf_s("%d", &choice);

    printf("\n");

    switch (choice) {
    case 1:
        printf("F1(x) = %lf\n", val_fa);
        break;
    case 2:
        printf("F2(x) = %lf\n", val_fb);
        break;
    case 3:
        printf("F1(x) = %lf, F2(x) = %lf\n", val_fa, val_fb);

        printf("Произведение: %lf\n", val_fa * val_fb);
        printf("Разность квадратов: %lf\n", (val_fa * val_fa) - (val_fb * val_fb));
        printf("Удвоенная сумма: %lf\n", 2 * (val_fa + val_fb));
        break;
    default:
        printf("Неверный выбор.\n");
    }
}

double fa(double x) {
    double y;
    // Вычисление значения функции
    if (x <= 3) {
        y = x * x - 3 * x + 9;
    }
    else {
        y = 1.0 / (x * x * x + 3);
    }
    return y;
}

double fb(double x) {
    double y;
    // Вычисление значения функции F2
    // x * e^(sin(x^2))
    y = x * exp(sin(x * x));
    return y;
}



void NumberTwo()
{
    double x, eps;
    int N;

    printf("Введите значение x (радианы): ");
    scanf_s("%lf", &x);

    printf("Введите количество членов ряда N: ");
    scanf_s("%d", &N);

    printf("Введите точность eps (например, 0.0001): ");
    scanf_s("%lf", &eps);

    printf("\n--- Результаты ---\n");

    // 1. Стандартная функция
    double std_res = tan(x);
    printf("1. Стандартная функция tan(x): %.6lf\n", std_res);

    // 2. Сумма N членов
    double n_res = tan_n(x, N);
    printf("2. Сумма %d членов ряда:       %.6lf\n", N, n_res);

    // 3. С заданной точностью
    double eps_res = tan_eps(x, eps);
    printf("3. С точностью %.4lf:          %.6lf\n", eps, eps_res);

    printf("\n--- Отклонения ---\n");
    printf("Отклонение (N членов): %.6lf\n", fabs(std_res - n_res));
    printf("Отклонение (eps):      %.6lf\n", fabs(std_res - eps_res));
}

double tan_n(double x, int N) {
    double sum = 0.0;
    double term = x; // Первый член ряда
    double x2 = x * x;

    double num[] = { 1, 1, 2, 17, 62, 1382, 21844, 929569 }; // Числители
    double den[] = { 1, 3, 15, 315, 2835, 155925, 6081075, 638512875 }; // Знаменатели


    double current_x_power = x; // x^1
    for (int k = 1; k <= N; k++) {
        double coef = 0;

        if (k - 1 < 8) {
            coef = num[k - 1] / den[k - 1];
        }
        else {
            coef = 1.0;
        }

        term = coef * current_x_power;
        sum += term;

        current_x_power *= x2;
    }

    return sum;
}

// 3. Функция вычисления с заданной точностью eps (через ряд)
double tan_eps(double x, double eps) {
    double sum = 0.0;
    double term = x; // Первый член
    double x2 = x * x;
    int k = 1;

    // Используем ту же логику с коэффициентами
    double num[] = { 1, 1, 2, 17, 62, 1382, 21844, 929569 };
    double den[] = { 1, 3, 15, 315, 2835, 155925, 6081075, 638512875 };

    double current_x_power = x;

    while (fabs(term) > eps) {
        double coef;
        if (k - 1 < 8) {
            coef = num[k - 1] / den[k - 1];
        }
        else {
            // Для больших k можно использовать рекурсию, но оставим 1 для простоты
            coef = 1.0;
        }

        term = coef * current_x_power;
        sum += term;

        current_x_power *= x2;
        k++;

        // Защита от бесконечного цикла
        if (k > 100) break;
    }

    return sum;
}



void HomeWork()
{
    int choice;
    float a, b, c, d;
    char symbol;

    printf("Введите параметры фигуры:\n");
    printf("Ширина левого прямоугольника (a): ");
    scanf_s("%f", &a);
    printf("Высота верхней части (b): ");
    scanf_s("%f", &b);
    printf("Ширина центрального прямоугольника (c): ");
    scanf_s("%f", &c);
    printf("Высота нижней части (d): ");
    scanf_s("%f", &d);

    do {
        printf("\n--- Меню ---\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nПлощадь фигуры: %.2f\n", area_figure(a, b, c, d));
            break;
        case 2:
            print_definition();
            break;
        case 3:
            printf("Введите символ для рисования (например, *): ");
            scanf_s(" %c", &symbol);
            draw_figure((int)a, (int)b, (int)c, (int)d, symbol);
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный ввод. Попробуйте снова.\n");
        }
    } while (choice != 0);
}
float area_figure(float a, float b, float c, float d) {
    return (a * b) + (c * b) + (c * d);
}

void print_definition() {
    printf("\n--- Определение фигуры ---\n");
    printf("Фигура состоит из трех прямоугольников:\n");
    printf("1. Левый верхний прямоугольник (ширина a, высота b)\n");
    printf("2. Центральный верхний прямоугольник (ширина c, высота b)\n");
    printf("3. Нижний центральный прямоугольник (ширина c, высота d)\n");
    printf("Фигура напоминает несимметричный крест.\n\n");
}

void draw_figure(int a, int b, int c, int d, char symbol) {
    printf("\n--- Рисунок фигуры ---\n");

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("%c", symbol);
        }
        for (int j = 0; j < c; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }


    for (int i = 0; i < d; i++) {
        for (int j = 0; j < a; j++) {
            printf(" ");
        }
        for (int j = 0; j < c; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
    printf("\n");
}