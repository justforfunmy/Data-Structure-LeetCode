#### 合法二叉搜索树

实现一个函数，检查一棵二叉树是否为二叉搜索树。

来源:[LeetCode](https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/)

#### 题解

二叉搜索树的特点是中序遍历呈递增状态，可以中序遍历并存入数组，判断数组是否递增即可。

````C
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int idx=0;
int getLength(struct TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        int len=1;
        return len+getLength(root->left)+getLength(root->right);
    }
}
void push(struct TreeNode* root,int* arr)
{
    if(root)
    {
        push(root->left,arr);
        arr[idx++]=root->val;
        push(root->right,arr);
    }
    else
    {
        return;
    }
}
bool isValidBST(struct TreeNode* root){
    int len = getLength(root);
    if(len<=1)
    {
        return true;
    }
    int* arr = (int *)malloc(sizeof(int)*len);
    idx = 0;
    push(root,arr);
    for(int i=1;i<len;i++)
    {
        if(arr[i-1]>=arr[i])
        {
            free(arr);
            return false;
        }
    }
    free(arr);
    return true;
}
````