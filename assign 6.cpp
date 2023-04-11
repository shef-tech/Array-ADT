#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define MAX 50005
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printMin(int Min_arr[], int size)
{
    cout << "Min Heap : ";
    for (int i = 0; i < size; i++)
    {
        cout << Min_arr[i] << " ";
    }
    cout << endl;
}

void printMax(int Max_arr[], int size)
{
    cout << "Max Heap : ";
    for (int i = 0; i < size; i++)
    {
        cout << Max_arr[i] << " ";
    }
    cout << endl;
}

void minheapifybuild(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (r < N && arr[r] < arr[largest])
        largest = r;
        
    if (l < N && arr[l] < arr[largest])
        largest = l;

    if (largest != i)
    {
        swap(arr, i, largest);

        minheapifybuild(arr, N, largest);
    }
}

void maxheapifybuild(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        maxheapifybuild(arr, N, largest);
    }
}

void MaxHeapSort(int arr[], int size)
{
    int N = size;
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        maxheapifybuild(arr, N, i);
    }

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        maxheapifybuild(arr, i, 0);
    }
}

void MinHeapSort(int arr[], int size)
{
    int N = size;
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        minheapifybuild(arr, N, i);
    }

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        minheapifybuild(arr, i, 0);
    }
}

void buildHeapMax(int arr[], int N)
{
    int start = (N / 2) - 1;

    for (int i = start; i >= 0; i--)
    {
        maxheapifybuild(arr, N, i);
    }
}

void buildHeapMin(int arr[], int N)
{
    int start = (N / 2) - 1;

    for (int i = start; i >= 0; i--)
    {
        minheapifybuild(arr, N, i);
    }
}

int insert(int arr[], int arr1[], int size, int n)
{
    if (size == MAX)
    {
        return size;
    }

    arr[size] = n;
    arr1[size] = n;
    size++;

    minheapifybuild(arr1, size, 0);
    maxheapifybuild(arr, size, 0);
    return size;
}

int extractLargestMax(int arr[], int size)
{

    int n = arr[0];
    swap(arr, 0, size - 1);
    maxheapifybuild(arr, size - 1, 0);
    return n;
}

int findInd(int arr[], int size, int N)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == N)
        {
            return i;
        }
    }
    return -1;
}

