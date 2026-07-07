class Solution {
public:
  bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
  }
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
          if(!isvowel(s[right])){
             right--;
          }
           if(!isvowel(s[left])){
             left++;
          }
          if(isvowel(s[left])&&isvowel(s[right])){
              swap(s[left],s[right]);
              right--;
              left++;
          }
        }
        return s;
    }
};