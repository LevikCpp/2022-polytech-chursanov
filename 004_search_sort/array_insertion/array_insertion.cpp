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
    int test_arr[] = {1, 2, 3, 5, 6};
    int num = 4;
    auto temp = insert(test_arr, (sizeof(test_arr) / sizeof(int)), num, 3);
    
    //------1
    std::cout << "Test 1" "\n";

    for (int i = 0; i < (sizeof(test_arr) / sizeof(int)) + 1; i++)
    {
        std::cout << i << ") " << temp[i] << "\n";
    }

    //delete temp;
    

    //------2
    auto temp2 = search_position(test_arr, (sizeof(test_arr) / sizeof(int)) + 1, num);

    std::cout << "Test 2" "\n";

    std::cout << "Position of " << num << " is " << temp2 << std::endl;
    
    if (temp2 == 4)
    {
        std::cout << "true" << std::endl;
    }
    
    
    //------3
    auto temp3 = insert_sorted(test_arr, 10, 5);
    
    std::cout << "Test 3" "\n";

    for (auto i = 0; i < (sizeof(test_arr) / sizeof(int)) + 1; ++i)
    {
        std::cout << i << ") " << temp3[i] << "\n";
    }

    //delete temp3;


    return 0;
}