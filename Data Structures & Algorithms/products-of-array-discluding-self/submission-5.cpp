class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> temp(nums.size());
        temp[0] = 1;
         for(int i = 1 ;i < nums.size();i++) {
            temp[i] = temp[i-1] * nums[i-1];
         }

        for(int i = nums.size()-2; i >= 0; i--) {
            temp[i] *= nums[i+1];
            nums[i] *= nums[i+1]; 
        }

        return temp;
    }
};