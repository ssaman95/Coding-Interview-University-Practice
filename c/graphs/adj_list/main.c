#include <stdio.h>
#include "graph_adj.h"

int main(void) {
    graph *g = create_graph(UNDIRECTED, 8);
    add_edge(g, 0, 1);
    add_edge(g, 0, 7);
    add_edge(g, 1, 6);
    add_edge(g, 2, 5);
    add_edge(g, 2, 3);
    add_edge(g, 2, 6);
    add_edge(g, 3, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);
    add_edge(g, 5, 6);
    display_graph(g);

    printf("================================================\n");
    printf("bfs:\n");
    bfs(g, 1);

    printf("================================================\n");
    printf("dfs:\n");
    dfs_rec(g, 1);

    printf("================================================\n");
    printf("dfs with stack:\n");
    dfs_iter(g, 1);
    return 0;
}
