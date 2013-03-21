#include "../utils/myhead.h"
/* problem 11 
 * description
 */

#define N       20
int array[N][N];

int main()
{
    int i;      // row
    int j;      // col
    int l_prod = 0;
    int prod;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &array[i][j]);
        }
        printf("done %d\n", i);
    }

    // do horizontal & vertical groups
   for(i = 0; i < N-4; i++){
        for(j = 0; j < N; j++){
            prod = array[i][j]*array[i+1][j]*array[i+2][j]*array[i+3][j];
            if (prod > l_prod)
                l_prod = prod;
            prod = array[j][i]*array[j][i+1]*array[j][i+2]*array[j][i+3];
            if (prod > l_prod)
                l_prod = prod;
        }
   }
    // do down > left groups
    for(i = 0; i < N-4; i++){
        for(j = 0; j < N-4; j++){
            prod = array[i][j]*array[i+1][j+1]*array[i+2][j+2]*array[i+3][j+3];
            if (prod > l_prod)
                l_prod = prod;
        }
   }
    
    // do down > right groups
    for(i = 3; i < N; i++){
        for(j = 0; j < N-4; j++){
            prod = array[i][j]*array[i-1][j+1]*array[i-2][j+2]*array[i-3][j+3];
            if (prod > l_prod)
                l_prod = prod;
        }
   }
 
    printf("%d\n", l_prod);
    return 0;
}
