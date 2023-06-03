#include <iostream>
using namespace std;

class tree {
    int a[20][20], v, e;

public:
    void input();
    void display();
    void minimum();
};

void tree::input() {
    cout << "Enter the no. of branches: ";
    cin >> v;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            a[i][j] = 999;
        }
    }

    cout << "\nEnter the no. of connections: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int l, u, w;
        cout << "Enter the end branches of connection " << i + 1 << ": ";
        cin >> l >> u;
        cout << "Enter the phone company charges for this connection: ";
        cin >> w;
        a[l - 1][u - 1] = a[u - 1][l - 1] = w;
    }
}

void tree::display() {
    cout << "\nAdjacency matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << a[i][j] << "   ";
        }
        cout << endl;
    }
}

void tree::minimum() {
    int selected[20] = {0};
    selected[0] = 1;
    int p, q, total = 0, count = 0;

    while (count < v - 1) {
        int min = 999;
        p = q = -1;

        for (int i = 0; i < v; i++) {
            if (selected[i] == 1) {
                for (int j = 0; j < v; j++) {
                    if (selected[j] != 1 && a[i][j] < min) {
                        min = a[i][j];
                        p = i;
                        q = j;
                    }
                }
            }
        }

        if (p != -1 && q != -1) {
            selected[q] = 1;
            total += min;
            cout << "Minimum cost connection is " << p + 1 << " -> " << q + 1
                 << "  with charge: " << min << endl;
            count++;
        } else {
            break;
        }
    }

    cout << "The minimum total cost of connections for all branches is: " << total << endl;
}

int main() {
    int ch;
    tree t;
    do {
        cout << "==========PRIM'S ALGORITHM=================" << endl;
        cout << "\n1. INPUT\n2. DISPLAY\n3. MINIMUM\n4. EXIT\n" << endl;
         cin >> ch;

        switch (ch) {
            case 1:
                cout << "*******INPUT YOUR VALUES*******" << endl;
                t.input();
                break;

            case 2:
                cout << "*******DISPLAY THE CONTENTS********" << endl;
                t.display();
                break;

            case 3:
                cout << "*********MINIMUM************" << endl;
                t.minimum();
                break;
        }
    } while (ch != 4);

    return 0;
}