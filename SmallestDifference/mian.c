#include <stdio.h>

void selectionSort(int *a, int l)
{

    int elementsOrdered = 0;

    int smallestElementI = 0;

    while (elementsOrdered < l - 1)
    {
        smallestElementI = elementsOrdered;

        for (int i = elementsOrdered + 1; i < l; i++)
        {
            if (a[smallestElementI] > a[i])
            {
                smallestElementI = i;
            }
        }

        int h = a[smallestElementI];
        a[smallestElementI] = a[elementsOrdered];
        a[elementsOrdered] = h;

        elementsOrdered++;
    }
}

int main(int argc, char const *argv[])
{

    int l1 = 0;
    int l2 = 0;

    printf(": ");
    scanf("%d %d", &l1, &l2);

    int values1[l1];
    int values2[l2];

    for (int i = 0; i < l1; i++)
    {
        scanf(" %d", &values1[i]);
    }

    for (int i = 0; i < l2; i++)
    {
        scanf(" %d", &values2[i]);
    }

    selectionSort(values1,l1);
    selectionSort(values2,l2);

/*
    for(int i=0 ; i<l1 ; i++)
        printf("%d ",values1[i]);

    printf("\n");

    for(int i=0 ; i<l2 ; i++)
        printf("%d ",values2[i]);

    printf("\n");

    */
    int sd1I = 0;
    int sd2I = 0;

    int sd = 2147483647;

    for(int i=0,y=0;i<l1&&y<l2;)
    {
        int diff = values1[i]-values2[y];

        if(diff<0)
            diff*=-1;

        //printf("%d (%d %d)\n",diff,values1[i],values2[y]);


        if(diff<sd )
        {
            sd1I=i;
            sd2I=y;
            sd = diff;
        }

        if(values1[i]>values2[y])
        {
            y++;
        }else{
            i++;
        }

    }

    printf("%d (%d, %d)",sd,values1[sd1I],values2[sd2I]);
    return 0;
}
