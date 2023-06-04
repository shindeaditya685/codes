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
"""
    Find the time and space requirements
of your method. 

ChatGPT
The time and space requirements of the provided method can be analyzed as follows:

Time Complexity:

Displaying the book structure (printNode function): The time complexity of this operation is O(n), where n is the total number of nodes in the book structure. This is because we need to visit each node once to print its name.
Adding a book: The time complexity for adding a book depends on the number of chapters, sections, and subsections entered by the user. If we denote these numbers as c, s, and ss respectively, the time complexity would be O(c * s * ss). This is because we have nested loops to iterate over chapters, sections, and subsections, resulting in a cubic time complexity.
Space Complexity:

Displaying the book structure: The space complexity of the printNode function is O(h), where h is the height of the book structure. This is because during the recursive calls, the function's call stack grows to accommodate the maximum depth of the book structure.
Adding a book: The space complexity for adding a book is O(n), where n is the total number of nodes in the book structure. This is because we create new Node objects for each chapter, section, and subsection, resulting in a linear space complexity.
Overall, the time complexity of the program depends on the number of nodes in the book structure, while the space complexity depends on the maximum depth or height of the book structure.
    """"
