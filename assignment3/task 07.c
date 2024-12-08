#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char title[50];          
    float rating;            
    int runtime;            
    char encoding_formats[30]; 
} ContentMetadata;
typedef struct {
    int resolution_preference; 
    char playback_history[100]; 
    float bandwidth_usage;     
} DevicePreference;
double **allocate_engagement_matrix(int users, int categories) {
    double **matrix = (double **)malloc(users * sizeof(double *));
    for (int i = 0; i < users; i++) {
        matrix[i] = (double *)malloc(categories * sizeof(double));
    }
    return matrix;
}
DevicePreference ***allocate_device_matrix(int users, int devices) {
    DevicePreference ***matrix = (DevicePreference ***)malloc(users * sizeof(DevicePreference **));
    for (int i = 0; i < users; i++) {
        matrix[i] = (DevicePreference **)malloc(devices * sizeof(DevicePreference *));
        for (int j = 0; j < devices; j++) {
            matrix[i][j] = (DevicePreference *)malloc(sizeof(DevicePreference));
        }
    }
    return matrix;
}

ContentMetadata ***allocate_content_matrix(int categories, int items) {
    ContentMetadata ***matrix = (ContentMetadata ***)malloc(categories * sizeof(ContentMetadata **));
    for (int i = 0; i < categories; i++) {
        matrix[i] = (ContentMetadata **)malloc(items * sizeof(ContentMetadata *));
        for (int j = 0; j < items; j++) {
            matrix[i][j] = (ContentMetadata *)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}
void input_engagement_matrix(double **matrix, int users, int categories) {
    printf("Enter engagement scores (e.g., viewing time) for each user and category:\n");
    for (int i = 0; i < users; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < categories; j++) {
            printf("  Category %d: ", j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void input_device_matrix(DevicePreference ***matrix, int users, int devices) {
    printf("Enter device preferences for each user and device:\n");
    for (int i = 0; i < users; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < devices; j++) {
            printf("  Device %d:\n", j + 1);
            printf("    Resolution preference (e.g., 1080): ");
            scanf("%d", &matrix[i][j]->resolution_preference);
            printf("    Playback history: ");
            scanf(" %[^\n]s", matrix[i][j]->playback_history);
            printf("    Bandwidth usage (in MB): ");
            scanf("%f", &matrix[i][j]->bandwidth_usage);
        }
    }
}
void input_content_matrix(ContentMetadata ***matrix, int categories, int items) {
    printf("Enter content metadata for each category and item:\n");
    for (int i = 0; i < categories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < items; j++) {
            printf("  Item %d:\n", j + 1);
            printf("    Title: ");
            scanf(" %[^\n]s", matrix[i][j]->title);
            printf("    Rating: ");
            scanf("%f", &matrix[i][j]->rating);
            printf("    Runtime (in minutes): ");
            scanf("%d", &matrix[i][j]->runtime);
            printf("    Encoding formats: ");
            scanf(" %[^\n]s", matrix[i][j]->encoding_formats);
        }
    }
}
void display_engagement_matrix(double **matrix, int users, int categories) {
    printf("\nEngagement Matrix:\n");
    for (int i = 0; i < users; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < categories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}
void display_device_matrix(DevicePreference ***matrix, int users, int devices) {
    printf("\nDevice Preferences:\n");
    for (int i = 0; i < users; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < devices; j++) {
            printf("  Device %d:\n", j + 1);
            printf("    Resolution: %d\n", matrix[i][j]->resolution_preference);
            printf("    Playback history: %s\n", matrix[i][j]->playback_history);
            printf("    Bandwidth usage: %.2f MB\n", matrix[i][j]->bandwidth_usage);
        }
    }
}
void display_content_matrix(ContentMetadata ***matrix, int categories, int items) {
    printf("\nContent Metadata:\n");
    for (int i = 0; i < categories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < items; j++) {
            printf("  Item %d:\n", j + 1);
            printf("    Title: %s\n", matrix[i][j]->title);
            printf("    Rating: %.2f\n", matrix[i][j]->rating);
            printf("    Runtime: %d minutes\n", matrix[i][j]->runtime);
            printf("    Encoding formats: %s\n", matrix[i][j]->encoding_formats);
        }
    }
}
int main() {
	
	void free_engagement_matrix(double **matrix, int users) {
    for (int i = 0; i < users; i++) {
        free(matrix[i]); 
    }
    free(matrix); 
}
void free_device_matrix(DevicePreference ***matrix, int users, int devices) {
    for (int i = 0; i < users; i++) {
        for (int j = 0; j < devices; j++) {
            free(matrix[i][j]); \
        }
        free(matrix[i]);
    }
    free(matrix);
}
void free_content_matrix(ContentMetadata ***matrix, int categories, int items) {
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < items; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix); 
}
    int users, categories, devices, items;
    printf("Enter the number of users: ");
    scanf("%d", &users);
    printf("Enter the number of categories: ");
    scanf("%d", &categories);
    printf("Enter the number of devices per user: ");
    scanf("%d", &devices);
    printf("Enter the number of items per category: ");
    scanf("%d", &items);
    double **engagementMatrix = allocate_engagement_matrix(users, categories);
    DevicePreference ***deviceMatrix = allocate_device_matrix(users, devices);
    ContentMetadata ***contentMatrix = allocate_content_matrix(categories, items);

    input_engagement_matrix(engagementMatrix, users, categories);
    input_device_matrix(deviceMatrix, users, devices);
    input_content_matrix(contentMatrix, categories, items);

    display_engagement_matrix(engagementMatrix, users, categories);
    display_device_matrix(deviceMatrix, users, devices);
    display_content_matrix(contentMatrix, categories, items);

    free_engagement_matrix(engagementMatrix, users);
    free_device_matrix(deviceMatrix, users, devices);
    free_content_matrix(contentMatrix, categories, items);

    return 0;
}
