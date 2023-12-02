#include <stdio.h>
#include <stdlib.h> 

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node Node; 

Node* root = NULL;

void insert(int val) {
    Node* p = root;
    Node* q = NULL;
    Node* t = (Node*)malloc(sizeof(Node));
    t->left = t->right = NULL;
    t->data = val;

    if (root == NULL) {
        root = t;
        return;
    }

    while (p) {
        if (p->data == val) {
            free(t); // Free the allocated memory if the value already exists
            return;
        }
        q = p;
        if (val < p->data)
            p = p->left;
        else if (val > p->data)
            p = p->right;
    }

    if (val < q->data)
        q->left = t;
    else if (val > q->data)
        q->right = t;
}

int search(int key) {
    Node* p = root;

    while (p) {
        if (p->data == key)
            return 1; // Element found
        else if (key < p->data)
            p = p->left;
        else if (key > p->data)
            p = p->right;
    }

    return 0; // Element not found
}

void inorder(Node* p) {
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%3d", p->data);
    inorder(p->right);
}

void preorder(Node* p) {
    if (p == NULL)
        return;
    printf("%3d", p->data);
    preorder(p->left);
    preorder(p->right);
}

void postorder(Node* p) {
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%3d", p->data);
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1. Insertion");
        printf("\n2. Inorder");
        printf("\n3. Preorder");
        printf("\n4. Postorder");
        printf("\n5. Search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Enter key element: ");
                scanf("%d", &x);
                if (search(x))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 6:
                exit(0);
        }
    }

    return 0;
}
