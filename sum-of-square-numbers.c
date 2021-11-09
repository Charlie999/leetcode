#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SQR(a) (a*a)

bool judgeSquareSum(unsigned int c){
    for (unsigned int a=0;SQR(a)<=c;a++) {
        double sqr = sqrt(c-SQR(a));
        if (sqr == floor(sqr))
            return true;
    }
    return false;
}

int main() {
 printf("%d\n",judgeSquareSum(2));
 return 0;
}
