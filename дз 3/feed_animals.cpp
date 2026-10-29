// leetcode https://leetcode.com/problems/assign-cookies/

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int g_sz = g.size(), s_sz = s.size();
    int j = 0, counter = 0; // counter for g

    for (int i = 0; i < s_sz && j < g_sz; i++) {
      if (s[i] >= g[j]) {
        counter++;
        j++;
      }
    }

    return counter;
  }
};