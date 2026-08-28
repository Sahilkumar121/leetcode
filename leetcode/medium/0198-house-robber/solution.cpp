
class Solution
{
    vector<int> memo;

public:
    int solve(vector<int> &nums, int i, int n)
    {
        if (i >= n)
        {
            return 0;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        int steal = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return memo[i] = max(steal, skip);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        memo.assign(n + 1, -1);

        return solve(nums, 0, n);
    }
};