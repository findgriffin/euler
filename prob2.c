#include "myhead.h"
/* problem 
 * sum of all the even numbers in the fibonacci
 * sequence below four million
 */

#define FOUR_MILLION    4000000

int main()
{
    int n = 1;
    long long sum = 0;
    int n1 = 1;
    int n2 = 1;
    while(n < FOUR_MILLION){
        if (n % 2 == 0)
            sum += n;
        n2 = n1;
        n1 = n;
        n = n1 + n2;
    }
    printf("%lld", sum);
    
    return 0;
}
