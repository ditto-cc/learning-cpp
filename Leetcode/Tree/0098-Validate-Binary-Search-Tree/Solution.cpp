

/*
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "../TreeNode.h"
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        vector<TreeNode*> s(1, root);
        auto p = root;
        while (p->left) {
            s.push_back(p->left);
            p = p->left;
        }

        int pre = p->val;
        p = p->right;
        s.pop_back();

        while (!s.empty() || p) {
            if (p) {
                s.push_back(p);
                p = p->left;
            } else {
                p = s[s.size()-1];
                s.pop_back();
                if (p->val <= pre)
                    return false;
                pre = p->val;
                p = p->right;
            }
        }

        return true;
    }
};