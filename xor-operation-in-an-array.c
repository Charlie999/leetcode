#include <stdio.h>
#include <stdlib.h>


int xorOperation(int n, int start){
    int out = 0;
    for (int i=0;i<n;i++) {
        out ^= start + 2*i;
    }
    return out;
}

int main() {
 printf("%d\n",xorOperation(5,0));
 return 0;
}
