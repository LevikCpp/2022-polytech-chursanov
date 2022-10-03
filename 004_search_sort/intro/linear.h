int linear_search(const int sequence[], const int num, const int len) 
{
    for (int i = 0; i < len; i++) 
    {
        if (sequence[i] == num) 
        {
            return i;
        }
    }

    return -1;
}