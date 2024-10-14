#include <iostream>

using namespace std;

// Node structure
struct node {
    int data;
    node* right;
    node* left;
    int height;  // Height of the node for balancing
};

// Function to create a new node
node* create_node(int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->right = nullptr;
    new_node->left = nullptr;
    new_node->height = 1;  // New node is initially at height 1
    return new_node;
}

// AVL Tree class
class avl {
    node* root_node;

public:
    avl() {
        root_node = nullptr;
    }

    // Function to get the height of the node
    int get_height(node* node) {
        if(node == nullptr){
            return 0;
        }
        else{
            return node->height;
        }

    }

    // Function to get the balance factor of the node
    int get_balance(node* current) {
        if (current == nullptr) {
            return 0;
        }
        return get_height(current->left) - get_height(current->right);
    }

    // Right Rotation
    node* right_rotate(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(get_height(y->left), get_height(y->right)) + 1;
        x->height = max(get_height(x->left), get_height(x->right)) + 1;

        return x;  // New root
    }

    // Left Rotation
    node* left_rotate(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(get_height(x->left), get_height(x->right)) + 1;
        y->height = max(get_height(y->left), get_height(y->right)) + 1;

        return y;  // New root
    }

    // Recursive function to insert a node and balance the tree
    node* insertion_recursion(node* current, int d) {
        // Perform normal BST insertion
        if (current == nullptr) {
            return create_node(d);
        }
        if (d < current->data) {
            current->left = insertion_recursion(current->left, d);
        } else if (d > current->data) {
            current->right = insertion_recursion(current->right, d);
        } else {
            return current;  // Duplicate values are not allowed
        }

        // Update height of this ancestor node
        current->height = 1 + max(get_height(current->left), get_height(current->right));

        // Get the balance factor
        int balance = get_balance(current);

        // If the node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && d < current->left->data) {
            return right_rotate(current);
        }

        // Right Right Case
        if (balance < -1 && d > current->right->data) {
            return left_rotate(current);
        }

        // Left Right Case
        if (balance > 1 && d > current->left->data) {
            current->left = left_rotate(current->left);
            return right_rotate(current);
        }

        // Right Left Case
        if (balance < -1 && d < current->right->data) {
            current->right = right_rotate(current->right);
            return left_rotate(current);
        }

        return current;  // Return the (unchanged) node pointer
    }

    // Public function to call the recursive insertion
    void insert(int data) {
        root_node = insertion_recursion(root_node, data);
    }

    // In-order traversal
    void in_order(node* current) {
        if (current == nullptr) {
            return;
        }
        in_order(current->left);
        cout << current->data << " ";
        in_order(current->right);
    }

    // Public function to display elements in in-order
    void display_inorder() {
        cout << "In-order Traversal: ";
        in_order(root_node);
        cout << endl;
    }

    // Pre-order traversal
    void pre_order(node* current) {
        if (current == nullptr) {
            return;
        }
        cout << current->data << " ";
        pre_order(current->left);
        pre_order(current->right);
    }

    // Public function to display elements in pre-order
    void display_preorder() {
        cout << "Pre-order Traversal: ";
        pre_order(root_node);
        cout << endl;
    }

    // Post-order traversal
    void post_order(node* current) {
        if (current == nullptr) {
            return;
        }
        post_order(current->left);
        post_order(current->right);
        cout << current->data << " ";
    }

    // Public function to display elements in post-order
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
    tree.insert(10); // LL rotation
    tree.insert(40);
    tree.insert(50);
    tree.insert(60); // RR rotation
    tree.insert(35); // LR rotation
    tree.insert(5);   // RL rotation

    // Display the elements in different orders
    tree.display_inorder();
    tree.display_preorder();
    tree.display_postorder();

    return 0;
}
