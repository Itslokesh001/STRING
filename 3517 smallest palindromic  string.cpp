
class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
        string start="";
        string single="";
        for(auto &it:mp){
            start.append(it.second/2,it.first);
            if(it.second%2==1) single.append(1,it.first);
            
        }
        string end1= start;
        reverse(end1.begin(),end1.end());
        return start+single+end1;
    }

};



class Solution {
public:
    string smallestPalindrome(string s) {
        int chars[26];
        for (char c : s) { chars[c - 'a']++; }
        string ans = "";
        char mid = ' ';
        for (int i = 0; i < 26; i++) {
            if (chars[i] % 2) { mid = 'a' + i; }
            ans += string(chars[i] / 2, 'a' + i);
        }
        string rans(ans.rbegin(), ans.rend());
        if (mid != ' ') { ans += mid; }
        ans += rans;
        return ans;
    }
};
