#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

struct node* deleteNode(struct treeNode* root, int key);

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        return node;

}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        int n,c,v,m;
        treeNode *root = NULL;
        while(1)
        {
                printf("Please enter data(-999 to stop)\n");
                scanf("%d",&n);
                if(n==-999)
                {
                        break;
                }
                root = Insert(root, n);
        }
        printf("What do you want to do? (1 for traversal, 2 for search and delete)\n");
        scanf("%d",&v);
        if (v==1)
        {
                printf("Which traversal you want?");
                printf("\n1 for inorder, 2 for postorder 3 for preorder\n");
                scanf("%d",&c);
                switch(c)
                {
                        case 1 : PrintInorder(root);
                                break;
                        case 2 : PrintPostorder(root);
                                break;
                        case 3 : PrintPreorder(root);
                                break;
                }
        }
        if(v==2)
        {
                printf("Please enter the value you want to search and delete\n");
                scanf("%d",&m);
                deleteNode(root, m);
                printf("Printing after delete in which traversal? (1 for inorder, 2 for postorder 3 for preorder)\n");
                scanf("%d",&c);
                switch(c)
                {
                        case 1 : PrintInorder(root);
                                break;
                        case 2 : PrintPostorder(root);
                                break;
                        case 3 : PrintPreorder(root);
                                break;
                }
        }

}

struct node * minValueNode(struct node* node)
{
        struct treeNode* current = node;
        while (current->left != NULL)
                current = current->left;
        return current;
}

struct node* deleteNode(struct treeNode* root, int key)
{
        if (root == NULL)
                return root;
        if (key < root->data)
                root->left = deleteNode(root->left, key);
        else if (key > root->data)
                root->right = deleteNode(root->right, key);
        else
        {
                if (root->left == NULL)
                {
                        struct node *temp = root->right;
                        free(root);
                        return temp;
                }
                else if (root->right == NULL)
                {
                        struct node *temp = root->left;
                        free(root);
                        return temp;
                }
                struct treeNode* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
        }
        return root;
}
