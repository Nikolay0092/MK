#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y) {
//    return y*y*log(1+x);
    return x*exp(-y);
}

double Func(double x) {
    return log((exp(1) + x*x)/2);
}

int main() {
    double a=1; double h=0.2;
    //double n=(b-a)/h;
    double n=10;
    double X[(int)n];
    double Y1[(int)n];
    double Y2[(int)n];
    double Y3[(int)n];
    double Y4[(int)n];
    double Y[(int)n];
    //calculate
    X[0]=a; Y[0]=1;
    for(int i=1; i<n; i++){
        X[i]=a+i*h;
        Y1[i]=h*F(X[i-1],Y[i-1]);
        Y2[i]=h*F(X[i-1]+h/2.0,Y[i-1]+Y1[i]/2.0);
        Y3[i]=h*F(X[i-1]+h/2,Y[i-1]+Y2[i]/2);
        Y4[i]=h*F(X[i-1]+h,Y[i-1]+Y3[i]);
        Y[i]=Y[i-1]+(Y1[i]+2*Y2[i]+2*Y3[i]+Y4[i])/6;
    }
    //print results
    cout << "metod Runge-Kutte\n";
    cout << "X[i]" << "\t" << "y" << "\t" << "Y[i]=" << "\t" << "F(x[i],y[i])" << "\n";
    for(int i=0; i<n; i++){
        cout <<X[i] <<"\t ";
        cout << Func(X[i]) << "\t";
        cout <<Y[i] << "\t ";
        cout <<F(X[i], Y[i]) << "\n";
    }
//    cout << endl;
//    for(int i=0; i<=n; i++){
//        cout << "Y["<<i<<"]="<<Y[i] << " ";
//    }
    return 0;
}