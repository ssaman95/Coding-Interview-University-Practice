#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> eg = {1, 2, 3};
    vector<int> :: iterator it;
    vector<int> :: reverse_iterator ir;

    for (it = eg.begin(); it < eg.end(); ++it) { // begin and end are iterator functions
       cout << *it << "  ";
    }
    cout << endl;

    eg.push_back(4);
    eg.push_back(5);

    cout << "Size: " << eg.size() << endl;
    cout << "Capacity: " << eg.capacity() << endl;
    cout << "Max Size: " << eg.max_size() << endl;
    
    cout << "Output of rend and rbegin:" << endl;
    for (ir = eg.rbegin(); ir < eg.rend(); ++ir) {
        cout<< *ir << "  ";
    } 
    cout << endl;

    eg.assign(10, 1);

    cout << "Size: " << eg.size() << endl;
    cout << "Capacity: " << eg.capacity() << endl;
    cout << "Max Size: " << eg.max_size() << endl;
    
    cout << "Output of rend and rbegin:" << endl;
    for (it = eg.begin(); it < eg.end(); ++it) {
        cout<< *it << "  ";
    } 
    cout << endl;

    vector<int> new_eg = eg;

    cout << "Size: " << eg.size() << endl;
    cout << "Capacity: " << eg.capacity() << endl;
    cout << "Max Size: " << eg.max_size() << endl;
    
    cout << "Output of rend and rbegin:" << endl;
    for (it = eg.begin(); it < eg.end(); ++it) {
        cout<< *it << "  ";
    } 
    cout << endl;


    return 0;
}
