#include<stdio.h>
#include <stdlib.h>

struct node {
 struct node *left;
 struct node *right;
 int data;
};

struct node *mkNode(int d, struct node *l, struct node *r) {
  struct node *n = NULL;
  if((n = malloc(sizeof (struct node))) != NULL){
    n->data = d; n->left = l; n->right = r; return n;}
    else { return NULL;}
  }

struct node *mkLeaf(int d) {
  return mkNode(d, NULL, NULL);
}

void printInorder(struct node *n) {
  if(n == NULL) return;
  printInorder(n->left);
  printf("%c\n", n->data);
  printInorder(n->right);
}

int count_occurrences(struct node *n, char c) {
  if (n == NULL) return 0;
  int match = (n -> data == c);
  int left_occurrences = count_occurrences(n -> left, c);
  int right_occurrences = count_occurrences(n -> right, c);
  return match + left_occurrences + right_occurrences;
}

int main(void) {
  struct node *tree = mkNode(' ', mkNode('n', mkNode(' ', mkNode('e', mkLeaf('S'), mkNode('i', NULL, mkLeaf('n'))), mkNode('e', mkNode('o', NULL, mkLeaf('d')), mkNode('r', NULL, mkLeaf(' ')))), mkNode(' ', mkNode('c', mkLeaf('i'), mkNode('h', NULL, mkLeaf('t'))), mkNode('i', mkNode('s', NULL, mkLeaf('e')), mkNode('n', NULL, mkLeaf(','))))), mkNode('e', mkNode('i', mkNode('a', mkLeaf('d'), mkNode('s', NULL, mkLeaf(' '))), mkNode(' ', mkNode('s', NULL, mkLeaf('t')), mkNode('h', NULL, mkLeaf('i')))), mkNode(' ', mkNode('d', mkNode('r', NULL, mkLeaf(' ')), mkNode('i', NULL, mkLeaf('e'))), mkNode('a', mkNode('F', NULL, mkLeaf('r')), mkNode('g', NULL, mkLeaf('e'))))));

  char input;
  printf("Zeichen eingeben: ");
  scanf("%c", &input);
  printf("Das Zeichen '%c' kommt %d mal vor\n", input, count_occurrences(tree, input));

  printInorder(tree);
  return 1;
}