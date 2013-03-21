#include "myhead.h"
/* problem 4 
 * find the largest palendromic number made from the product of two 2 digit numbers
 */

int is_pal(int num){
    int cols[6];
    int i;
    for (i = 0; i < 6; i++){
        cols[i] = (num % (int) pow(10,i+1))/(int) pow(10,i);
    }
    int max = 5;            // the location of the most significant figure
    while (cols[max] == 0)
        max--;
    int a = 0;
    int b = max;
    while (a < b && cols[a] == cols[b]){
        a++;
        b--;
    }
    if (b - a < 1)
        return 1;
    return 0;
}

int main()
{
    int a = 999;
    int b = 999;
    int pal = 0;
    int l_pal = 0;
    for (a = 999; a > 99; a--){
        for (b = 999; b > 99; b--){
        pal = is_pal(a*b);
            if(pal)
                if(a*b > l_pal){
                    l_pal = a*b;
                    printf("%d = %d x %d is the largest palindrome\n", a*b, a, b);
                }
        }

    }
    return 0;
}
