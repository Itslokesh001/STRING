class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10] = {0};
        for(char c : num)
            freq[c - '0']++;
        string left="", mid="";
        for(int i = 9; i >= 0; i--) {
            if(i == 0 && left.empty())
                continue;           // it is used to not contain all leading 
            if(freq[i] % 2 == 1 && mid.empty())
                mid.append(1,i + '0');

            // if(i == 0 && left.empty())
            //     continue;

            left.append(freq[i] / 2, i + '0');
        }
        if(left.empty() && mid.empty())
            return "0"; // this case is only when all string contain zero "0000"

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
