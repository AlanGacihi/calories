#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_EXERCISES 37
#define MAX_LINE 105

// Function to read exercise names and MET values from a file
void readExerciseData(char exercises[][MAX_LINE], double metValues[]);

int main() {
    char exercises[NUM_EXERCISES][MAX_LINE];
    double metValues[NUM_EXERCISES];

    // Read exercise data from the file
    readExerciseData(exercises, metValues);

    // Change stdin
    freopen("/dev/tty", "rw", stdin);

    // Declare variables to store user input and calculated values
    double weight, duration, totalCal;
    int userChoice;

    // Prompt the user for their weight (in pounds)
    printf("Enter your weight (pounds): ");
    scanf("%lf", &weight);

    do {
        // Display the list of exercises and prompt the user to choose one
        printf("\n\n");
        for (int i = 0; i < NUM_EXERCISES; i++) {
            printf("%d. %s\n", i + 1, exercises[i]);
        }
        printf("Choose exercise number: ");
        scanf("%d", &userChoice);

        // Prompt the user for the exercise duration (in minutes)
        printf("Enter exercise duration (minutes): ");
        scanf("%lf", &duration);

        // Calculate total calories burned using the formula
        totalCal = duration * (metValues[userChoice - 1] * 3.5 * (weight / 2.205)) / 200;

        // Display the total calories burned
        printf("The total calories burned: %.1lf\n\n", totalCal);

        // Ask the user if they want to choose another exercise
        printf("Would you like to choose another exercise? (1 for yes, 0 for no): ");
        scanf("%d", &userChoice);

    } while (userChoice == 1);

    return 0;
}

void readExerciseData(char exercises[][MAX_LINE], double metValues[]) {
    for (int i = 0; i < NUM_EXERCISES; i++) {
        // Read exercise name with spaces
        fgets(exercises[i], MAX_LINE, stdin);
        // Remove the trailing newline character
        exercises[i][strcspn(exercises[i], "\n")] = '\0';
        // Read MET value
        scanf("%lf", &metValues[i]);
    }
    for (int i = 0; i < NUM_EXERCISES; i++) {
        printf("%lf\n", metValues[i]);
    }

}
