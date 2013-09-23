#include <stdio.h>
#include <stdlib.h>
#include "variable_queue.h"

Q_NEW_HEAD(new_list_type, node);

typedef struct node {
  Q_NEW_LINK(node) node_link; 
  int data;
} node_t;

new_list_type new_list;

int main() {
  Q_INIT_HEAD(&new_list);   
  node_t *node_1 = (node_t *) malloc(sizeof(node_t));
  node_1->data = 1;
  node_t *node_2 = (node_t *) malloc(sizeof(node_t));
  node_2->data = 2;
  Q_INSERT_FRONT(&new_list, node_1, node_link);
  Q_INSERT_TAIL(&new_list, node_2, node_link);
  node_t *itr;
  Q_FOREACH(itr, &new_list, node_link) {
    printf("%d\n", itr->data);
  }
  printf("\n");
  free(node_1);
  free(node_2);
}
