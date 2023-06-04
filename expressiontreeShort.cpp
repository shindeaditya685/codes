#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* top;

    void expression(const string& prefix);
    void display(Node* root);
    void nonRecursivePostorder(Node* top);
    void deleteNodes(Node* node);
};

void Tree::expression(const string& prefix) {
    stack<Node*> s;
    Node *t1, *t2;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        top = new Node(prefix[i]);

        if (isalpha(prefix[i])) {
            s.push(top);
        } else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' || prefix[i] == '/') {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
}

void Tree::display(Node* root) {
    if (root != nullptr) {
        cout << root->data;
        display(root->left);
        display(root->right);
    }
}

void Tree::nonRecursivePostorder(Node* top) {
    stack<Node*> s1, s2;
    Node* T = top;

    s1.push(T);
    while (!s1.empty()) {
        T = s1.top();
        s1.pop();
        s2.push(T);
        if (T->left != nullptr)
            s1.push(T->left);
        if (T->right != nullptr)
            s1.push(T->right);
    }

    while (!s2.empty()) {
        top = s2.top();
        s2.pop();
        cout << top->data;
    }
}

void Tree::deleteNodes(Node* node) {
    if (node == nullptr)
        return;
    deleteNodes(node->left);
    deleteNodes(node->right);
    cout << endl << "Deleting node: " << node->data << endl;
    delete node;
}

int main() {
    string expr;
    Tree t;

    cout << "Enter prefix Expression: ";
    cin >> expr;
    cout << expr;

    t.expression(expr);
    t.nonRecursivePostorder(t.top);
    t.deleteNodes(t.top);

    return 0;
}
