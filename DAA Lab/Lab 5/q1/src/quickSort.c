void quickSort(int *ptr, int size)
{
    if (size <= 1)
    {
        return;
    }
    int pivot = ptr[size - 1];
    int i = 0;
    int j = 0;
    while (j < size - 1)
    {
        if (ptr[j] < pivot)
        {
            int temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;
            i++;
        }
        j++;
    }
    int temp = ptr[i];
    ptr[i] = ptr[size - 1];
    ptr[size - 1] = temp;
    quickSort(ptr, i);
    quickSort(ptr + i + 1, size - i - 1);
}
