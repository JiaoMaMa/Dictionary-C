/**
 * dict2.h
 *
 * Created by Christine Kneer
 *
 * The header of dict ADT of stage 2.
 */

#ifndef DICT2_H
#define DICT2_H

#include "common.h"

typedef struct l_node_t {
	/* value */
	data_t *d;
	/* next node */
	struct l_node_t *next;
} l_node_t;

typedef struct node_t {
	/* key */
	char *key;
	/* linked list value */
	l_node_t *value;
	/* left node */
	struct node_t *l;
	/* right node */
	struct node_t *r;
} node_t;

typedef struct {
	/* root of the dict */
	node_t *root;
	/* the number of num_comparisons */
	int num_comparisons;
	/* the output file */
	FILE *out_fp;
	/* search result */
	data_t *result;
} dict_t;

dict_t* makedict(FILE *out_fp);
void insert(dict_t *dict, char *key, data_t *value);
data_t* search(dict_t *dict, char *key);

#endif
