class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq.reserve(nums.size());

        for (int x : nums)
            ++freq[x];

        vector<pair<int, int>> v;
        v.reserve(freq.size());

        for (auto& [num, count] : freq)
            v.push_back({count, num});

        nth_element(v.begin(), v.begin() + k, v.end(),
                    [](const auto& a, const auto& b) {
                        return a.first > b.first;
                    });

        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; ++i)
            ans.push_back(v[i].second);

        return ans;
    }
};
