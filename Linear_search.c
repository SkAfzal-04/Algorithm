#include<stdio.h>

int main()
{
    int arr[50], i, n, x, flag = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Element found at position %d\n", i + 1);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

// Alorithm
// START

// DECLARE arr array of size 50
// DECLARE n, x, flag as integers
// READ n from user

// FOR i = 0 TO n-1 DO
//     PRINT "Enter element " (i + 1) ": "
//     READ arr[i] from user
// END FOR

// PRINT "Enter the element to be searched: "
// READ x from user

// SET flag = 0

// FOR i = 0 TO n-1 DO
//     IF arr[i] == x THEN
//         SET flag = 1
//         EXIT LOOP
//     END IF
// END FOR

// IF flag == 1 THEN
//     PRINT "Element found at position " (i + 1)
// ELSE
//     PRINT "Element not found"
// END IF

// STOP
