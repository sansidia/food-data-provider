#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 20
#define MAX_LINE 15

void readFoodItem(char*);
int readNoOfTypes(char[]);

int main() {
    int noFoodTypes = readNoOfTypes("food");
    char **foodTypes = (char**)malloc(noFoodTypes * sizeof(char*));
    printf("Please food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noFoodTypes; i++) {
        foodTypes[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        gets(foodTypes[i]);
    }

    int *noFoodSubtypes = (int*)malloc(noFoodTypes* sizeof(int));
    char ***foodSubtypes = (char***)malloc(noFoodTypes * sizeof(char**));
    double **foodSubtypePrices = (double**)malloc(noFoodTypes* sizeof(double*));
    for (int i = 0; i < noFoodTypes; ++i) {
        printf("Please input number of speciffic foods for food \"%s\"\n", foodTypes[i]);
        scanf("%d", &noFoodSubtypes[i]); getchar();
        foodSubtypes[i] = (char**)malloc(noFoodSubtypes[i]* sizeof(char*));
        foodSubtypePrices[i] = (double*)malloc(noFoodSubtypes[i]* sizeof(double));

        printf("Please input \"%s\" speciffic foods &prices: each line in the format <speciffic food> (price):\n", foodTypes[i]);
        for (int j = 0; j < noFoodSubtypes[i]; j++) {
            foodSubtypes[i][j] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
            readFoodItem(foodSubtypes[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%lf", &foodSubtypePrices[i][j]);
        }
    }

    int noDrinks = readNoOfTypes("drinks");
    char **drinks = (char**)malloc(noDrinks * sizeof(char*));
    double *drinkPrices = (double*)malloc(noDrinks* sizeof(double));
    printf("Please input the drinks: each line in format <drink> (price):\n");
    for (int k = 0; k < noDrinks; k++) {
        drinks[k] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
        readFoodItem(drinks[k]);
        char line[MAX_LINE];
        gets(line);
        sscanf(line, "%lf", &drinkPrices[k]);
    }
    FILE *outputFile = fopen("data.txt", "w");
    fprintf(outputFile, "The food data is:\n");
    for (int m = 0; m < noFoodTypes; m++) {
        fprintf(outputFile, "%s: ", foodTypes[m]);
        for (int i = 0; i < noFoodSubtypes[m]; i++) {
            fprintf(outputFile, "(%s - %.2lf) ", foodSubtypes[m][i], foodSubtypePrices[m][i]);
        }
        fprintf(outputFile, "\n");
    }
    fprintf(outputFile, "The drinks data is:\n");
    fprintf(outputFile, "drinks: ");
    for (int n = 0; n < noDrinks; n++) {
        fprintf(outputFile, "%s", drinks[n]);
        if(n!=noDrinks-1) fprintf(outputFile, ", ");
    }
    fprintf(outputFile, "\nprices: ");
    for (int n = 0; n < noDrinks; n++) {
        fprintf(outputFile, "%.0lf", drinkPrices[n]);
        if(n!=noDrinks-1) fprintf(outputFile, ", ");
    }

    free(drinkPrices);
    for (int l = 0; l < noDrinks; l++) {
        free(drinks[l]);
    }
    free(drinks);
    for (int j = 0; j < noFoodTypes; ++j) {
        free(foodSubtypePrices[j]);
    }
    free(foodSubtypePrices);
    for (int j = 0; j < noFoodTypes; ++j) {
        for (int i = 0; i < noFoodSubtypes[i];i++) {
            free(foodSubtypes[i][j]);
        }
    }
    free(foodSubtypes);
    free(noFoodSubtypes);
    for (int j = 0; j < noFoodTypes; ++j) {
        free(foodTypes[j]);
    }
    free(foodTypes);
    return 0;
}

int readNoOfTypes(char type[]) {
    int number;
    printf("Please input number of %s types\n", type);
    scanf("%d", &number);
    getchar();
    return number;
}

void readFoodItem(char* foodItem) {
    char c = getchar();
    int i = 0;
    while (c!= '(') {
        foodItem[i] = c;
        c = getchar();
        i++;
    }
    foodItem[i] = '\0';
}