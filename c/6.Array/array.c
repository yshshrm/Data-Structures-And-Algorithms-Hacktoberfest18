#include "array.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/*
 * Created by shriaas2898 on 17/08/19.
 * Description: An api file for implementing arrays in C
 * File contains helper function s to implement array through ARRAY structure defined in array.h
*/


/* create() - Allocates requested size of memory. If successful returns the address of memory block allocated
 * and also stores it in array variable along with size. On error, returns NULL.
 */
int* create(ARRAY* aname, unsigned short size)
{
    if(aname->base=(int*)malloc(sizeof(int)*size)){
        aname->size=size;
        return aname->base;
    }
    errno = ENOMEM;
    return NULL;
}

/* store() - Stores a value at the specified index. If successful returns 0.
 * The function checks for bounds and on error, returns -1.
 */
int store(ARRAY* aname, int value, unsigned short index){
    if(index>-1 && index<aname->size){
        *(aname->base+index)=value;
        return 0;
    }
    errno = EINVAL;
    //strerror(errno);
    perror("Error store:");
    return errno;
}

/* read() - Returns a value at the specified index.
 */
int read(ARRAY aname, unsigned short index)
{
    if(!(index>-1 && index<aname.size)) {
        errno = EINVAL;
        perror("Error: ");

    }
    return *(aname.base + index);

}

/* delete() - Releases the memory allocated to array.
 */
void delete(ARRAY aname)
{
    free (aname.base);
    aname.base = null;
}
