void merge(int *left, int *right, int *ptr, int leftSize, int rightSize)
{
    int leftIndex = 0;
    int rightIndex = 0;
    int index = 0;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            ptr[index] = left[leftIndex];
            leftIndex++;
        }
        else
        {
            ptr[index] = right[rightIndex];
            rightIndex++;
        }
        index++;
    }
    while (leftIndex < leftSize)
    {
        ptr[index] = left[leftIndex];
        leftIndex++;
        index++;
    }
    while (rightIndex < rightSize)
    {
        ptr[index] = right[rightIndex];
        rightIndex++;
        index++;
    }
}
