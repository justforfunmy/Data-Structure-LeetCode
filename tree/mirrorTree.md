#### 二叉树镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

来源：[LeetCode](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)

#### 题解

先序遍历，先处理当前节点，交换左右子树，再分别处理左右子树

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root)
    {
        struct TreeNode* left = root->left;
        struct TreeNode* right = root->right;
        root->left=right;
        root->right=left;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
    return root;
}
````