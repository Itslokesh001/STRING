
class Solution {
public:
    int longestPalindrome(string s) {
        int hash[256]={0};
        for(char c: s){
            hash[c-'A']++;
        }
        int len=0;
        int cnt=1;
        for(int i=0;i<256;i++){
            if(hash[i]==0) continue;
            len=len+(hash[i]/2)*2;
            if(hash[i]%2==1 && cnt==1) {len++; cnt--;}
        }
        return len;
        
    }
};
// return the maximum length of palidrome can form using this string
// we are using hashing 
//in answer we store the multiple of 2 and possible take one 1 odd frequency number
