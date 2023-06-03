#include <iostream>
#include <string>

using namespace std;

// Structure for each node in the binary search tree
struct TreeNode {
    string keyword;
    string meaning;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* createNode(string keyword, string meaning) {
    TreeNode* newNode = new TreeNode;
    newNode->keyword = keyword;
    newNode->meaning = meaning;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
TreeNode* insertNode(TreeNode* root, string keyword, string meaning) {
    // If the root is null, create a new node and return it
    if (root == NULL) {
        root = createNode(keyword, meaning);
        return root;
    }

    // If the keyword already exists, update its meaning
    if (root->keyword == keyword) {
        root->meaning = meaning;
        return root;
    }

    // If the keyword is less than the root node's keyword, insert it into the left subtree
    if (keyword < root->keyword) {
        root->left = insertNode(root->left, keyword, meaning);
    }
    // If the keyword is greater than the root node's keyword, insert it into the right subtree
    else {
        root->right = insertNode(root->right, keyword, meaning);
    }

    return root;
}

// Function to search for a node in the binary search tree
TreeNode* searchNode(TreeNode* root, string keyword, int& comparisons) {
    // If the root is null or the keyword is found at the root, return the root
    if (root == NULL || root->keyword == keyword) {
        return root;
    }

    // If the keyword is less than the root node's keyword, search in the left subtree
    if (keyword < root->keyword) {
        comparisons++;
        return searchNode(root->left, keyword, comparisons);
    }
    // If the keyword is greater than the root node's keyword, search in the right subtree
    else {
        comparisons++;
        return searchNode(root->right, keyword, comparisons);
    }
}

// Function to find the minimum node in the binary search tree
TreeNode* findMinNode(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
TreeNode* deleteNode(TreeNode* root, string keyword) {
    // If the root is null, return null
    if (root == NULL) {
        return root;
    }

    // If the keyword is less than the root node's keyword, delete from the left subtree
    if (keyword < root->keyword) {
        root->left = deleteNode(root->left, keyword);
    }
    // If the keyword is greater than the root node's keyword, delete from the right subtree
    else if (keyword > root->keyword) {
        root->right = deleteNode(root->right, keyword);
    }
    // If the keyword is found at the root, delete the root
    else {
        // Case 1: The root has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: The root has one child
        else if (root->left == NULL){
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
    }
        // Case 3: The root has two children
        else {
            TreeNode* temp = findMinNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }return root;

}

// Function to display the binary search tree in ascending order
void displayAscending(TreeNode* root) {
    if (root != NULL) {
        displayAscending(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        displayAscending(root->right);
    }
}

// Main function
int main() {
    TreeNode* root = NULL;
    int choice, comparisons = 0;
    string keyword, meaning;
    while (true) {
        cout << "1. Add new keyword" << endl;
        cout << "2. Delete keyword" << endl;
        cout << "3. Update keyword" << endl;
        cout << "4. Display data in ascending order" << endl;
        cout << "5. Find maximum number of comparisons" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter keyword: ";
            cin >> keyword;
            cout << "Enter meaning: ";
            cin >> meaning;
            root = insertNode(root, keyword, meaning);
            break;
        case 2:
            cout << "Enter keyword to delete: ";
            cin >> keyword;
            root = deleteNode(root, keyword);
            break;
        case 3:
            cout << "Enter keyword to update: ";
            cin >> keyword;
            cout << "Enter new meaning: ";
            cin >> meaning;
            root = insertNode(root, keyword, meaning);
            break;
        case 4:
            cout << "Dictionary in ascending order:" << endl;
            displayAscending(root);
            break;
        case 5:
            cout << "Enter keyword to search: ";
            cin >> keyword;
            comparisons = 0;
            searchNode(root, keyword, comparisons);
            cout << "Maximum number of comparisons required: " << comparisons << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
    }
}

return 0;

}