#include <iostream>

using namespace std;

//to heapify a subtree rooted with node i which is an index in arr[]. n is size of heap.
void heapify(int arr[], int n, int i)
{
  int largest = i; //initialize largest root
  int l = 2*i + 1; //left
  int r = 2*i + 2; //right

  //if left child is larger than root
  if(l < n && arr[l] > arr[largest])
  {
    largest = l;
  }

  //if right child is larger than current largest
  if(r < n && arr[r] > arr[largest])
  {
    largest = r;
  }

  //if largest is not root
  if(largest != i)
  {
    swap(arr[i], arr[largest]);

    //recursively heapify the affected subtree
    heapify(arr, n, largest);
  }
}

//main function for heapSort
void heapSort(int arr[], int n)
{
  //build heap (rearrange array)
  for(int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  //one by one extracting element from heap 
  for(int i = n - 1; i >= 0; i--)
  {
    //move current root to end
    swap(arr[0], arr[i]);

    //call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

void printArray(int arr[], int n)
{
  for(int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr, n);

  cout << "Sorted array: \n";
  printArray(arr, n);

  return 0;
}
