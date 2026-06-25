class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
       int j=0;
         map<char,int>mp;
         for(int i=0;i<s.length();i++){
             mp[s[i]]++;
             while(mp[s[i]]>1){
                mp[s[j]]--;
                j++;
             }
             maxlen=max(maxlen,i-j+1);
             }
         
         return maxlen;
    }
};