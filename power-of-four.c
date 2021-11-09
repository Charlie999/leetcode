#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfFour(int n){
    if (n==1) return true;
    for (unsigned int i=1;i<31;i+=2) {
     if (n == 0b10 << i)
         return true;
    }
    return false;
}

int main() {
 printf("%d\n",isPowerOfFour(4));
 return 0;
}
