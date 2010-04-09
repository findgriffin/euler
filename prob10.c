#include "myhead.h"
/* problem 10 
 * the sum of all primes below 2 million
 */

#define N 2000000

int main()
{
    long long sum = 0;
    long long i;
    for (i = 2; i < N; i++){
        if (p_test(i))
            sum+=i;
        if (i%100000 == 0){
            printf("%lld\n",i);
        }
    }
    printf("%lld", sum);
    return 0;
}
