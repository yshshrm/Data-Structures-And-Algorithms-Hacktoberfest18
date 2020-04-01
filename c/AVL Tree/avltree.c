
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int Max(int a, int b)
{
    if (a > b)
        return a;

    else
        return b;
}

Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = Max(height(y->left), height(y->right)) + 1;
    x->height = Max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *z = y->left;

    y->left = x;
    x->right = z;

    x->height = Max(height(x->left), height(x->right)) + 1;
    y->height = Max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

void Print(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        Print(root->left);
        Print(root->right);
    }

    else
        return;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

void Find(Node *root, int key)
{
    Node *current = root;

    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("The number is present in the AVL tree\n");
            return;
        }

        else if (current->data > key)
            current = current->left;
        else
            current = current->right;
    }

    printf("The number doesn't exist in the AVL tree\n");
    return;
}

Node *Insert(Node *node, int key)
{

    if (node == NULL)
        return (createNode(key));

    if (key < node->data)
        node->left = Insert(node->left, key);

    else if (key > node->data)
        node->right = Insert(node->right, key);

    else
        return node;

    node->height = 1 + Max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left  Rotation Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Rotation Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Rotation Case
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Rotation Case
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + Max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    Node *g_root = NULL;
    int choice, key_var_insert, key_var_delete, key_var_find;

    while (1)
    {
        printf("\n");
        printf(" _____________________________________________________________\n");
        printf("|************AVL:SELF BALANCING TREE DATA STRUCTURE***********|\n");
        printf("|---------------------------MENU------------------------------|\n");
        printf("|1.Insert A Key in the AVL Tree                               |\n");
        printf("|2.Find a Key in the AVL Tree                                 |\n");
        printf("|3.Delete a Key from the AVL Tree                             |\n");
        printf("|4.Print the AVL Tree                                         |\n");
        printf("|_____________________________________________________________|\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the number you wish to insert:\n");
            scanf("%d", &key_var_insert);
            g_root = Insert(g_root, key_var_insert);
            break;
        }

        case 2:
        {
            printf("Enter the number you wish to search for: \n");
            scanf("%d", &key_var_find);
            Find(g_root, key_var_find);
            break;
        }

        case 3:
        {
            printf("Enter the number you wish to delete:\n");
            scanf("%d", &key_var_delete);
            g_root = deleteNode(g_root, key_var_delete);
            break;
        }

        case 4:
        {
            Print(g_root);
            printf("\n");
            break;
        }
        }
    }

    return 0;
}
