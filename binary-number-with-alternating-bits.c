#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int nbits(int n) {
    for (unsigned int i=30;i>=0;i--) {
        if ((uint32_t)n & (1 << i))
            return i;
    }
}

bool hasAlternatingBits(int n){
    int lastBit = 0;
    for (unsigned int i=0;i<=nbits(n);i++) {
        int thisBit = ((uint32_t)n & (1 << i))>0;
        if (thisBit==lastBit && i>0) return false;
        lastBit=thisBit;
    }
    return true;
}

int main() {
 printf("%d\n",hasAlternatingBits(3));
 return 0;
}
