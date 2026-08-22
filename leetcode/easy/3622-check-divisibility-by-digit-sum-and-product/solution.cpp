class Solution {
public:
    bool checkDivisibility(int n) {
        int copy_n = n;

        int sum = 0;
        int product = 1;
        while (copy_n > 0)
        {
            int remainder = copy_n % 10;
            sum += remainder;
            product *= remainder;
            copy_n /= 10;
        }

        if (n % (sum + product) == 0)
        {
            return true;
        }

        return false;
    }
};