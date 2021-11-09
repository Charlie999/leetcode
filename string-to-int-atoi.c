
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// who puts random letters into atoi ?!
int myAtoi(char* s) {
 int slen = strlen(s);

 if (slen==0) return 0;

 int digits[slen];
 int sign = 0;
 int signd = 0;
 int dptr = -1;

 for (int i=0;i<slen;i++) {
  if ((s[i] == '+' || s[i] == '-') && (signd || dptr>=0)) break;
  if (s[i] == '+') {sign=0;signd=1;continue;}
  if (s[i] == '-') {sign=1;signd=1;continue;}
  if (s[i] == ' ' && (dptr>=0 || signd)) break;
  if (s[i] == ' ') continue;
  if (s[i] < 0x30 || s[i] > 0x39) break;
  dptr++;
  digits[dptr] = s[i]-0x30;
 }

 if (dptr<0) return 0;

 long mul = 1;
 long accumulator = 0;
 int *rdigits = digits;

 while(rdigits[0] == 0 && dptr > 0) {
  dptr--;
  rdigits+=1;
  if (dptr<0) return 0;
 }

 if (rdigits[0] == 0) return 0;

 if (dptr>10 && sign) return -2147483648;
 if (dptr>10        ) return  2147483647;

 for (int i=dptr;i>=0;i--) {
  if (mul <= 10000000000) {
   accumulator += rdigits[i]*mul;
   mul *= 10;
  }
 }

 if (sign) accumulator=-accumulator;
 if (accumulator < -2147483648) return -2147483648;
 if (accumulator >  2147483647) return  2147483647;

 int ret = accumulator;

 return ret;
}


int main() {
 printf("%d\n",myAtoi("-000000000000001"));
 return 0;
}
