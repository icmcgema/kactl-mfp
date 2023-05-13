/**
 * Author: Fakhoury
 * Date: 2023
 * License: CC0
 * Source: ?
 * Description: Ternary search on a function. Get the minimum or maximum of a parabola, for example.
 * Time: $O(\log (hi - lo))$
 */
#pragma once
const double EPS = 1e-9;

// function f() to be defined. Can be int as well
double f(double x) { ... }
double maximum(double lo, double hi) {
    while (hi - lo > EPS) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = lo + 2.0 * (hi - lo) / 3.0;
        if (f(m1) < f(m2)) lo = m1;
        else hi = m2;
    }
    return (lo + hi) / 2;
}
double minimum(double lo, double hi) {
    while (hi - lo > EPS) {
        double m1 = lo + (hi - lo) / 3.0;
        double m2 = lo + 2.0 * (hi - lo) / 3.0;
        if (f(m1) < f(m2)) hi = m2;
        else lo = m1;
    }
    return (lo + hi) / 2.0;
}
// F(x) has to be strictly incr. or decr. where x is not max
int maximum(int lo, int hi) {
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1)) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
// F(x) has to be strictly incr. or decr. where x is not min
int minimum(int lo, int hi) {
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1)) hi = mi;
        else lo = mi + 1;
    }
    return lo;
}
