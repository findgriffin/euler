#include <stdint.h>
#include <iostream>
#include <cstdlib>
 
using namespace std;
 
typedef int numT;
 
int numFact(numT n)
{
    int res(0);
    for(int i(1); i*i<=n; ++i)
    if(!(n%i))
        res+=(i*i==n ? 1 : 2);
    return res;
}
 
int main()
{
    numT num(1);
    numT k(2);
         
    while(numFact(num)<=500)
    {
        num+=k;
        k+=1;
    }
           
    cout << num << endl;
             
    return EXIT_SUCCESS;
}
