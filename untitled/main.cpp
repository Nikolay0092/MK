#include <iostream>
#include <cmath>
using namespace std;

double F (double x) {
    //return (x - sqrt(log10(x+
    return  (x * sin(x) - 1.23);
}

int main() {
    setlocale(LC_ALL, "Rus"); // поддержка русского языка

    //double x1 = 1, x = F(x1), E = 0.000001; // объявление переменных
    double A, B, M, E = 0.000001, x;

    //cout << "Введите точность: "; cin >> E; // запрашиваем точность
    cout << "interval "; cin >> A >> B;
    cout << "M = "; cin >> M;
    cout << "approach "; cin >> x; // начальное приближение

    if (x == B) {
        B = A; A = x;
    }

    while (F(x) / M > E) {
        x = x - F(x) / (F(x) - F(B)) * (x - B);
    }

    /*while (x-x1 > E) {
        x1 = x; x = F(x1);
    }*/

    cout << "Root Meaning with Surprise " << E << " = " << x << endl;

    cout << "F(x) = " << F(x);

    return 0;
}
