class Solution {
public:
    int findMinArrowShots(vector<vector<int>>&arr) {
     int n=arr.size();
   sort(arr.begin(),arr.end());
  int temp = arr[0][1];
int count = 1;    

for (int i = 1; i < n; i++) {
    if (arr[i][0] > temp) { 
        temp = arr[i][1]; 
        count++; 
    } 
    else {
        temp = min(arr[i][1], temp); 
    }
}

return count;

    }
};