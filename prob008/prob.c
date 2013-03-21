#include "myhead.h"
/* problem 8 
 * gets 1000 digit number from stdin
 * finds the greatest product of five consecutive digits
 * doing it in MATLAB!
 */

#define N       1000
int num[N];


int main()
{
    int i;
    int greatest = 0;
    //read data into array
    for(i = 0; !feof(stdin) && i < N; i++){
        char st[] = {getchar(),'\0'};
        num[i] = atoi(st);
    }
    for(i = 0; i < N-5; i++){
        int prod = num[i]*num[i+1]*num[i+2]*num[i+3]*num[i+4];
        if (prod > greatest){
            greatest = prod;
            printf("%d is now the greatest, indexes %d to %d",prod,i,i+4);
            printf(": %d%d%d%d%d\n",num[i],num[i+1],num[i+2],num[i+3],num[i+4]);
        }
    }
    return 0;
}
