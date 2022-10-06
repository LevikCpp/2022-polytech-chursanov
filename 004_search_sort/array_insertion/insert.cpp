#include <iostream>

int *insert(int arr[], int n, int x, int p)
{
    for (auto i = n + 1; i > p; i--)
    {
        arr[i] = arr[i - 1];       
    }

    arr[p] = x;
    
    return arr;
}

int search_position(int arr[], int n, int x)
{
    for (auto i = 0; i < n - 1; ++i) 
    {
        if (arr[i] >= x)
        {
            return i;
        }
    }

    return n;
}

int main()
{
    int test_arr[] = {1, 2, 3, 5, 6};

    auto temp = insert(test_arr, (sizeof(test_arr) / sizeof(int)) + 1, 4, 3);
    
    for (int i = 0; i < 6 ; i++)
    {
        std::cout << i << ") " << temp[i] << std::endl;
    }
    
    

    return 0;
}