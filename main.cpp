#include <iostream>
#include <vector>
#include "optimisation.h"
int main() {
    std::vector<std::vector<double>> hessian;
    int n = 5;
    hessian.resize(n);
    for (int i = 0 ; i < n; ++i)
    {
        hessian[i].resize(n);
    }
    std::vector<double> rhs;
    rhs.resize(n);
    std::vector<double> x;
    x.resize(n);
    for (int i = 0; i < n; ++i)
    {
        x[i] = 0;
    }
    x[1] = 0;
    optimisation::solveNewton(hessian, rhs, x);
    return 0;


}
