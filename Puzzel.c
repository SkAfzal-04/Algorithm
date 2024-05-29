// C++ program to check if a given instance of 8 puzzle is solvable or not
#include<stdio.h>
#include <stdbool.h>

// A utility function to count inversions in given array 'arr[]'
int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < 16 - 1; i++)
		for (int j = i+1; j < 16; j++)
			// Value 0 is used for empty space
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
	return inv_count;
}

// This function returns true if given 8 puzzle is solvable.
bool isSolvable(int puzzle[4][4])
{
	// Count inversions in given 8 puzzle
	int invCount = getInvCount((int *)puzzle);

	// return true if inversion count is even.
	return (invCount%2 == 0);
}

/* Driver program to test above functions */
int main()
{
int puzzle[4][4] = {{12, 1, 10, 2},
					{7, 11, 4, 14}, 
					{5, 0, 9, 15},  // Value 0 is used for empty space
                    {8, 13, 16, 3}};
isSolvable(puzzle)?printf("Solvable"):printf("Not Solvable");
return 0;
}

// Algorithm
// START

// DEFINE FUNCTION getInvCount(arr[])
//     DECLARE inv_count as integer
//     SET inv_count to 0
//     FOR i = 0 to 16 - 2 DO
//         FOR j = i + 1 to 16 - 1 DO
//             IF arr[j] is not 0 AND arr[i] is not 0 AND arr[i] > arr[j] THEN
//                 INCREMENT inv_count by 1
//             END IF
//         END FOR
//     END FOR
//     RETURN inv_count
// END FUNCTION

// DEFINE FUNCTION isSolvable(puzzle[4][4])
//     DECLARE invCount as integer
//     SET invCount to getInvCount((int *)puzzle)
//     RETURN (invCount modulo 2 is equal to 0)
// END FUNCTION

// START main function
//     DECLARE puzzle[3][3] as 2D array of integers
//     ASSIGN values to puzzle
//     IF isSolvable(puzzle) THEN
//         PRINT "Solvable"
//     ELSE
//         PRINT "Not Solvable"
//     END IF
// END main function
