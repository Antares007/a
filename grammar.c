#include "m.h"
// clang-format off
/*
A.1 Lexical grammar

A.1.1 Lexical elements

token:
  keyword
  identifier
  constant
  string_literal
  punctuator
preprocessing_token:
  header_name
  identifier
  pp_number
  character_constant
  string_literal
  punctuator
  each non_white_space character that cannot be one of the above

A.1.2 Keywords

keyword: one of
  auto break case char const continue default do double else enum extern float for goto
  ∗ if inline int long register restrict return short signed sizeof static struct switch
  typedef union unsigned void volatile while _Alignas _Alignof _Atomic _Bool _Complex
  _Generic _Imaginary _Noreturn _Static_assert _Thread_local

*/
void _(){}
        TG(0, "Z", _,
      L)TG(L, "z", _,
      L)TG(L, "Y", _,
      L)TG(L, "y", _,
      L)TG(L, "X", _,
      L)TG(L, "x", _,
      L)TG(L, "W", _,
      L)TG(L, "w", _,
      L)TG(L, "V", _,
      L)TG(L, "v", _,
      L)TG(L, "U", _,
      L)TG(L, "u", _,
      L)TG(L, "T", _,
      L)TG(L, "t", _,
      L)TG(L, "S", _,
      L)TG(L, "s", _,
      L)TG(L, "R", _,
      L)TG(L, "r", _,
      L)TG(L, "Q", _,
      L)TG(L, "q", _,
      L)TG(L, "P", _,
      L)TG(L, "p", _,
      L)TG(L, "O", _,
      L)TG(L, "o", _,
      L)TG(L, "N", _,
      L)TG(L, "n", _,
      L)TG(L, "M", _,
      L)TG(L, "m", _,
      L)TG(L, "L", _,
      L)TG(L, "l", _,
      L)TG(L, "K", _,
      L)TG(L, "k", _,
      L)TG(L, "J", _,
      L)TG(L, "j", _,
      L)TG(L, "I", _,
      L)TG(L, "i", _,
      L)TG(L, "H", _,
      L)TG(L, "h", _,
      L)TG(L, "G", _,
      L)TG(L, "g", _,
en_alfa_gz)
        TG(0, "F", _,
      L)TG(L, "f", _,
      L)TG(L, "E", _,
      L)TG(L, "e", _,
      L)TG(L, "D", _,
      L)TG(L, "d", _,
      L)TG(L, "C", _,
      L)TG(L, "c", _,
      L)TG(L, "B", _,
      L)TG(L, "b", _,
      L)TG(L, "A", _,
      L)TG(L, "a", _,
en_alfa_af)
        AG(0, en_alfa_gz, _,
      L)AG(L, en_alfa_af, _,
en_alfa)
        AG(0, en_alfa, _,
      L)TG(L, "_", _,
nondigit)
        TG(0, "9", _,
      L)TG(L, "8", _,
      L)TG(L, "7", _,
      L)TG(L, "6", _,
      L)TG(L, "5", _,
      L)TG(L, "4", _,
      L)TG(L, "3", _,
      L)TG(L, "2", _,
      L)TG(L, "1", _,
nonzero_digit)
        AG(0, nonzero_digit, _,
      L)TG(L, "0", _,
digit)
        AG(0, en_alfa_af, _,
      L)AG(L, digit, _,
hexadecimal_digit)
     AAAAG(0, hexadecimal_digit, hexadecimal_digit, hexadecimal_digit, hexadecimal_digit, _,
hex_quad)
       TAG(0, "\\u", hex_quad, _,
    L)TAAG(L, "\\U", hex_quad, hex_quad, _,
universal_character_name)
        AG(0, universal_character_name, _,
      L)AG(L, nondigit, _,
identifier_nondigit)
void identifier(pith_t*);
        AG(0, identifier_nondigit, _,
     L)AAG(L, identifier, identifier_nondigit, _,
     L)AAG(L, identifier, digit, _,
identifier)

extern int printf(const char *restrict __format, ...);
#define C(...) (const void *[]) { __VA_ARGS__ }

NT(pith2_t, void (*o)(struct pith2_t*, const char *, void *, void *); void *l1; void *l2;)
typedef void (*bark_t)(pith2_t*);

void pith(pith2_t *p, const char *n, void *h, void *t) {
  if(*n == 'A') {
    void **l = p->l1;
    int found = 0;
    for(; l && !found; l = l[1]) found = l[0] == h;
    if(!found) {
      p->l1 = C(h, p->l1);
      p->l2 = C(n + 1, h, p->l2);
    }
  }
  if(*n =='G') 
    printf("\n  ");
  else 
    printf("%s ", n+1);
  if(t) 
    ((bark_t)t)(p);
  else if (p->l2){
    void **rest = p->l2;
    p->l2 = rest[2];
    printf("\n%s:\n  ", rest[0]);
    ((bark_t)rest[1])(p);
  }
}

