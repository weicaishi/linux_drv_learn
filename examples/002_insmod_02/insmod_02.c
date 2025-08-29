#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <linux/module.h>
#include <sys/syscall.h>

int main(int argc, char *argv[]) {
  int fd = 0;
  int ret = 0;
  char *image = NULL;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <module_path>\n", argv[0]);
    return 1;
  }
  do {
    const char *module_path = argv[1];
    fd = open(module_path, O_RDONLY);
    if (fd < 0) {
      perror("open");
      break;
    }

    struct stat st;
    ret = fstat(fd, &st);
    if (ret < 0) {
      perror("fstat");
      break;
    }
    printf("File size: %ld bytes\n", st.st_size);

    image = malloc(st.st_size);
    if (NULL == image) {
      perror("malloc");
      break;
    }
    ret = read(fd, image, st.st_size);
    if (ret < 0) {
      perror("read");
      break;
    }
    ret = init_module(image, st.st_size, "");
    if (ret < 0) {
      perror("init_module");
      break;
    }
    printf("Module %s inserted successfully\n", module_path);

  } while (0);

  if (image) {
    free(image);
    image = NULL;
  }
  if (fd > 0) {
    close(fd);
    fd = 0;
  }
  return 0;
}