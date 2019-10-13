#include <stdio.h>
#include <stdlib.h>
#include "graph_adj.h"

adj_list_node *create_node(unsigned vertex) {
    adj_list_node *new_node = malloc(sizeof(adj_list_node));
    check_address(new_node);

    new_node->vertex = vertex;
    new_node->next = NULL;

    return new_node;
}

graph *create_graph(edge_type type, unsigned n) {
    graph *g = malloc(sizeof(graph));
    check_address(g);
    g->type = type;
    g->n_vertices = n;
    g->n_edges = 0;
    g->adj_list_arr = malloc(n * sizeof(adj_list));
    check_address(g->adj_list_arr);

    for (int i = 0; i < n; ++i) {
        g->adj_list_arr[i].n_neighbors = 0;
        g->adj_list_arr[i].head = NULL;
    }

    return g;
}

void check_address(void *ptr) {
    if (!ptr) {
        printf("Memory can't be allocated\n");
        exit(EXIT_FAILURE);
    }
}

bool edge_exists(graph *g, unsigned src, unsigned dest) {
    adj_list_node *cur = g->adj_list_arr[src].head;
    while (cur) {
        if (cur->vertex == dest)
            return true;
        cur = cur->next;
    }

    return false;
}

void add_edge(graph *g, unsigned src, unsigned dest) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }

    if (src >= g->n_vertices || dest >= g->n_vertices) {
        printf("One of the verties doesn't exist.\n");
        return;
    }

    if (edge_exists(g, src, dest)) {
        printf("Edge already exists\n.");
        return;
    }

    adj_list_node *dest_node = create_node(dest);
    adj_list_insert(g, src, dest_node);

    if (g->type == UNDIRECTED) {
        adj_list_node *src_node = create_node(src);
        adj_list_insert(g, dest, src_node);
    }

    ++g->n_edges;
}

void adj_list_insert(graph *g, unsigned src, adj_list_node *dest_node) {
    dest_node->next = g->adj_list_arr[src].head;
    g->adj_list_arr[src].head = dest_node;
    ++g->adj_list_arr[src].n_neighbors;
}

void delete_edge(graph *g, unsigned src, unsigned dest) {
    if (!g) {
        printf("Graph does not exist\n");
        return;
    }

    if (src >= g->n_vertices || dest >= g->n_vertices) {
        printf("One of the verties doesn't exist.\n");
        return;
    }

    if (!edge_exists(g, src, dest)) {
        printf("Edge doesn't exist\n.");
        return;
    }

    adj_list_remove(g, src, dest);
    if (g->type == UNDIRECTED)
        adj_list_remove(g, dest, src);
    
    --g->n_edges;
}

void adj_list_remove(graph *g, unsigned src, unsigned dest) {
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

    --g->adj_list_arr[src].n_neighbors;
}

void display_graph(graph *g) {
    printf("\n#vertices = %u", g->n_vertices);
    printf("\n#edges = %u", g->n_edges);

    for (int i = 0; i < g->n_vertices; ++i) {
        printf("\n%d ===> ", i);
        adj_list_node *curr = g->adj_list_arr[i].head;
        while (curr) {
            printf("%u -> ", curr->vertex);
            curr = curr->next;
        }
    }
    printf("\n");
}
