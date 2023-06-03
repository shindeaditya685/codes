#include<iostream>
#define SIZE 10
using namespace std;

class Optimal{
private:
    int p[SIZE];       //probability of searching an element
    int q[SIZE];       //probability of not finding an element
    int a[SIZE];       //Elements from which OBST is to be built
    int w[SIZE][SIZE];      //Weight w[i][j] of a tree having root[i][j]
    int c[SIZE][SIZE];      //Cost c[i][j] of a tree having root[i][j]
    int r[SIZE][SIZE];      //Represent root
    int n;
    int front, rear, queue[20];
public:
    Optimal();
    void get_data();
    int Min_Value(int, int);
    void OBST();
    void build_tree();
};
Optimal::Optimal(){
    front = rear = -1;
}
/*This function accepts the input data*/

void Optimal::get_data(){
    int i;
    cout << "\nOBST\n";
    cout << "\nEnter the number of nodes: ";
    cin >> n;
    cout << "\nEnter the data as: \n";
    for (i=1; i<=n; i++){
        cout << "\n a[" << i << "]:";
        cin >> a[i];
    }
    cout << "\nEnter probability for a successful search : \n";
    for (i=1; i<=n; i++){
        cout << "p[" << i << "]:";
        cin >> p[i];
    }

    cout << "\nEnter probability for an unsuccessful search: \n";
    for (i=0; i<=n; i++){
        cout << "q[" << i << "]:";
        cin >> q[i];
    }

}

int Optimal::Min_Value(int i, int j){
    int m, k;
    int minimum = 32000;
    for (m = r[i][j-1]; m <= r[i+1][j]; m++){
        if (c[i][m-1] + c[m][j] < minimum){
            minimum = c[i][m-1] + c[m][j];
            k = m;
        }
    }
    return k;
}

void Optimal::OBST(){
    int i,j,k,m;
    for (i=0; i<n; i++){
        w[i][i] = q[i];
        r[i][i] = c[i][i] = 0;
        w[i][i+1] = q[i] + q[i+1] + p[i+1];
        r[i][i+1] = i + 1;
        c[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
    //Find optimal trees with m nodes
    for (m = 2; m <= n; m++){
        for (i=0; i<=n-m; i++){
            j = i + m;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            k = Min_Value(i,j);
            c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
            r[i][j] = k;
        }
    }
}

void Optimal::build_tree(){
    int i, j , k;
    cout << "The OBST for the given node is: \n";
    cout << "\nThe Root of this OBST is :: " << r[0][n];
    cout << "\nThe Cost of this OBST is :: " << c[0][n];
    cout << "\n\n\tNODE\tLEFT CHILD\tRIGHT CHILD";
    cout << "\n----------------------------------" << endl;
    queue[++rear] = 0;
    queue[++rear] = n;
    while(front!=rear){
        i = queue[++front];
        j = queue[++front];
        k = r[i][j];
        cout << "\n\t" << k;
        if (r[i][k-1] != 0){
            cout << "         " << r[i][k-1];
            queue[++rear] = i;
            queue[++rear] = k-1;
        }
        else
            cout << "         -";
        if (r[k][j] != 0){
            cout << "         " << r[k][j];
            queue[++rear] = k;
            queue[++rear] = j;

        }
        else
            cout << "         -";
    }
    cout << endl;
}

int main(){
    Optimal obj;
    obj.get_data();
    obj.OBST();
    obj.build_tree();
}