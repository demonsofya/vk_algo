class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k = k % sz;

        reverse(nums, 0, sz - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, sz - 1);

        return;
    }
private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            int foo = nums[left];
            nums[left++] = nums[right];
            nums[right--] = foo;
            //std::swap(nums[left], nums[right]);
            
            //left++;
            //right--;
        }
    }
};