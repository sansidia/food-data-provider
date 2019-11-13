#include <stdio.h>
#include <stdlib.h>

#define MAX_FOOD_NAME 20

int main() {
    int noFoodTypes;
    printf("Please input the number of food types\n");
    scanf("%d", &noFoodTypes);
    getchar();
    char **foodTypes;
    foodTypes = (char**)malloc(noFoodTypes * sizeof(char*));
    printf("Please food types (each on a new line, may contain spaces)\n");
    for (int i = 0; i < noFoodTypes; i++) {
        foodTypes[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        gets(foodTypes[i]);
    }
    for (int i = 0; i < noFoodTypes; i++) {
        printf("%s\n", foodTypes[i]);
    }


    //memory deallocation

    free(foodTypes);
    
    return 0;
}