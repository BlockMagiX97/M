#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure and enum definitions


#define TEXTLEN		512	// Length of symbols in input
#define NSYMBOLS 1024

struct symtable {
  char *name;
};

// Token types
enum {
  T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_PRINT, T_INT, T_EQUALS, T_IDENTIFIER
};

// Token structure
struct token {
  int token;			// Token type, from the enum list above
  union {
    int intvalue;			// For T_INTLIT, the integer value
    char *var_name;
  };
  
  
};

// AST node types
enum {
  A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

// Abstract Syntax Tree structure
struct ASTnode {
  int op;			// "Operation" to be performed on this tree
  struct ASTnode *left;		// Left and right child trees
  struct ASTnode *right;
  int intvalue;			// For A_INTLIT, the integer value
};
