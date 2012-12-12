#include "myhead.h"
/* problem 5 
 * smallest number which has 1-20 as factors
 */

#define TWENTY 20
int main()
{
    int i = TWENTY; // number we are testing
    int n;
    while (i < INT_MAX) {
        n = TWENTY-1;
        while(i % n  == 0 && n > 1)
            n--;

        if (n == 1){
            printf("answer: %d\n", i);
            return 0;
        }
        i += TWENTY;
    }
    return 0;
}
