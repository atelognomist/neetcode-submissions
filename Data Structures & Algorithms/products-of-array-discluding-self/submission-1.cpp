class Solution {
public:
    int suffix(vector<int>& nums, vector<int>& output, int i) {
        if (i == nums.size())
            return 1;

        int right = suffix(nums, output, i + 1);

        output[i] *= right;

        return nums[i] * right;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int prefix = 1;

        for (int i = 0; i < nums.size(); i++) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        suffix(nums, output, 0);

        return output;
    }
};
