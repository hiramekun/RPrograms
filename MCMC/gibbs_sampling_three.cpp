#include <iostream>
#include <cmath>

const int niter = 10000;

// ガウス乱数生成
int BoxMuller(double &p, double &q) {
    double pi = 2e0 * asin(1e0);
    double r = (double) rand() / RAND_MAX;
    double s = (double) rand() / RAND_MAX;

    p = sqrt(-2e0 * log(r)) * sin(2e0 * pi * s);
    q = sqrt(-2e0 * log(r)) * cos(2e0 * pi * s);

    return 0;
}


// s(x, y, z) = (x^2 + 2y^2 + 2z^2 + 2xy + 2yz + 2zx) / 2
int main() {
    double A[3][3];
    A[0][0] = 1e0, A[1][1] = 2e0, A[2][2] = 2e0;
    A[0][1] = 1e0, A[0][2] = 1e0, A[1][2] = 1e0;
    A[1][0] = A[0][1], A[2][0] = A[0][2], A[2][1] = A[1][2];

    srand((unsigned) time(nullptr));
    double x = 0e0, y = 0e0, z = 0e0;
    for (int iter = 0; iter < niter; iter++) {
        double sigma, mu;
        double r1, r2;

        // x更新
        sigma = 1e0 / sqrt(A[0][0]);
        mu = -A[0][1] / A[0][0] * y - A[0][2] / A[0][0] * z;
        BoxMuller(r1, r2);
        x = sigma * r1 + mu;

        // y更新
        sigma = 1e0 / sqrt(A[1][1]);
        mu = -A[1][0] / A[1][1] * x - A[1][2] / A[1][1] * z;
        BoxMuller(r1, r2);
        y = sigma * r1 + mu;

        // x更新
        sigma = 1e0 / sqrt(A[2][2]);
        mu = -A[2][0] / A[2][2] * x - A[2][1] / A[2][2] * y;
        BoxMuller(r1, r2);
        z = sigma * r1 + mu;

        if ((iter + 1) % 10 == 0) {
            std::cout << x << "  " << y << "  " << x << std::endl;
        }
    }
    return 0;
}