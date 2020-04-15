#### 二叉树剪枝

给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

来源：[LeetCode](https://leetcode-cn.com/problems/binary-tree-pruning/)

#### 题解

后序遍历的思路，先处理左右子树，再处理当前节点。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void deleteNode(struct TreeNode* root)
{
    if(root)
    {
        deleteNode(root->left);
        deleteNode(root->right);
        if(root->left&&root->left->left==NULL&&root->left->right==NULL&&root->left->val==0)
        {
            root->left=NULL;
        }
        if(root->right&&root->right->left==NULL&&root->right->right==NULL&&root->right->val==0)
        {
            root->right=NULL;
        }
    }
}

struct TreeNode* pruneTree(struct TreeNode* root){
    if(!root)
    {
        return NULL;
    }
    else
    {
        deleteNode(root);
    }
    return root;

}
````