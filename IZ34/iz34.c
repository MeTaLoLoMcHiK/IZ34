#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <locale.h>


double f_x(double x) {
    if (x < -3)
        return x * x + 1;
    else if (x <= 3)
        return 2 * x + 1;
    else
        return 3;
}

double f_xy(double x, double y) {
    return (x + y) / sqrt(x - y);
}

int main() {
    setlocale(LC_ALL, "RU");
    
    double a, b, h_x, c, d, h_y;
    double x, y;

    printf("������� ��������� �������� x (a): ");
    scanf("%lf", &a);
    printf("������� �������� �������� x (b): ");
    scanf("%lf", &b);
    printf("������� ��� ��� x (h_x): ");
    scanf("%lf", &h_x);

    double min_fx = DBL_MAX, max_fx = DBL_MIN;

    printf("\n������� �������� y = f(x):\n");
    printf("x\tf(x)\n");
    for (x = a; x <= b; x += h_x) {
        double fx = f_x(x);
        printf("%lf\t%lf\n", x, fx);

        if (fx < min_fx) min_fx = fx;
        if (fx > max_fx) max_fx = fx;
    }
    printf("������� f(x): %lf\n", min_fx);
    printf("�������� f(x): %lf\n\n", max_fx);
    printf("������� ��������� �������� y (c): ");
    scanf("%lf", &c);
    printf("������� �������� �������� y (d): ");
    scanf("%lf", &d);
    printf("������� ��� ��� y (h_y): ");
    scanf("%lf", &h_y);

    double min_fxy = DBL_MAX, max_fxy = DBL_MIN;

    printf("\n������� �������� z = f(x, y):\n");
    printf("x\ty\tf(x, y)\n");
    for (x = a; x <= b; x += h_x) {
        for (y = c; y <= d; y += h_y) {
           
            if (x == y) continue;

            double fxy = f_xy(x, y);
            printf("%lf\t%lf\t%lf\n", x, y, fxy);

          
            if (fxy < min_fxy) min_fxy = fxy;
            if (fxy > max_fxy) max_fxy = fxy;
        }
    }
    printf("������� f(x, y): %lf\n", min_fxy);
    printf("�������� f(x, y): %lf\n", max_fxy);

    return 0;
}
