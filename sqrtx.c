
#include <stdio.h>
#include <stdlib.h>

#define MIDPOINT(a,b) (a+b)/2

unsigned int mySqrt(unsigned int x){
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

int main() {
 printf("%d\n",mySqrt(4));
 return 0;
}
