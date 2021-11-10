#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define V4ALPHABET "0123456789."
#define V6ALPHABET "0123456789abcdefABCDEF:"

bool inAlphabet(char c, char* al) {
    for (int i=0;i<strlen(al);i++) {
        if (c==al[i])
            return true;
    }
    return false;
}

int occurences(char c, char* s) {
    int oc = 0;
    for (int i=0;i<strlen(s);i++)
        if (c==s[i]) oc++;
    return oc;
}

char * validIPAddress(char * IP){
    int slen = strlen(IP);
    bool v4 = true;
    bool v6 = true;
    for (int i=0;i<slen;i++) {
        v4 &= inAlphabet(IP[i],V4ALPHABET);
        v6 &= inAlphabet(IP[i],V6ALPHABET);
    }    

    if (!(v4 || v6)) return "Neither";

    if (v4) v4 &= (occurences('.',IP)==3)?1:0;
    if (v6) v6 &= (occurences(':',IP)==7)?1:0;
    
    if (!(v4 || v6)) return "Neither";
    
    long p = 0;
    if (v4) { // IPv4 (maybe)
        int cptr = 0;
        int cpn = 0;
        for (int i=0;i<4;i++) {
            for (int i=cptr;i<slen;i++) {
                if (IP[i] == '.') {IP[i]='\0';cpn=i+1;break;}
            }
            if (strlen(IP+cptr)>1 && IP[cptr]=='0') return "Neither";
            if (strlen(IP+cptr)==0) return "Neither";
            if (strlen(IP+cptr)>3) return "Neither";
            p = strtol(IP+cptr, NULL, 10);
            if (p>=256) return "Neither";
            cptr = cpn;
        }
        return "IPv4";
    } else { // IPv6 (maybe)
        int cptr = 0;
        int cpn = 0;
        for (int i=0;i<8;i++) {
            for (int i=cptr;i<slen;i++) {
                if (IP[i] == ':') {IP[i]='\0';cpn=i+1;break;}
            }
            if (strlen(IP+cptr)==0) return "Neither";
            if (strlen(IP+cptr)>4) return "Neither";
            p = strtol(IP+cptr, NULL, 16);
            if (p>=65536) return "Neither";
            cptr = cpn;
        }
        return "IPv6";
    }

    return "Neither";
}

int main() {
 char *str = (char*)malloc(9);
 memset(str,0,8);
 strcpy(str, "1.2.3.4");

 printf("%s\n",validIPAddress(str));

 free(str);
 return 0;
}
