#include "myhead.h"
/* problem 7 
 * find the 10001st prime number
 */

#define N   10001
int main()
{
    long long count;
    int prime_count = 0;
    for(count = 2; prime_count < N; count++){
        if(p_test(count)){ 
            prime_count++;
//            printf("found %lld the %dth prime\n", count, prime_count);
        }
    }
    printf("the %dth prime is %lld\n", N, count - 1);
        
    return 0;
}
