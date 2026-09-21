class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];

        res[nums.length - 1] = 1;

        for(int i = nums.length - 1 ; i > 0 ; i--){
            res[i - 1] = nums[i] * res[i];
        }

        int currProd = 1;
        for(int i = 0 ; i < nums.length ; i++){
            res[i] = currProd * res[i];
            currProd *= nums[i];
        }

        return res;
    }
}  