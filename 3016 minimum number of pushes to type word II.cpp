class Solution {
public:
    int minimumPushes(string word) {
        
        int hash[26]={0};
        for(int i:word){
            hash[i-'a']++;
        }
        int ans=0;
        sort(hash,hash+26,greater<int>());
        for(int i=0;i<26;i++){
            if(hash[i]==0) continue;
            ans=ans+hash[i]*(i/8+1);

        }
        return ans;

    }
};
