// C++ program to insert new element to Heap

#include <iostream>
using namespace std;

#define MAX 1000 // Max size of Heap
int arr[MAX];
int n = 0;

void delete_heapify(int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] < arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] < arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        delete_heapify(largest);
    }
}

// Function to delete the root from Heap
void deleteRoot()
{
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace root with last element
    arr[0] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the root node
    delete_heapify(0);
}

// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void insert_heapify(int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        if (arr[i] < arr[parent])
        {
            swap(arr[i], arr[parent]);

            insert_heapify(n, parent);
        }
    }
}

// Function to insert a new node to the Heap
void insertNode(int Key)
{
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = Key;

    // Heapify the new node following a
    // Bottom-up approach
    insert_heapify(n, n - 1);
}

void heapify(int brr[], int N, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && brr[l] < brr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < N && brr[r] < brr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(brr[i], brr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(brr, N, largest);
    }
}

// Function to build a Max-Heap from the given array
void buildHeap(int brr[], int N)
{
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(brr, N, i);
    }
}

void printArray()
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

int peak()
{
    return arr[0];
}

// Driver Code
int main()
{

    // int m;
    // cin >> m;

    // for (int i = 0; i < m; i++)
    // {
    //     int x;
    //     cin >> x;
    //     insertNode(x);
    // }

    // printArray();

    // int d;
    // cin >> d;

    // for (int i = 0; i < d; i++)
    // {
    //     deleteRoot();
    //     printArray();
    // }

    return 0;
}
