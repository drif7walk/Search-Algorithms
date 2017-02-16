#include <stdio.h>
#include <stdlib.h>

/* Sort using bubblesort */
void sort(int* array, int sz)
{
    int i;
    unsigned char done = 0;
    int c;

    while (done != 1)
    {
        done = 1;
        for (i = 1; i < sz-1; i++)
        {
            if (array[i] < array[i-1])
            {
                done = 0;
                c = array[i];
                array[i] = array[i-1];
                array[i-1] = c;
            }
        }

    }
}

/* Find linearly */
int findLinear(int* array, int needle, int sz)
{
    int i;

    for (i = 0; i < sz - 1; i++)
        if (array[i] == needle) return i;

    return -1;
}

/* Use binary search */
int findBinary(int* array, int needle, int sz)
{
    int min = 0;
    int max = sz;
    int mid = sz / 2;
    /* First sort the array */
    sort(array, sz);

    while (min < max && mid > min && mid < max)
    {

        if (needle > array[mid])
            min = mid;
        else if (needle < array[mid])
            max = mid;
        else return mid;

        mid = (min + max) / 2;
    }

    return -1;
}

int main()
{
    /* Initialize */
    int sz = 300;
    int i;
    int* array = malloc(sz * sizeof(int));
    int needle;
    int index;

    srand(time(NULL));

    /* Define values in array */
    for (i = 0; i < sz-1;i++)
        array[i] = rand() % 500;

    printf("Linear search:\r\n");
    printf("Needle: %i\r\n", (needle = rand() % 10));

    index = findLinear(array, needle, sz);

    if (index > -1)
    {
        printf("Needle found! Index: %i\r\n", index);
        printf("     %i     %i     %i     \r\n", array[index-1], array[index], array[index+1]);

        printf("... [%i]   [%i]   [%i] ...\r\n", index-1, index, index+1);
    }
    else
    {
        printf("%i not found in array.\r\n", index);
    }

    printf("\r\nBinary search:");
    printf("Needle: %i\r\n", needle);

    index = findBinary(array, needle, sz);

    if (index > -1)
    {
        printf("Needle found! Index: %i\r\n", index);
        printf("     %i     %i     %i     \r\n", array[index-1], array[index], array[index+1]);

        printf("... [%i]   [%i]   [%i] ...\r\n", index-1, index, index+1);
    }
    else
    {
        printf("%i not found in array.\r\n", index);
    }
    /* Display array sorting */
    //for (i = 0; i < sz-1; i++)
        //printf("%i ", array[i]);

    free(array);
    return 0;
}
