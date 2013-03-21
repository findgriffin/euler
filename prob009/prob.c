#include "../utils/myhead.h"
/* problem 9 
 * largest a^2 + b^2 = c^2 where a + b + c = 1000
 */

#define N       1000

int main()
{
//    printf("testing my_pow(N,2)=%d", my_pow(N,2));
    int a;
    int b;
    int c;
    // for different values of a
    for (a = 1; a < 333; a++){
        //calculate b
        b = (my_pow(N,2) - 2*N*a) / (2*(N - a));
        c = N - a - b;
    //    printf("a=%d, b=%d,c=%d\n", a,b,c);
        if(c > 0 && b > a && c > b && (my_pow(a,2) + my_pow(b,2)) == my_pow(c,2) && a+b+c == N){
            printf("%d + %d + %d = %d a*b*c=%d\n", a, b, c, a+b+c,a*b*c);
        }
    }
    return 0;

}
