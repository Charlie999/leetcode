#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// NOT NEEDED IN LEETCODE ONLINE
int pow_(int a, int b) {
 int accum = 1;
 for (int i=0;i<b;i++) accum*=a;
 return accum;
}

int reverse(int x){
    int mul = 1000000000; // max ^10 for 32 bit int
    int sign = 0;
    
    unsigned int v = x;
    
    if (x<0) {sign=1;v=-v;}

    int ilen = 10;
    while (v < mul) {
        mul /= 10;
        ilen --;
    }
    
    mul = pow_(10, ilen-1);
    int mul2 = 1;
    unsigned int ret = 0;
    for (int i=0;i<ilen;i++) {
        int d = (v / mul)%10;
        v -= ((int)(v/mul)) * mul;
        mul /= 10;
        if (d>2 && mul2==1000000000) {
            return 0;
        }
        if (ret+((unsigned int)d*mul2) > 2147483647) return 0;
        ret += d*mul2;
        if (mul2==1000000000) break;
        mul2*=10;
    }

    
    return sign?-ret:ret;
}

bool isPalindrome(int x){
 return x>=0&&reverse(x)==x;
}

int main() {
 printf("%d\n",isPalindrome(121));
 return 0;
}
