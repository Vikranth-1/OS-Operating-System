#include <stdio.h>

int main() {
    int ref[50], frame[10], n, f, i, j, k = 0, faults = 0, found;

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // If not found, replace the oldest (FIFO)
        if (!found) {
            frame[k] = ref[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("\nFrames after reference %d: ", ref[i]);
        for (j = 0; j < f; j++)
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
