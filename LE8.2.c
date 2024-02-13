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
//SEARCH AN SMALLEST/LARGEST ELEMENT
struct node* search(struct node* root,int ch)
{
  if(root==NULL)
     return NULL;
  if(ch == 2) //LARGEST
  {
  if(root->right == NULL)
     return root;
  else
     return search(root->right,ch);
  }
  if(ch == 3) //SMALLEST
  {
  if(root->left == NULL)
     return root;
  else
     return search(root->left,ch);
  }
}
//COUNT LEAF NODES
void countLeaf(struct node* root,int *count)
{
  if(root!=NULL)
  {
    countLeaf(root->left,count);
    if(root->left == NULL && root->right == NULL)
    {
       printf("%d ",root->data);
       *count = *count+1;
    }
    countLeaf(root->right,count);
  }
}
//HEIGHT OF TREE
int height(struct node *root)
{
  if (root == NULL) 
    return -1;
  int lh = height(root->left);
  int rh = height(root->right);
  return (lh>rh) ? lh+1 : rh+1 ;
}
//INSERT NODE
void InsertNewNode(struct node* root,int ele)
{
  struct node* prev=NULL;
  struct node* ptr;
  while(root!=NULL)
  {
    prev=root;
    if(ele == root->data)
    {
      printf("Duplicate node cannot be inserted");
      return;
    }
    else if(ele < root->data)
      root=root->left;
    else
      root=root->right;
  }
  struct node* newnode = CreateNode(ele);
  if(ele < prev->data)
    prev->left = newnode;
  else
    prev->right = newnode;
  printf("element inserted");
}
//IN ORDER PREDECESSOR NODE
struct node* inOrderPredecessor(struct node* root)
{
  root = root->left;
  while(root->right != NULL)
  { 
    root = root->right;
  }
  return root;
}
//DELETE NODE
struct node* DeleteNode(struct node* root,int value,int *found)
{
  struct node* iPre;
  if(root == NULL)
  {
     *found=0; // Element not found
     return NULL;
  }
  if(root->left == NULL && root->right == NULL)
  {  
      if(root->data == value)
     {
        *found=1; // Element found and deleted
        free(root);
        return NULL;
     }
     else
     {
        *found=0;// Element not found
        return root;
     }
  } 
  //serach for the node to be deleted
  if(value < root->data){
     root->left = DeleteNode(root->left,value,found);
     }
  else if(value > root->data){
     root->right = DeleteNode(root->right,value,found);
     }
  else 
  { 
    *found = 1; // Element found
    // Node with only one child or no child
    if (root->left == NULL) {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
    // Node with two children: Get inorder predecessor
    iPre = inOrderPredecessor(root);
    root->data = iPre->data; // Copy inorder predecessor's content to this node

    // Delete the inorder predecessor
    root->left = DeleteNode(root->left, iPre->data, found);
    }
  }
  return root;
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
  inorder(root);
  printf("\n");
  
  int choice, found, key, count;
  found,count=0;
    printf("\nMAIN MENU:\n");
    printf("1. Insert\n");
    printf("2. Largest\n");
    printf("3. Smallest\n");
    printf("4. Height\n");
    printf("5. Count leaf nodes\n");
    printf("6. Delete\n");
    printf("7. Exit\n");
    while (1) 
    {
        printf("Inorder: ");
        inorder(root);
        //printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter node to insert: ");
                scanf("%d", &key);
                InsertNewNode(root,key);
                printf("\n");
                break;

            case 2:
                n=search(root,choice);
                if(n!=NULL)
                  printf("Largest element: %d\n",n->data);
                else
                  printf("element not found\n");
                break;

            case 3:
                n=search(root,choice);
                if(n!=NULL)
                  printf("Smallest element: %d\n",n->data);
                else
                  printf("element not found\n");
                break;

            case 4:
                printf("Height: %d\n",height(root)); 
                break;
                
            case 5:
                printf("leaf nodes: ");
                countLeaf(root,&count);
                printf("\nno. of leaf nodes: %d\n",count);
                break;
                
            case 6:
                printf("Enter node to delete: ");
                scanf("%d", &key);
                n=DeleteNode(root,key,&found);
                if(found)
                  printf("element deleted\n");
                else
                  printf("element not found\n");
                inorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
  
  return 0;
}
