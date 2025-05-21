#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100  

int adjMatrix[MAX][MAX];
int n;

typedef struct node {
    int vertex;
    struct node* next;
} node;

node* adjList[MAX];

node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void createGraphMatrix() {
    int i, max_edges, origin, destin;

    printf("Enter number of nodes for adjacency matrix: ");
    scanf("%d", &n);
    max_edges = n*(n-1);

    for(i = 1; i <= max_edges; i++) {
        printf("Enter edge %d(-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if((origin == -1) && (destin == -1))
            break;

        if(origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--; 
        } else {
            adjMatrix[origin][destin] = 1;
            adjMatrix[destin][origin] = 1;
        }
    }
}

void createGraphList() {
    int i, max_edges, origin, destin;

    printf("Enter number of nodes for adjacency list: ");
    scanf("%d", &n);
    max_edges = n*(n-1);

    for(i = 1; i <= max_edges; i++) {
        printf("Enter edge %d(-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if((origin == -1) && (destin == -1))
            break;

        if(origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            addEdgeList(origin, destin);
            addEdgeList(destin, origin);
        }
    }
}

void printAdjMatrix() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList() {
    int i;
    node* temp;
    printf("\nAdjacency List:\n");
    for(i = 0; i < n; i++) {
        temp = adjList[i];
        printf("Vertex %d: ", i);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    queue[++rear] = start; // enqueue start node
    visited[start] = 1; 

    while(front != rear) {
        int v = queue[++front]; // dequeue a vertex

        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adjMatrix[v][i] && !visited[i]) {
                queue[++rear] = i; // enqueue adjacent node
                visited[i] = 1;
            }
        }
    }
}
void DFS(int v, int visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for(int i = 0; i < n; i++) {
        if(adjMatrix[v][i] && !visited[i])
            DFS(i, visited);
    }
}

void searchBFS(int start, int target) {
    int visited[MAX] = {0};
    int queue[MAX], front = -1, rear = -1;

    queue[++rear] = start; // enqueue start node
    visited[start] = 1;

    while(front != rear) {
        int v = queue[++front]; // dequeue a vertex

        if (v == target) {
            printf("Found\n");
            return;
        }

        for(int i = 0; i < n; i++) {
            if(adjMatrix[v][i] && !visited[i]) {
                queue[++rear] = i; // enqueue adjacent node
                visited[i] = 1;
            }
        }
    }
    printf("Not Found\n");
}

int main() {
    int i, option, visited[MAX];

    do {
        printf("\n****Menu****\n");
        printf("1. Create Graph (Adjacency Matrix)\n");
        printf("2. Create Graph (Adjacency List)\n");
        printf("3. Breadth First Search (BFS)\n");
        printf("4. Depth First Search (DFS)\n");
        printf("5. search of edge\n");
        printf("6. Print Adjacency Matrix\n");
        printf("7. Print Adjacency List\n");
        printf("8. Exit\n");
        printf("Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                createGraphMatrix();
                break;
            case 2:
                createGraphList();
                break;

            case 3:
                for(i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter start node for BFS : ");
                scanf("%d", &i);
                printf("Nodes reachable from %d are : ", i);
                BFS(i);
                break;
            case 4:
                for(i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter start node for DFS : ");
                scanf("%d", &i);
                printf("Nodes reachable from %d are : ", i);
                DFS(i, visited);
                break;
            case 5 :
            {
                int start, target;
                printf("Enter start node for BFS : ");
                scanf("%d", &start);
                printf("Enter the target node: ");
                scanf("%d", &target);
                printf("Searching for node %d starting from %d: ", target, start);
                searchBFS(start, target);
                break;
            }
            case 6:
                printAdjMatrix();
                break;
            case 7:
                printAdjList();
                break;
        }
    } while(option != 8);

    return 0;
} 