#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string name;
    vector<Node*> children;

    Node(string n) {
        name = n;
    }
};

void printNode(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << "- " << node->name << endl;
    for (int i = 0; i < node->children.size(); i++) {
        printNode(node->children[i], level+1);
    }
}

int main() {
    Node* root = new Node("Book");

    string bookName, chapterName, sectionName, subsectionName;

    cout << "Enter the name of the book: ";
    getline(cin, bookName);

    root->name = bookName;

    int numChapters;
    cout << "How many chapters does the book have? ";
    cin >> numChapters;

    for (int i = 0; i < numChapters; i++) {
        cin.ignore();
        cout << "Enter the name of chapter " << i+1 << ": ";
        getline(cin, chapterName);

        Node* chapterNode = new Node(chapterName);
        root->children.push_back(chapterNode);

        int numSections;
        cout << "How many sections does the chapter have? ";
        cin >> numSections;

        for (int j = 0; j < numSections; j++) {
            cin.ignore();
            cout << "Enter the name of section " << j+1 << ": ";
            getline(cin, sectionName);

            Node* sectionNode = new Node(sectionName);
            chapterNode->children.push_back(sectionNode);

            int numSubsections;
            cout << "How many subsections does the section have? ";
            cin >> numSubsections;

            for (int k = 0; k < numSubsections; k++) {
                cin.ignore();
                cout << "Enter the name of subsection " << k+1 << ": ";
                getline(cin, subsectionName);

                Node* subsectionNode = new Node(subsectionName);
                sectionNode->children.push_back(subsectionNode);
            }
        }
    }

    cout << endl << "Tree:" << endl;
    printNode(root, 0);

    return 0;
}