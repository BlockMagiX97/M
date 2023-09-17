#include "data.h"
#include "defs.h"
#include "decl.h"


void var_decleration(void) {
    match(T_INT, "int");
    match(T_IDENTIFIER, "identifier");
    addglob(Text);
    genglobsym(Text);
    semi();
}