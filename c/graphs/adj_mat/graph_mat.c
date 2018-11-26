#include <stdio.h>
#include <stdlib.h>
#include "graph_mat.h"

void check_address(void *ptr) {
    if (!ptr) {
        printf("Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}

graph *create_graph(edge_type type, unsigned n) {
    graph *g = malloc(sizeof(graph));
    check_address(g);
    g->type = type;
    g->edge_count = 0;
    g->vertex_count = n;
    g->adj_mat = malloc( n * sizeof(unsigned *));
    check_address(g->adj_mat);
    for (int i = 0; i < n; ++i) {
        g->adj_mat[i] = malloc(n * sizeof(unsigned));
        check_address(g->adj_mat[i]);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g->adj_mat[i][j] = 0;

    return g;
}

bool edge_exists(graph *g, unsigned src, unsigned dest) {
    return g->adj_mat[src][dest];
}

void add_edge(graph *g, unsigned src, unsigned dest, unsigned weight) {
    if (src >= g->vertex_count || dest >= g->vertex_count) {
        printf("Vertices don't exist\n");
        return;
    }

    if (edge_exists(g, src, dest)) {
        printf("Edge %u-->%u already eists\n", src, dest);
        return;
    }

    g->adj_mat[src][dest] = weight;

    if (g->type == UNDIRECTED)
        g->adj_mat[dest][src] = weight;

    ++g->edge_count;
}

void delete_edge(graph *g, unsigned src, unsigned dest) {
    if (src >= g->vertex_count || dest >= g->vertex_count) {
        printf("Vertices don't exist\n");
        return;
    }

    if (!edge_exists(g, src, dest)) {
        printf("Edge %u-->%u doesn't exist\n", src, dest);
        return;
    }

    g->adj_mat[src][dest] = 0;

    if (g->type == UNDIRECTED)
        g->adj_mat[dest][src] = 0;

    --g->edge_count;
}

void display_graph(graph *g) {
    printf("#verties = %u\n", g->vertex_count);
    printf("#edges = %u\n", g->edge_count);

    for (int i = 0; i < g->vertex_count; ++i) {
        for (int j = 0; j < g->vertex_count; ++j) {
            printf("%u ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
