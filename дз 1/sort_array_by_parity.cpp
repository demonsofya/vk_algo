//leetcode https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int nums_sz = nums.size(), j = 0; //j is for even nums

        for (int i = 0; i < nums_sz; i++) {
            if (nums[i] % 2 == 0) {
                int foo = nums[i];
                nums[i] = nums[j];
                nums[j] = foo;
                j++;
            }
        }

        return nums;
    }
};