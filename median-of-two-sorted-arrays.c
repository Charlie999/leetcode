#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b

#define MAXEQ(a,b) (a>=b)?a:b
#define MINEQ(a,b) (a<=b)?a:b

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* n1, int n1s, int* n2, int n2s){
    int *nums3 = (int*)malloc(sizeof(int) * (n1s + n2s));

    int* a = (n1s>=n2s)?n1:n2;
    int as = MAXEQ(n1s,n2s);
    
    int* b = (n1s<n2s)?n1:n2;
    int bs = MIN(n1s,n2s);
        
    int ap=0,bp=0;
    for (int i=0;i<(as + bs);i++) {
       if (ap<as && bp<bs) {
           nums3[i] = MIN(a[ap],b[bp]);
           if (a[ap]<b[bp]) ap++;
           else bp++;
       } else {
	  if (bp>=bs) {
           nums3[i] = a[ap];
	   ap++;
	  } else {
           nums3[i] = b[bp];
	   bp++;
	  }
       } 
    }

    double med = 0;

    if (as<=1) {
        med = nums3[0];
    } else {
        if ((n1s+n2s)&1) {
            med = nums3[((n1s+n2s)>>1)];
        } else {
            med = (nums3[((n1s+n2s)>>1)] + nums3[((n1s+n2s)>>1) - 1])/2.0d;
        }
    }
    
    return med;
}


int main() {
	int a[2] = {1,3};
	int b[1] = {2};

	printf("m=%f\n",findMedianSortedArrays(a,2,b,1));

	return 0;
}
