#include <stdio.h>

struct ant
{
    int x;
    int y;
    char direction;
};

void turnLeft(struct ant* a)
{
    switch(a->direction)
    {
        case 'n' :
            a->direction = 'w';
            break;
            
        case 'e' :
            a->direction = 'n';
            break;
            
        case 's' :
            a->direction = 'e';
            break;
            
        case 'w' :
            a->direction = 's';
            break;
    }

}

void turnRight(struct ant* a)
{
    switch(a->direction)
    {
        case 'n' :
            a->direction = 'e';
            break;
            
        case 'e' :
            a->direction = 's';
            break;
            
        case 's' :
            a->direction = 'w';
            break;
            
        case 'w' :
            a->direction = 'n';
            break;
    }

}

void moveForward(struct ant* a)
{
    switch(a->direction)
    {
        case 'n' :
            a->y = a->y - 1;
            break;
            
        case 'e' :
            a->x = a->x + 1;
            break;
            
        case 's' :
            a->y = a->y + 1;
            break;
            
        case 'w' :
            a->x = a->x - 1;
            break;
    }
}

void printArray(char p[10][10]){
    for(int i = 0;i<10;i++){
        for(int y = 0;y<10;y++){
            printf("%c",p[i][y]);
        }
            printf("\n");
    }
}

int main(int argc, char const *argv[])
{

    struct ant a = {0, 0, 'w'};

    int turns = 0;

    printf("Enter number of turns: ");
    scanf(" %d",&turns);

    printf("Enter start position: ");
    scanf("%d %d",&a.x,&a.y);


    char field[10][10];

    for(int i = 0;i<10;i++){
        for(int y = 0;y<10;y++){
            field[i][y]='.';
        }
    }

    for( int i=0 ; i<turns ; i++)
    {

        if(field[a.y][a.x]=='.')
        {
            turnRight(&a);
            field[a.y][a.x]='#';
        }else{
            turnLeft(&a);
            field[a.y][a.x]='.';
        }

        moveForward(&a);

        if(  a.x<0 || a.x>9 || a.y<0 || a.y>9  )
        {
            printArray(field);
            return 0;
        }
    }

    if(field[a.y][a.x]=='.')
    {
        field[a.y][a.x]='a';
    }else{
        field[a.y][a.x]='A';
    }

    printArray(field);
            
    return 0;
}
