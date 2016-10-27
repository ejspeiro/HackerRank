/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

void insert_helper(node **root, int value) {
  if (*root == nullptr) {
    *root = new node;
    (*root)->data = value;
    (*root)->left = nullptr;
    (*root)->right = nullptr;
  } else {
    if (value <= (*root)->data) {
      insert_helper(&((*root)->left), value);
    } else {
      insert_helper(&((*root)->right), value);
    }
  }
}

node * insert(node * root, int value)
{

    insert_helper(&root, value);

   return root;
}
