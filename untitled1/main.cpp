#include<iostream>
#include<cmath>
/* defining ordinary differential equation to be solved */
/* In this example we are solving dy/dx = x + y */
//#define f(x,y) y*y*log(1+x)

using namespace std;

double func(double x, double y) {
//    return y*y*log(1+x);
    return x*exp(-y);
}

double Func(double x) {
    return log((exp(1) + x*x)/2);
}

int main() {
    double x0, y0, xn, h, yn, slope;
    int i, n;

//    cout<<"Enter Initial Condition"<< endl;
//    cout<<"x0 = ";
//    cin>> x0;
//    cout<<"y0 = ";
//    cin >> y0;
//    cout<<"Enter calculation point xn = ";
//    cin>>xn;
//    cout<<"Enter number of steps: ";
//    cin>> n;
    x0 = 1;
    y0 = 1;
    xn = 0.2;
    n = 10;
 /* Calculating step size (h) */
 //h = (xn-x0)/n;

 /* Euler's Method */
    cout << "metod Euler\n";
    cout<<"\nx0\ty\ty0\tslope\n";
    cout<<"------------------------------\n";

    for(i=0; i < n; i++) {
        slope = func(x0, y0);
        yn = y0 + xn * slope;
        cout<< x0<<"\t"<< Func(x0) << "\t"<< y0<<"\t"<< slope<< endl;
        y0 = yn;
        x0 = x0 + xn;
    }

 /* Displaying result */
    cout<<"\nValue of y at x = "<< xn<< " is " << yn;

    return 0;
}

