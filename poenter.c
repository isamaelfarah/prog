#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

int search(struct TreeNode* root, int key) {
    if (root == NULL)
        return 0;

    if (key == root->data)
        return 1;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    struct TreeNode* root = NULL;

    printf("Enter a list of numbers (separated by commas): ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, ",");
    while (token != NULL) {
        root = insert(root, atoi(token));
        token = strtok(NULL, ",");
    }

    printf("Enter a number to search in the tree: ");
    int searchNumber;
    scanf("%d", &searchNumber);

    if (search(root, searchNumber)) {
        printf("%d found in the tree.\n", searchNumber);
    } else {
        printf("%d not found in the tree.\n", searchNumber);
    }

    return 0;
}
