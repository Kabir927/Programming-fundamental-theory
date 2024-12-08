#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int *ratings;
    int totalScore;
};
void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
	int i;
    for (i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        int j;
        for (j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d: ", j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
	int i;
    for ( i = 0; i < numEmployees; i++) {
        printf("Employee %d:\n", i + 1);
        int j;
        for (j = 0; j < numPeriods; j++) {
            printf("Period %d: %d\n", j + 1, ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int maxAvgIndex = 0;
    double maxAvg = 0.0;
int i;
    for (i = 0; i < numEmployees; i++) {
        double avg = 0.0;
        int j;
        for (j = 0; j < numPeriods; j++) {
            avg += ratings[i][j];
        }
        avg /= numPeriods;
        if (avg > maxAvg) {
            maxAvg = avg;
            maxAvgIndex = i;
        }
    }
    return maxAvgIndex;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int maxPeriod = 0;
    double maxAvg = 0.0;
	int i;
    for ( i = 0; i < numPeriods; i++) {
        double avg = 0.0;
        int j;
        for ( j = 0; j < numEmployees; j++) {
            avg += ratings[j][i];
        }
        avg /= numEmployees;

        if (avg > maxAvg) {
            maxAvg = avg;
            maxPeriod = i;
        }
    }

    return maxPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int minAvgIndex = 0;
    double minAvg = 10.0;
int i;
    for (i = 0; i < numEmployees; i++) {
        double avg = 0.0;
        int j;
        for (j = 0; j < numPeriods; j++) {
            avg += ratings[i][j];
        }
        avg /= numPeriods;

        if (avg < minAvg) {
            minAvg = avg;
            minAvgIndex = i;
        }
    }

    return minAvgIndex;
}

int main() {
    int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    int i;
    for (i = 0; i < numEmployees; i++) {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: %d\n", highestRatedPeriod + 1);

    int worstPerformingEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: %d\n", worstPerformingEmployee + 1);

    for (i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
