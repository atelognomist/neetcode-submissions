class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> arr;
        arr.reserve(strs.size());

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            arr.push_back({key, s});
        }

        sort(arr.begin(), arr.end());

        vector<vector<string>> ans;

        string previousKey;

        for (auto& p : arr) {
            if (ans.empty() || p.first != previousKey) {
                ans.push_back({p.second});
                previousKey = p.first;
            } else {
                ans.back().push_back(p.second);
            }
        }

        return ans;
    }
};