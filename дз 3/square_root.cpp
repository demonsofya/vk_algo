// leetcode https://leetcode.com/problems/sqrtx/

class Solution {
public:
  int mySqrt(int x) {
    int left = 0,
        right =
            x < 46340
                ? x
                : 46340; // max_int = 2 ^ 31 - 1 => result must be < 46340 for x
                         // <int> (and also i can use mid, left as ints with
                         // this max, otherwise there will be int overflow)

    while (left < right) {
      int mid = (left + right + 1) >> 1;
      int mid_2 = mid * mid;

      if (mid_2 == x)
        return mid;
      else if (mid_2 < x)
        left = mid;
      else
        right = mid - 1;
    }

    return left;
  }
};