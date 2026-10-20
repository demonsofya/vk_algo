// leetcode https://leetcode.com/problems/valid-palindrome/description/
//  quiete the same, but i need to rm non-alphanumeric characters so there are
//  some std::isalpha and std::isdigit

class Solution {
public:
  bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      while (!(std::isalpha(s[left]) || std::isdigit(s[left])) && left < right)
        left++;

      while (!(std::isalpha(s[right]) || std::isdigit(s[right])) &&
             left < right)
        right--;

      if (std::tolower(s[left]) != std::tolower(s[right]))
        return false;

      left++;
      right--;
    }

    return true;
  }
};