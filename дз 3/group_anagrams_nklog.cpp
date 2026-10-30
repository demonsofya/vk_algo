// leetcode https://leetcode.com/problems/group-anagrams/
//  it works in nk log k cause str sorting is k log  (and i just got modify with
//  specific sort only with english letters so idk how fast is it now)

class Solution {
public:
  void my_sort(string &s) {
    int count[26] = {};
    int s_sz = s.size();

    for (int i = 0; i < s_sz; i++) {
      count[s[i] - 'a']++;
    }

    int pos = 0;

    for (int i = 0; i < 26; i++) {
      while (count[i] > 0) {
        s[pos++] = i + 'a';
        count[i]--;
      }
    }
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<string, vector<string>> map;

    int strs_sz = strs.size(), v_sz = 0;
    for (int i = 0; i < strs_sz; i++) {
      string str = strs[i];
      my_sort(str);
      // sort(str.begin(), str.end());

      map[str].emplace_back(strs[i]);
    }

    std::vector<vector<string>> v;
    // v.reserve(map.size());

    for (auto iter : map) {
      v.emplace_back(iter.second);
    }

    return v;
  }
};