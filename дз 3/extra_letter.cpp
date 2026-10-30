// leetcode https://leetcode.com/problems/find-the-difference

class Solution {
public:
  char findTheDifference(string s, string t) {
    std::unordered_map<char, int> hash_map;

    int s_sz = s.size(), t_sz = t.size();

    for (int i = 0; i < t_sz; i++) {
      hash_map[t[i]]++;
    }

    for (int i = 0; i < s_sz; i++) {
      hash_map[s[i]]--;
    }

    for (auto iter = hash_map.begin(); iter != hash_map.end(); iter++) {
      if (iter->second != 0)
        return iter->first;
    }

    return 'a';
  }
};