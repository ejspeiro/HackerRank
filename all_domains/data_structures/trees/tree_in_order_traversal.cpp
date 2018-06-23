// Copyright 2018 Eduardo Sanchez

void inOrder(node *root) {
  if (root != nullptr) {
    inOrder(root->left);
    std::cout << root->data << ' ';
    inOrder(root->right);
  }
}
