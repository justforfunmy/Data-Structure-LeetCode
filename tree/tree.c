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