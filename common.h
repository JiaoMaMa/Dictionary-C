/**
 * common.h
 *
 * Created by Christine Kneer
 *
 * The common part.
 */

#ifndef COMMON_H
#define COMMON_H

#define LENGTH 128
#define LINE   512

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[LENGTH];
    char sex[LENGTH];
    char age[LENGTH];
    char height[LENGTH];
    char weight[LENGTH];
    char team[LENGTH];
    char noc[LENGTH];
    char game[LENGTH];
    char year[LENGTH];
    char season[LENGTH];
    char city[LENGTH];
    char sport[LENGTH];
    char event[LENGTH];
    char medal[LENGTH];
} data_t;

#endif
