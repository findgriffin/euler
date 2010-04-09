#include "myhead.h"
/* problem 
 * description find the longest sequence starting under 10^6
 * apparently there were overflow errors when regular ints were used!
 */

long long int sequence(int start)
{
        int length = 1;
        long long int n = start;
        while(n>1)
        {
                length++;
                if(n % 2 == 0)
                        n = n/2;
                else
                        n = 3*n + 1;
        }
        return length;
}


int main()
{

        long long int start;
        int highest = 0;
        for (start = 1000000; start = start - 1; start > 1)
        {
                int i = sequence(start);
                if (i > highest){
                        printf("Sequence starting with %lld has %d terms\n",start,i);
                        highest = i;
                }
        }
    return 0;
}
