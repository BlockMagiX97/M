#include "defs.h"
#include "data.h"
#include "decl.h"

int findglob(char *s) {
    for (int i=0;i<NSYMBOLS;i++) {
        if (strcmp(s, Gsym[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

static int getnextglobpos(void) {
    int p;
    if ((p = Globs++) >= NSYMBOLS) {
        fatal("Too many global symbols");
    }
    return p;
}
int addglob(char *name) {
    int i;
    if ((i = findglob(name)) != -1) {
        return i;
    }
    i = getnextglobpos();

    Gsym[i].name = strdup(name);
    return i;
}