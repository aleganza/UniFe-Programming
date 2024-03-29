/* 

    Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

    Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
    Pentagonal	 	Pn=n(3n−1)/2	1, 5, 12, 22, 35, ...
    Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
    It can be verified that T285 = P165 = H143 = 40755.

    Find the next triangle number that is also pentagonal and hexagonal.

    Result: 1533776805

*/

#include <stdio.h>
#include <stdlib.h>

#define START_TRIANGLE 286
#define START_PENTAGONE 166
#define START_HEXAGONE 144

unsigned long long toTriangle(int n) {
    return (unsigned long long) n*(n+1)/2;
}

unsigned long long toPentagonal(int n) {
    return (unsigned long long) n*(3*n-1)/2;
}

unsigned long long toHexagonal(int n) {
    return (unsigned long long) n*(2*n-1);
}

int main() {
    int t, p, h;
    unsigned long long numberT = 1, 
                       numberP = 1, 
                       numberH = 1;

    for (t=START_TRIANGLE; ; t++) {
        numberT = toTriangle(t);

        for (p=START_PENTAGONE; numberP<=numberT; p++) {
            numberP = toPentagonal(p);
    
            if (numberP == numberT) {
                for (h=START_HEXAGONE; numberH<=numberP; h++) {
                    numberH = toHexagonal(h);

                    if (numberP == numberH) {
                        printf ("Found! (%llu)\nTriangle n: %d\nPentagonal n: %d\nHexagonal n: %d", numberT, t, p, h);
                        exit (0);
                    }
                }
            }
        }
    }

    return 0;
}