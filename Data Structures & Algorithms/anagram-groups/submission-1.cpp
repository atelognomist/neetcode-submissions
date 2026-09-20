class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size());

        for (const string& s : strs) {
            int freq[26] = {};

            for (char c : s)
                freq[c - 'a']++;

            string key;
            key.resize(26 * sizeof(unsigned char));

            for (int i = 0; i < 26; i++)
                key[i] = static_cast<unsigned char>(freq[i]);

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& [key, group] : mp)
            ans.push_back(move(group));

        return ans;
    }
};
