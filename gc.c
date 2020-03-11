#include "n.h"
/*6.4.1 Keywords
Semantics
The above tokens (case sensitive) are reserved (in translation phases 7 and 8)
for use as keywords, and shall not be used otherwise. The keyword _Imaginary is
reserved for specifying imaginary types.*/
static const char kw_auto[] = "auto";
static const char kw_break[] = "break";
static const char kw_case[] = "case";
static const char kw_char[] = "char";
static const char kw_const[] = "const";
static const char kw_continue[] = "continue";
static const char kw_default[] = "default";
static const char kw_do[] = "do";
static const char kw_double[] = "double";
static const char kw_else[] = "else";
static const char kw_enum[] = "enum";
static const char kw_extern[] = "extern";
static const char kw_float[] = "float";
static const char kw_for[] = "for";
static const char kw_goto[] = "goto";
static const char kw_star[] = "∗";
static const char kw_if[] = "if";
static const char kw_inline[] = "inline";
static const char kw_int[] = "int";
static const char kw_long[] = "long";
static const char kw_register[] = "register";
static const char kw_restrict[] = "restrict";
static const char kw_return[] = "return";
static const char kw_short[] = "short";
static const char kw_signed[] = "signed";
static const char kw_sizeof[] = "sizeof";
static const char kw_static[] = "static";
static const char kw_struct[] = "struct";
static const char kw_switch[] = "switch";
static const char kw_typedef[] = "typedef";
static const char kw_union[] = "union";
static const char kw_unsigned[] = "unsigned";
static const char kw_void[] = "void";
static const char kw_volatile[] = "volatile";
static const char kw_while[] = "while";
static const char kw__Alignas[] = "_Alignas";
static const char kw__Alignof[] = "_Alignof";
static const char kw__Atomic[] = "_Atomic";
static const char kw__Bool[] = "_Bool";
static const char kw__Complex[] = "_Complex";
static const char kw__Generic[] = "_Generic";
static const char kw__Imaginary[] = "_Imaginary";
static const char kw__Noreturn[] = "_Noreturn";
static const char kw__Static_assert[] = "_Static_assert";
static const char kw__Thread_local[] = "_Thread_local";
static const char *keywords[45] = // one of
    {kw_auto,         kw_break,      kw_case,      kw_char,
     kw_const,        kw_continue,   kw_default,   kw_do,
     kw_double,       kw_else,       kw_enum,      kw_extern,
     kw_float,        kw_for,        kw_goto,      kw_star,
     kw_if,           kw_inline,     kw_int,       kw_long,
     kw_register,     kw_restrict,   kw_return,    kw_short,
     kw_signed,       kw_sizeof,     kw_static,    kw_struct,
     kw_switch,       kw_typedef,    kw_union,     kw_unsigned,
     kw_void,         kw_volatile,   kw_while,     kw__Alignas,
     kw__Alignof,     kw__Atomic,    kw__Bool,     kw__Complex,
     kw__Generic,     kw__Imaginary, kw__Noreturn, kw__Static_assert,
     kw__Thread_local};

/* nondigit: one of
_ a b c d e f g h i j k l m
  A B C D E F G H I J K L M
  n o p q r s t u v w x y z
  N O P Q R S T U V W X Y Z */
void nondigit(int *o, const char *b) {
  *o = *b == '_' || ('a' <= *b && *b <= 'z') || //
               ('A' <= *b && *b <= 'Z')         //
           ? 1
           : -1;
}

/* digit: one of 013456789 */
void digit(int *o, const char *b) { *o = ('0' <= *b && *b <= '9') ? 1 : -1; }

void _() {}
void UniversalCharacterName(pith_t o, void *vs[2]);
// clang-format off
/*6.4.3 Universal character names
1) Syntax
*/
/* universal-character-name:
        \u hex-quad
        \U hex-quad hex-quad*/
/* hex-quad:
        hexadecimal-digit hexadecimal-digit
        hexadecimal-digit hexadecimal-digit*/
/*
6.4.2 Identifiers
1) Syntax
*/
/* identifier-nondigit:
        nondigit
        universal-character-name*/
  N(0, _,
L)N(L, nondigit,
L)N(L, _,
L)N(L, UniversalCharacterName,
       IdentifierNondigit);

/* identifier:
        identifier-nondigit
        identifier identifier-nondigit
        identifier digit */
void Identifier(pith_t o, void*vs);
  N(0,      _,
L)N(L,      IdentifierNondigit,
L)N(L,      _,
L)N(L,      IdentifierNondigit,
L)N(L,      Identifier,
L)N(L,      _,
L)N(L,      digit,
L)N(L,      Identifier,
            Identifier);
/*

Semantics
2) An identifier is a sequence of nondigit characters (including the underscore
_, the lowercase and uppercase Latin letters, and other characters) and digits,
which designates one or more entities as described in 6.2.1. Lowercase and
uppercase letters are distinct. There is no specific limit on the maximum length
of an identifier.
3) Each universal character name in an identifier shall
designate a character whose encoding in ISO/IEC 10646 falls into one of the
ranges specified in D.1. 71) The initial character shall not be a universal
character name designating a character whose encoding falls into one of the
ranges specified in D.2. An implementation may allow multibyte characters that
are not part of the basic source character set to appear in identifiers; which
characters and their correspondence to universal character names is
implementation-defined.
*/
int main() { (void)keywords; }
