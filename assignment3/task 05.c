#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char **supplies;
    int numSupplies;
} Species;
void addSupply(Species *species) {
    char newSupply[50];
    printf("Enter the supply name to add: ");
    scanf("%s", newSupply);
    species->numSupplies++;
    species->supplies = (char **)realloc(species->supplies, species->numSupplies * sizeof(char *));
    species->supplies[species->numSupplies - 1] = (char *)malloc(strlen(newSupply) + 1);
    strcpy(species->supplies[species->numSupplies - 1], newSupply);
}
void updateSupply(Species *species, int numSpecies) {
    int speciesIndex, supplyIndex;
    char newSupply[50];
    printf("Enter the index of the species to update: ");
    scanf("%d", &speciesIndex);
    if (speciesIndex >= 0 && speciesIndex < numSpecies) {
        printf("Enter the index of the supply to update: ");
        scanf("%d", &supplyIndex);
        if (supplyIndex >= 0 && supplyIndex < species[speciesIndex].numSupplies) {
            printf("Enter the new supply name: ");
            scanf("%s", newSupply);
            free(species[speciesIndex].supplies[supplyIndex]);
            species[speciesIndex].supplies[supplyIndex] = (char *)malloc(strlen(newSupply) + 1);
            strcpy(species[speciesIndex].supplies[supplyIndex], newSupply);
        } else {
            printf("Invalid supply index.\n");
        }
    } else {
        printf("Invalid species index.\n");
    }
}
void removeSpecies(Species *species, int *numSpecies, int index) {
	int i;
    if (index >= 0 && index < *numSpecies) {
        free(species[index].supplies);
        for (i = index; i < *numSpecies - 1; i++) {
            species[i] = species[i + 1];
        }
        (*numSpecies)--;
        printf("Species removed successfully.\n");
    } else {
        printf("Invalid index.\n");
    }
}
void displayInventory(Species *species, int numSpecies) {
	int i,j;
    for (i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (j = 0; j < species[i].numSupplies; j++) {
            printf("- %s\n", species[i].supplies[j]);
        }
        printf("\n");
    }
}

int main() {
    int numSpecies;
	int i;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    Species *species = (Species *)malloc(numSpecies * sizeof(Species));

    for (i = 0; i < numSpecies; i++) {
        species[i].numSupplies = 0;
        species[i].supplies = NULL;
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Supply\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < numSpecies; i++) {
                    printf("Add supply to species %d:\n", i + 1);
                    addSupply(&species[i]);
                }
                break;
            case 2:
                updateSupply(species, numSpecies);
                break;
            case 3:
                {
                    int speciesIndex;
                    printf("Enter the index of the species to remove: ");
                    scanf("%d", &speciesIndex);
                    removeSpecies(species, &numSpecies, speciesIndex);
                }
                break;
            case 4:
                displayInventory(species, numSpecies);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    for (i = 0; i < numSpecies; i++) {
        free(species[i].supplies);
    }
    free(species);

    return 0;
}
