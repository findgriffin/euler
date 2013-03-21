#include "../utils/myhead.h"
/* problem 15 
 * how many routes between top left and bottom right corner of a 20x20 grid
 * (without backtracking)
 * turns out this is equivalent to 40 choose 20
 * which is the middle number in the 40th row of pascals triangle
 * factorial method has overflow errors when 21 choose 10 and above
 * recursive method is too slow
 * iterative method is just right, but have no idea how it works
 * it was copied from: http://blog.plover.com/math/choose.html
 */

unsigned long long binomial(unsigned long long n, long long k)
{
        return factorial(n) / factorial(k) / factorial(n-k);
}


unsigned long long binom_r(unsigned long long n, unsigned long long k)
{
        if (k < 0 || k > n)
                return 0;
        if (k == 0 || k == n)
                return 1;
        return binom_r(n-1,k-1) + binom_r(n-1,k);
}

unsigned long long binom_i(unsigned long long n, unsigned long long k)
{
        unsigned long long r = 1;
        unsigned long long d;
        if (k > n)
                return 0;
        for(d = 1; d <= k; d++)
        {
                r *= n--;
                r /= d;
        }
        return r;
}


int main()
{
        int i;
        // show that all the methods are equivalent
        for (i = 1; i <= 22; i++)
                printf("(%d, %d) fact: %lld r: %lld i:%lld\n",i, i/2, binomial(i,i/2), binom_r(i,i/2), binom_i(i,i/2));
        // calculate the answer
        printf("(%d,%d) iterative: %lld\n",40,20,binom_i(40,20));
        return 0;
}
