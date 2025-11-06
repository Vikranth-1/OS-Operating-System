#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main() {
    int f[50], i, st, len, j, c, k, count;

    clrscr();


    for (i = 0; i < 50; i++)
        f[i] = 0; // 0 means unallocated

    printf("Sequential File Allocation Method\n");

    printf("Files allocated are:\n");

    while (1) {
        count = 0;
        printf("\nEnter starting block and length of file: ");
        scanf("%d%d", &st, &len);

        for (k = st; k < (st + len); k++) {
            if (f[k] == 0)
                count++;
        }

        if (len == count) {
            for (j = st; j < (st + len); j++) {
                if (f[j] == 0) {
                    f[j] = 1; 
                    printf("%d\t%d\n", j, f[j]);
                }
            }
            printf("The file is successfully allocated to disk.\n");
        } else {
            printf("The file cannot be allocated (blocks already occupied).\n");
        }

        printf("\nDo you want to enter more files? (Yes-1 / No-0): ");
        scanf("%d", &c);

        if (c == 0)
            break;
    }

    printf("\nFile Allocation Table:\n");
    printf("Block\tStatus\n");
    for (i = 0; i < 50; i++)
        printf("%d\t%d\n", i, f[i]);

    printf("\nProgram ended.\n");

    getch(); // Wait for key press before closing Turbo C output window
}
