#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, const int m, const vector<int>& nums2, const int n) {
        int i = m - 1, j = n - 1, k = (m+n)-1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums2[j];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    const vector<int> num2 = {2,5,6};
    constexpr  int m = 3, n = 3;

    Solution::merge(nums1, m, num2, n);

    for (const int &num : nums1) {
        cout << num << " ";
    }
    cout << "\n";

}