main()
{
    int Max_arr[MAX];
    int Min_arr[MAX];
    int size = 0;
    int n;
    do
    {
        cout << "0.Quit\n";
        cout << "1.n Random Input\n";
        cout << "2.Display the Array\n";
        cout << "3.Sort the Array in Ascending Order by using Max-Heap Sort technique\n";
        cout << "4.Sort the Array in Descending Order by using min-Heap Sort technique\n";
        cout << "5.Time Complexity to sort ascending of random data\n";
        cout << "6.Time Complexity to sort ascending of data already sorted in ascending order\n";
        cout << "7.Time Complexity to sort ascending of data already in decending order\n";
        cout << "8.Time Complexity to sort ascending all Cases(Data Ascending,Data in Decending & Random Data) in Tabular Form for values n=5000 to 50000,step=5000\n";
        cout << "9.Extract largest Element\n";
        cout << "10.Replace value at a node with new value\n";
        cout << "11.Insert a new Element\n";
        cout << "12.Delete an Element\n";
        cout << "Enter your choice\n";
        cin >> n;

        if (n == 0)
        {
            cout << "Thank you for working with us\n";
        }
        else if (n == 1)
        {
            cout << "Enter the number of elements you want to enter\n";
            int m;
            cin >> m;
            size = m;
            srand(0);
            for (int i = 0; i < m; i++)
            {
                Max_arr[i] = rand() % (3 * m - 0 + 1) + 0;
                Min_arr[i] = Max_arr[i];
            }
        }
        else if (n == 2)
        {
            buildHeapMax(Max_arr, size);
            buildHeapMin(Min_arr, size);
            printMax(Max_arr, size);
            printMin(Min_arr, size);
        }
        else if (n == 3)
        {
            MaxHeapSort(Max_arr, size);
            printMax(Max_arr, size);
            buildHeapMax(Max_arr, size);
        }
        else if (n == 4)
        {
            MinHeapSort(Min_arr, size);
            printMin(Min_arr, size);
            buildHeapMin(Min_arr, size);
        }
        else if (n == 5)
        {
            for (int i = 0; i < size; i++)
            {
                Max_arr[i] = rand() % (size - 0 + 1) + 0;
                Min_arr[i] = Max_arr[i];
            }

            auto start = steady_clock::now();
            MaxHeapSort(Max_arr, size);
            auto stop = steady_clock::now();
            auto duration = duration_cast<microseconds>(stop - start).count();
            cout << "time taken for random data is = " << duration << endl;

            MinHeapSort(Min_arr, size);
        }
        else if (n == 6)
        {
            for (int i = 0; i < size; i++)
            {
                Max_arr[i] = i + 1;
                Min_arr[i] = Max_arr[i];
            }

            auto start = steady_clock::now();
            MaxHeapSort(Max_arr, size);
            auto stop = steady_clock::now();
            auto duration = duration_cast<microseconds>(stop - start).count();
            cout << "time taken ascending data is = " << duration << endl;

            MinHeapSort(Min_arr, size);
        }
        else if (n == 7)
        {
            for (int i = 0; i < size; i++)
            {
                Max_arr[i] = size - i;
                Min_arr[i] = Max_arr[i];
            }

            auto start = steady_clock::now();
            MaxHeapSort(Max_arr, size);
            auto stop = steady_clock::now();
            auto duration = duration_cast<microseconds>(stop - start).count();
            cout << "time taken decending data is = " << duration << endl;

            MinHeapSort(Min_arr, size);
        }
        else if (n == 8)
        {
            cout << "N value\t\tTC for Ascending\t\tTC for decending\t\tTC for Random\n";
            for (int j = 5000; j < 50000; j = j + 5000)
            {
                size = j;
                // random
                for (int i = 0; i < size; i++)
                {
                    Max_arr[i] = rand() % (size - 0 + 1) + 0;
                    Min_arr[i] = Max_arr[i];
                }

                auto start1 = steady_clock::now();
                MaxHeapSort(Max_arr, size);
                auto stop1 = steady_clock::now();
                auto durationrand = duration_cast<microseconds>(stop1 - start1).count();

                // ascending
                for (int i = 0; i < size; i++)
                {
                    Max_arr[i] = i + 1;
                    Min_arr[i] = Max_arr[i];
                }

                auto start2 = steady_clock::now();
                MaxHeapSort(Max_arr, size);
                auto stop2 = steady_clock::now();
                auto durationasc = duration_cast<microseconds>(stop2 - start2).count();

                // descending
                for (int i = 0; i < size; i++)
                {
                    Max_arr[i] = size - i;
                    Min_arr[i] = Max_arr[i];
                }

                auto start3 = steady_clock::now();
                MaxHeapSort(Max_arr, size);
                auto stop3 = steady_clock::now();
                auto durationdes = duration_cast<microseconds>(stop3 - start3).count();

                cout << j << "\t\t\t" << durationasc << "\t\t\t\t" << durationdes << "\t\t\t\t" << durationrand << endl;
                MinHeapSort(Min_arr, size);
            }
        }
        else if (n == 9)
        {
            int max = extractLargestMax(Max_arr, size);
            MinHeapSort(Min_arr, size);
            MaxHeapSort(Max_arr, size);
            minheapifybuild(Min_arr, size, 0);
            maxheapifybuild(Max_arr, size, 0);
            size--;
            cout << "Max element extracted is : " << max << endl;
        }
        else if (n == 10)
        {
            int num;
            cout << "Enter the element to be replaced\n";
            cin >> num;
            int ind1 = findInd(Max_arr, size, num);
            int ind2 = findInd(Min_arr, size, num);

            if (ind1 == -1 || ind2 == -1)
            {
                cout << "Element does'nt exist\n";
            }
            else
            {
                cout << "enter with what you want to replace\n";
                cin >> num;
                Max_arr[ind1] = num;
                Min_arr[ind2] = num;

                MinHeapSort(Min_arr, size);
                MaxHeapSort(Max_arr, size);
                minheapifybuild(Min_arr, size, 0);
                maxheapifybuild(Max_arr, size, 0);
            }
        }
        else if (n == 11)
        {
            int num;
            cout << "Enter the number to be entered\n";
            cin >> num;
            size = insert(Max_arr, Min_arr, size, num);
        }
        else if (n == 12)
        {
            int num;
            cout << "Enter the element to be Deleted\n";
            cin >> num;
            int ind1 = findInd(Max_arr, size, num);
            int ind2 = findInd(Min_arr, size, num);

            if (ind1 == -1 || ind2 == -1)
            {
                cout << "Element does'nt exist\n";
            }
            else
            {
                Max_arr[ind1] = INT16_MAX;
                Min_arr[ind2] = INT16_MIN;

                MinHeapSort(Min_arr, size);
                MaxHeapSort(Max_arr, size);
                size--;
                minheapifybuild(Min_arr, size, 0);
                maxheapifybuild(Max_arr, size, 0);
            }
        }
        else
        {
            cout << "Invalid Input\n";
        }
        cout << "\n\n";
    } while (n != 0);
}
