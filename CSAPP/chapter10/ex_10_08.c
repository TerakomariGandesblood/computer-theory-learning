#include <csapp.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "need a fd\n");
    exit(EXIT_FAILURE);
  }

  struct stat stat;
  Fstat(strtol(argv[1], NULL, 10), &stat);

  const char *type;
  if (S_ISREG(stat.st_mode)) {
    type = "regular";
  } else if (S_ISDIR(stat.st_mode)) {
    type = "directory";
  } else {
    type = "other";
  }

  const char *read_ok;
  if (stat.st_mode & S_IRUSR) {
    read_ok = "yes";
  } else {
    read_ok = "no";
  }

  printf("type: %s, read: %s\n", type, read_ok);
}
