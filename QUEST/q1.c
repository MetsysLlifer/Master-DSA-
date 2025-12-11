#include <stdio.h>
#include <stdlib.h> // Essential for malloc

// Defining the Blueprint
typedef struct node {
    int value;           // The loot (data)
    struct node* left;  // The magical thread to the next node
    struct node* right;
}*TreeNode;

TreeNode createNode(int value);
void preOrder(TreeNode);
TreeNode insert(TreeNode*, int value);
TreeNode search(TreeNode, int value);

int main(){
    TreeNode A = NULL;
    // TreeNode B = createNode(2);
    // TreeNode C = createNode(3);
    // A->left = B;
    // A->right = C;
    
    insert(&A, 3);
    insert(&A, 1);
    insert(&A, 7);
    insert(&A, 2);
    
    
    
    printf("PreOrder: ");
    preOrder(A);
    
    int value = 2;
    printf("\nsearch [%d]: %s", value, search(A, value) != NULL? "Found": "Missing");
    value = 5;
    printf("\nsearch [%d]: %s", value, search(A, value) != NULL? "Found": "Missing");
    return 0;
}


TreeNode createNode(int value){
    TreeNode node = (TreeNode)malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void preOrder(TreeNode node){
    if(node == NULL) return;
    
    printf("%d ", node->value);
    
    preOrder(node->left);
    preOrder(node->right);
}

TreeNode insert(TreeNode* root, int value){
    if(*root == NULL){
        TreeNode node = createNode(value);
        *root = node;
        return node;
    }
    
    if (value < (*root)->value) (*root)->left = insert(&(*root)->left, value);
    if (value > (*root)->value) (*root)->right = insert(&(*root)->right, value);
    
    return *root;
}

TreeNode search(TreeNode root, int value){
    if(root == NULL){
        return NULL;
    }
    
    if(root->value == value){
        return root;
    }else if(value < root->value){
        return search(root->left, value);
    }else{
        return search(root->right, value);
    }
}