int main() {
  printf("identifier:\n  ");
  identifier((pith_t*)&(pith2_t){pith, C(identifier, 0), 0});
  return 99;
}

static void
            *integer_suffix,
            *octal_constant,
            *hexadecimal_constant,
            *c_char_sequence,
            *hexadecimal_floating_constant,
            *decimal_floating_constant
            ;

        AG(0, nonzero_digit, _,
     L)AAG(L, decimal_constant, digit, _,
decimal_constant)
        AG(0, identifier, _,
enumeration_constant)
        AG(0, hexadecimal_floating_constant, _,
      L)AG(L, decimal_floating_constant, _,
floating_constant)
      TATG(0, "U'", c_char_sequence, "'", _,
    L)TATG(L, "u'", c_char_sequence, "'", _,
    L)TATG(L, "L'", c_char_sequence, "'", _,
    L)TATG(L,  "'", c_char_sequence, "'", _,
character_constant)
        AG(0, octal_constant, _,
     L)AAG(L, octal_constant, integer_suffix, _,
     L) AG(L, hexadecimal_constant, _,
     L)AAG(L, hexadecimal_constant, integer_suffix, _,
     L) AG(L, decimal_constant, _,
     L)AAG(L, decimal_constant, integer_suffix, _,
integer_constant)
        AG(0, enumeration_constant, _,
      L)AG(L, floating_constant, _,
      L)AG(L, character_constant, _,
      L)AG(L, integer_constant, _,
constant)

