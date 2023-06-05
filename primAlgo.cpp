#include<iostream>
using namespace std;

class tree{
	int a[20][20], lowerBranch, upperBranch, weight, vertices, edges, visited[20];

	public:
		void input();
		void display();
		void minimum();
};

void tree::input(){
	cout<<"\nEnter the no. of vertices: ";
	cin>>vertices;

	for(int i=0; i<vertices; i++){
		visited[i] = 0;
		for(int j=0; j<vertices; j++){
			a[i][j] = 999;
		}
	}

	cout<<"\nEnter the no. of edges: ";
	cin>>edges;

	for(int i=0; i<edges; i++){
		cout<<"\nEnter the end vertices connections: ";
		cin>>lowerBranch>>upperBranch;

		cout<<"Enter the phone company charges for this connection: ";
		cin>>weight;
		a[lowerBranch-1][upperBranch-1] = a[upperBranch-1][lowerBranch-1] = weight;
	}
}


void tree::display(){
	cout<<"\nAdjancency Matric: ";

	for(int i=0; i<vertices; i++){
		cout<<endl;
		for(int j=0; j<vertices; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void tree::minimum(){
	int p = 0, q = 0, total = 0, min;
	visited[0] = 1;
	for(int count=0; count<(vertices-1); count++){
		min = 999;
		for(int i=0; i<vertices; i++){
			if(visited[i] == 1){
				for(int j=0; j<vertices; j++){
					if(visited[j] != 1){
						if(min > a[i][j]){
							min = a[i][j];
							p = i;
							q = j;
						}
					}
				}
			}
		}
		visited[p] = 1;
		visited[q] = 1;
		total = total+min;
		cout<<"Minimum cost connection is "<<(p+1)<<" -> "<<(q+1)<<" with charge: "<<min<<endl;
	}

	cout<<"The minimum total cost of connections of all branch is: "<<total<<endl;
}

int main(){
	int choice;
	tree t;

	do{
		cout<<"==========PRIM'S ALGORITHM================="<<endl;
		cout<<"\n1.INPUT\n \n2.DISPLAY\n \n3.MINIMUM\n"<<endl;
		
		cout<<"Enter your choice :";
		cin>>choice;
		cout<<endl;

		switch(choice){
			case 1:
				cout<<"*********INPUT YOUR VALUES*********"<<endl;
				t.input();
				cout<<endl;
				break;
			case 2:
				cout<<"*********DISPLAY THE CONTENTS*********"<<endl;
				t.display();
				cout<<endl;
				break;
			case 3:
				cout<<"*********MINIMUM*********"<<endl;
				t.minimum();
				cout<<endl;
				break;
		}
	}while(choice != 4);

	return 0;
}
