class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int high=letters.size()-1;
        int low=0;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(letters[mid]>target){
                ans=letters[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};