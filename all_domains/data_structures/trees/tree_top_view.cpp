/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void go_left(node * root) {
    if (root != nullptr) {
        go_left(root->left);
        std::cout << root->data << ' ';
    }
}

void go_right(node * root) {
    if (root != nullptr) {
        std::cout << root->data << ' ';
        go_right(root->right);
    }
}

void top_view(node * root)
{
    go_left(root->left);
    std::cout << root->data << ' ';
    go_right(root->right);
}
