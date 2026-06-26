class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()){
            return false ;
        }
        vector<int>temp(26,0);
        vector<int>window(26,0);
        for(int i=0;i<s1.length();i++){
           temp[s1[i]-'a']++;
           window[s2[i]-'a']++;
        }
        if(temp==window)return true;
        for(int i=s1.length();i<s2.length();i++){
            window[s2[i]-'a']++;//adding new char in window
            window[s2[i-s1.length()]-'a']--;//deleting old char from window;
            if(temp==window){
                return true;
            }
        }
        return false;
    }
};