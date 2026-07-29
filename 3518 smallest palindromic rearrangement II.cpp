class Solution {
   static const int limit=1000000;
   long long combination(int n,int r){
    if(r<0 ||r>n) return 0;
    long long res=1;
    for(int i=1;i<=r;i++){
        res=res*(n-r+i)/i;
        if(res>limit){
            return limit;
        }
    }
    return res;
   }

   long long countways(vector<int>&cnt){
    int left=accumulate(cnt.begin(),cnt.end(),0);
    long long ways=1;
    for(int x:cnt){
        if(!x) continue;
        ways*=combination(left,x);
        if(ways>limit) return limit;
        left-=x;
            }
            return ways;
   }

public:
    
        
    string smallestPalindrome(string s, int k) {
        vector<int>freq(26),half(26);
        for(char i: s){
          freq[i-'a']++;
        }
       string mid="";
       for(int i=0;i<freq.size();i++){
        if(freq[i]%2==1) mid.append(1,i+'a');
        half[i]=freq[i]/2;
       }
       if(countways(half)<k){
        return "";
       }

       string first="";
       int len=s.size()/2;
       while((int)first.length()<len){
        for(int i=0;i<26;i++){
            if(!half[i]) continue;
            half[i]--;
            long long ways=countways(half);
            if(ways>=k){          // answer is charcter ko fix kr hi ayga
               first.append(1,i+'a');
               break; // is wale charcter ki frequency to minus kr de
            }
            k-=ways;
            half[i]++;
        }
       }
       string second=first;
       reverse(second.begin(),second.end());
       return first+mid+second;
    }
};
