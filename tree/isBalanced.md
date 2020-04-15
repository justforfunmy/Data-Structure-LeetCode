#### 平衡二叉树

输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

来源:[LeetCode](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)

#### 题解

先得到左右子树的深度，比较差值。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int getDepth(struct TreeNode* root)
{
    int left,right ;
    if(root)
    {
        left=1,right=1;
        if(root->left)
        {
            left+=getDepth(root->left);
        }
        if(root->right)
        {
            right+=getDepth(root->right);
        }
        return left>right?left:right;
    }
    else
    {
        return 0;
    }
}
bool isBalanced(struct TreeNode* root){
    if(root)
    {
        int left=getDepth(root->left);
        int right=getDepth(root->right);
        int diff = abs(left-right);
        if(diff>1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
    }
    else
    {
        return true;
    }
    
}
````