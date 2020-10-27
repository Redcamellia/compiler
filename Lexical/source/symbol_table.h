#include <string>
#include <map>


enum token_type_e
{
    KEYWORD , ID , NUM , OPERATION , MISC
};


typedef struct token_spec_t
{
    std::string value ;
    int index ;
    token_type_e type ;    
};




typedef struct symbol_table
{
    std::map<std::string , token_spec_t> symbol_map ;
    
};

/* searches the specified table for the word , if it exists 
it returns the spec for that word
otherwise it allocates the spec for this word on that table */
token_spec_t get_token(symbol_table * arg_table , const std::string& arg_word);
