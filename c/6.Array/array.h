#ifndef ARRAY_H
#define ARRAY_H
/*
 * Created by shriaas2898 on 17/08/19.
 * Description: An api file for implementing arrays in C
 * file contains a structure for array and prototype pf functions present in array.c
*/
typedef struct {
    int* base;
    unsigned short size;
}ARRAY;

int* create(ARRAY* aname, unsigned short size);
int store(ARRAY* aname, int value, unsigned short  index);
int read(ARRAY aname, unsigned short index);
void delete(ARRAY aname);
#endif 
