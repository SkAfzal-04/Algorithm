#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[30],count=0;
int place(int pos) {
	int i;
	for (i=1;i<pos;i++) {
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
		   return 0;
	}
	return 1;
}
void print_sol(int n) {
	int i,j;
	count++;
	printf("\n\nSolution #%d:\n",count);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if(a[i]==j)
			    printf("Q\t"); else
			    printf("*\t");
		}
		printf("\n");
	}
}
void queen(int n) {
	int k=1;
	a[k]=0;
	while(k!=0) {
		a[k]=a[k]+1;
		while((a[k]<=n)&&!place(k))
		   a[k]++;
		if(a[k]<=n) {
			if(k==n)
			    print_sol(n); else {
				k++;
				a[k]=0;
			}
		} else
		   k--;
	}
}
void main() {
	int i,n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	queen(n);
	printf("\nTotal solutions=%d", count);
}

// Algorithm
// START

// DECLARE a array of size 30, count as integer variables
// DECLARE place function that takes an integer pos as input
//     FOR i = 1 TO pos-1 DO
//         IF a[i] equals a[pos] OR absolute value of (a[i] - a[pos]) equals absolute value of (i - pos) THEN
//             RETURN 0
//         END IF
//     END FOR
//     RETURN 1
// END FUNCTION

// DECLARE print_sol function that takes an integer n as input
//     DECLARE i, j as integers
//     INCREMENT count by 1
//     PRINT "Solution #" concatenated with count followed by a newline
//     FOR i = 1 TO n DO
//         FOR j = 1 TO n DO
//             IF a[i] equals j THEN
//                 PRINT "Q\t"
//             ELSE
//                 PRINT "*\t"
//             END IF
//         END FOR
//         PRINT newline
//     END FOR
// END FUNCTION

// DECLARE queen function that takes an integer n as input
//     DECLARE k as integer, initialized to 1
//     SET a[k] to 0
//     WHILE k is not equal to 0 DO
//         INCREMENT a[k] by 1
//         WHILE a[k] is less than or equal to n AND NOT place(k) DO
//             INCREMENT a[k] by 1
//         END WHILE
//         IF a[k] is less than or equal to n THEN
//             IF k is equal to n THEN
//                 CALL print_sol(n)
//             ELSE
//                 INCREMENT k by 1
//                 SET a[k] to 0
//             END IF
//         ELSE
//             DECREMENT k by 1
//         END IF
//     END WHILE
// END FUNCTION

// START main function
//     DECLARE i, n as integers
//     PRINT "Enter the number of Queens"
//     READ n from user
//     CALL queen(n)
//     PRINT "Total solutions=" concatenated with count
// END main function

