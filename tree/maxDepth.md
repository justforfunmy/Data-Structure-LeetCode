#### 二叉树深度

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

来源：[LeetCode](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/)

#### 题解

后序遍历，先处理左右子树，得到左右子树中的最长路径，加上当前节点。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root)
    {
        int left=1,right=1;
        if(root->left)
        {
            left+=maxDepth(root->left);
        }
        if(root->right)
        {
            right+=maxDepth(root->right);
        }
        return left>right?left:right;
    }
    else
    {
        return 0;
    }
}
````