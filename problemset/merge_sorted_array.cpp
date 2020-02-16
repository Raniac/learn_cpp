#include <iostream>
#include <vector>

using namespace std;

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        while (n) {
            if (m == 0 || nums1[m-1] <= nums2[n-1]) {
                nums1[last--] = nums2[--n];
            } else {
                nums1[last--] = nums1[--m];
            }
        }
        return;
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    cout << nums1[4] << endl;
    return 0;
}