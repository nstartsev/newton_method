//
// Created by мак on 20.03.2023.
//

#include "optimisation.h"
#include <vector>
#include <math.h>
void optimisation::solveNewton(std::vector<std::vector<double>>& hessian, std::vector<double>& rhs, std::vector<double>& x)
{
    /// compute hessian and rhs
    int n = rhs.size();
    double residual = 1.;
    double y;
    double n1 = n - 1;
    std::vector<double> a(n), b(n), step(n);
    while (residual > 0.0001)
    {
        fillData(hessian, rhs, x);
        /// forward
        y = hessian[0][0];
        a[0] = -hessian[0][1] / y;
        b[0] = rhs[0] / y  ;

        for (int i = 1; i < n1; i++) {
            y = hessian[i][i] + hessian[i][i - 1] * a[i - 1];
            a[i] = -hessian[i][i + 1] / y;
            b[i] = (rhs[i] - hessian[i][i - 1] * b[i - 1]) / y;
        }
        /// backward
        step[n1] = (rhs[n1] - hessian[n1][n1 - 1] * b[n1 - 1]) / (hessian[n1][n1] + hessian[n1][n1 - 1] * a[n1 - 1]);
        for (int i = n1 - 1; i >= 0; i--) {
            step[i] = a[i] * step[i + 1] + b[i];
        }
        residual = 0;
        double norm = 0;
        for (int i = 0 ; i < n; ++i)
        {
            norm += step[i] * step[i];
        }
        norm = sqrt(norm);
        for (int i = 0; i < n; ++i)
        {
            residual += step[i] * step[i];
            if (norm > 0.01)
            {
                x[i] += step[i] * 0.01;
            }
            else
            {
                x[i] += step[i];
            }
        }
        residual = sqrt(residual);

    }
}
void optimisation::fillData(std::vector<std::vector<double>>& hessian, std::vector<double>& rhs, std::vector<double>& x)
{
    int n = rhs.size();
    /// f = sum (x_i - x_(i+1))^2 + (x_0 - 1)^2
    /// df/dx_idx_(i+1) = -2
    /// df/dx_i = 2 * x_i
    for (int i = 0; i < n; i++)
    {
        /// compute gradient
        if (i == 0)
        {
            rhs[i] = - (2 * (x[i] - 1) + 2 * (x[i] - x[i + 1]));
        }
        if (i > 0 && i < n - 1)
        {
            rhs[i] = - (2 * (x[i] - x[i-1]) + 2 * (x[i] - x[i-1]));
        }
        if (i == n - 1)
        {
            rhs[i] = - 2 * (x[i] - x[i-1]);
        }
        /// compute hessian
        for (int j = 0; j < n; j++)
        {
            if ((j == (i-1) && i > 0 )|| (j == (i + 1) && i < n-1))
            {
                hessian[i][j] = -2;
            }
            if (j == i)
            {
                hessian[i][j] = (j < (n-1)) ? 4 : 2;
            }
        }
    }
    double tmp;
}