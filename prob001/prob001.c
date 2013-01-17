#include "../utils/myhead.h"
/* problem 1
 * add all the multiples of 3 and 5 below 1000
 */

#define THOUSAND    1000
#define THREE       3
#define FIVE        5

int main()
{
    int sum = 0;
    int i;
    for (i = 1; i < THOUSAND; i++)
    {
        if (i % THREE == 0 || i % FIVE == 0){
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
