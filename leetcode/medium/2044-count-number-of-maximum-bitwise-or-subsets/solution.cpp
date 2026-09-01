class Solution {
public:
    int countSubset(vector<int>& nums, int i, int currOr, int maxOr) {
        if (i >= nums.size()) {
            if (currOr == maxOr) {
                return 1;
            }

            return 0;
        }

        int takeint = countSubset(nums, i + 1, currOr | nums[i], maxOr);

        int nottakeint = countSubset(nums, i + 1, currOr, maxOr);

        return takeint + nottakeint;
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int n = nums.size();

        int max_or = 0;
        for (const auto& val : nums) {
            max_or = val | max_or;
        }

        int currOr = 0;
        return countSubset(nums, 0, currOr, max_or);
    }
};