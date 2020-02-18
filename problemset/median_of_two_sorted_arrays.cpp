#include <iostream>
#include <vector>

using namespace std;

class BinarySearchSolution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1); // let nums1 be the shorter one

        // use binary search to update left and right part
        // the median will then be between the maxLeft and minRight
        int iMin = 0; int iMax = m;
        while (iMin <= iMax) {
            // define the left part pos for nums1 and nums2
            int i = (iMin + iMax) / 2; // update the boundary of left and right parts
            int j = (m + n + 1) / 2 - i; // move pos as much as i did
            if (j != 0 && i != m && nums2[j-1] > nums1[i]) iMin = i + 1;
            else if (i != 0 && i != m && nums2[j] < nums1[i-1]) iMax = i - 1;
            else {
                int maxLeft = 0;
                if (i == 0) maxLeft = nums2[j-1]; // left part has no num in nums1
                else if (j == 0) maxLeft = nums1[i-1]; // left part has no num in nums2
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                if ((m + n) % 2 == 1) return maxLeft; // m + n is odd

                int minRight = 0;
                if (i == m) minRight = nums2[j]; // right part has no num in nums1
                else if (j == n) minRight = nums1[i]; // right part has no num in nums2
                else minRight = min(nums1[i], nums2[j]);

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;

    }
};

class FindKthSolution {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2; // in m-plus-n-is-even case, find kth and (k+1)th
        int right = (m + n + 2) / 2; // in m-plus-n-is-odd case, find kth twice
        return (findKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + findKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) * 0.5;
    }
    int findKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if (len1 > len2) return findKth(nums2, start2, end2, nums1, start1, end1, k); // let nums1 be the shorter one
        if (len1 == 0) return nums2[start2 + k - 1];

        if (k == 1) return min(nums1[start1], nums2[start2]);

        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {
            return findKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1)); // discard smaller nums in nums2
        }
        else {
            return findKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1)); // discard smaller nums in nums1
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 2, 3};
    double res;
    BinarySearchSolution sol;
    res = sol.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}