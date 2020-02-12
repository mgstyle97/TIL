#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _TreeNode{
    int data;
    struct _TreeNode *left, *right;
    int is_thread;
}TreeNode;
//      A
//  B       C
//D   E   F   G
TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode *root = &n7;

TreeNode* find_successor(TreeNode *node) {
    TreeNode *p = node->right;
    if (p == NULL || node->is_thread == TRUE)
        return p;
    while (p->left)
        p = p->left;
    return p;
}

void thread_inorder(TreeNode *node)
{
    TreeNode *p = node;
    while(p->left)
        p = p->left;

    do{
        printf("%c-> ", p->data);
        p = find_successor(p);
    }while(p);
}

int main(){
    // 스레드 설정
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;
    // 중위 순회
    thread_inorder(root);
    printf("\n");
}

