#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MIDPOINT(a,b) (a+b)/2
#define SQR(a) (a*a)

unsigned int _sqrt(unsigned int x){
    if (x==0) return 0;
    
    int min = 0;
    int max = 65535;
    
    unsigned int mp = MIDPOINT(min,max);
    int c = 0;
    
    while ((mp*mp) != x) {
        c = 0;
        mp = MIDPOINT(min,max);
        if ((mp*mp) >= x && max!=mp) {
            max = mp;
            c=1;
        } else if ((mp*mp) <= x && min!=mp) {
            min = mp;
            c=1;
        } else if ((mp*mp) == x){
            return mp;
        }
        if ((max-min)&1 && !c) {
            return MIDPOINT(max,min);
        }
        if (max==min) return max;
    }
    
    return mp;
}

bool isPerfectSquare(int num){
    return SQR(_sqrt(num)) == num;
}

int main() {
 printf("%d\n",isPerfectSquare(4));
 return 0;
}
