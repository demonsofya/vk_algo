// leetocode https://leetcode.com/problems/two-sum/description/

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> hash_map;

    int nums_sz = nums.size();

    for (int i = 0; i < nums_sz; i++) {
      hash_map[nums[i]] = i;
    }

    for (int i = 0; i < nums_sz; i++) {
      int difference = target - nums[i];
      auto diff_iter = hash_map.find(difference);

      if (diff_iter != hash_map.end() && diff_iter->second != i)
        return {i, hash_map[difference]};
    }

    return {-1, -1};
  }
};