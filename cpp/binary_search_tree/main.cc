#include "bst.h"
#include <cassert>

using namespace std;

int main() {
    BST<int> node;

    node.insert(20);
    node.insert(30);
    node.insert(10);
    node.insert(5);
    node.insert(8);
    node.insert(3);
    node.insert(6);
    node.insert(25);
    node.insert(28);
    node.insert(35);
    node.insert(38);

    node.inOrder();
    cout << endl;
    node.levelOrder();
    cout << endl;

    // Test Insertion
    assert(node.root->data == 20);
    assert(node.root->left->data == 10);
    assert(node.root->right->data == 30);

    // test search
    assert(node.search(20));
    assert(node.search(30));
    assert(node.search(10));
    assert(!node.search(50));
    assert(node.search(6));


    // Delete node
    node.remove(10);
    node.remove(6);
    node.remove(30);

    // Test deletion
    assert(!node.search(10));
    assert(!node.search(6));
    assert(!node.search(30));
    assert(node.root->right->data == 28);

    node.inOrder();
    cout << endl;

    node.levelOrder();
    cout << endl;


    return 0;
}
