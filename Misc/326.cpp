#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467 is the largest power of three because of the limitations of int.
        // because three is a prime number the only divisor for 3^19 are 3^0, 3^1, 3^2,..., 3^19.
        // If the remainder = 0 that means n is a divisor of 3^19 and is therefore a power of three.
        return n > 0 && 1162261467 % n == 0;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if ( n <= 0) return false;
        // log10(n) = xlog10(3) <=> log10(n)/log10(3) = x
        // If x is an integer than n is a power of three.
        double x = log10(n)/log10(3);
        return (x == floor(x));
    }
};