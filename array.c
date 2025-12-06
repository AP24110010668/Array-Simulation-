#include <stdio.h>
int main() {
    int arr[50], n, choice, pos, value, i;

    printf("----- ARRAY SIMULATION -----\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    while(1) {
        printf("\n-----------------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter position to insert (1 to %d): ", n+1);
            scanf("%d", &pos);
            printf("Enter value: ");
            scanf("%d", &value);

            printf("\nShifting elements to the right...\n");
            for(i = n; i >= pos; i--) {
                printf("arr[%d] = arr[%d]\n", i, i-1);
                arr[i] = arr[i-1];
            }
            arr[pos-1] = value;
            n++;

            printf("Inserted %d at position %d\n", value, pos);
        }

        else if(choice == 2) {
            printf("Enter position to delete (1 to %d): ", n);
            scanf("%d", &pos);

            printf("\nShifting elements to the left...\n");
            for(i = pos-1; i < n-1; i++) {
                printf("arr[%d] = arr[%d]\n", i, i+1);
                arr[i] = arr[i+1];
            }
            n--;

            printf("Deleted element at position %d\n", pos);
        }

        else if(choice == 3) {
            printf("Enter value to search: ");
            scanf("%d", &value);

            int found = 0;
            for(i = 0; i < n; i++) {
                printf("Checking arr[%d]...\n", i);
                if(arr[i] == value) {
                    found = 1;
                    printf("Value found at position %d\n", i+1);
                    break;
                }
            }
            if(!found) printf("Value not found.\n");
        }

        else if(choice == 4) {
            printf("\nCurrent Array: ");
            for(i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }

        else if(choice == 5) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
