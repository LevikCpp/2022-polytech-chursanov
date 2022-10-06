#include <iostream>

int *insert(int arr[], int n, int x, int p)
{
    int *n_arr = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        if (i < p)
        {
            n_arr[i] = arr[i];
        }
        else
        {
            if (i == p)
            {
                n_arr[i] = x;
            }
            else
            {
                n_arr[i] = arr[i - 1];
            }
        }
    }
    
    return n_arr;
}

int main()
{
    int array[5] = {0,1,2,4,5};
    auto answer = insert(array, sizeof(array)/sizeof(int), 3, 3);

    for (int i = 0; i < 6; i++)
    {
        std::cout << i << ')' << answer[i];
    }

    return 0;
}