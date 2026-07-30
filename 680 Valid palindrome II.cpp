class Solution {
    bool checkpalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
       int l=0;
       int r=s.size()-1;
       while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else{
            return checkpalindrome(s,l+1,r)|| checkpalindrome(s,l,r-1);// after remove that charcter check all remaining character palindrome or not check from both of the side
        }
       }
       return true;

    }
};
