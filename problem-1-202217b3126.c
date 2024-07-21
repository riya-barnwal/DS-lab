#include <stdio.h>
#include <stdlib.h> // For exit() function

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int a, b[20], n, p, pos, e, i;

int main()
{
    int ch;
    char g = 'y';

    while (g == 'y' || g == 'Y') {
        printf("\nMain Menu");
        printf("\n1. Create");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Insert");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nEnter the correct choice.");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g); // Note the space before %c to consume any leftover newline characters
    }

    return 0;
}

void create()
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of nodes exceeds the maximum limit of %d.\n", MAX);
        n = MAX;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter the Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid Location.\n");
    } else {
        for (i = pos + 1; i < n; i++) {
            b[i - 1] = b[i];
        }
        n--;
    }

    printf("\nThe Elements after deletion:");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
    printf("\n");
}

void search()
{
    printf("\nEnter the Element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the position %d\n", i);
            return;
        }
    }
    printf("Value %d is not in the list.\n", e);
}

void insert()
{
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid Location.\n");
    } else if (n >= MAX) {
        printf("\nList is full. Cannot insert new element.\n");
    } else {
        for (i = MAX - 1; i >= pos; i--) {
            b[i + 1] = b[i];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
    }

    printf("\nThe list after insertion:\n");
    display();
}

void display()
{
    printf("\nThe Elements of The list are:");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
    printf("\n");
}