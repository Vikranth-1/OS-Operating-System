#include <stdio.h>
#include <conio.h>
#include <dos.h>

int counter = 0;   // Step 3: Counter is maintained

// Function that simulates a job
void doSomething() {
    counter++;   // Increase job count

    // Step 4: Enter logs when job starts
    printf("\nJob %d started\n", counter);

    delay(2000);  // Simulate work (2 seconds delay)

    // Step 4: Enter logs when job finishes
    printf("Job %d finished\n", counter);
}

int main() {
    // Step 1: Start the program
    clrscr();

    printf("Program started...\n");

    // Step 2: Create number of 'threads' (jobs simulated)
    doSomething();
    doSomething();

    // Step 5: Stop the program
    printf("\nAll jobs completed.\n");

    getch();
    return 0;
}
