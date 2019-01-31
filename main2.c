/**
 * main2.c
 *
 * Created by Christine Kneer
 *
 * The main program of stage 2.
 *
 * To run the program:
 * ./dict1 <datafile> <outputfile>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "dict1.h"

/* the main function of the Information Retrieval System */
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./dict2 <datafile> <outputfile>\n");
        return 0;
    }
    char *datafile = argv[1];
    char *outputfile = argv[2];

    FILE *fp, *out_fp;
    char buffer[LINE];

    /* handle input file */
    fp = fopen(datafile, "r");
    if (fp == NULL) {
        printf("Cannot open %s.\n", datafile);
        return 0;
    }

    /* handle output file */
    out_fp = fopen(outputfile, "w");
    if (out_fp == NULL) {
        printf("Cannot open %s.\n", outputfile);
        return 0;
    }

    /* create new dict */
    dict_t *dict = makedict(out_fp);

    /* read line from input file */
    while (fgets(buffer, LINE, fp)) {
        char *token = ",";
        char *p = strtok(buffer, token);
        if (p) {
        	data_t *d = malloc(sizeof(data_t));
			char *key;
			/* id */
			d->id = atoi(p);
			/* name */
			p = strtok(NULL, token);
			strcpy(d->name, p);
			key = d->name;
			/* sex */
			p = strtok(NULL, token);
			strcpy(d->sex, p);
			/* age */
			p = strtok(NULL, token);
			strcpy(d->age, p);
			/* height */
			p = strtok(NULL, token);
			strcpy(d->height, p);
			/* weight */
			p = strtok(NULL, token);
			strcpy(d->weight, p);
			/* team */
			p = strtok(NULL, token);
			strcpy(d->team, p);
			/* noc */
			p = strtok(NULL, token);
			strcpy(d->noc, p);
			/* game */
			p = strtok(NULL, token);
			strcpy(d->game, p);
			/* year */
			p = strtok(NULL, token);
			strcpy(d->year, p);
			/* season */
			p = strtok(NULL, token);
			strcpy(d->season, p);
			/* city */
			p = strtok(NULL, token);
			strcpy(d->city, p);
			/* sport */
			p = strtok(NULL, token);
			strcpy(d->sport, p);
			/* event */
			p = strtok(NULL, token);
			strcpy(d->event, p);
			/* medal */
			p = strtok(NULL, token);
			strcpy(d->medal, p);
			if (d->medal[strlen(d->medal) - 1] == '\n') {
				d->medal[strlen(d->medal) - 1] = '\0';
			}
			/* insert key/value to dict */
            insert(dict, key, d);
        }
    }

    fclose(fp);

    /* read search key from STDIN */
    while (fgets(buffer, LINE, stdin)) {
    	if (buffer[strlen(buffer) - 1] == '\n') {
    		buffer[strlen(buffer) - 1] = '\0';
    	}

    	/* search data */
    	data_t *result = search(dict, buffer);
    	if (result == NULL) {
    		fprintf(out_fp, "%s --> NOTFOUND\n\n", buffer);
    	}

    	printf("%s --> %d\n", buffer, dict->num_comparisons);
    }
    fclose(out_fp);

    return 0;
}
