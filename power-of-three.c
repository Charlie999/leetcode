#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPowerOfThree(int n){
    float d = log(n)/log(3);
    return (n==(int)pow(3,round(d)))&(n>0);
}

int main() {
 printf("%d\n",isPowerOfThree(27));
 return 0;
}
