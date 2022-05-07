#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y){
    return  y*y*log(1+x);
}

int main() {
    double a = 1;
//    double b = 1;
    double h = 0.2;
    double slope;
//    double n=(b-a)/h;
    double n = 10;
    double X[(int) n];
    double Y1[(int) n];
    double Y[(int) n];
    //calculate
    X[0] = a;
    Y[0] = 1;
    for (int i = 1; i < n; i++) {
        X[i] = a + i * h;
        Y1[i] = Y[i - 1] + h * F(X[i - 1], Y[i - 1]);
        Y[i] = Y[i - 1] + h * (F(X[i - 1], Y[i - 1]) + F(X[i], Y1[i])) / 2.0;
    }
    //print results
    cout << "metod M-Euler\n";
    for(int i=0; i<n; i++){
        cout << "X["<<i<<"]=" << " " << "Y["<<i<<"]=" << " " << "F(x[i],y[i])" << "\n";
        cout <<X[i] <<"\t ";
        cout <<Y[i] << "\t ";
        cout <<F(X[i], Y[i]) << "\n";
    }
//    for (int i = 0; i <= n; i++) {
//        cout << "X[" << i << "]=" << X[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i <= n; i++) {
//        cout << "Y[" << i << "]=" << Y[i] << " ";
//    }
    return 0;
}