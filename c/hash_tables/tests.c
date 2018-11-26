#include "hashtable.c"
#include <assert.h>

void test_exists();
void test_add_get();
void test_add_delete();

void run_all_tests() {
    test_exists();
    test_add_get();
    test_add_delete();
}


void test_exists() {
    hash_table *table = create_hash_table(64);

    add(table, "Aman", "12150203");
    add(table, "Alankar", "12150202");
    add(table, "Ravi", "12150229");
    add(table, "Prabhash", "RPS");
    add(table, "Atish", "Kuttummel");
    add(table, "Ravi EEE", "Kuttummel");
    add(table, "Saurav", "pseudo-ktml");
    add(table, "Bihar", "BR");
    add(table, "Kerala", "KL");
    add(table, "Jharkhand", "JH");
    add(table, "Rajasthan", "RJ");
    add(table, "J&K", "JK");
    add(table, "Maharashtra", "MH");
    add(table, "UP", "UP");
    add(table, "New Delhi", "DL");
    add(table, "10", "RPS");
    add(table, "12", "JVM");
    add(table, "B.Tech", "CUCEK");
    add(table, "India", "Rupee");
    add(table, "USA", "USD");
    add(table, "Tamil Nadu", "TN");
    add(table, "Bengal", "WB");
    add(table, "Kundan", "LBH");
    add(table, "Subham Soni", "LBH");
    add(table, "CUCEK", "Pulincunnoo");
    add(table, "RPS", "Madhubani");
    add(table, "JVM", "Ranchi");
    add(table, "Home", "Munger");
    add(table, "Second Home", "Soha");
    add(table, "Real Home", "MBI");




    assert(exists(table, "Prabhash"));
    assert(exists(table, "Aman"));
    assert(exists(table, "Alankar"));
    assert(exists(table, "Saurav"));

    print_table(table);

    destroy_table(table);
}


void test_add_get() {
    hash_table *table = create_hash_table(64);

    add(table, "Aman", "12150203");
    add(table, "Alankar", "12150202");
    add(table, "Ravi", "12150229");
    add(table, "Prabhash", "RPS");
    add(table, "Atish", "Kuttummel");
    add(table, "Ravi EEE", "Kuttummel");
    add(table, "Saurav", "pseudo-ktml");
    add(table, "Bihar", "BR");
    add(table, "Kerala", "KL");
    add(table, "Jharkhand", "JH");
    add(table, "Rajasthan", "RJ");
    add(table, "J&K", "JK");
    add(table, "Maharashtra", "MH");
    add(table, "UP", "UP");
    add(table, "New Delhi", "DL");
    add(table, "10", "RPS");
    add(table, "12", "JVM");
    add(table, "B.Tech", "CUCEK");
    add(table, "India", "Rupee");
    add(table, "USA", "USD");
    add(table, "Tamil Nadu", "TN");
    add(table, "Bengal", "WB");
    add(table, "Kundan", "LBH");
    add(table, "Subham Soni", "LBH");
    add(table, "CUCEK", "Pulincunnoo");
    add(table, "RPS", "Madhubani");
    add(table, "JVM", "Ranchi");
    add(table, "Home", "Munger");
    add(table, "Second Home", "Soha");
    add(table, "Real Home", "MBI");

    assert(!strcmp(get(table, "Aman"), "12150203"));
    assert(!strcmp(get(table, "Atish"), "Kuttummel"));
    assert(!strcmp(get(table, "Second Home"), "Soha"));
    assert(!strcmp(get(table, "New Delhi"), "DL"));

    destroy_table(table);
}


void test_add_delete() {
    hash_table *table = create_hash_table(64);

    add(table, "Aman", "12150203");
    add(table, "Alankar", "12150202");
    add(table, "Ravi", "12150229");
    add(table, "Prabhash", "RPS");
    add(table, "Atish", "Kuttummel");
    add(table, "Ravi EEE", "Kuttummel");
    add(table, "Saurav", "pseudo-ktml");
    add(table, "Bihar", "BR");
    add(table, "Kerala", "KL");
    add(table, "Jharkhand", "JH");
    add(table, "Rajasthan", "RJ");
    add(table, "J&K", "JK");
    add(table, "Maharashtra", "MH");
    add(table, "UP", "UP");
    add(table, "New Delhi", "DL");
    add(table, "10", "RPS");
    add(table, "12", "JVM");
    add(table, "B.Tech", "CUCEK");
    add(table, "India", "Rupee");
    add(table, "USA", "USD");
    add(table, "Tamil Nadu", "TN");
    add(table, "Bengal", "WB");
    add(table, "Kundan", "LBH");
    add(table, "Subham Soni", "LBH");
    add(table, "CUCEK", "Pulincunnoo");
    add(table, "RPS", "Madhubani");
    add(table, "JVM", "Ranchi");
    add(table, "Home", "Munger");
    add(table, "Second Home", "Soha");
    add(table, "Real Home", "MBI");

    delete(table, "New Delhi");
    assert(!exists(table, "New Delhi"));
    delete(table, "Aman");
    assert(!exists(table, "Aman"));

    print_table(table);

    destroy_table(table);
}


