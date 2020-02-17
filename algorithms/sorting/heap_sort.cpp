#include <iostream>
#include <vector>

using namespace std;

/*
In-Place Heap-Sort.
Reference: Data Structures and Algorithms in C++, P351.
*/

void heapSort(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return;
    // Phase 1: build heap in-place
    int b = 1; // heap-list boundary
    for (b; b < n; b++) {
        int j = b;
        while (j > 0) {
            if (nums[j] > nums[(j - 1) / 2]) {
                swap(nums[j], nums[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
            else break;
        }
    }
    for (auto &n : nums) { cout << n; }
    cout << endl;
    // Phase 2: sort with built heap
    b = n - 1;
    while (b > 0) {
        swap(nums[b], nums[0]);
        b--;
        // restructure heap
        int p = 0;
        while (p * 2 + 2 <= b) {
            if (nums[p] < nums[2 * p + 1] || nums[p] < nums[2 * p + 2] ) {
                if (nums[2 * p + 1] > nums[2 * p + 2]) {
                    swap(nums[p], nums[2 * p + 1]);
                    p = 2 * p + 1;
                }
                else {
                    swap(nums[p], nums[2 * p + 2]);
                    p = 2 * p + 2;
                }
            }
            else break;
        }
    }
    for (auto &n : nums) { cout << n; }
    cout << endl;
    return;
}

int main() {
    vector<int> nums = {3,7,2,1,4};
    heapSort(nums);
    return 0;
}
