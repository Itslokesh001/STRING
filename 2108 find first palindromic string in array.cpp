class Solution {
    bool checkpalindrome(string s){
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string i:words){
            if(checkpalindrome(i)) return i;
        }
        return "";
    }
