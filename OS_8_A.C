#include <stdio.h>

int main() {
    int ref[50], frame[10], freq[10] = {0};
    int n, f, i, j, k, min, pos, faults = 0, found;

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

        for (j = 0; j < f; j++) {
            if (frame[j] == ref[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            faults++;
            pos = 0;
            min = freq[0];

            for (k = 1; k < f; k++) {
                if (freq[k] < min) {
                    min = freq[k];
                    pos = k;
                }
            }

            frame[pos] = ref[i];
            freq[pos] = 1;
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
