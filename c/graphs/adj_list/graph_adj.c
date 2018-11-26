#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "queue.h" // needed for bfs
#include "graph_adj.h"


// Create a node to be inserted into an adjacency list
adj_list_node *create_adj_list_node(int vertex) {
    adj_list_node *new_node = malloc(sizeof(adj_list_node));
    check_address(new_node);

    new_node->vertex = vertex;
    new_node->next = NULL;

    return new_node;
}


// Initialize a pointer to a graph
graph *create_graph(edge_type type, unsigned n) {
    graph *g = malloc(sizeof(graph));
    check_address(g);

    g->type = type;
    g->vertex_count = n;
    g->edge_count = 0;
    g->adj_list_arr = malloc(n * sizeof(adj_list));
    check_address(g->adj_list_arr);

    for (int i = 0; i < n; ++i) {
        g->adj_list_arr[i].neighbor_count = 0;
        g->adj_list_arr[i].head = NULL;
    }

    return g;
}

/*
// Check if memory was allocated
void check_address(void *ptr) {
    if (!ptr) {
        printf("Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}
*/


// Check whether the edge alredy exists
bool edge_exists(graph *g, int src, int dest) {
    assert(g);      // g is valid pointer or not
    // Check if src and dest are within range or not.
    // This function is for internal usag, so using assert.
    assert(src >= 0 && src < g->vertex_count);
    assert(dest >= 0 && dest < g->vertex_count);

    adj_list_node *cur = g->adj_list_arr[src].head;
    while (cur) {
        if (cur->vertex == dest)
            return true;
        cur = cur->next;
    }

    return false;
}


// Add an edge to the graph
void add_edge(graph *g, int src, int dest) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }

    if (src < 0 || dest < 0 || src >= g->vertex_count || dest >= g->vertex_count) {
        printf("One of the verties doesn't exist.\n");
        return;
    }

    if (edge_exists(g, src, dest)) {
        printf("Edge already exists\n.");
        return;
    }

    adj_list_node *dest_node = create_adj_list_node(dest);
    adj_list_insert(g, src, dest_node);

    // If undirected graph, insert reverse of the edge
    if (g->type == UNDIRECTED) {
        adj_list_node *src_node = create_adj_list_node(src);
        adj_list_insert(g, dest, src_node);
    }

    ++g->edge_count;
}


// Insert a node to front of an adjacency list
void adj_list_insert(graph *g, int src, adj_list_node *dest_node) {
    assert(g);
    assert(dest_node);
    assert(src >= 0 && src < g->vertex_count);

    dest_node->next = g->adj_list_arr[src].head;
    g->adj_list_arr[src].head = dest_node;
    ++g->adj_list_arr[src].neighbor_count;
}


// Delete an edge from the graph
void delete_edge(graph *g, int src, int dest) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }

    if (src < 0 || dest< 0 || src >= g->vertex_count || dest >= g->vertex_count) {
        printf("One of the verties doesn't exist.\n");
        return;
    }

    if (!edge_exists(g, src, dest)) {
        printf("Edge doesn't exist\n.");
        return;
    }

    adj_list_remove(g, src, dest);
    // Remove reverse of the edge also.
    if (g->type == UNDIRECTED)
        adj_list_remove(g, dest, src);
    
    --g->edge_count;
}


// Search and remove a node from adjacency list
void adj_list_remove(graph *g, int src, int dest) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }
    adj_list_node *curr = g->adj_list_arr[src].head;
    adj_list_node *prev = NULL;

    while (curr->vertex != dest) {
        prev = curr;
        curr = curr->next;
    }

    if (prev)
        prev->next = curr->next;
    else
        g->adj_list_arr[src].head = curr->next;

    --g->adj_list_arr[src].neighbor_count;
}


// Display the graph
void display_graph(graph *g) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }
    printf("\n#vertices = %u", g->vertex_count);
    printf("\n#edges = %u", g->edge_count);

    for (int i = 0; i < g->vertex_count; ++i) {
        printf("\n%d ===> ", i);
        adj_list_node *curr = g->adj_list_arr[i].head;
        while (curr) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
    }
    printf("\n");
}


// Breadth First traversal through graph g, start vertex: s
void bfs(graph *g, int s) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }

    int n = g->vertex_count;
    if (s < 0 || s >= n) {
        printf("Start vertex not found\n");
        return;
    }

    bool *seen = calloc(n, sizeof(bool));
    bool *visited = calloc(n, sizeof(bool));
    int *parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        parent[i] = -1;
    unsigned *distance = malloc(n * sizeof(unsigned));
    for (int i = 0; i < n; ++i)
        distance[i] = INT_MAX;

    seen[s] = true;
    distance[s] = 0;

    queue *q = create_queue();

    enqueue(q, s);

    while (!empty(q)) {
        int cur = dequeue(q);
        adj_list_node *node = g->adj_list_arr[cur].head;
        
        while (node) {
            int v = node->vertex;
            if (!seen[v]) {
                seen[v] = true;
                distance[v] = distance[cur] + 1;
                parent[v] = cur;
                enqueue(q, v);
            }
            node = node->next;
        }
        visited[cur] = true;
        printf("%d -> ", cur);
    }
    printf("\n");
    printf("\nvert : par: dist\n");
    for (int i = 0; i < n; ++i)
        printf("%d : %d : %d\n", i, parent[i], distance[i]);
}
