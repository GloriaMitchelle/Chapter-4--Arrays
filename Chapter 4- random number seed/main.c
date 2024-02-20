#include <stdio.h>
#define MAX 10

int a[MAX];
int rand_seed = 10; // Initial seed value, you can change this

int rand(void)
{
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int)(rand_seed / 65536) % 32768;
}

void bubble_sort(void)
{
    int t, x, y;

    // Bubble sort the array
    for (x = 0; x < MAX - 1; x++)
    {
        for (y = 0; y < MAX - x - 1; y++)
        {
            if (a[y] > a[y + 1])
            {
                t = a[y];
                a[y] = a[y + 1];
                a[y + 1] = t;
            }
        }
    }
}

int main(void)
{
    int i;

    // Initialize the random number seed to a different value
    rand_seed = 42; // You can change this value

    // Fill the array with random numbers
    for (i = 0; i < MAX; i++)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }

    // Call the bubble_sort function
    bubble_sort();

    // Print the sorted array
    printf("--------------\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
