//leetcode https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr_len = 1;
        int max_len = curr_len;

        int nums_sz = nums.size();
        for (int i = 1; i < nums_sz; i++) {
            if (nums[i] > nums[i-1]) {
                curr_len++;
                if (curr_len > max_len)
                    max_len = curr_len;
            }
            else
                curr_len = 1;
        }

        return max_len;
    }
};
