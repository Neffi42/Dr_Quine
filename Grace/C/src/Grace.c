#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define FILE "Grace_kid.c"
#define CODE "#include <unistd.h>%2$c#include <stdio.h>%2$c#include <fcntl.h>%2$c#include <string.h>%2$c#define FILE %3$cGrace_kid.c%3$c%2$c#define CODE %3$c%1$s%3$c%2$c#define GRACE() int main() {int fd = open(FILE, O_CREAT | O_TRUNC | O_WRONLY, 0644); if (fd == -1) {return -1;} char buf[1000] = {0}; sprintf(buf, CODE, CODE, 10, 34); write(fd, buf, strlen(buf)); close(fd); return 0;}%2$c/*%2$c    One comment%2$c*/%2$cGRACE()%2$c"
#define GRACE() int main() {int fd = open(FILE, O_CREAT | O_TRUNC | O_WRONLY, 0644); if (fd == -1) {return -1;} char buf[1000] = {0}; sprintf(buf, CODE, CODE, 10, 34); write(fd, buf, strlen(buf)); close(fd); return 0;}
/*
    One comment
*/
GRACE()
