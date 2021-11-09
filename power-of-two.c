#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n){
 if (n<0) return false;
 int bitsSet = 0;
 for (unsigned int i=0;i<31;i++) {
     if ((unsigned int)n & (1 << i))
         bitsSet++;
     if (bitsSet>1) return false;
 }
 return bitsSet==1;
}

int main() {
 printf("%d\n",isPowerOfTwo(2));
 return 0;
}
