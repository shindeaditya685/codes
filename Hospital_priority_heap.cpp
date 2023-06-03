#include <iostream>

using namespace std;

struct patient {
    string name;
    int priority; // 1 = Serious, 2 = Non-serious, 3 = General check-up
};

class priorityQueue {
    private:
        patient *heapArray; // Array to hold the heap
        int maxSize; // Maximum size of the heap
        int currentSize; // Current size of the heap

        void buildHeap() {
            // Heapify the array from the middle to the start
            for (int i = currentSize / 2; i >= 0; i--) {
                percolateDown(i);
            }
        }

        void percolateDown(int index) {
            int child;
            patient temp = heapArray[index];

            // Loop until there is at least one child
            while (index * 2 + 1 < currentSize) {
                child = index * 2 + 1;

                // Check if there is a right child and it has higher priority
                if (child != currentSize - 1 && heapArray[child + 1].priority < heapArray[child].priority) {
                    child++;
                }

                // Check if the parent has higher priority than the child
                if (heapArray[child].priority < temp.priority) {
                    heapArray[index] = heapArray[child];
                } else {
                    break;
                }

                index = child;
            }

            heapArray[index] = temp;
        }

    public:
        priorityQueue(int size) {
            heapArray = new patient[size];
            maxSize = size;
            currentSize = 0;
        }

        ~priorityQueue() {
            delete [] heapArray;
        }

        bool insert(patient p) {
            if (currentSize == maxSize) {
                return false;
            }

            heapArray[currentSize] = p;
            currentSize++;

            // Bubble up the new element until its parent has higher priority
            int index = currentSize - 1;
            while (index > 0 && heapArray[(index - 1) / 2].priority > heapArray[index].priority) {
                swap(heapArray[index], heapArray[(index - 1) / 2]);
                index = (index - 1) / 2;
            }

            return true;
        }

        patient remove() {
            patient min = heapArray[0];

            // Move the last element to the root and percolate it down
            heapArray[0] = heapArray[currentSize - 1];
            currentSize--;
            percolateDown(0);

            return min;
        }

        bool isEmpty() {
            return currentSize == 0;
        }

        bool isFull() {
            return currentSize == maxSize;
        }

        void display() {
            for (int i = 0; i < currentSize; i++) {
                cout << heapArray[i].name << " (Priority: " << heapArray[i].priority << ")" << endl;
            }
        }
};

int main() {
    int size, choice;
    string name;
    patient p;
    cout << "Enter the size of the priority queue: ";
    cin >> size;
    priorityQueue pq(size);

    do {
        cout << "1. Add a patient\n";
        cout << "2. Remove the highest priority patient\n";
        cout << "3. Display the priority queue\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the name of the patient: ";
                cin >> p.name;
                cout << "Enter the priority of the patient (1 = Serious, 2 = Non-serious, 3 = General check-up): ";
                cin >> p.priority;
            if (pq.insert(p)) {
                cout << "Patient added successfully!\n";
            } else {
                cout << "Priority queue is full. Cannot add patient.\n";
            }
            break;
            case 2:
            if (!pq.isEmpty()) {
                p = pq.remove();
                cout << "Removed patient: " << p.name << " (Priority: " << p.priority << ")" << endl;
            } else {
                cout << "Priority queue is empty. Cannot remove patient.\n";
            }
            break;
            case 3:
            if (!pq.isEmpty()) {
                cout << "Priority Queue:\n";
                pq.display();
            } else {
                cout << "Priority queue is empty.\n";
            }
            break;
            case 4:
                cout << "Quitting program.\n";
            break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;

}