#include <iostream>
#include <cmath>

double eps = 1e-5;

double f(double x){
    return pow(x, 5) - 3*pow(x, 2) + 1;
}

double f_der(double x){
    return 5*pow(x, 4) - 6*x ;
}

// fixed point iteration
double phi(double x){
    return x - 0.1*f(x);
}

double phi_der(double x){
    return x - 0.1*f(x);
}

double iterative_process(double x_0, double n_max){
    double x_prev = x_0;
    double x_next = x_0;
    double err = std::abs(x_next - x_prev);
    int n = 0;

    while ((n < n_max) && ((err > eps) || (std::abs(f(x_prev)) > eps))){
        x_next = phi(x_prev);
        printf("%d    %f     %f     %f\n", n, x_next, x_prev, f(x_next));
        x_prev = x_next;
        ++n;
    }
    return x_next;
}

int main() {
    double x = iterative_process(1.3, 100);
    std::cout << x << std::endl;
    return 0;
}
