//
// Created by sleep on 2026-07-15.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, const int val) {
        vector<int> result;

        for (const int &num : nums) {
            if (num != val) {
                result.push_back(num);
            }
        }

        const int k = static_cast<int>(result.size());
        nums = result;
        return k;
    }
};