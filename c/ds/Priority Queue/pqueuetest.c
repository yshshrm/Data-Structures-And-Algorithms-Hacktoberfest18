#include <stdio.h>
#include "pqueue.h"

int cmp(const void *elem_addr1, const void *elem_addr2){
  return *(int *)elem_addr1 - *(int *)elem_addr2;
}

int main() {
  printf("Testing... \n");
  pqueue myq;
  pqueue_new(&myq, sizeof(int), cmp, NULL);
  // Test 0 --------------------------------------------------------------------
  int n0 = 5;
  pqueue_push(&myq, &n0);
  int res0;
  pqueue_top(&myq, &res0);
  printf("%d\n", res0);
  // Test 1 --------------------------------------------------------------------
  int n1 = 4;
  pqueue_push(&myq, &n1);
  int res1;
  pqueue_top(&myq, &res1);
  printf("%d\n", res1);
  // Test 2 --------------------------------------------------------------------
  int n2 = 6;
  pqueue_push(&myq, &n2);
  int res2;
  pqueue_top(&myq, &res2);
  printf("%d\n", res2);
  // Test 3 --------------------------------------------------------------------
  pqueue_pop(&myq);
  int res3;
  pqueue_top(&myq, &res3);
  printf("%d\n", res3);
  // Test 4 --------------------------------------------------------------------
  pqueue_pop(&myq);
  int res4;
  pqueue_top(&myq, &res4);
  printf("%d\n", res4);
  /*
  int n = 5;
  pqueue_push(&myq, &n);
  int m = 6;
  pqueue_push(&myq, &m);
  */
  /*

  int n = 5;
  pqueue_push(&myq, &n);

  int m = 6;
  pqueue_push(&myq, &m);

  int k = 6;
  pqueue_push(&myq, &k);

  int l = 6;
  pqueue_push(&myq, &l);

  pqueue_test(&myq);
  */
  /*
  int res;
  pqueue_top(&myq, &res);
  printf("%d\n", res);

  printf("\nPushing again... \n");
  int m = 6;
  pqueue_push(&myq, &m);

  int r;
  pqueue_top(&myq, &r);
  printf("%d\n", r);
  */

  printf("\nTesting is finished! \n");
  return 0;
}
