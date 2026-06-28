class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        for (char ch : t)
            freq[ch]++;
        int left = 0;
        int count = 0;
        int start = -1;
        int minLen = s.size()+1;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                count++;
            freq[s[right]]--;
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count--;

                left++;
            }
        }
        return (start == -1) ? "" : s.substr(start, minLen);
    }
};