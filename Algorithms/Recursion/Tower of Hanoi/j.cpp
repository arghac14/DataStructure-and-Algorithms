#include <stdio.h>
void towers(int, char, char, char);
int main()
 
{
    int num;
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}
 
void towers(int num, char beg, char aux, char end)
 
{
     if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", beg, end);
        return;
    }
    towers(num - 1, beg,end,aux);
    printf("\n Move disk %d from peg %c to peg %c", num, beg, aux);
    towers(num - 1, aux,beg,end);
 
}

