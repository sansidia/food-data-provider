#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 20
#define MAX_LINE 15

void readFoodItem(char*);

int main() {
    //reading number of food types
    int noFoodTypes;
    printf("Please input the number of food types\n");
    scanf("%d", &noFoodTypes);
    getchar();

    //reading food types
    char **foodTypes = (char**)malloc(noFoodTypes * sizeof(char*));
    printf("Please food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noFoodTypes; i++) {
        foodTypes[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        gets(foodTypes[i]);
    }

    /*for (int i = 0; i < noFoodTypes; i++) {
        printf("%s\n", foodTypes[i]);
    }*/

    //reading number of food subtypes per type
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

    int noDrinks;
    printf("Please input no of drinks\n");
    scanf("%d", &noDrinks);
    getchar();
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

    printf("The food data is:\n");
    for (int m = 0; m < noFoodTypes; m++) {
        printf("%s: ", foodTypes[m]);
        for (int i = 0; i < noFoodSubtypes[m]; i++) {
            printf("(%s - %.2lf) ", foodSubtypes[m][i], foodSubtypePrices[m][i]);
        }
        printf("\n");
    }
    printf("The drinks data is:\n");
    printf("drinks: ");
    for (int n = 0; n < noDrinks; n++) {
        printf("%s", drinks[n]);
        if(n!=noDrinks-1) printf(", ");
    }
    printf("\nprices: ");
    for (int n = 0; n < noDrinks; n++) {
        printf("%.0lf", drinkPrices[n]);
        if(n!=noDrinks-1) printf(", ");
    }




    //memory deallocation

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