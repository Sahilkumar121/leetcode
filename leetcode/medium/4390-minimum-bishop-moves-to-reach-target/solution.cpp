class Solution {
public:
    char checkColor(int x, int y)
    {
        if ((x == y) || (x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
        {
            return 'w';
        }

        return 'b';
    }
    
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if (target[0] == source[0] && target[1] == source[1]) {
            return 0;
        }

        if (checkColor(source[0], source[1]) ==
            checkColor(target[0], target[1])) {
            for (int i = 1; i <= 8; i++) {
                if (source[0] + i == target[0] && source[1] + i == target[1] ||
                    (source[0] + i == target[0] &&
                     source[1] - i == target[1]) ||
                    (source[0] - i == target[0] &&
                     source[1] + i == target[1]) ||
                    (source[0] - i == target[0] &&
                     source[1] - i == target[1])) {
                    return 1;
                }
            }

            return 2;
        }

        return -1;
    }
};