#include "../utils/myhead.h"
/* problem 3 
 * find th largest prime factor of NUMBER
 */

 #define NUMBER          600851475143
// #define NUMBER          341113195
#define NO_OF_FACTORS   100000

int main()
{
    long long num = NUMBER;
    long long i =  2;
    while(i < NUMBER/2){
        if(num % i == 0){
//            printf("found that %lld is a factor\n", i);
            if(p_test(i) == 1){
                printf("%lld is a prime factor of %lld\n", i, num);
            }
        }
        i++;
    }
    return 0;
}
