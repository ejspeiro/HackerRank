// Copyright 2018 Eduardo Sanchez

void postOrder(node *root) {
  if (root != nullptr) {
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << ' ';
  }
}
