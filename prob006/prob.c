#include "../utils/myhead.h"
/* problem 6 
 * the difference between the sum of squares of the first 100 natural numbers and the square of the sum
 * 1^2 + 2^2+...+100^2 = a
 * (1+2+...+100)^2 = b
 * ans = b - a
 */

#define N   100

int main()
{
    long long a = 0;
    long long b = 0;
    long long i;
    for (i = 1; i <= N; i++){
        a = a + pow(i,2);
    }
    for (i = 1; i <= N; i++){
        b += i;
    }
    b = my_powl(b,2);
    printf("%lld\n", b-a);
    return 0;
}
