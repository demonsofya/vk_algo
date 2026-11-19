//leetocde https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        int nums_sz = nums.size();

        for (int i = 0; i < nums_sz; i++) {
            minHeap.push(nums[i]);

            if (minHeap.size() > k)
                minHeap.pop();
        }
        
        return minHeap.top();
    }
};
