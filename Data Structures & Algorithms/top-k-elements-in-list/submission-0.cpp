class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<pair<int, int>> arr;

        for (auto& [num, count] : freq) {
            arr.push_back({count, num});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }

        return result;
    }
};