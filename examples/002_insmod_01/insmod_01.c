#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

#define finit_module(fd, params, flags) syscall(SYS_finit_module, fd, params, flags)

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <module_path>\n", argv[0]);
        return 1;
    }

    const char *module_path = argv[1];
    int fd = open(module_path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    int ret = finit_module(fd, "", 0);
    if (ret != 0)
    {
        perror("finit_module");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}