#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void run_example();

int main(int argc, char* argv[]) {
    run_all_tests();
    run_example();

    return EXIT_SUCCESS;
}

void run_example() {
  int capacity = 0;

  printf("Enter many numbers would you like to store: ");
  scanf("%d", &capacity);

  printf("You'll be storing %d numbers.\n", capacity);

  // make it so

  SArray* aptr = new_sarray(capacity);

  for (int d = 1; d <= capacity; ++d) {
    push(aptr, d);
  }

  int insert_value = 999;
  printf(" - Inserting %d at index %d.\n", insert_value, capacity - 1);
  insert(aptr, capacity - 1, insert_value);

  printf(" - Prepending %d.\n", 12);
  prepend(aptr, 12);

  printf(" - Popping an item: %d\n", pop(aptr));

  print(aptr);

  int index_to_remove = size(aptr) - 3;
  printf(" - Deleting from index %d\n", index_to_remove);
  delete_at(aptr, index_to_remove);

  push(aptr, 12);
  push(aptr, 12);

  print(aptr);

  printf(" - Deleting 12s\n");

  remove_value(aptr, 12);

  print(aptr);

  destroy(aptr);
}
