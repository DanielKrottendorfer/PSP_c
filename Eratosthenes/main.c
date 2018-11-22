#include <stdio.h>
#include <math.h>

int isPrime(int number)
{
    int i, r, prime = 1;
    if (number != 2 && number % 2 == 0)
        prime = 0;
    else
        for (i = 3, r = sqrt(number); i <= r && prime; i += 2)
            if (number % i == 0)
                prime = 0;
    return prime;
}

int main(void)
{

    printf(": ");

    int n = 0;

    scanf("%d", &n);

    n++;

    int num[n];

    for (int i = 0; i < n; i++)
    {
        num[i] = i;
    }

    for(int i=2 ; i<n ; i++){

        //printf("%d %d \n",i,num[i]);
        if(num[i]==0)
            continue;

        if(isPrime(num[i]))
        {
            for(int y=i*i ; y<n ; y*=y){
                //printf("%d %d \n",y,num[y]);
                num[y] = 0;
            }
        }else{
            num[i] = 0;
        }

    }

    for (int i = 2, y = 0; i < n; i++)
    {
        if(num[i]==0)
            continue;


        if (y == 10)
        {
            printf("\n");
            y=0;
        }
        y++;
        printf("%d ", num[i]);
    }
    return 0;
}