#ifndef GARPH_H
#define GRAPH_H

#include <stdbool.h>

typedef enum {UNDIRECTED = 0, DIRECTED} edge_type;

typedef struct adj_list_node {
    unsigned vertex;
    struct adj_list_node *next;
}adj_list_node;

typedef struct adj_list {
    unsigned n_neighbors;
    adj_list_node *head;
}adj_list;

typedef struct graph {
    edge_type type;
    unsigned n_vertices;
    unsigned n_edges;
    adj_list *adj_list_arr;
}graph;

adj_list_node *create_node(unsigned vertex);
void check_address(void *ptr);
graph *create_graph(edge_type type, unsigned n);
void delete_graph(graph *g);
void add_edge(graph *g, unsigned src, unsigned dest);
void delete_edge(graph *g, unsigned src, unsigned dest);
void display_graph(graph *g);
bool edge_exists(graph *g, unsigned src, unsigned dest);
void adj_list_insert(graph *g, unsigned src, adj_list_node *dest_node);
void adj_list_remove(graph *g, unsigned src, unsigned dest);

#endif
