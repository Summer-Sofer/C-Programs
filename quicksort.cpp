clude <iostream>
 using namespace std;

 void quicksort(int a[], int start, int last);
 int partition(int a[], int start, int last);

 int main()
 {
     int arr[10] = { 2, 5, -2, 0, 50, 7, 40, 100, -5, 10};
     quicksort(arr, 0, 9);
     for (int i = 0; i < 10; i++)
         cout << arr[i] << endl;
     return 0;
 }

 int partition(int a[], int start, int last)
 {
     // take the pivot to be at the start of the range to be partitioned
     int pivotValue = a[start]; // start at posiiton 0
     int pivotPosition = start;
     for (int i = start; i < last; i++)
      cout << a[i] << " ";
      cout << endl;

     // rearrange the array to partition the range from start to end
     for (int pos = start + 1; pos <= last; pos++)
     {
         if (a[pos] < pivotValue) // this means number is before pivot value
         {
             swap(a[pivotPosition + 1], a[pos]);
             swap(a[pivotPosition], a[pivotPosition + 1]);
             // notice we moved the pivot
             // it must be repositioned
             pivotPosition++;
         }
     }
     for (int i = start; i < last; i++)
      cout << a[i] << " ";
      cout << endl;
      cout << "Pivot Position: " << pivotPosition << endl;
      cout << "Pivot Value: " << pivotValue << endl;
     return pivotPosition;
 }

 void quicksort(int a[], int start, int last)
 {
     if (start < last)
     {
         // partition the array and get the pivot position
         cout << "DOING PARTITION " << endl;
         int pivot = partition(a, start, last); // index of pivot
         // sort the array portion before the pivot
         quicksort(a, start, pivot - 1);
         // sort the other portion of the array after the pivot
         quicksort(a, pivot + 1, last);
     }
 }
