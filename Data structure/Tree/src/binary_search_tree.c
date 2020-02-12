#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode{
    int data;
    struct _TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(int key)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

    node->data = key;
    node->right = node->left = NULL;
    return node;
}

TreeNode* search(TreeNode *root, int key)
{
    if(root == NULL)
        return NULL;
    if(key == root->data)
        return root;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

TreeNode* insert_node(TreeNode *root, int key)
{
    if(root == NULL)
        return new_node(key);
    if(key < root->data)
        root->left = insert_node(root->left, key);
    else if(key > root->data)
        root->right = insert_node(root->right, key);

    return root;
}

TreeNode* min_value_node(TreeNode *node)
{
    TreeNode *current = node;

    while(current->left)
        current = current->left;
    return current;
}

TreeNode* delete_node(TreeNode *root, int key)
{
    if(root == NULL)
        return NULL;
    if(key < root->data)
        root->left = delete_node(root->left, key);
    else if(key > root->data)
        root->right = delete_node(root->right, key);
    else{
        if(root->left == NULL){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = min_value_node(root->right);

        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(TreeNode *root)
{
    if(root){
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

int main(){
    TreeNode *root = NULL;
    TreeNode *tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("result of binary search tree inorder traversal \n");
    inorder(root);
    printf("\n\n");
    if(search(root, 30) != NULL)
        printf("Found 30 in binary search tree \n");
    else
        printf("No found 30 in binary search tree \n");
}