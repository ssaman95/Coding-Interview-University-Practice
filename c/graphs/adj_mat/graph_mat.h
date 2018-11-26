#ifndef GRAPH_MAT_H
#define GRAPH_MAT_H

#include <stdbool.h>

typedef enum {UNDIRECTED = 0, DIRECTED} edge_type;

typedef struct graph {
    unsigned **adj_mat;
    edge_type type;
    unsigned vertex_count;
    unsigned edge_count;
}graph;

void check_address(void *ptr);
graph *create_graph(edge_type type, unsigned n);
void add_edge(graph *g, unsigned src, unsigned dest, unsigned weight);
void delete_edge(graph *g, unsigned src, unsigned dest);
void display_graph(graph *g);
bool edge_exists(graph *g, unsigned src, unsigned dest);

#endif