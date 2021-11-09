int lengthOfLongestSubstring(char * s){
    int rlen = 0, v = 0;
    char* sO = s;
    while (*s) {
        int i = s-sO;
        int len = 0;
        v = 0;
        for (int j=0;j<strlen(s);j++) {
            for (int k=0;k<j;k++) {
                if (s[j]==s[k]) v = -1;
            }
            if (v==0) len++;
            else break;
        }

        rlen = (len>rlen)?len:rlen;

        s++;
    }
    
    return rlen;
}
