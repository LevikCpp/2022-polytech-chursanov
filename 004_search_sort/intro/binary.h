int binary_search(const int sequence[], const int num, const int high, const int low)
{
    const int mid = (high + low) / 2;

    if (high == low) 
    {
        return -1;
    }
    if (sequence[mid] < num) 
    {
        return binary_search(sequence, num, high, mid);
    } 
    else if (sequence[mid] > num) 
    {
        return binary_search(sequence, num, mid, low);
    } 
    else 
    {
        return mid;
    }
}