// #include <stdio.h>
// #define MAX 100

// typedef struct Job {
//   char id[5];
//   int deadline;
//   int profit;
// } Job;

// void jobSequencingWithDeadline(Job jobs[], int n);

// int minValue(int x, int y) {
//   if(x < y) return x;
//   return y;
// }

// int main(void) {

//   int i, j;

//   Job jobs[5] = {
//     {"j1", 2,  60},
//     {"j2", 1, 100},
//     {"j3", 3,  20},
//     {"j4", 2,  40},
//     {"j5", 1,  20},
//   };


//   Job temp;

//   int n = 5;

//   for(i = 1; i < n; i++) {
//     for(j = 0; j < n - i; j++) {
//       if(jobs[j+1].profit > jobs[j].profit) {
//         temp = jobs[j+1];
//         jobs[j+1] = jobs[j];
//         jobs[j] = temp;
//       }
//     }
//   }

//   printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
//   for(i = 0; i < n; i++) {
//     printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
//   }

//   jobSequencingWithDeadline(jobs, n);

//   return 0;
// }

// void jobSequencingWithDeadline(Job jobs[], int n) {

//   int i, j, k, maxprofit;

//   int timeslot[MAX];

//   int filledTimeSlot = 0;

//   int dmax = 0;
//   for(i = 0; i < n; i++) {
//     if(jobs[i].deadline > dmax) {
//       dmax = jobs[i].deadline;
//     }
//   }
//   for(i = 1; i <= dmax; i++) {
//     timeslot[i] = -1;
//   }

//   printf("dmax: %d\n", dmax);

//   for(i = 1; i <= n; i++) {
//     k = minValue(dmax, jobs[i - 1].deadline);
//     while(k >= 1) {
//       if(timeslot[k] == -1) {
//         timeslot[k] = i-1;
//         filledTimeSlot++;
//         break;
//       }
//       k--;
//     }

//     if(filledTimeSlot == dmax) {
//       break;
//     }
//   }

//   printf("\nRequired Jobs: ");
//   for(i = 1; i <= dmax; i++) {
//     printf("%s", jobs[timeslot[i]].id);

//     if(i < dmax) {
//       printf(" --> ");
//     }
//   }

//   maxprofit = 0;
//   for(i = 1; i <= dmax; i++) {
//     maxprofit += jobs[timeslot[i]].profit;
//   }
//   printf("\nMax Profit: %d\n", maxprofit);
// }
#include<stdio.h>
#include<stdlib.h>
typedef struct jobs{
	int job;
	int deadl;
	int prof;
}jo;
int main(){
	int size,i,j;
	printf("How many jobs you want to insert: ");
	scanf("%d",&size);
	jo arr[size];
	for (i=0;i<size;i++){
		printf("Job ID: ");
		scanf("%d",&arr[i].job);
		printf("Deadline: ");
		scanf("%d",&arr[i].deadl);
		printf("Profit: ");
		scanf("%d",&arr[i].prof);
	}

	for(i=0;i<size;i++){
		for(j=0;j<size-i-1;j++){
			if(arr[j+1].prof>arr[j].prof){
				jo t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
	}

	int max=arr[0].deadl;
	for(i=0;i<size;i++){
		if (arr[i].deadl>max)
			max=arr[i].deadl;
	}
	int res[max],rec[max];
	int r=0,maxprof=0;
	for(i=0;i<size;i++){
		if (r==max)
			break;
		else{
			int f=0;
			for(int c=0;c<max;c++){
				if(arr[i].deadl==rec[c]){
					f=1;
					break;
				}
			}
			if (f==0){
			maxprof+=arr[i].prof;
			res[arr[i].deadl-1]=arr[i].job;
			rec[r]=arr[i].deadl;
			r++;
			}
		
	}
	}
	printf("Maximum profit=%d\n",maxprof);
	for(i=0;i<max;i++)
		if (i==max-1){
			printf("J%d",res[i]);
		}
		else{
		printf("J%d-->",res[i]);
		}
	
}

// Algorithm
// START

// DEFINE STRUCT jobs
//     job as int
//     deadl as int
//     prof as int
// END STRUCT

// PROCEDURE main
//     DECLARE size, i, j, max, r, maxprof as int
//     DECLARE arr[size] as array of jobs
//     DECLARE res[max] as array of int
//     DECLARE rec[max] as array of int

//     INPUT size
//     FOR i = 0 TO size-1 DO
//         INPUT arr[i].job
//         INPUT arr[i].deadl
//         INPUT arr[i].prof
//     END FOR

//     FOR i = 0 TO size-1 DO
//         FOR j = 0 TO size-i-2 DO
//             IF arr[j+1].prof > arr[j].prof THEN
//                 SWAP arr[j+1] WITH arr[j]
//             END IF
//         END FOR
//     END FOR

//     SET max = arr[0].deadl
//     FOR i = 0 TO size-1 DO
//         IF arr[i].deadl > max THEN
//             SET max = arr[i].deadl
//         END IF
//     END FOR

//     SET r = 0
//     SET maxprof = 0

//     FOR i = 0 TO size-1 DO
//         IF r == max THEN
//             BREAK
//         ELSE
//             SET f = 0
//             FOR c = 0 TO max-1 DO
//                 IF arr[i].deadl == rec[c] THEN
//                     SET f = 1
//                     BREAK
//                 END IF
//             END FOR
//             IF f == 0 THEN
//                 SET maxprof = maxprof + arr[i].prof
//                 SET res[arr[i].deadl-1] = arr[i].job
//                 SET rec[r] = arr[i].deadl
//                 SET r = r + 1
//             END IF
//         END IF
//     END FOR

//     PRINT "Maximum profit = " maxprof
//     FOR i = 0 TO max-1 DO
//         IF i == max-1 THEN
//             PRINT "J" res[i]
//         ELSE
//             PRINT "J" res[i] "-->"
//         END IF
//     END FOR

// END PROCEDURE

// STOP
