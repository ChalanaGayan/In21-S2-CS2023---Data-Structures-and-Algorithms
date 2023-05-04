#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root; 
    int l = 2*root + 1; 
    int r = 2*root + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }  
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    string input;
    cout << "Enter the number list (with spaces between): ";
    getline(cin, input);
    
    vector<int> heap_arr;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        heap_arr.push_back(num);
    }
    
    int n = heap_arr.size();
    cout<<"Input array"<<endl;
    displayArray(heap_arr.data(),n);

    heapSort(heap_arr.data(), n);
    cout << "Sorted array"<<endl;
    displayArray(heap_arr.data(), n);
    return 0;
}