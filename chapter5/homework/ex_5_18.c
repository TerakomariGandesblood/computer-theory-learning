//
// Created by kaiser on 18-12-5.
//

double poly(double a[], double x, long degree) {
    long i;
    double result = a[0];
    double xpwr = x;
    for (i = 1; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr = x * xpwr;
    }
    return result;
}

double polyh(double a[], double x, long degree) {
    long i;
    double result = a[degree];
    for (i = degree - 1; i >= 0; i--) {
        result = a[i] + x * result;
    }
    return result;
}

double poly_6_3a(double a[], double x, long degree) {
    long i;
    double result = a[0], result2 = 0, result3 = 0;
    double xpwr = x, xpwr2 = x * x, xpwr3 = x * x * x;
    double xpwr4 = x * x * x * x, xpwr5 = x * x * x * x * x, xpwr6 = x * x * x * x * x * x;
    double x6 = x * x * x * x * x * x;
    for (i = 1; i <= degree - 5; i += 6) {
        result += (a[i] * xpwr + a[i + 1] * xpwr2);
        result2 += (a[i + 2] * xpwr3 + a[i + 3] * xpwr4);
        result3 += (a[i + 4] * xpwr5 + a[i + 5] * xpwr6);

        xpwr *= x6;
        xpwr2 *= x6;
        xpwr3 *= x6;
        xpwr4 *= x6;
        xpwr5 *= x6;
        xpwr6 *= x6;
    }

    for (; i <= degree; i++) {
        result += a[i] * xpwr;
        xpwr *= x;
    }
    return result + result2 + result3;
}
