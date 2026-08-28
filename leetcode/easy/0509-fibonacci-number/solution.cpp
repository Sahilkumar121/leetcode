class Solution {
public:
    int ans(int n, std::vector<int>& memo) {
        if (memo[n] != -1) {
            return memo[n];
        }

        return memo[n] = ans(n - 1, memo) + ans(n - 2, memo);
    }
    int fib(int n) {

        if (n <= 1)
        {
            return n;
        }
        
        std::vector<int> memo(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;

        return ans(n, memo);
    }
};