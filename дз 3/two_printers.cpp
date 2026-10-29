#include <iostream>

int copyTime(int N, int x, int y) {
  int left = 0, right = (N - 1) * std::max(x, y);

  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (mid / x + mid / y < N - 1) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return right + std::min(x, y);
}

int main() {
  int N = 0, x = 0, y = 0;
  std::cin >> N >> x >> y;

  std::cout << copyTime(N, x, y);

  return 0;
}