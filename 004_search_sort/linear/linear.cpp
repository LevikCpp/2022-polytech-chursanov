#include <cassert>

    const int ResaultSize = 1024;
    const int whatFind = 1;
    int arr[] = {1, 2, 3, 1, 4, 5, 1};

    int search(int arr[], int n, int x, int *result);

int main() 
{
    int result[ResaultSize] = {};
    
    assert(search(arr, sizeof(arr) / sizeof(arr[0]), whatFind, result) == 3);

  return 0;
}

int search(int arr[],  // Array itself
           int n,      // Array size
           int x,      // What to search
           int *result // Results array
) 
{

    // After we have checked the entire `arr`
    if (n == 0) 
    {
        int count = 0;
        for (int i = 0; i < ResaultSize; i++) 
        {
            if (result[i] != 0)
            {
                count++;
            }
            else
            {
                return count;
            }
        }
    } 

    else if (arr[n - 1] == x) 
    {
        for (int i = 0; i < ResaultSize; i++) 
        {
            if (result[i] == 0) 
            {
                result[i] = n - i;
                return search(arr, n - 1, x, result);
            }
        }
    
        return -1;
    }

    return search(arr, n - 1, x, result);
}