#include "myhead.h"
/* problem 3 
 * find th largest prime factor of NUMBER
 */

 #define NUMBER          600851475143
// #define NUMBER          341113195
#define NO_OF_FACTORS   100000


int p_test(long long num)
{
    /* a test for primality */
    long long i = 2;
    long long sqrt_num = sqrt(num);
//    printf("about to start while loop half_num=%lld \n", half_num);
    while(i <= sqrt_num){
//        printf("num %lld i %lld num (mod i) %lld\n", num, i, num % i);
        if (p_test(i) && num % i == 0)
            return 0;
        i++;
    }
    return 1;

}

int main()
{
    long long num = NUMBER;
    long long i =  sqrt(num);
    while(i > (long long) 0){
        if(num % i == 0){
            printf("found that %lld is a factor\n", i);
            if(p_test(i) == 1){
                printf("%lld is the largest prime of %lld\n", i, num);
                return 0;
            }
        }
        i--;
    }
    return 0;
}
