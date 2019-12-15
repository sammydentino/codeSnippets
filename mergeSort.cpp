#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  
  //create temp sub-arrays
  int L[n1], R[n2];
  
  //copy data to temp arrays L[] and R[]
  for(i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
  }
  for(j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
  }
  
  //merge temp arrays back into arr[1...r]
  i = 0; //initial index of first sub-array
  j = 0; //initial index of second sub-array
  k = l; //initial index of merged sub-array
  
  while(i < n1 && j < n2)
  {
    if(L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  //copy remaining elements of L[] if there are any
  while(i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
  //copy remaining elements of R[] if there are any
  while(j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    //same as (l+r)/2, but avoids overflow for large l and h
    int m = l + (r - 1)/2;
    
    //sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    
    merge(arr, l, m, r);
  }
}

void printArray(int A[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  
  cout << "Given array is: \n";
  printArray(arr, arr_size);
  
  mergeSort(arr, 0, arr_size - 1);
  
  cout << "\nSorted array is \n";
  printArray(arr, arr_size);
  
  return 0;
}
