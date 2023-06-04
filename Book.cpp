#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string name;
    vector<Node*> children;

    Node(string name) : name(name) {}
};

void constructTree(Node* node) {
    cout << "Enter the number of children for node '" << node->name << "': ";
    int numChildren;
    cin >> numChildren;

    for (int i = 0; i < numChildren; i++) {
        cout << "Enter the name of child " << (i + 1) << " for node '" << node->name << "': ";
        string childName;
        cin.ignore(); // Ignore any leftover newline character
        getline(cin, childName);

        Node* child = new Node(childName);
        node->children.push_back(child);

        constructTree(child); // Recursively construct the child's subtree
    }
}

void printNodes(Node* node, int level = 0) {
    for (int i = 0; i < level; i++) {
        cout << "  "; // Indentation for levels
    }
    cout << node->name << endl; // Print the node name

    // Recursively print the children nodes
    for (Node* child : node->children) {
        printNodes(child, level + 1);
    }
}

int main() {
    Node* book = nullptr;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\nOptions:\n";
        cout << "1. Display\n";
        cout << "2. Add Book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                if (book == nullptr) {
                    cout << "No book added yet.\n";
                } else {
                    cout << "\nBook Structure:\n";
                    printNodes(book);
                }
                break;
            }
            case 2: {
                if (book != nullptr) {
                    cout << "A book is already added. Only one book is supported.\n";
                } else {
                    string bookName;
                    cout << "Enter the name of the book: ";
                    cin.ignore(); // Ignore any leftover newline character
                    getline(cin, bookName);

                    book = new Node(bookName);
                    constructTree(book);
                    cout << "Book added successfully.\n";
                }
                break;
            }
            case 3: {
                exitProgram = true;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    // Clean up the allocated memory
    delete book;

    return 0;
}
