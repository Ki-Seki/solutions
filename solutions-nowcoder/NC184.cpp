/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    int index = 0, array[10005];
    void inOrder(TreeNode* root) {
        if (root == NULL) return;
        inOrder(root->left);
        array[index++] = root->val;
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for (int i = 1; i < index; i++)
            if (array[i-1] >= array[i])
                return false;
        return true;
    }
};
