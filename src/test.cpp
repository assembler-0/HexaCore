#include <iostream>
#include "../include/boost/boost/math/quadrature/trapezoidal.hpp"

int main() {
    double a = 0;    // Lower limit
    double b = 2;    // Upper limit
    double tol = 1e-6; // Tolerance

    // Inline lambda function for f(x) = x^2
    auto f = [](double x) { return x * x; };

    double result = boost::math::quadrature::trapezoidal(f, a, b, tol);

    std::cout << "The integral is approximately: " << result << std::endl;
    return 0;
}
