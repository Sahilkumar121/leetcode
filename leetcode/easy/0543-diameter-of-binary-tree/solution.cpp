/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxDiameter;
public:
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftPart = getDepth(root->left);
        int rightPart = getDepth(root->right);

        maxDiameter = max(maxDiameter, rightPart + leftPart);

        return max(leftPart ,rightPart) + 1;

    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDiameter = 0;
        getDepth(root);

        return maxDiameter;
    }
};