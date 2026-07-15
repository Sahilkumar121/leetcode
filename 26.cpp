//
// Created by sleep on 2026-07-15.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {
        unordered_map<int,int> freq;
        vector<int> result;
        for (const int &num : nums) {
            freq[num]++;
            if (freq[num] == 1) {
                result.push_back(num);
            }
        }

        const int k = static_cast<int>(result.size());
        nums = result;
        return  k;
    }
};