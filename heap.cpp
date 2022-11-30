#include <iostream>
using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int right(int i) {
    return i * 2 + 2;
}

int left(int i) {
    return i * 2 + 1;
}

void heapify(int arr[], int i, int size, bool isMax) {
    int L = left(i);
    int R = right(i);
    int MAX = i;

    if (isMax) {
        if (L < size && arr[L] > arr[MAX]) {
            MAX = L;
        }
        if (R < size && arr[R] > arr[MAX]) {
            MAX = R;
        }
        if (MAX != i) {
            swap(arr[i], arr[MAX]);
            heapify(arr, MAX, size, isMax);
        }
    }
    else {
        if (L < size && arr[MAX] > arr[L]) {
            MAX = L;
        }
        if (R < size && arr[MAX] > arr[R]) {
            MAX = R;
        }
        if (MAX != i) {
            swap(arr[i], arr[MAX]);
            heapify(arr, MAX, size, isMax);
        }
    }
}

int main() {
    char input;
    bool isMax = true;


    int* heap;
    int size = 0;
    int capacity = 1;
    heap = new int[capacity];

    while (cin >> input) {
        if (input == '+') {
            int n;
            cin >> n;

            if ((size + 1) >= capacity) {
                int* nHeap;
                capacity = (size + 1) * 2;
                nHeap = new int[capacity];
                for (int i = 0; i < size; i++) {
                    nHeap[i] = heap[i];
                }
                delete[] heap;
                heap = nHeap;
            }
            heap[size] = n;
            size++;

            int child = size - 1;
            int theparent = parent(child);

            if (isMax) {
                while (child > 0 && heap[child] > heap[theparent]) {
                    swap(heap[child], heap[theparent]);
                    child = theparent;
                    theparent = parent(child);
                }
            }
            else {
                while (child > 0 && heap[theparent] > heap[child]) {
                    swap(heap[child], heap[theparent]);
                    child = theparent;
                    theparent = parent(child);
                }
            }
        }
        if (input == '-') {
            cout << heap[0] << endl;
            heap[0] = heap[size - 1];
            size--;
            heapify(heap, 0, size, isMax);
        }
        if (input == 'p') {
            for (int i = 0; i < size; i++) {
                cout << heap[i] << ' ';
            }
            cout << endl;
        }
        if (input == 'r') {
            int n;
            cin >> n;
            capacity = n * 2;
            size = n;
            int* nHeap;
            capacity = (size + 1) * 2;
            nHeap = new int[capacity];
            for (int i = 0; i < size; i++) {
                cin >> nHeap[i];
            }
            delete[] heap;
            heap = nHeap;
            for (int i = size; i >= 0; i--) {
                heapify(heap, i, size, isMax);
            }
        }
        if (input == 's') {
            if (isMax) isMax = false;
            else isMax = true;
            for (int i = size; i >= 0; i--) {
                heapify(heap, i, size, isMax);
            }
        }
        if (input == 'q') {
            break;
        }
    }

    return 0;
}