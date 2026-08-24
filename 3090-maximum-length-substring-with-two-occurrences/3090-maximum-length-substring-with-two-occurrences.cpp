class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int maxlen=INT_MIN;
        int left=0;int right=0;
        while(s[right]!='\0'){
            mp[s[right]]++;
            while(mp[s[right]]>2){
              mp[s[left]]--;
              if(mp[s[left]]==0){
                mp.erase(s[left]);
              }
              left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};