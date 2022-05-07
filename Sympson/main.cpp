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
