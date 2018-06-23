// Copyright 2018 Eduardo Sanchez

void preOrder(node *root) {
  if (root != nullptr) {
    std::cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
  }
}
