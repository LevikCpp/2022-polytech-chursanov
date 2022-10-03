#include <cassert>

int binary_search(const int seq[], const int num, int high, int low) 
{
    while (high - low > 1) 
    {
        const int mid = (high + low) / 2;
        
        if (seq[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (high == num)
    { 
        return high;
    }

    return low;
}

int main() 
{
    int seq[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    assert(binary_search(seq, 6, 9, 0) == 6);
    assert(binary_search(seq, 1, 9, 0) == 1);

    return 0;
}