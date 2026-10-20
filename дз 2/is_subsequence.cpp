// leetcode https://leetcode.com/problems/is-subsequence/

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int s_len = s.size();
    int t_len = t.size();

    int i = 0, j = 0;

    while (i < s_len && j < t_len) {
      if (s[i] == t[j])
        i++;

      j++;
    }

    return i == s_len;
  }
};