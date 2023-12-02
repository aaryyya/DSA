#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode; // typedef for better readability

// Function to create a new binary tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the binary tree
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to perform in-order traversal of the binary tree
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}

// Function to perform pre-order traversal of the binary tree
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform post-order traversal of the binary tree
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}

int main() {
    TreeNode* root = NULL; // Initialize an empty tree
    int numNodes, value, searchValue;

    // Get the number of nodes in the binary tree
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &numNodes);

    // Get input values from the user and insert them into the binary tree
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < numNodes; ++i) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Traversal examples
    printf("\nIn-order traversal: ");
    inorder(root);
    
    printf("\nPre-order traversal: ");
    preorder(root);
    
    printf("\nPost-order traversal: ");
    postorder(root);

    // Search for a value in the binary tree
    printf("\nEnter a value to search in the binary tree: ");
    scanf("%d", &searchValue);

    TreeNode* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Value %d found in the binary tree.\n", searchValue);
    } else {
        printf("Value %d not found in the binary tree.\n", searchValue);
    }

    // Remember to free allocated memory (not done in this simple example for brevity)
    
    return 0;
}
