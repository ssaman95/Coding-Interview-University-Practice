#include <stdio.h>
#include "graph_adj.h"

int main(void) {
    graph *g = create_graph(DIRECTED, 5);
    add_edge(g, 0, 3);
    add_edge(g, 1, 2);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);
    display_graph(g);

    delete_edge(g, 2, 4);
    display_graph(g);

    return 0;
}
