#include <iostream>  

using namespace std;  

struct node {
    int data;
    node* right;
    node* left;
};  

node* create_node (int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->right = nullptr;
    new_node->left = nullptr;
    return new_node;
}
class bst {
    node* root_node;

public:
    bst() {
        root_node = nullptr;
    }
    node* insertion_recursion (node* node,int d){
        if (node == nullptr){
            node = create_node(d);
            return node;
        }
        else if(node->data>d){
            node->left = insertion_recursion(node->left,d);
        }else if(node->data<d){
            node->right = insertion_recursion(node->right,d);
        }
        return node;
    }
    
    void in_order(node* node){
        if (node == nullptr){
            return; 
        }
        in_order(node->left);
        cout<<node->data<<endl;
        in_order(node->right);
    }
    void pre_order (node* node){
        if (node == nullptr){
            return;
        }
        cout<<node->data<<endl;
        pre_order(node->left);
        pre_order(node->right);
    }
    void display_preorder(){
        pre_order(root_node);
    }
    void post_order (node* node){
        if (node == nullptr){
            return;
        }
        post_order(node->left);
        post_order(node->right);
        cout<<node->data<<endl;
    }
    void display_postorder(){
        post_order(root_node);
    }
    
    void insert (int data) {
        if (root_node == nullptr){
            root_node = create_node(45);
            
        }
        else{
            insertion_recursion(root_node,data);
        }
    }
};

int main() {
    bst b;  
    b.insert(45);
    b.insert(65);
    b.insert(46);
    b.insert(25);
    b.insert(76);
    b.insert(9);
    b.display_postorder();
    return 0;
}
