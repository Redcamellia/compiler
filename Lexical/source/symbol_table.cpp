#include "symbol_table.h"


token_spec_t get_token(symbol_table * arg_table , const std::string& arg_word)
{
    auto current = arg_table->symbol_map.find(arg_word);
    if( current == arg_table->symbol_map.end())
    {
        token_spec_t* token_spec =  new token_spec_t();
        token_spec->index = arg_table->symbol_map.size()+1;
        token_spec->type = token_type_e::KEYWORD;
        arg_table->symbol_map.emplace(std::make_pair(arg_word , token_spec ));

        return *token_spec;
    }
    else
    {
        return current->second;
    }
    

}