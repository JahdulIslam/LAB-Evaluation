#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int val)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(Node **root, int val)
{
    Node *newNode = createNode(val);

    if (*root == NULL)
    {
        *root = newNode;
        return; 
    }

    Node *temp;
    Node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = *root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            queue[++rear] = temp->left;
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            queue[++rear] = temp->right;
        }
    }
}

Node *getDeepestRightMost(Node *root)
{
    Node *temp;
    Node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->left != NULL)
        {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL)
        {
            queue[++rear] = temp->right;
        }
    }

    return temp;
}

Node *search(Node *root, int val)
{
    Node *temp;
    Node *queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->data = val)
        {
            return temp;
        }
        
        if (temp->left != NULL)
        {
            queue[++rear] = temp->left;
        }
        
        if (temp->right != NULL)
        {
            queue[++rear] = temp->right;
        }
    }

    return NULL;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    Node *root = NULL;
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);
    insert(&root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    int target = 90;
    Node *searchResult = search(root, target);

    if (searchResult != NULL)
    {
        printf("Node %d found in the BST\n", target);
    }
    else
    {
        printf("Node %d not found in the BST\n", target);
    }

    Node *RightMostNode = getDeepestRightMost(root);
    printf("%d is the right-most node\n", RightMostNode->data);

    return 0;                        
}