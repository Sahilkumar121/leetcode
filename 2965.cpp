
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> findMissingAndRepeatedValues(const vector<vector<int>>& grid) {
        const int size = static_cast<int>(grid.size() * grid.size()) ;
        vector<int> freq(size+1, 0);
        vector<int> ans(2);

        for (const auto &row : grid) {
            for (const auto &num : row) {
                freq[num]++;
            }
        }

        for (int i=1; i<=size; i++) {
            if (freq[i] == 2) {
                ans[0] = i;
            } else if (freq[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
};

int main() {
    const vector<vector<int>> grid = {{1,3}, {2,2}};
    const vector<int> result = Solution::findMissingAndRepeatedValues(grid);
    cout << result[0] << " " << result[1] << "\n";
}
