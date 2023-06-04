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
                    printNode(book, 0);
                }
                break;
            }
            case 2: {
                if (book != nullptr) {
                    cout << "A book is already added. Only one book is supported.\n";
                } else {
                    cin.ignore();

                    string bookName, chapterName, sectionName, subsectionName;

                    cout << "Enter the name of the book: ";
                    getline(cin, bookName);

                    book = new Node(bookName);

                    int numChapters;
                    cout << "How many chapters does the book have? ";
                    cin >> numChapters;

                    for (int i = 0; i < numChapters; i++) {
                        cin.ignore();
                        cout << "Enter the name of chapter " << i+1 << ": ";
                        getline(cin, chapterName);

                        Node* chapterNode = new Node(chapterName);
                        book->children.push_back(chapterNode);

                        int numSections;
                        cout << "How many sections does chapter " << chapterName << " have? ";
                        cin >> numSections;

                        for (int j = 0; j < numSections; j++) {
                            cin.ignore();
                            cout << "Enter the name of section " << j+1 << " in chapter " << chapterName << ": ";
                            getline(cin, sectionName);

                            Node* sectionNode = new Node(sectionName);
                            chapterNode->children.push_back(sectionNode);

                            int numSubsections;
                            cout << "How many subsections does section " << sectionName << " have? ";
                            cin >> numSubsections;

                            for (int k = 0; k < numSubsections; k++) {
                                cin.ignore();
                                cout << "Enter the name of subsection " << k+1 << " in section " << sectionName << ": ";
                                getline(cin, subsectionName);

                                Node* subsectionNode = new Node(subsectionName);
                                sectionNode->children.push_back(subsectionNode);
                            }
                        }
                    }

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

