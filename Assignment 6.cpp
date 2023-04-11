#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int N, int i){
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < N && arr[l] > arr[largest])
       largest = l;
   if (r < N && arr[r] > arr[largest])
       largest = r;
   if (largest != i) {
       swap(arr[i], arr[largest]);
       heapify(arr, N, largest);
   }
}
void heapSort(int arr[], int N){
   for (int i = N / 2 - 1; i >= 0; i--)
       heapify(arr, N, i);
   for (int i = N - 1; i > 0; i--) {
       swap(arr[0], arr[i]);
       heapify(arr, i, 0);
   }
}
void printArray(int arr[], int N)
{
   for (int i = 0; i < N; ++i)
       cout << arr[i] << " ";
   cout << "\n";
}

int main()
{
   int N=50;
   int *arr = new int[51];
   time_t start, end;
   auto time_taken=double(start-end);
   int choice,p,e;
   cout<<"0. Quit\n"
         "1. n Random numbers=>Array\n"
         "2. Display the Array\n"
         "3. Sort the Array in Ascending Order by using Max-Heap Sort\n"
         "technique\n"
         "4. Sort the Array in Descending Order by using any algorithm\n"
         "5. Time Complexity to sort ascending of random data\n"
         "6. Time Complexity to sort ascending of data already sorted in\n"
         "ascending order\n"
         "7. Time Complexity to sort ascending of data already sorted in\n"
         "descending order\n"
         "8. Time Complexity to sort ascending all Cases (Data Ascending,\n"
         "Data in Descending & Random Data) in Tabular form for\n"
         "values n=5000 to 50000, step=5000\n"
         "9. Extract largest element\n"
         "10. Replace value at a node with new value\n"
         "11. Insert a new element\n"
         "12. Delete an element"<<endl;
   while(1){
       cout<<"Enter your Choice : ";
       cin>>choice;
       switch (choice) {
           case 0:
               return 0;
               break;
           case 1:
               for (int i = 0; i < N; i++) {
                   arr[i] = rand() % N;
               }
               break;
           case 2:
               cout << "Sorted array is \n";
               printArray(arr, N);
               break;
           case 3:
//                N = sizeof(arr) / sizeof(arr[0]);
               heapSort(arr, N);
               break;
           case 4:
               reverse(arr, arr + N);
               break;
           case 5:
               for (int i = 0; i < N; i++) {
                   arr[i] = rand() % N;
               }
               time(&start);
               heapSort(arr, N);
               time(&end);
               time_taken = double(end - start);
               cout << "Time taken by random data is : " << fixed << time_taken;
               cout << " sec " << endl;
               cout << endl << endl;
               break;
           case 6:
               for (int i = 0; i < N; i++) {
                   arr[i] = rand() % N;
               }
               heapSort(arr, N);
               time(&start);
               heapSort(arr, N);
               time(&end);
               time_taken = double(end - start);
               cout << "Time taken by ascending data is : " << fixed << time_taken;
               cout << " sec " << endl;
               cout << endl << endl;
               break;
           case 7:
               for (int i = 0; i < N; i++) {
                   arr[i] = rand() % N;
               }
               heapSort(arr, N);
               reverse(arr, arr + N);
               time(&start);
               heapSort(arr, N);
               time(&end);
               time_taken = double(end - start);
               cout << "Time taken by descending data is : " << fixed << time_taken;
               cout << " sec " << endl;
               cout << endl << endl;
               break;
           case 9:
               cout << "Largest element is : " << arr[N - 1] << endl;
               break;
           case 11:
               cout << "Enter pos and element to be replaced : " << endl;
               cin >> p >> e;
               arr[p] = e;
               break;
           case 12:
               cout << "Insert new element : " << endl;
               cin >> arr[51];
               break;
           case 13:
               cout << "Delete an element : " << endl;
               arr[51] = 0;
               break;
       }
   }
}
