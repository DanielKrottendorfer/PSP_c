
#include <stdio.h>

int main(int argc, char const *argv[])
{

    printf("Enter numbers: ");

    int arr[1024];
    int l = 0;
    while (l < 1024)
    {
        scanf("%d", &arr[l]);
        if (arr[l] == 0)
        {
            break;
        }

        l++;
    }

    printf("\n");

    int elementsOrdered = 0;
    int comparisonC = 0;
    int swapC = 0;
    while (elementsOrdered < l - 1)
    {

        int smallestElementI = elementsOrdered;
        for (int i = elementsOrdered + 1; i < l; i++)
        {
            comparisonC++;
            if (arr[smallestElementI] > arr[i])
            {
                smallestElementI = i;
            }
        }

        printf("Step %d: ", elementsOrdered + 1);

        for (int i = 0; i < l; i++)
        {

            if (i == smallestElementI)
                printf("[");
            if (i == elementsOrdered)
                printf("(");

            printf("%d", arr[i]);

            if (i == elementsOrdered)
                printf(")");
            if (i == smallestElementI)
                printf("]");

            printf(" ");
        }
        int h = arr[smallestElementI];
        arr[smallestElementI] = arr[elementsOrdered];
        arr[elementsOrdered] = h;
        swapC++;

        elementsOrdered++;
        printf("\n");
    }
    printf("Result: ");
    for(int i=0 ; i<l ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    printf("Number of comparisons: %d\n", comparisonC);
    printf("Number of swaps: %d", swapC);

    return 0;
}
