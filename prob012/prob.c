#include "myhead.h"
/* problem 12 
 * first triangle number to have over five hundred divisors
 */

#define N 500
#define SIZE 800000

int factors(long long num){
    printf("factorising %lld\n", num);
    int i = 0;
    long long n;
    for(n = 1; n <= (long long) num/2; n++){
        if (num % n == 0)
            i++;
    }
    printf("found %d factors\n", i);
    return i;
}



int main()
{
    long long tri[SIZE];
    int i;
    tri[0] = 1;
    for (i=1; i < SIZE; i++){
        tri[i] = tri[i-1] + i + 1;
    }

    printf("%lld has %d factors\n", tri[SIZE/10], factors(tri[SIZE/10]));
    int facts = 0;
    int mul = SIZE/2000;
    for (i = 1000; facts < N && i < SIZE; i += mul){
        facts = factors(tri[i]);
        if (facts > N && mul > 1){
            i -= mul;
            mul = mul/10;
            facts = 0;
        }
        else if (facts > N){
            printf("tri[%d]=%lld has %d factors", i, tri[i], facts);

        }
    }
        


    return 0;
}
