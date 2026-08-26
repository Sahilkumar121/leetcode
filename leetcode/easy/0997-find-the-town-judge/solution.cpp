class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (n == 1) return 1;
        vector<int> trust_level(n + 1, 0);

        for (const auto& people : trust) {
            trust_level[people[0]]--;
            trust_level[people[1]]++;
        }

        for (int i = 0; i < n + 1; i++) {
            if (trust_level[i] > 0 && trust_level[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};