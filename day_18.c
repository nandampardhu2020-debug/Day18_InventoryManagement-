#include <stdio.h>

int main() {
    int productID[10], quantity[10];
    float price[10];
    char name[10][50];   // Array of strings
    int n = 0;           // Number of products entered
    int choice, i;

    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Input product details\n");
        printf("2. Display all products\n");
        printf("3. Calculate inventory value & show highest/lowest value product\n");
        printf("4. Search product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many products do you want to enter (max 10)? ");
            scanf("%d", &n);

            if (n > 10) {
                printf("You can only enter up to 10 products!\n");
                n = 10;
            }

            for (i = 0; i < n; i++) {
                printf("\n--- Product %d ---\n", i + 1);
                printf("Enter Product ID: ");
                scanf("%d", &productID[i]);

                printf("Enter Product Name: ");
                scanf("%s", name[i]);

                printf("Enter Quantity: ");
                scanf("%d", &quantity[i]);

                printf("Enter Price: ");
                scanf("%f", &price[i]);
            }
        }

        else if (choice == 2) {
            if (n == 0) {
                printf("No products added yet!\n");
            } else {
                printf("\n--- Product List ---\n");
                for (i = 0; i < n; i++) {
                    printf("\nProduct %d\n", i + 1);
                    printf("ID: %d\n", productID[i]);
                    printf("Name: %s\n", name[i]);
                    printf("Quantity: %d\n", quantity[i]);
                    printf("Price: %.2f\n", price[i]);
                }
            }
        }

        else if (choice == 3) {
            if (n == 0) {
                printf("No products available!\n");
            } else {
                float totalValue = 0, value;
                float highestValue, lowestValue;
                int highIndex = 0, lowIndex = 0;

                // Initial values
                highestValue = quantity[0] * price[0];
                lowestValue = quantity[0] * price[0];

                for (i = 0; i < n; i++) {
                    value = quantity[i] * price[i];
                    totalValue += value;

                    if (value > highestValue) {
                        highestValue = value;
                        highIndex = i;
                    }

                    if (value < lowestValue) {
                        lowestValue = value;
                        lowIndex = i;
                    }
                }

                printf("\nTotal Inventory Value: %.2f\n", totalValue);

                printf("\nProduct with Highest Value:\n");
                printf("ID: %d, Name: %s, Value: %.2f\n", 
                        productID[highIndex], name[highIndex], highestValue);

                printf("\nProduct with Lowest Value:\n");
                printf("ID: %d, Name: %s, Value: %.2f\n", 
                        productID[lowIndex], name[lowIndex], lowestValue);
            }
        }

        else if (choice == 4) {
            int id, found = 0;
            printf("Enter Product ID to search: ");
            scanf("%d", &id);

            for (i = 0; i < n; i++) {
                if (productID[i] == id) {
                    found = 1;
                    printf("\nProduct Found!\n");
                    printf("ID: %d\n", productID[i]);
                    printf("Name: %s\n", name[i]);
                    printf("Quantity: %d\n", quantity[i]);
                    printf("Price: %.2f\n", price[i]);
                    break;
                }
            }

            if (!found)
                printf("Product Not Found!\n");
        }

        else if (choice == 5) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
