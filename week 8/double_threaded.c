#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
    int lthread, rthread;
};

struct node *root = NULL;

struct node* getNode(int);
struct node* insertion(int);
void inorder();
struct node* inorder_successor(struct node*);

int main()
{
    int choice, data;

    do
    {
        printf("\n1.INSERTION \t 2.DELETION \t 3.INORDER TRAVERSAL \t 0. EXIT \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
                break;
            case 1:
                printf("Enter the data to be inserted : ");
                scanf("%d", &data);
                root = insertion(data);
                break;
            case 3:
                printf("Inorder : ");
                inorder();
                break;
            default:
                printf("Invalid choice \n");
        }
    }while(choice != 0);

    return 0;
}

struct node* getNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lthread = newNode->rthread = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insertion(int data)
{
    struct node *ptr = root, *par = root;

    while(ptr)
    {
        if(root->data == data)
            return root;

        par = ptr;

        if(ptr->data > data)
        {
            if(!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else if(ptr->data < data)
        {
            if(!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }
    
    struct node *newNode = getNode(data);

    if(par == NULL)
    {
        root = newNode;
        root->lthread = root->rthread = 1;
    }
    else if(data < par->data)
    {
        newNode->left = par->left;
        newNode->right = par;
        par->lthread = 0;
        par->left = newNode;
    }
    else if(data > par->data)
    {
        newNode->right = par->right;
        newNode->left = par;
        par->rthread = 0;
        par->right = newNode;
    }
    return root;
}

void inorder()
{
    struct node *temp = root;

    if(root == NULL) return;

    while(!temp->lthread)
        temp = temp->left;
    
    while(temp)
    {
        printf("%d  ", temp->data);
        temp = inorder_successor(temp);
    }
}

struct node* inorder_successor(struct node *temp)
{
    if(temp->rthread)
        return temp->right;
    
    temp = temp->right;
    while(!temp->lthread)
        temp = temp->left;

    return temp;
}