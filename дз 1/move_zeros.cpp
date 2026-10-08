class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // if non-nul, we will put elem in this place
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int foo = nums[i];
                nums[i] = nums[j];
                nums[j] = foo;
                j++;
            }
        }
    }
};