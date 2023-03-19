//
// Created by мак on 20.03.2023.
//

#ifndef SOLVEHESSIAN_OPTIMISATION_H
#define SOLVEHESSIAN_OPTIMISATION_H
#include <iostream>

class optimisation {
public:
    static void solveNewton(std::vector<std::vector<double>>& hessian, std::vector<double>& rhs, std::vector<double>& x);
    static void fillData(std::vector<std::vector<double>>& hessian, std::vector<double>& rhs, std::vector<double>& x);
};


#endif //SOLVEHESSIAN_OPTIMISATION_H
