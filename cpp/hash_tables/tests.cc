#include <cassert>
#include "tests.h"
#include "hash_table.h"

void run_all_tests() {
    test_add_exists();
    test_probing();
    test_get();
    test_remove();
}

void test_add_exists() {
    as::HashTable states(100);

    as::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);

    assert(states.Exists("Texas"));
}

void test_probing() {
    // setting high load to force collisions
    as::HashTable states(8);

    as::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    as::HashObject ca;
    ca.SetKey("California");
    ca.SetValue("Sacramento");

    as::HashObject nm;
    nm.SetKey("New Mexico");
    nm.SetValue("Santa Fe");

    as::HashObject fl;
    fl.SetKey("Florida");
    fl.SetValue("Tallahassee");

    as::HashObject oregon;
    oregon.SetKey("Oregon");
    oregon.SetValue("Salem");

    as::HashObject wa;
    wa.SetKey("Washington");
    wa.SetValue("Olympia");

    as::HashObject ut;
    ut.SetKey("Utah");
    ut.SetValue("Salt Lake City");

    as::HashObject ny;
    ny.SetKey("New York");
    ny.SetValue("Albany");

    as::HashObject mn;
    mn.SetKey("Minnesota");
    mn.SetValue("St. Paul");

    states.Add(&tx);  // 1
    states.Add(&ca);  // 0
    states.Add(&nm);  //
    states.Add(&fl);
    states.Add(&oregon);
    states.Add(&wa);
    states.Add(&ut);
    states.Add(&ny);
    states.Add(&mn);

    //  Texas:1
    //  California:0
    //  New Mexico:5
    //  Florida:5
    //  Oregon:4
    //  Washington:0
    //  Utah:6
    //  New York:7
    //  Minnesota:6

    //  0: California:Sacramento
    //  1: Texas:Austin
    //  2: Washington:Olympia
    //  3: New York:Albany
    //  4: Oregon:Salem
    //  5: New Mexico:Santa Fe
    //  6: Florida:Tallahassee
    //  7: Utah:Salt Lake City

    assert(states.Exists("California"));
    assert(states.Exists("New Mexico"));
    assert(states.Exists("Florida"));
    assert(!states.Exists("Minnesota"));  // no room
}

void test_get() {
    as::HashTable states(100);

    as::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);
    assert(states.Get("Texas") == "Austin");
}

void test_remove() {
    as::HashTable states(100);

    as::HashObject tx;
    tx.SetKey("Texas");
    tx.SetValue("Austin");

    states.Add(&tx);

    assert(states.Exists("Texas"));

    states.Remove("Texas");

    assert(!states.Exists("Texas"));
}
