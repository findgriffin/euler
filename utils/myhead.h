#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


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

long long my_powl(long long x, long long y)
{
    long long ans = x;
    long long i;
    for (i = 1; i < y; i++){
        ans *= x;
    }
    return ans;
}

int my_pow(int x, int y)
{
    int ans = x;
    int i;
    for (i = 1; i < y; i++){
        ans *= x;
    }
    return ans;
}

unsigned long long factorial(unsigned long long n)
{
        unsigned long long ans = 1;
        unsigned long long i = 2;
        while(i <=n)
        {
                ans = ans*i;
                i++;
        }
        return ans;
}

