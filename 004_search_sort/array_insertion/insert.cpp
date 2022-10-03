#include <iostream>

int *insert(int arr[], int x, int p)
{
    int *n_arr = new int [sizeof(arr) / sizeof(arr[0]) + 1];
    
    for (int i = 0; i < sizeof(n_arr) / sizeof(n_arr[0]); i++)
    {
        if (i == p)
        {
            n_arr[i] = x;
        }
        else
        {
             n_arr[i] = arr[i];
        }
    }

    return n_arr;
}

int main()
{
    int test_arr[] = {1, 2, 4, 5, 6};

    int temp_arr[] = {*insert(test_arr, 3, 3)};
    
    for (int i = 0; i < 6 ; i++)
    {
        std::cout << temp_arr[i];
    }
    
    

    return 0;
}