/*
A.1.5 Constants

octal_constant:
  0
  octal_constant octal_digit
hexadecimal_constant:
  hexadecimal_prefix hexadecimal_digit
  hexadecimal_constant hexadecimal_digit
hexadecimal_prefix: one of
  0x 0X
nonzero_digit: one of
  1 2 3 4 5 6 7 8 9
octal_digit: one of
  0 1 2 3 4 5 6 7
integer_suffix:
  unsigned_suffix long_suffix?opt
  unsigned_suffix long_long_suffix
  long_suffix unsigned_suffix?opt
  long_long_suffix unsigned_suffix?opt
unsigned_suffix: one of
  u U
long_suffix: one of
  l L
long_long_suffix: one of
  ll LL
decimal_floating_constant:
  fractional_constant exponent_part?opt floating_suffix?opt
  digit_sequence exponent_part floating_suffix?opt
hexadecimal_floating_constant:
  hexadecimal_prefix hexadecimal_fractional_constant binary_exponent_part floating_suffix?opt
  hexadecimal_prefix hexadecimal_digit_sequence binary_exponent_part floating_suffix?opt
fractional_constant:
  digit_sequence?opt . digit_sequence
  digit_sequence .
exponent_part:
  e sign?opt digit_sequence
  E sign?opt digit_sequence
sign: one of
  + -
digit_sequence:
  digit
  digit_sequence digit
hexadecimal_fractional_constant:
  hexadecimal_digit_sequence?opt .  hexadecimal_digit_sequence
  hexadecimal_digit_sequence .
binary_exponent_part:
  p sign?opt digit_sequence
  P sign?opt digit_sequence
hexadecimal_digit_sequence:
  hexadecimal_digit
  hexadecimal_digit_sequence hexadecimal_digit
floating_suffix: one of
  f l F L
c_char_sequence:
  c_char
  c_char_sequence c_char
c_char:
  any member of the source character set except the single_quote ', backslash \, or new_line character
  escape_sequence
escape_sequence:
  simple_escape_sequence
  octal_escape_sequence
  hexadecimal_escape_sequence
  universal_character_name
simple_escape_sequence: one of
  \' \" \? \\ \a \b \f \n \r \t \v
octal_escape_sequence:
  \ octal_digit
  \ octal_digit octal_digit
  \ octal_digit octal_digit octal_digit
hexadecimal_escape_sequence:
  \x hexadecimal_digit
  hexadecimal_escape_sequence hexadecimal_digit

A.1.6 String literals

string_literal:
  encoding_prefix?opt " s_char_sequence?opt "
encoding_prefix:
  u8
  u
  U
  L
s_char_sequence:
  s_char
  s_char_sequence s_char
s_char:
  any member of the source character set except the double_quote ", backslash \, or new_line character
  escape_sequence

A.1.7 Punctuators

punctuator: one of
  [ ] ( ) { } . ->
  ++ -- & * + - ~ !
  / % << >> < > <= >= ? : ; ...
  = *= /= %= += -= <<= , # ## <: :> <% %> %: %:%: == >>=
  != &= ^ | ^= && || |=

A.1.8 Header names

header_name:
  < h_char_sequence >
  " q_char_sequence "
h_char_sequence:
  h_char
  h_char_sequence h_char
h_char:
  any member of the source character set except the new_line character and >
q_char_sequence:
  q_char
  q_char_sequence q_char
q_char:
  any member of the source character set except the new_line character and "

A.1.9 Preprocessing numbers

pp_number:
  digit
  . digit
  pp_number digit
  pp_number identifier_nondigit
  pp_number e sign
  pp_number E sign
  pp_number p sign
  pp_number P sign
  pp_number .

A.2 Phrase structure grammar

A.2.1 Expressions

primary_expression:
  identifier
  constant
  string_literal
  ( expression )
  generic_selection
generic_selection:
  _Generic ( assignment_expression , generic_assoc_list )
generic_assoc_list:
  generic_association
  generic_assoc_list , generic_association
generic_association:
  type_name : assignment_expression
  default : assignment_expression
postfix_expression:
  primary_expression
  postfix_expression [ expression ]
  postfix_expression ( argument_expression_list?opt )
  postfix_expression . identifier
  postfix_expression -> identifier
  postfix_expression ++
  postfix_expression --
  ( type_name ) { initializer_list }
  ( type_name ) { initializer_list , }
argument_expression_list:
  assignment_expression
  argument_expression_list , assignment_expression
unary_expression:
  postfix_expression
  ++ unary_expression
  -- unary_expression
  unary_operator cast_expression
  sizeof unary_expression
  sizeof ( type_name )
  _Alignof ( type_name )
unary_operator: one of
  & * + - ~ !
cast_expression:
  unary_expression
  ( type_name ) cast_expression
multiplicative_expression:
  cast_expression
  multiplicative_expression * cast_expression
  multiplicative_expression / cast_expression
  multiplicative_expression % cast_expression
additive_expression:
  multiplicative_expression
  additive_expression + multiplicative_expression
  additive_expression - multiplicative_expression
shift_expression:
  additive_expression
  shift_expression << additive_expression
  shift_expression >> additive_expression
relational_expression:
  shift_expression
  relational_expression < shift_expression
  relational_expression > shift_expression
  relational_expression <= shift_expression
  relational_expression >= shift_expression
equality_expression:
  relational_expression
  equality_expression == relational_expression
  equality_expression != relational_expression
AND_expression:
  equality_expression
  AND_expression & equality_expression
exclusive_OR_expression:
  AND_expression
  exclusive_OR_expression ^ AND_expression
inclusive_OR_expression:
  exclusive_OR_expression
  inclusive_OR_expression | exclusive_OR_expression
logical_AND_expression:
  inclusive_OR_expression
  logical_AND_expression && inclusive_OR_expression
logical_OR_expression:
  logical_AND_expression
  logical_OR_expression || logical_AND_expression
conditional_expression:
  logical_OR_expression
  logical_OR_expression ? expression : conditional_expression
assignment_expression:
  conditional_expression
  unary_expression assignment_operator assignment_expression
assignment_operator: one of
  = *= /= %= += -= <<= >>= &= ^= |=
expression:
  assignment_expression
  expression , assignment_expression
constant_expression:
  conditional_expression

A.2.2 Declarations

declaration:
  declaration_specifiers init_declarator_list?opt ;
  static_assert_declaration
declaration_specifiers:
  storage_class_specifier declaration_specifiers?opt
  type_specifier declaration_specifiers?opt
  type_qualifier declaration_specifiers?opt
  function_specifier declaration_specifiers?opt
  alignment_specifier declaration_specifiers?opt
init_declarator_list:
  init_declarator
  init_declarator_list , init_declarator
init_declarator:
  declarator
  declarator = initializer
storage_class_specifier:
  typedef
  extern
  static
  _Thread_local
  auto
  register
type_specifier:
  void
  char
  short
  int
  long
  float
  double
  signed
  unsigned
  _Bool
  _Complex
  atomic_type_specifier
  struct_or_union_specifier
  enum_specifier
  typedef_name
struct_or_union_specifier:
  struct_or_union identifier?opt { struct_declaration_list }
  struct_or_union identifier
struct_or_union:
  struct
  union
struct_declaration_list:
  struct_declaration
  struct_declaration_list struct_declaration
struct_declaration:
  specifier_qualifier_list struct_declarator_list?opt ;
  static_assert_declaration
specifier_qualifier_list:
  type_specifier specifier_qualifier_list?opt
  type_qualifier specifier_qualifier_list?opt
struct_declarator_list:
  struct_declarator
  struct_declarator_list , struct_declarator
struct_declarator:
  declarator
  declarator?opt : constant_expression
enum_specifier:
  enum identifier?opt { enumerator_list }
  enum identifier?opt { enumerator_list , }
  enum identifier
enumerator_list:
  enumerator
  enumerator_list , enumerator
enumerator:
  enumeration_constant
  enumeration_constant = constant_expression
atomic_type_specifier:
  _Atomic ( type_name )
type_qualifier:
  const
  restrict
  volatile
  _Atomic
function_specifier:
  inline
  _Noreturn
alignment_specifier:
  _Alignas ( type_name )
  _Alignas ( constant_expression )
declarator:
  pointer?opt direct_declarator
direct_declarator:
  identifier
  ( declarator )
  direct_declarator [ type_qualifier_list?opt assignment_expression?opt ]
  direct_declarator [ static type_qualifier_list?opt assignment_expression ]
  direct_declarator [ type_qualifier_list static assignment_expression ]
  direct_declarator [ type_qualifier_list?opt * ]
  direct_declarator ( parameter_type_list )
  direct_declarator ( identifier_list?opt )
pointer:
  * type_qualifier_list?opt
  * type_qualifier_list?opt pointer
type_qualifier_list:
  type_qualifier
  type_qualifier_list type_qualifier
parameter_type_list:
  parameter_list
  parameter_list , ...
parameter_list:
  parameter_declaration
  parameter_list , parameter_declaration
parameter_declaration:
  declaration_specifiers declarator
  declaration_specifiers abstract_declarator?opt
identifier_list:
  identifier
  identifier_list , identifier
type_name:
  specifier_qualifier_list abstract_declarator?opt
abstract_declarator:
  pointer
  pointer?opt direct_abstract_declarator
direct_abstract_declarator:
  ( abstract_declarator )
  direct_abstract_declarator?opt [ type_qualifier_list?opt assignment_expression?opt ]
  direct_abstract_declarator?opt [ static type_qualifier_list?opt assignment_expression ]
  direct_abstract_declarator?opt [ type_qualifier_list static assignment_expression ]
  direct_abstract_declarator?opt [ * ]
  direct_abstract_declarator?opt ( parameter_type_list?opt )
typedef_name:
  identifier
initializer:
  assignment_expression
  { initializer_list }
  { initializer_list , }
initializer_list:
  designation?opt initializer
  initializer_list , designation?opt initializer
designation:
  designator_list =
designator_list:
  designator
  designator_list designator
designator:
  [ constant_expression ]
  . identifier
static_assert_declaration:
  _Static_assert ( constant_expression , string_literal ) ;

A.2.3 Statements

statement:
  labeled_statement
  compound_statement
  expression_statement
  selection_statement
  iteration_statement
  jump_statement
labeled_statement:
  identifier : statement
  case constant_expression : statement
  default : statement
compound_statement:
  { block_item_list?opt }
block_item_list:
  block_item
  block_item_list block_item
block_item:
  declaration
  statement
expression_statement:
  expression?opt ;
selection_statement:
  if ( expression ) statement
  if ( expression ) statement else statement
  switch ( expression ) statement
iteration_statement:
  while ( expression ) statement
  do statement while ( expression ) ;
  for ( expression?opt ; expression?opt ; expression?opt ) statement
  for ( declaration expression?opt ; expression?opt ) statement
jump_statement:
  goto identifier ;
  continue ;
  break ;
  return expression?opt ;

A.2.4 External definitions

translation_unit:
  external_declaration
  translation_unit external_declaration
external_declaration:
  function_definition
  declaration
function_definition:
  declaration_specifiers declarator declaration_list?opt compound_statement
declaration_list:
  declaration
  declaration_list declaration

A.3 Preprocessing directives

preprocessing_file:
  group?opt
group:
  group_part
  group group_part
group_part:
  if_section
  control_line
  text_line
  # non_directive
if_section:
  if_group elif_groups?opt else_group?opt endif_line
if_group:
  # if constant_expression new_line group?opt
  # ifdef identifier new_line group?opt
  # ifndef identifier new_line group?opt
elif_groups:
  elif_group
  elif_groups elif_group
elif_group:
  # elif
else_group:
  # else new_line group?opt
endif_line:
  # endif new_line
control_line:
  # include pp_tokens new_line
  # define identifier replacement_list new_line
  # define identifier lparen identifier_list?opt ) replacement_list new_line
  # define identifier lparen ... ) replacement_list new_line
  # define identifier lparen identifier_list , ... ) replacement_list new_line
  # undef identifier new_line
  # line pp_tokens new_line
  # error pp_tokens?opt new_line
  # pragma pp_tokens?opt new_line
  # new_line
text_line:
  pp_tokens?opt new_line
non_directive:
  pp_tokens new_line
lparen:
  a ( character not immediately preceded by white_space
replacement_list:
  pp_tokens?opt
pp_tokens:
  preprocessing_token
  pp_tokens preprocessing_token
new_line:
  the new_line character
*/
