#include <stdio.h>
#include <stdlib.h>
int count=0;
struct node {
  int key;
  struct node *left, *right;
};


struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


void display(struct node *root) {
 
  if (root != NULL) {
    
    display(root->left);
    printf("%d -> ", root->key);     
    display(root->right);
  }
  
}


struct node *insert(struct node *node, int key) {
 
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}


struct node *minvaluenode(struct node *node) {
  struct node *current = node;

  
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct node *deletenode(struct node *root, int key) {
  
  if (root == NULL) return root;

  
  if (key < root->key)
    root->left = deletenode(root->left, key);
  else if (key > root->key)
    root->right = deletenode(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }


    struct node *temp = minvaluenode(root->right);

    
    root->key = temp->key;

    root->right = deletenode(root->right, temp->key);
  }
  return root;
}
int main()
{
    struct node *root = NULL;
    while(1)
    {
        int choice,item;
        printf("Enter the option number :-\n\t1)Insertion\n\t2)deletion\n\t3)display\n\t4)exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("Enter the number to insert :-\t");
                scanf("%d",&item);
                printf("\n");
                if(root==NULL)
                    root = insert(root,item);
                else
                {
                    insert(root,item);
                }
                count++;
                break;
            
            case 2 :
                count--;
                printf("Enter the number to delete :-\t");
                scanf("%d",&item);
                printf("\n");
                deletenode(root, item);
                break;
            
            case 3:
                printf("display traversal: \n");
                display(root);
                printf("\nno of node is %d\n",count);
                break;

            case 4:
                exit(1);
            
            default:
                printf("Wrong number\n");
        }
    }
    
    return 0;
}