class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<string> bucket(s.size() + 1);

        for (auto &it : freq) {
            bucket[it.second] += string(it.second, it.first);
        }

        string ans;
        for (int i = s.size(); i >= 1; i--) {
            ans += bucket[i];
        }

        return ans;
    }
};