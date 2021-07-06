#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    
    bool lthread;
    bool rthread;
};

struct node *insert(struct node *root, int key)
{
    struct node *ptr = root;
    struct node *par = NULL ; //parent

    while(ptr != NULL)
    {
        if(key == (ptr->data))
        {
            printf("Duplicate key !!! :( :(\n");
            return root;
        }

        par = ptr;

        if(key < ptr->data)
        {
            if(ptr->lthread == false)
                ptr = ptr-> left;

            else
                break;
        }
        else
        {
            if(ptr -> rthread == false)
                ptr = ptr -> right;
            else   
                break;
        }
    }
     
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> data = key;
    tmp -> lthread = true;
    tmp -> rthread = true;

    if(par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if(key < (par->data))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par-> right;
        par -> rthread = false;
        par -> right = tmp;
    }

    return root;
}

struct node *inordersuccessor(struct node *ptr)
{
    if(ptr->rthread == true)
        return ptr->right;

    ptr = ptr->right;
    while(ptr -> lthread == false)
        ptr = ptr->left;
    return ptr;
}

void inorder(struct node *root)
{
    if( root == NULL)
        printf("Tree is empty\n");

    struct node *ptr = root;
    while(ptr->lthread == false)
    {
        ptr = ptr -> left;
    }

    while(ptr != NULL)
    {
        printf("%d-> ",ptr->data);
        ptr = inordersuccessor(ptr);
    }
}

int main()
{
    struct node *root = NULL;
    
    
    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 
  
    inorder(root); 
    return 0;
}

