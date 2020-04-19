## 二叉树小结

#### 树

树是一种由有限个数的节点组成的数据结构，它有以下特点：
+ 根节点只有一个。
+ 每个节点的前驱节点（即父节点）只有一个。
+ 每个节点可以有任意数量的后驱节点（即子树节点）。

二叉树是一种特殊的树，它的每个节点只有两个后驱节点。二叉搜索树又是一种特殊的二叉树，它除了有二叉树的特点外，还有：
+ 如果根节点的左子树不为空，则左子树上每个节点的值小于根节点的值，且左子树也是一棵二叉搜索树，以此类推。
+ 如果根节点的右子树不为空，则右子树上每个节点的值大于根节点的值，且右子树也是一棵二叉搜索树，以此类推。



#### 实现二叉搜索树

````C
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    int val;
    SearchTree left;
    SearchTree right;
};

Position Find(int x, SearchTree root)
{
    if (!root)
    {
        return NULL;
    }
    else
    {
        if (root->val == x)
        {
            return root;
        }
        else
        {
            if (root->val > x)
            {
                return Find(x, root->left);
            }
            else
            {
                return Find(x, root->right);
            }
        }
    }
}

Position FindMin(SearchTree root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->left == NULL)
        {
            return root;
        }
        else
        {
            return FindMin(root->left);
        }
    }
}

Position FindMax(SearchTree root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->right == NULL)
        {
            return root;
        }
        else
        {
            return FindMin(root->right);
        }
    }
}

SearchTree insertNode(int x, SearchTree root)
{

    if (root == NULL)
    {
        SearchTree node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = x;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
    {
        if (x < root->val)
        {
            root->left = insertNode(x, root->left);
        }
        else
        {
            root->right = insertNode(x, root->right);
        }
    }
    return root;
}

SearchTree deleteNode(int x, SearchTree root)
{
    Position temp;
    if (x < root->val)
    {
        root->left = deleteNode(x, root->left);
    }
    else if (x > root->val)
    {
        root->right = deleteNode(x, root->right);
    }
    else
    {
        if (root->left && root->right)
        {
            temp = FindMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->val, root->right);
        }
        else
        {
            temp = root;
            if (root->left == NULL)
            {
                root = root->right;
            }
            else if (root->right == NULL)
            {
                root = root->left;
            }
            free(temp);
        }
    }
}

//前序遍历
void preOrder(SearchTree root)
{
    if (root)
    {
        printf("val:%d \n", root->val);
        if (root->left)
        {
            preOrder(root->left);
        }
        if (root->right)
        {
            preOrder(root->right);
        }
    }
}

//中序遍历
void inOrder(SearchTree root)
{
    if (root)
    {
        if (root->left)
        {
            inOrder(root->left);
        }
        printf("val:%d \n", root->val);
        if (root->right)
        {
            inOrder(root->right);
        }
        
    }
}

//后续遍历
void postOrder(SearchTree root)
{
    if (root)
    {
        
        if (root->left)
        {
            postOrder(root->left);
        }
        if (root->right)
        {
            postOrder(root->right);
        }
        printf("val:%d \n", root->val);
    }
}

void main()
{
    SearchTree tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tree->val=10;
    tree->left=NULL;
    tree->right=NULL;
    insertNode(3,tree);
    insertNode(15,tree);
    insertNode(5,tree);
    insertNode(2,tree);
    insertNode(11,tree);
    insertNode(18,tree);
    insertNode(1,tree);
    printf("preorder:\n");
    preOrder(tree);
    printf("inorder:\n");
    inOrder(tree);
    printf("postorder:\n");
    postOrder(tree);
    
}
````

#### 关于遍历

对于二叉树，主要的遍历方式有3种：

##### 前序遍历

方法是先处理当前节点，再处理左右子树。

````C
//前序遍历
void preOrder(SearchTree root)
{
    if (root)
    {
        printf("val:%d \n", root->val);
        if (root->left)
        {
            preOrder(root->left);
        }
        if (root->right)
        {
            preOrder(root->right);
        }
    }
}
````

前序遍历算法示例：

+ 合并二叉树

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

来源：[LeetCode](https://leetcode-cn.com/problems/merge-two-binary-trees)

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
        //先处理当前节点，再处理左右子树
        t1->val=t1->val+t2->val;
        t1->left=mergeTrees(t1->left,t2->left);
        t1->right=mergeTrees(t1->right,t2->right);
        return t1;
    }
}
````

##### 中序遍历

先遍历左子树，再处理当前节点，最后处理右子树。

````C
//中序遍历
void inOrder(SearchTree root)
{
    if (root)
    {
        if (root->left)
        {
            inOrder(root->left);
        }
        printf("val:%d \n", root->val);
        if (root->right)
        {
            inOrder(root->right);
        }
        
    }
}
````

中序遍历算法示例：

+ 合法二叉搜索树

实现一个函数，检查一棵二叉树是否为二叉搜索树。

来源:[LeetCode](https://leetcode-cn.com/problems/legal-binary-search-tree-lcci/)

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

##### 后序遍历

先处理左右子树，最后处理当前节点。

````C
//后续遍历
void postOrder(SearchTree root)
{
    if (root)
    {
        
        if (root->left)
        {
            postOrder(root->left);
        }
        if (root->right)
        {
            postOrder(root->right);
        }
        printf("val:%d \n", root->val);
    }
}

````

后序遍历算法示例：

+ 二叉树剪枝

给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

来源：[LeetCode](https://leetcode-cn.com/problems/binary-tree-pruning/)

根据左右子树的处理结果处理当前节点。

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