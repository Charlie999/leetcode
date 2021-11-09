#include <stdio.h>
#include <stdlib.h>

double rpow(double x, long n) {
    if (n==0) return 1;
    else if (n<0) return 1/rpow(x,-n);
    else if ((n&1)==0) return rpow(x,n/2)*rpow(x,n/2);
    else return x * rpow(x, n/2) * rpow(x, n/2);
}

double myPow(double x, int n){
    return rpow(x,n);
}

int main() {
 printf("%f\n",myPow(2,10));
 return 0;
}
