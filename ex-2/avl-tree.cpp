#include <iostream>

using namespace std;

struct node {
    int data;
    node* right;
    node* left;
    int height;
};

node* create_node(int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->right = nullptr;
    new_node->left = nullptr;
    new_node->height = 1;
    return new_node;
}

class avl {
    node* root_node;

public:
    avl() {
        root_node = nullptr;
    }

    int get_height(node* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node->height;
        }
    }

    int get_balance(node* current) {
        if (current == nullptr) {
            return 0;
        }
        return get_height(current->left) - get_height(current->right);
    }

    node* right_rotate(node* y) {
        node* x = y->left;
        node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;
        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        return x;
    }

    node* left_rotate(node* x) {
        node* y = x->right;
        node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;
        return y;
    }

    node* insertion_recursion(node* current, int d) {
        if (current == nullptr) {
            return create_node(d);
        }
        if (d < current->data) {
            current->left = insertion_recursion(current->left, d);
        } else if (d > current->data) {
            current->right = insertion_recursion(current->right, d);
        } else {
            return current;
        }
        current->height = 1 + max(get_height(current->left), get_height(current->right));
        int balance = get_balance(current);
        if (balance > 1 && d < current->left->data) {
            return right_rotate(current);
        }
        if (balance < -1 && d > current->right->data) {
            return left_rotate(current);
        }
        if (balance > 1 && d > current->left->data) {
            current->left = left_rotate(current->left);
            return right_rotate(current);
        }
        if (balance < -1 && d < current->right->data) {
            current->right = right_rotate(current->right);
            return left_rotate(current);
        }
        return current;
    }

    void insert(int data) {
        root_node = insertion_recursion(root_node, data);
    }

    void in_order(node* current) {
        if (current == nullptr) {
            return;
        }
        in_order(current->left);
        cout << current->data << " ";
        in_order(current->right);
    }

    void display_inorder() {
        cout << "In-order Traversal: ";
        in_order(root_node);
        cout << endl;
    }

    void pre_order(node* current) {
        if (current == nullptr) {
            return;
        }
        cout << current->data << " ";
        pre_order(current->left);
        pre_order(current->right);
    }

    void display_preorder() {
        cout << "Pre-order Traversal: ";
        pre_order(root_node);
        cout << endl;
    }

    void post_order(node* current) {
        if (current == nullptr) {
            return;
        }
        post_order(current->left);
        post_order(current->right);
        cout << current->data << " ";
    }

    void display_postorder() {
        cout << "Post-order Traversal: ";
        post_order(root_node);
        cout << endl;
    }
};

int main() {
    avl tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(35);
    tree.insert(5);

    tree.display_inorder();
    tree.display_preorder();
    tree.display_postorder();

    return 0;
}
