#include <iostream>

using namespace std;

float weight[] = {80, 140, 70, 300, 500, 250, 400, 700, 350};
float amount[] = {2000, 2500, 1900, 4000, 6000, 3000, 7000, 6500, 3500};
float A_W[9];

void insertionSort(float[], float[], float[], int);

int main()
{
    float ans = 0, maxWeight = 1000;
    for (int i = 0; i < 9; i++)
    {
        A_W[i] = amount[i] / weight[i];
    }
    insertionSort(A_W, amount, weight, 9);
    int i;
    for (i = 0; i < 9; i++)
    {
        if (maxWeight > 0 && weight[i] < maxWeight)
        {
            maxWeight = maxWeight - weight[i];
            ans = ans + amount[i];
        }
        else
        {
            break;
        }
    }
    if (maxWeight > 0)
    {
        ans = ans + A_W[i] * maxWeight;
    }
    cout << "Max profit is: " << ans;
}
void insertionSort(float arr[], float amount[], float weight[], int n)
{
    for (int j = 1; j < 9; j++)
    {
        float key1 = arr[j];
        float key2 = amount[j];
        float key3 = weight[j];
        int i = j - 1;
        while (i > 0 && arr[i] < key1)
        {
            arr[i + 1] = arr[i];
            amount[i + 1] = amount[i];
            weight[i + 1] = weight[i];
            i = i - 1;
        }
        arr[i + 1] = key1;
        amount[i + 1] = key2;
        weight[i + 1] = key3;
    }
}
