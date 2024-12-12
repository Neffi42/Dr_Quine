#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define NEWLINE 10
#define QUOTE 34
#define CODE "#include <unistd.h>%2$c#include <stdio.h>%2$c#include <fcntl.h>%2$c#include <string.h>%2$c#include <stdlib.h>%2$c%2$c#define NEWLINE 10%2$c#define QUOTE 34%2$c#define CODE %3$c%1$s%3$c%2$c#define CMD %3$ccc -Wall -Wextra -Werror %%s -o Sully_%%d%3$c%2$c%2$cint main() {%2$c    int i = %4$d;%2$c    if (i < 0) return 0;%2$c    char file[20];%2$c    sprintf(file, %3$cSully_%%d.c%3$c, i);%2$c    int fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);%2$c    if (fd < 0) return 1;%2$c    char code[2000];%2$c    sprintf(code, CODE, CODE, NEWLINE, QUOTE, i - 1);%2$c    write(fd, code, strlen(code));%2$c    close(fd);%2$c%2$c    char cmd[200];%2$c    sprintf(cmd, CMD, file, i);%2$c    system(cmd);%2$c%2$c    if (i - 1 >= 0) {%2$c        sprintf(cmd, %3$c./Sully_%%d%3$c, i);%2$c        system(cmd);%2$c    }%2$c    return 0;%2$c}%2$c"
#define CMD "cc -Wall -Wextra -Werror %s -o Sully_%d"

int main() {
    int i = 5;
    if (i < 0) return 0;
    char file[20];
    sprintf(file, "Sully_%d.c", i);
    int fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0) return 1;
    char code[2000];
    sprintf(code, CODE, CODE, NEWLINE, QUOTE, i - 1);
    write(fd, code, strlen(code));
    close(fd);

    char cmd[200];
    sprintf(cmd, CMD, file, i);
    system(cmd);

    if (i - 1 >= 0) {
        sprintf(cmd, "./Sully_%d", i);
        system(cmd);
    }
    return 0;
}
