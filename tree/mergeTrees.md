#### 合并二叉树

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

来源：[LeetCode](https://leetcode-cn.com/problems/merge-two-binary-trees)

#### 题解

先序遍历，先处理当前节点，再处理左右子树。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(!t1&&!t2)
    {
        return NULL;
    }
    else if(t1&&!t2)
    {
        return t1;
    }
    else if(!t1&&t2)
    {
        return t2;
    }
    else
    {
        t1->val=t1->val+t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
}
````