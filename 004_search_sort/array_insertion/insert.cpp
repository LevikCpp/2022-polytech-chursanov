#include <iostream>

int *insert(int arr[], int n, int x, int p)
{
    int *n_arr = new int [n];
    
    for (int i = 0; i < n; i++)
    {
        if (i == p)
        {
            n_arr[i] = x;
            n_arr[i + 1] = arr[i];
            i++;
        }
        else
        {
             n_arr[i] = arr[i];
        }
    }

    return n_arr;
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
    int test_arr[] = {1, 2, 4, 5, 6};

    auto temp = insert(test_arr, sizeof(test_arr) / sizeof(int) + 1, 3, 3);
    
    for (int i = 0; i < 5 ; i++)
    {
        std::cout << i << ") " << temp[i] << std::endl;
    }
    
    

    return 0;
}