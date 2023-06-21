#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int tsp(int graph[MAX_N][MAX_N], int n, int start, int visited_all, int dp[MAX_N][1 << MAX_N]) {
    // Base case: if all nodes have been visited, return the cost from current node to start node
    if (visited_all == ((1 << n) - 1))
        return graph[start][0];
    
    // Check if the subproblem has already been solved
    if (dp[start][visited_all] != -1)
        return dp[start][visited_all];
    
    int min_cost = INT_MAX;
    
    // Try all unvisited cities as the next destination
    for (int city = 0; city < n; city++) {
        if (!(visited_all & (1 << city))) {
            int new_cost = graph[start][city] + tsp(graph, n, city, visited_all | (1 << city), dp);
            
            // Update the minimum cost
            if (new_cost < min_cost)
                min_cost = new_cost;
        }
    }
    
    // Memoize the result
    dp[start][visited_all] = min_cost;
    
    return min_cost;
}

void printPath(int graph[MAX_N][MAX_N], int n, int start, int visited_all, int dp[MAX_N][1 << MAX_N]) {
    int path[MAX_N];
    int path_index = 0;
    int curr_city = start;
    
    while (visited_all != ((1 << n) - 1)) {
        path[path_index++] = curr_city;
        int next_city = -1;
        int min_cost = INT_MAX;
        
        // Find the next city with the minimum cost
        for (int city = 0; city < n; city++) {
            if (!(visited_all & (1 << city))) {
                int new_cost = graph[curr_city][city] + dp[city][visited_all | (1 << city)];
                
                if (new_cost < min_cost) {
                    min_cost = new_cost;
                    next_city = city;
                }
            }
        }
        
        curr_city = next_city;
        visited_all |= (1 << curr_city);
    }
    
    // Add the start city to the path
    path[path_index++] = curr_city;
    
    printf("Path: ");
    for (int i = 0; i < path_index; i++) {
        printf("%d ", path[i]+1);
    }
    
    printf("\n");
}

int main() {
    int n, graph[MAX_N][MAX_N],i,j;
    
    printf("Enter the number of cities (maximum 10): ");
    scanf("%d", &n);
    
    printf("\nEnter Cost Matrix\n");
	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row %d: \n",i+1);
		for( j=0;j < n;j++)
			scanf("%d",&graph[i][j]);
	}
	printf("\n\nThe cost list is:\n\n");
	for( i=0;i < n;i++)
	{
		
		for(j=0;j < n;j++)
			printf("\t%d",graph[i][j]);
		printf("\n\n");
	}
    
    
    
    // Initialize the dynamic programming table
    int dp[MAX_N][1 << MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
    
    int min_cost = tsp(graph, n, 0, 1, dp);
    
    printf("Minimum cost: %d\n", min_cost);
    
    printf("Optimal path: ");
    printPath(graph, n, 0, 1, dp);
    
    return 0;
}
