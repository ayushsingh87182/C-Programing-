#include <stdio.h>

void Towers_Hanoi(int n, char src, char dest, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }

    Towers_Hanoi(n-1, src, aux, dest);

    printf("Move disk %d from %c to %c\n", n, src, dest);

    Towers_Hanoi(n-1, aux, dest, src);
}

int main()
{
    int n;

    printf("How many disks?\n");
    scanf("%d", &n);

    Towers_Hanoi(n, 'A', 'C', 'B');

    return 0;
}