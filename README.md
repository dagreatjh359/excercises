# excercises
practice code sources
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    
    int pattern[2*n-1][2*n-1];
    pattern[n-1][n-1]=1;
    
    int i,j;
    
    for(i=1;i<=n-1;i++)  //counts to take for the correspoding number
    {
        for(j=0;j<=2*i;j++)
        {
            pattern[n-1+i][n-1-i+j]=pattern[n-1][n-1]+i;
            pattern[n-1-i][n-1-i+j]=pattern[n-1][n-1]+i;
        }
        for(j=0;j<=2*i-2;j++)
        {
            pattern[n-1-(i-1)+j][n-1+i]=pattern[n-1][n-1]+i;
            pattern[n-1-(i-1)+j][n-1-i]=pattern[n-1][n-1]+i;
        }
    }
    
    for(i=0;i<2*n-1;i++)
    {
        for(j=0;j<2*n-1;j++)
        {
            printf("%d ",pattern[i][j]);
        }printf("\n");
    }
    
    return 0;
}
