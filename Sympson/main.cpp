#include <iostream>
#include <cmath>
using namespace std;

double func1(double x) {
//    double a = 0.83, b = 1.53;
    return exp(0.73 * x) * sin(1.46 * x);
}

double func2(double x) {
    return 1 / sqrt(x * x + 0.72);
}

int main() {
    double A, B;
    double X = 0, H, S1, S2;
    int N;

//    cout << "Enter the ends of the gap ";
//    cin >> A >> B;
    A = 1;
    B = 2;

    cout << "Enter N \n";
    cin >> N;

    H = (B - A) / N;
    S1 = (func1(A) - func1(B)) / 2;
    S2 = (func2(A) - func2(B)) / 2;
    cout << "i\tx(i)\tF1(xi)\tF2(xi)\n";
    for (int i = 0; i <= N / 2; i++) {
        X = A + 2 * i * H;
        cout << i << "\t" << X << "\t" << func1(X) << "\t" << func2(X) << "\n";
        S1 = S1 + func1(X) + 2 * func1(X - H);
        S2 = S2 + func2(X) + 2 * func2(X - H);
    }

    S1 = S1 * 2 * H / 3;
    S2 = S2 * 2 * H / 3;
    cout << "The value of the integral " << S1 << "\t" << S2 << "\n";

    return 0;
}

//#include <iostream>
//#include <math.h>
//#include <cmath>
//using namespace std;
//typedef double(*pointFunc)(double);
//double f(double x) {
//    double a = 0.83, b = 1.53;
//    return exp(a * x) * sin(b * x);
//}
//double simpson_integral(pointFunc f, double a, double b, int n) {
//    const double h = (b-a)/n;
//    double k1 = 0, k2 = 0;
//    for(int i = 1; i < n; i += 2) {
//        k1 += f(a + i*h);
//        k2 += f(a + (i+1)*h);
//        cout << i << "\t" << k1 << "\t" << k2 << "\t" << h/3*(f(a) + 4*k1 + 2*k2) << "\n";
//    }
//    return h/3*(f(a) + 4*k1 + 2*k2);
//}
//int main() {
//    double a, b, eps;
//    double s1, s;
//    int n = 1; //начальное число шагов
//    cout << "Left edge a = ";
//    cin >> a;
//    cout << "\nRight edge b = ";
//    cin >> b;
//    cout << "\nEps = ";
//    cin >> eps;
//    s1 = simpson_integral(f, a, b, n); //первое приближение для интеграла
//    do {
//        s = s1;     //второе приближение
//        n = 2 * n;  //увеличение числа шагов в два раза,
//        //т.е. уменьшение значения шага в два раза
//        s1 = simpson_integral(f, a, b, n);
//    }
//    while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
//    cout << "\nInteger = " << s1 << endl;
//}