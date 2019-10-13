#include <stdio.h>
#include "graph_mat.h"

int main(void) {
    graph *g = create_graph(UNDIRECTED, 5);
    add_edge(g, 0, 1, 5);
    add_edge(g, 3, 2, 2);
    add_edge(g, 4, 1, 3);
    add_edge(g, 2, 3, 1);
    add_edge(g, 1, 4, 5);
    add_edge(g, 1, 2, 6);
    display_graph(g);

    delete_edge(g, 1, 4);
    display_graph(g);

    return 0;
}
