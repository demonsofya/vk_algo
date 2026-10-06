class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = 1e5 + 1;

        int left = 0;
        int right = 0;

        int curr_sum = 0;

        while (right < nums.size()) {
            curr_sum += nums[right];

            while (curr_sum >= target) {
                int curr_len = right - left + 1;
                if (curr_len < min_len) 
                    min_len = curr_len;
                curr_sum -= nums[left];
                left++;
            }

            right++;
        }

        if (min_len == 1e5 + 1)
            return 0;

        return min_len; 
    }
};