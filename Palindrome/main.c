
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char str[41];

    printf("Enter a message: ");
    fgets(str, 41, stdin);

    int l = 41;

    while (str[l] != 10 && l>0)
        l--;

    if(l==0)
        l = 41;

    for (int i = 0; i < l; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

    int lB = 0, rB = l;

    while (!(str[lB] >= 'a' && str[lB] <= 'z'))
        lB++;

    while (!(str[rB] >= 'a' && str[rB] <= 'z'))
        rB--;

    while ((rB - lB) > 1)
    {

        while (!(str[lB] >= 'a' && str[lB] <= 'z'))
            lB++;

        while (!(str[rB] >= 'a' && str[rB] <= 'z'))
            rB--;

        if (str[lB] != str[rB])
        {
            printf("Not a palindrome");
            return 0;
        }

        lB++;
        rB--;
    }

    printf("Palindrome");

    return 0;
}