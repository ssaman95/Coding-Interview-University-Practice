#ifndef GARPH_H
#define GRAPH_H

#include <stdbool.h>

typedef enum {UNDIRECTED = 0, DIRECTED} edge_type;

typedef struct adj_list_node {
    int vertex;
    struct adj_list_node *next;
}adj_list_node;

typedef struct adj_list {
    unsigned neighbor_count;
    adj_list_node *head;
}adj_list;

typedef struct graph {
    edge_type type;
    unsigned vertex_count;
    unsigned edge_count;
    adj_list *adj_list_arr;
}graph;

adj_list_node *create_adj_list_node(int vertex);
//void check_address(void *ptr);
graph *create_graph(edge_type type, unsigned n);
void delete_graph(graph *g);
void add_edge(graph *g, int src, int dest);
void delete_edge(graph *g, int src, int dest);
void display_graph(graph *g);
bool edge_exists(graph *g, int src, int dest);
void adj_list_insert(graph *g, int src, adj_list_node *dest_node);
void adj_list_remove(graph *g, int src, int dest);

void bfs(graph *g, int s);
void dfs_rec(graph *g, int s);
void dfs_visit_rec(graph *g, int s, int *time, bool *visited, bool *seen, int *discovery_time, int *finish_time);
void dfs_iter(graph *g, int s);

#endif
