#include <stdio.h>

/*
    Comment outside of the program
*/

void f() {
    char *code = "#include <stdio.h>%1$c%1$c/*%1$c    Comment outside of the program%1$c*/%1$c%1$cvoid f() {%1$c    char *code = %3$c%2$s%3$c;%1$c    printf(code, 10, code, 34);%1$c}%1$c%1$cint main() {%1$c    /*%1$c        Comment inside main function%1$c    */%1$c    f();%1$c    return 0;%1$c}%1$c";
    printf(code, 10, code, 34);
}

int main() {
    /*
        Comment inside main function
    */
    f();
    return 0;
}
