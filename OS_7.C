#include <stdio.h>
#include <conio.h>

int main() {
    int frameno, pagesize, offset, phyadd;

    clrscr();

    printf("=== Paging Simulation ===\n\n");

    // Input values
    printf("Enter Frame Number : ");
    scanf("%d", &frameno);

    printf("Enter Page Size : ");
    scanf("%d", &pagesize);

    printf("Enter Offset : ");
    scanf("%d", &offset);

    // Calculate physical address
    phyadd = (frameno * pagesize) + offset;

    // Output result
    printf("\nPhysical Address is : %d", phyadd);

    getch();
    return 0;
}

