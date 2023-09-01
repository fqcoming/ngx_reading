#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <wait.h>
#include "ngx_shmem.h"




int main() {

    ngx_shm_t shm1;
    shm1.size = 1024;

    if (!ngx_shm_alloc(&shm1)) {
        std::cout << "alloc failed" << std::endl;
        return -1;
    }

    std::cout << "alloc successfully" << std::endl;
    memset(shm1.addr, 0, shm1.size);
    memcpy(shm1.addr, "happy", 5);

    pid_t pid = fork();
    if (pid < 0) {

        std::cout << "pid < 0" << std::endl;

    } else if (pid == 0) {

        // 子进程
        std::cout << shm1.addr << std::endl;
        memcpy(shm1.addr, "fuqia", 5);

    } else {

        // 父进程
        sleep(10);

        std::cout << shm1.addr << std::endl;
        int status;
        waitpid(-1, &status, WUNTRACED);  // 阻塞
    }



    if (!ngx_shm_free(&shm1)) {
        return -1;
    }

    return 0;
}


















