#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 20
#define INF INT_MAX

int n; // Number of cities
int dist[MAX_CITIES][MAX_CITIES]; // Adjacency matrix to store the distances between cities
int dp[MAX_CITIES][1 << MAX_CITIES]; // DP table to store the minimum cost for each state
int visited_all; // All cities visited bitmask

// Function to find the minimum cost path
int tsp(int mask, int pos) {
    // If all cities are visited
    if (mask == visited_all) {
        return dist[pos][0]; // Return to the starting city
    }

    // Check if the result is already computed
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int answer = INF;

    // Try to go to any unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // If city is not visited
            int new_answer = dist[pos][city] + tsp(mask | (1 << city), city);
            if (new_answer < answer) {
                answer = new_answer;
            }
        }
    }

    dp[pos][mask] = answer; // Store the result
    return answer;
}

int main() {
    // Example distances
    n = 4;
    int distances[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Copy distances to the global array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = distances[i][j];
        }
    }

    // Initialize the DP table
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < (1 << MAX_CITIES); j++) {
            dp[i][j] = -1;
        }
    }

    visited_all = (1 << n) - 1; // All cities visited bitmask

    printf("The minimum cost is %d\n", tsp(1, 0)); // Start from the first city

    return 0;
}

// Algorithm
// function tsp(mask, pos)
//     if mask == visited_all
//         return dist[pos][0]
    
//     if dp[pos][mask] != -1
//         return dp[pos][mask]
    
//     min_cost = INF
    
//     for each city from 0 to n-1
//         if (mask & (1 << city)) == 0
//             new_cost = dist[pos][city] + tsp(mask | (1 << city), city)
//             if new_cost < min_cost
//                 min_cost = new_cost
    
//     dp[pos][mask] = min_cost
//     return min_cost
