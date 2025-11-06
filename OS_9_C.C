#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct block {
    int bno;           
    struct block *next;   
};

struct fileTable {
    char name[20];       
    int nob;            
    struct block *sb;     
} ft[30];

void main() {
    int i, j, n;
    char s[20];
    struct block *temp;

    clrscr(); 

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);

        ft[i].sb = (struct block *)malloc(sizeof(struct block));
        temp = ft[i].sb;

        printf("Enter the block numbers of the file: ");
        scanf("%d", &temp->bno);
        temp->next = NULL;

        for (j = 1; j < ft[i].nob; j++) {
            temp->next = (struct block *)malloc(sizeof(struct block));
            temp = temp->next;
            scanf("%d", &temp->bno);
            temp->next = NULL;
        }
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("\nFile not found.\n");
    } else {
        printf("\nFILE NAME\tNO. OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t", ft[i].name, ft[i].nob);

        temp = ft[i].sb;
        while (temp != NULL) {
            printf("%d -> ", temp->bno);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    getch(); 
}
