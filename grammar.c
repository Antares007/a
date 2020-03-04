#define CAG(t, a, g, n)
#define AAG(t, aa, ab, g, n)
#define AAAG(t, aa, ab, ac, g, n)
#define AATG(t, aa, ab, tt, g, n)
#define AG(t, a, g, n)
// clang-format off
// translation_unit:
//          external_declaration
//          translation_unit external_declaration
   CAG(0,   external_declaration, _,
            translation_unit)

// external_declaration:
//          function_definition
//          declaration
    AG(0,   declaration, _,
  L)AG(L,   function_definition, _, 
            external_declaration)

// function_definition:
//          declaration_specifiers_opt declarator declaration_list_opt
//          compound_statement
  AAAG(0,   declaration_specifiers_opt, declarator, declaration_list_opt, _,
  L)AG(L,   compound_statement, _,
            function_definition)

// declaration:
//          declaration_specifiers init_declarator_list_opt ;
  AATG(L,   declaration_specifiers, init_declarator_list_opt, semicolon, _,
            declaration)

// declaration_list:
//          declaration
//          declaration_list declaration
   CAG(0,   declaration, _,
            declaration_list)
// declaration_specifiers:
//          storage_class_specifier declaration_specifiers_opt
//          type_specifier declaration_specifiers_opt
//          type_qualifier declaration_specifiers_opt
   AAG(0,   storage_class_specifier, declaration_specifiers_opt, _,
 L)AAG(L,   type_specifier, declaration_specifiers_opt, _,
 L)AAG(L,   type_qualifier, declaration_specifiers_opt, _,
            declaration_specifiers)
// storage_class_specifier: one of auto register static extern typedef
