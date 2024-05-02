#include <iostream>
#include <cmath>
#include <vector>

// Function to convert from Cylindrical to Cartesian coordinates
std::vector<double> cylindricalToCartesian(double rho, double phi, double z) {
    return {rho * cos(phi), rho * sin(phi), z};
}

// Function to convert from Spherical to Cartesian coordinates
std::vector<double> sphericalToCartesian(double r, double theta, double phi) {
    return {
        r * sin(theta) * cos(phi),
        r * sin(theta) * sin(phi),
        r * cos(theta)
    };
}

// Function to convert from Cartesian to Spherical coordinates
std::vector<double> cartesianToSpherical(double x, double y, double z) {
    double r = sqrt(x * x + y * y + z * z);
    double theta = acos(z / r);
    double phi = atan2(y, x);
    return {r, theta, phi};
}

// Function to sum two vectors
std::vector<double> sumVectors(const std::vector<double>& a, const std::vector<double>& b) {
    return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

int main() {
    int n;
    std::cin >> n; // Number of vectors

    std::vector<double> sum = {0, 0, 0}; // Initialize sum vector

    while (n--) {
        char coordType;
        std::cin >> coordType;
        
        std::vector<double> vec(3);
        std::cin >> vec[0] >> vec[1] >> vec[2];

        // Convert to Cartesian coordinates if necessary and sum
        switch (coordType) {
            case 'C': // Cartesian
                sum = sumVectors(sum, vec);
                break;
            case 'c': // Cylindrical
                sum = sumVectors(sum, cylindricalToCartesian(vec[0], vec[1], vec[2]));
                break;
            case 's': // Spherical
                sum = sumVectors(sum, sphericalToCartesian(vec[0], vec[1], vec[2]));
                break;
        }
    }

    // Convert the sum to spherical coordinates
    std::vector<double> result = cartesianToSpherical(sum[0], sum[1], sum[2]);

    std::cout << result[0] << " " << result[1] << " " << result[2] << std::endl;

    return 0;
}
