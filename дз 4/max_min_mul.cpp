#include <vector>

int MinMaxMul(std::vector<int> data) {
    int data_sz = data.size();
    if (data_sz < 3)
        return -1;

    int min_idx = 1;
    int max_idx = 2;

    for (; min_idx < data_sz; min_idx = min_idx * 2 + 1) {
        ;
    }

    for (; max_idx < data_sz; max_idx = max_idx * 2 + 2) {
        ;
    }

    return data[min_idx] * data[max_idx];
}