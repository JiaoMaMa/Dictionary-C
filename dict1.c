/**
 * dict1.c
 *
 * Created by Christine Kneer
 *
 * The dict ADT of stage 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "dict1.h"

/* make a new dict */
dict_t* makedict(FILE *out_fp) {
    dict_t *d = malloc(sizeof(dict_t));
    d->out_fp = out_fp;
    return d;
}

/* helper function of insert */
void insert_rec(node_t *node, char *key, data_t *value) {
    int compare = strcmp(node->key, key);
    if (compare > 0) {
        if (node->l == NULL) {
        	/* insert data to left leaf */
            node_t *new_node = malloc(sizeof(node_t));
            new_node->key = key;
            new_node->d = value;
            new_node->l = NULL;
            new_node->r = NULL;
            node->l = new_node;
        } else {
        	insert_rec(node->l, key, value);
        }
    } else if (compare <= 0) {
        if (node->r == NULL) {
        	/* insert data to right leaf */
            node_t *new_node = malloc(sizeof(node_t));
            new_node->key = key;
            new_node->d = value;
            new_node->l = NULL;
            new_node->r = NULL;
            node->r = new_node;
        } else {
        	insert_rec(node->r, key, value);
        }
    }
}

/* insert a key/value pair to the dict */
void insert(dict_t *dict, char *key, data_t *value) {
    if (dict->root == NULL) {
        node_t *node = malloc(sizeof(node_t));
        node->key = key;
        node->d = value;
        node->l = NULL;
        node->r = NULL;
        dict->root = node;
    } else {
        insert_rec(dict->root, key, value);
    }
}

/* write search result info the file */
void write_to_file(dict_t *dict, data_t *data) {
	fprintf(dict->out_fp, "%s --> ", data->name);
	fprintf(dict->out_fp, "ID: %d ", data->id);
	fprintf(dict->out_fp, "Sex: %s || ", data->sex);
	fprintf(dict->out_fp, "Age: %s || ", data->age);
	fprintf(dict->out_fp, "Height: %s || ", data->height);
	fprintf(dict->out_fp, "Weight: %s || ", data->weight);
	fprintf(dict->out_fp, "Team: %s || ", data->team);
	fprintf(dict->out_fp, "NOC: %s || ", data->noc);
	fprintf(dict->out_fp, "Games: %s || ", data->game);
	fprintf(dict->out_fp, "Year: %s || ", data->year);
	fprintf(dict->out_fp, "Season: %s || ", data->season);
	fprintf(dict->out_fp, "City: %s || ", data->city);
	fprintf(dict->out_fp, "Sport: %s || ", data->sport);
	fprintf(dict->out_fp, "Event: %s || ", data->event);
	fprintf(dict->out_fp, "Medal: %s ||\n\n", data->medal);
}

/* helper function of search */
void search_rec(dict_t *dict, node_t *node, char *key) {
	if (node == NULL) {
		return;
	}
    int compare = strcmp(node->key, key);
    dict->num_comparisons++;
    /* find data */
    if (compare == 0) {
    	write_to_file(dict, node->d);
    	dict->result = node->d;
    }
    if (compare > 0) {
    	search_rec(dict, node->l, key);
    } else {
        search_rec(dict, node->r, key);
    }
}

/* search data from dict via a key */
data_t* search(dict_t *dict, char *key) {
	dict->num_comparisons = 0;
	dict->result = NULL;
	search_rec(dict, dict->root, key);
	return dict->result;
}
