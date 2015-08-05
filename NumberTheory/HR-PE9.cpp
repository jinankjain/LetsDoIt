#include <bits/stdc++.h>
int main()
{
    unsigned int numTests;
    scanf("%u",&numTests);
    // Finds pythagorean triples of the form: a^2 + b^2 = c^2, a + b + c = n
    //
    // Where:
    //
    // a = i^2-j^2
    // b = 2*i*j
    // c = i^2+j^2
    //
    // Therefore, n = a+b+c = 2*(i^2) + 2*i*j
    while (numTests > 0) {
        unsigned int i = 2;
        unsigned int j = 1;
        unsigned int n;
        long maxProduct = -1;

        scanf("%u",&n);
        while(1) {
            int sumABC = 2*i*i+2*i*j;
            if (sumABC > n) {
                if (j==1)
                    break;
                j=1;
                i++;
            } else {
                if (n % sumABC == 0) {
                    int counter = n / sumABC;
                    long product = 2*i*j*(i*i+j*j)*(i*i-j*j)*
                                    counter*counter*counter;
                    if (maxProduct < product)
                        maxProduct = product;
                }
                if (i>j+1) {
                    j++;
                } else {
                    j=1;
                    i++;
                }
            }
        }
        printf("%li\n", maxProduct);
        numTests--;
    }
    
    return 0;
}