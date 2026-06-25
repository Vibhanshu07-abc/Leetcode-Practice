class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
       int l=0;
       int j=0;
         for(int i=0;i<s.length();i++){
            map<char,int>mp;
            j=i;
            l=0;
             while(j<s.length()){
              mp[s[j]]++;
              if(mp[s[j]]>1){
                break;
              }
              l++;
              j++;
              maxlen=max(maxlen,l);
             }
         }
         return maxlen;
    }
};