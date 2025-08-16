#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val)
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

void insert(Node** root, int val)
{
    Node* newNode = createNode(val);

    if (*root == NULL)
    {
        *root = newNode;
        return;
    }

    Node* temp;
    Node* queue[100];
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

Node* getDeepestRightMostNode(Node* root)
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

void deleteDeepestRightMostNode(Node* root, Node* dNode)
{
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp == dNode)
        {
            temp == NULL;
            free(dNode);
            return;
        }

        if (temp->left == dNode)
        {
            temp->left = NULL;
            free(dNode);
            return;
        }
        else
        {
            queue[++rear] = temp->left;
        }

        if (temp->right == dNode)
        {
            temp->right = NULL;
            free(dNode);
            return;
        }
        else
        {
            queue[++rear] = temp->right;
        }
    }
}

void delete(Node** root, int val)
{
    if(*root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    if((*root)->left == NULL && (*root)->right == NULL)
    {
        if((*root)->data == val)
        {
            free(*root);
            *root = NULL;
            return;
        }
        else
        {
            printf("Node not found\n");
            return;
        }
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    Node* keyNode = NULL;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->data == val)
        {
            keyNode = temp;
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

    if (keyNode != NULL)
    {
        Node* deepest = getDeepestRightMostNode(*root);
        keyNode->data = deepest->data;
        deleteDeepestRightMostNode(*root, deepest);
    }
    else
    {
        printf("Node not found\n");
    }
}

Node* search(Node* root, int val)
{
    Node *temp;
    Node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear)
    {
        temp = queue[++front];

        if (temp->data == val)
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
    Node* root = NULL;
    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 9);
    insert(&root, 14);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    int target = 14;
    Node *searchResult = search(root, target);

    if (searchResult != NULL)
    {
        printf("Node %d found in the BST\n", target);
    }
    else
    {
        printf("Node %d not found in the BST\n", target);
    }

    delete(&root, 10);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
