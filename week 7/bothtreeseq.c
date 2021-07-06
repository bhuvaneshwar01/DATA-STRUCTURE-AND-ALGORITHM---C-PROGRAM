#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *left, *right;
};
struct node *newnode(int num)
{
        struct node *temp =  (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
}                                                                                                                                                                      
struct node* insert(struct node* node, int num)
{
        if (node == NULL)
                return newnode(num);

        if (num < node->data)
                node->left  = insert(node->left, num);
        else if (num > node->data)
                node->right = insert(node->right, num);
        return node;
}
int isEqual(struct node* a, struct node* b)
{
        if (a==NULL && b==NULL)
                return 1;
        if (a!=NULL && b!=NULL)
        {
          return
                (
                     a->data == b->data && isEqual(a->left, b->left) &&
                     isEqual(a->right, b->right)
                );
        }
          return 0;
}
void main()
{
        struct node *root = NULL;
        struct node *root2 = NULL;
        int c=0;
        printf("Enter data for 1st tree(0 to stop):\n");
        int data;
        scanf("%d",&data);
        root=insert(root,data);
        while(data!=0){
                scanf("%d",&data);
                if(data==0)
                        break;
                insert(root,data);
        }

        printf("Enter data for 2nd tree(0 to stop):\n");
        int data2;
        scanf("%d",&data2);
        root2=insert(root2,data2);
        while(data2!=0){
                scanf("%d",&data2);
                if(data2==0)
                        break;
                insert(root2,data2);
        }
        printf("\n");
        if(isEqual(root, root2))
                printf("Both trees are equal\n");
        else
                printf("Trees are not equal\n");
}
