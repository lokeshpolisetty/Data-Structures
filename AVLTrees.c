#include <stdio.h>
#include <stdlib.h>

struct AVLnode {
    struct AVLnode *left;
    int data;
    struct AVLnode *right;
    int height;
};

// Function to create a new AVL node
struct AVLnode* createNewNode(int data) {
    struct AVLnode* newNode = (struct AVLnode*)malloc(sizeof(struct AVLnode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of a node
int height(struct AVLnode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform a right rotation LLrotation
struct AVLnode* rotateRight(struct AVLnode* y) {
    struct AVLnode* x = y->left;
    struct AVLnode* right = x->right;

    x->right = y;
    y->left = right;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation RR rotation
struct AVLnode* rotateLeft(struct AVLnode* x) {
    struct AVLnode* y = x->right;
    struct AVLnode* right = y->left;

    y->left = x;
    x->right = right;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a node into AVL tree
struct AVLnode* insertAVL(struct AVLnode* root, int data) {
    if (root == NULL)
        return createNewNode(data);

    if (data < root->data)
        root->left = insertAVL(root->left, data);
    else if (data > root->data)
        root->right = insertAVL(root->right, data);
    else
        return root; // Duplicate keys not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = height(root->left) - height(root->right);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to delete a node from AVL tree
struct AVLnode* deleteNode(struct AVLnode* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct AVLnode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp; // Copy the contents of non-NULL child
            free(temp);
        } else {
            struct AVLnode* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = height(root->left) - height(root->right);

    if (balance > 1 && height(root->left->left) - height(root->left->right) >= 0)
        return rotateRight(root);

    if (balance > 1 && height(root->left->left) - height(root->left->right) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && height(root->right->right) - height(root->right->left) >= 0)
        return rotateLeft(root);

    if (balance < -1 && height(root->right->right) - height(root->right->left) < 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to display AVL tree in inorder traversal
void displayInorder(struct AVLnode* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

// Function to check if a tree is AVL
int isAVL(struct AVLnode* root) {
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isAVL(root->left) && isAVL(root->right))
        return 1;

    return 0;
}

int main() {
    struct AVLnode* root = NULL;
    int choice, n, data;

    while (1) {
        printf("\nAVL Tree Operations Menu\n");
        printf("1. Create AVL tree\n");
        printf("2. Display AVL tree (inorder)\n");
        printf("3. Insert data into AVL tree\n");
        printf("4. Delete data from AVL tree\n");
        printf("5. Check if AVL tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the no. of nodes to create AVL tree: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    root = insertAVL(root, data);
                }
                break;
            case 2:
                printf("AVL tree (inorder): ");
                displayInorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                root = insertAVL(root, data);
                printf("Element %d inserted into AVL tree.\n", data);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element %d deleted from AVL tree.\n", data);
                break;
            case 5:
                if (isAVL(root))
                    printf("The tree is AVL.\n");
                else
                    printf("The tree is not AVL.\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
