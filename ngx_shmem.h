#ifndef __NGX_SHMEM_H_INCLUDED__
#define __NGX_SHMEM_H_INCLUDED__


#include <stddef.h>


typedef struct {
    unsigned char *addr;
    size_t    size;
} ngx_shm_t;


bool ngx_shm_alloc(ngx_shm_t *shm);
bool ngx_shm_free (ngx_shm_t *shm);


#endif /* __NGX_SHMEM_H_INCLUDED__ */
