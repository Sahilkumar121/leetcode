class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum = 0;

        int leftQuestion = 0;
        int rightQuestion = 0;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '?') {
                if (i < num.size() / 2) {
                    leftQuestion++;
                } else {
                    rightQuestion++;
                }
            } else {
                if (i < num.size() / 2) {
                    leftSum += num[i] - '0';
                } else {
                    rightSum += num[i] - '0';
                }
            }
        }

        int total = leftQuestion + rightQuestion;

        if (total % 2 == 1) {
            return true;
        }

        int RIGHT = (2 * leftSum) + (9 * leftQuestion);
        int LEFT = (2 * rightSum) + (9 * rightQuestion);

        if (RIGHT == LEFT) {
            return false;
        }

        return true;
    }
};