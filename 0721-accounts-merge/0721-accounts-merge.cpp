class Solution {
    vector<int> par, size;

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionfind(int x, int y) {
        int ulu = find(x);
        int ulv = find(y);

        if (ulu == ulv) return;

        if (size[ulu] < size[ulv]) {
            par[ulu] = ulv;
            size[ulv] += size[ulu];
        }
        else {
            par[ulv] = ulu;
            size[ulu] += size[ulv];
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        par.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                }
                else {
                    unionfind(i, mp[mail]);
                }
            }
        }
        vector<vector<string>> mergemail(n);

        for (auto it : mp) {
            string mail = it.first;
            int node = find(it.second);

            mergemail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {

            if (mergemail[i].empty()) continue;

            sort(mergemail[i].begin(), mergemail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (auto it : mergemail[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};