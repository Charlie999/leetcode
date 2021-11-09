#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int c=0;
    for (;n;c++){
        n=n&(n-1);
    }
    return c;
}

int main() {
 printf("%d\n",hammingWeight(0x7FFFFFFF));
 return 0;
}
