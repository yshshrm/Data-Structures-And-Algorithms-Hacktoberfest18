#include "hashmap.h"
#include <stdio.h>

int cmp(const void *arg1, const void *arg2){
  return *(int *)arg1 - *(int *)arg2;
}

int hashfn(const void *elem_addr, int num_buckets){
  return *(int *)elem_addr;
}

int main() {
  printf("Testing hashmap...\n");
  printf("############################################\n");
  hashmap hm;
  hashmap_new(&hm, sizeof(int), sizeof(char), 100, cmp, NULL, hashfn);
  printf("Testing put...\n");
  printf("--------------------------------------------\n");
  // Test #1
  int key = 2;
  char value = 'a';
  hashmap_put(&hm, &key, &value);
  printf("Passed\n");
  // Test #2
  key = 3;
  value = 'b';
  hashmap_put(&hm, &key, &value);
  printf("Passed\n");
  // Test #3
  key = 2;
  value = 'k';
  hashmap_put(&hm, &key, &value);
  printf("Passed\n");

  // Test #4
  key = 1;
  value = 'l';
  hashmap_put(&hm, &key, &value);
  printf("Passed\n");

  // Test #5
  key = 4;
  value = 'g';
  hashmap_put(&hm, &key, &value);
  printf("Passed\n");

  printf("Testing contains_key...\n");
  printf("--------------------------------------------\n");

  // Test #6
  if (hashmap_contains_key(&hm, &key)){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }
  // Test #7
  key = 3;
  if (hashmap_contains_key(&hm, &key)){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }
  // Test #8
  key = 17;
  if (!hashmap_contains_key(&hm, &key)){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }

  printf("Testing get...\n");
  printf("--------------------------------------------\n");

  // Test #9
  key = 1;
  char res;
  hashmap_get(&hm, &key, &res);
  if (res == 'l'){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }
  // Test #10
  key = 2;
  res;
  hashmap_get(&hm, &key, &res);
  if (res == 'k'){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }

  printf("Testing remove...\n");
  printf("--------------------------------------------\n");
  // Test #11
  int prev_len = hashmap_length(&hm);
  hashmap_remove(&hm, &key);
  if (hashmap_length(&hm) == prev_len - 1){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }
  // Test #12
  key = 4;
  prev_len = hashmap_length(&hm);
  hashmap_remove(&hm, &key);
  if (hashmap_length(&hm) == prev_len - 1){
    printf("Passed\n");
  } else {
    printf("Wrong\n");
  }

  printf("Testing dispose...\n");
  printf("--------------------------------------------\n");
  // Test #13
  hashmap_dispose(&hm);
  printf("Passed\n");
  // End of tests --------------------------------------------------------------
  printf("############################################\n");
  printf("Testing done...\n");
  return 0;
}
