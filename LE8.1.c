#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* CreateNode(int data)
{
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void insert_node(struct node **root, int data) 
{
  if (*root == NULL) 
  {
    *root = CreateNode(data);
    return;
  }
  if (data < (*root)->data) 
  {
    insert_node(&(*root)->left, data);
  } 
  else 
  {
    insert_node(&(*root)->right, data);
  }
}

// PRE-ORDER TRAVERSAL OF BST
void preorder(struct node* root)
{
  if(root!=NULL)
  {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
// POST-ORDER TRAVERSAL OF BST
void postorder(struct node* root)
{
  if(root!=NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}
// IN-ORDER TRAVERSAL OF BST
void inorder(struct node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}
//SEARCH AN ELEMENT
struct node* search(struct node* root,int key)
{
  int found=0;
  if(root==NULL)
     return NULL;
  if(root->data == key)
  {
     found=1;
     return root;
  }
  else if(root->data > key)
     return search(root->left,key);
  else
     return search(root->right,key);
}

//find height of tree
int height(struct node* root)
{
  if(root == NULL)
     return -1;
  int lh = height(root->left);
  int rh = height(root->right);
  return ( lh>rh ) ? lh+1 : rh+1 ;  
}
//LEVEL-ORDER
void levelorder(struct node* root,int level)
{
  if(root == NULL)
    return;
  if(level == 0){
    printf("%d",root->data);
  }
  else if(level>0){
    levelorder(root->left,level-1);
    levelorder(root->right,level-1);
  }
}
//loop for levelorder traversal
void printlevel(struct node* root)
{
  int h = height(root);
  printf("height: %d\n",h);
  for(int i = 0;i<=h;i++)
      levelorder(root,i);
}

int main()
{
  int nodes,data;
  printf("Enter number of nodes: ");
  scanf("%d", &nodes);

  struct node *root = NULL;
  struct node *n;

  printf("Enter nodes of BST: ");
  for (int i = 0; i < nodes; i++)
  {
    scanf("%d", &data);
    insert_node(&root, data);
  }
  printf("tree created\n");
  
  /*struct node* p=CreateNode(0);
  struct node* p1=CreateNode(1);
  struct node* p2=CreateNode(2);
  struct node* p3=CreateNode(3);
  struct node* p4=CreateNode(4);
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4; */
  printlevel(root);
  printf("\n");
  
   int choice, item, key;
    printf("\nMAIN MENU:\n");
    printf("1. Preorder\n");
    printf("2. Postorder\n");
    printf("3. Inorder\n");
    printf("4. Search\n");
    printf("5. Exit\n");

    while (1) 
    {
        
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                preorder(root);
                printf("\n");
                break;

            case 2:
                postorder(root);
                printf("\n");
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                n=search(root,key);
                if(n!=NULL)
                  printf("element found");
                else
                  printf("element not found");
                printf("\n");
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
  
  return 0;
}

