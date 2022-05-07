#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double func(double x) {
//    return x * sqrt(x + 1);
//    return x * cos(x * x);
//    return exp(0.73 * x) * sin(1.46 * x);
    return 1 / sqrt(x * x + 0.72);
}

double rand(double b, double e)
{
    return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000.;
}

int main() {
    double A, B;
    double x, h, S;
    int i, n;

//    A = 0; B = 1;
//    A = 0.4; B = 1.2;
    A = 1; B = 2;

    srand(static_cast<unsigned int>(time(NULL)));

    n = 100;

    h = (B - A) / n;
    S = 0;

    cout << "i\tx(i)\tF1(xi)\n";
    for (i = 0; i <= n; i++) {
        x = rand(A, B);
        cout << i << "\t" << x << "\t" << func(x)  << "\n";
        S = S + func(x) * h;
    }
    cout << "integer\t" << S << "\n";
    return 0;
}
