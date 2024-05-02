#include <iostream>
#include <cmath>


int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    // Handle non-quadratic case where a = 0
    if (a == 0) {
        if(b == 0) {
            std::cout << "undefined" << std::endl;
        } else {
            double singleRoot = -c / b;
            std::cout << "1 " << singleRoot << std::endl; // For the bonus point
        }
    } else {
        double discriminant = b*b - 4*a*c;
        // No real roots
        if (discriminant < 0) {
            std::cout << "0" << std::endl;
        }
        // One real root
        else if (discriminant == 0) {
            double x = -b / (2*a);
            std::cout << "1 " << x << std::endl;
        }
        // Two real roots
        else {
            double x1 = (-b + std::sqrt(discriminant)) / (2*a);
            double x2 = (-b - std::sqrt(discriminant)) / (2*a);
            std::cout << "2 " << x1 << " " << x2 << std::endl;
        }
    }

    return 0;
}
