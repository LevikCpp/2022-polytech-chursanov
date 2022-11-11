#include <cassert>

int *insert(int arr[], int n, int x, int p)
{
    for (auto i = n; i > p; i--)
    {
        arr[i] = arr[i - 1];       
    }

    arr[p] = x;
    
    return arr;
}

int search_position(int arr[], int n, int x)
{
    for (auto i = 0; i < n - 1; i++) 
    {
        if (arr[i] >= x)
        {
            return i;
        }
    }

    return n;
}

int *insert_sorted(int arr[], int n, int x)
{
    int p = search_position(arr, n, x);
    
    return insert(arr, n, x, p);
}

int main()
{
    int arr0[10] =      { 0, 1, 2, 3,      4, 5, 6, 7, 8, 9 };
    int expected0[11] = { 0, 1, 2, 3, 100, 4, 5, 6, 7, 8, 9 };

    auto r0 = insert(arr0, 10, 100, 4);
    for (auto i = 0; i < 11; i++)
    {
        assert(r0[i] == expected0[i]);
    }


    // search_position` example
    int arr1[4] = { 1, 3, 5, 6 };
    assert(search_position(arr1, 4, 5) == 2);


    // insert_sorted
    int arr2[10] =      { 0, 1, 2, 3, 4, 5,    6, 7, 8, 9 };
    int expected2[11] = { 0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9 };

    auto r4 = insert_sorted(arr2, 10, 5);
    for (auto i = 0; i < 11; i++)
    {
        assert(r4[i] == expected2[i]);
    }

    return 0;
}