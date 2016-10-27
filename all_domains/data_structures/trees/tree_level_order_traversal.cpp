
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

int height(node* root) {
    if (root == nullptr) {
        return -1;
    } else {
        return 1 + std::max(height(root->left), height(root->right));
    }
}

void PrintGivenLevel(node * root, int level) {

    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        std::cout << root->data << ' ';
    } else if (level > 1) {
        PrintGivenLevel(root->left, level - 1);
        PrintGivenLevel(root->right, level - 1);
    }
}

void LevelOrder(node * root)
{
    int hh = height(root) + 1;

    for (int ii = 1; ii <= hh; ii++) {
        PrintGivenLevel(root, ii);
    }

}
