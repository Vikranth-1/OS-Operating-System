#include <stdio.h>

int main() {
    int ref[50], frame[10], freq[10] = {0};
    int n, f, i, j, pos, faults = 0, found, min;

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frame[i] = -1;
        freq[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if page exists in frame
        for (j = 0; j < f; j++) {
            if (frame[j] == ref[i]) {
                freq[j]++;  // increase frequency
                found = 1;
                break;
            }
        }

        // If not found, replace least frequently used page
        if (!found) {
            pos = 0;
            for (j = 1; j < f; j++)
                if (freq[j] < freq[pos])
                    pos = j;

            frame[pos] = ref[i];
            freq[pos] = 1;
            faults++;
        }

        printf("\nFrames after reference %d: ", ref[i]);
        for (j = 0; j < f; j++)
            if (frame[j] != -1)
                printf("%d(%d) ", frame[j], freq[j]);
            else
                printf("- ");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
