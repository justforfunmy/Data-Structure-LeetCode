#### 最大二叉树

给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

1. 二叉树的根是数组中的最大元素。
2. 左子树是通过数组中最大值左边部分构造出的最大二叉树。
3. 右子树是通过数组中最大值右边部分构造出的最大二叉树。
4. 通过给定的数组构建最大二叉树，并且输出这个树的根节点。

来源：[LeetCode](https://leetcode-cn.com/problems/maximum-binary-tree)

#### 题解

递归函数，作用是找到最大值，前后分成两个数组。创建节点，左右子树分别由函数调用两个数组生成。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if(numsSize>0)
    {
        int maxIdx=0;
        int idx;
        for(idx=0;idx<numsSize;idx++)
        {
            if(nums[idx]>nums[maxIdx])
            {
                maxIdx=idx;
            }
        }
        struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val=nums[maxIdx];
        node->left=constructMaximumBinaryTree(nums,maxIdx);
        node->right=constructMaximumBinaryTree(&nums[maxIdx+1],numsSize-maxIdx-1);
        return node;
    }
    else
    {
        return NULL;
    }
    

}
````