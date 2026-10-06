class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = nums1.size() - nums2.size() - 1;
        int pointer2 = nums2.size() - 1;

        vector<int>::iterator iter3 = nums1.end() - 1;

        while(pointer2 >= 0) {
            if (pointer1 >= 0 && nums1[pointer1] > nums2[pointer2]) {
                *iter3 = nums1[pointer1];
                pointer1--;
            } else {
                *iter3 = nums2[pointer2];
                pointer2--;
            }
            iter3--;
        } 
    }
};