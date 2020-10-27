#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


enum token_type_e
{
    KEYWORD , ID , NUM , OPERATION , MISC
};
typedef struct token_spec_t
{
    std::string value ;
    token_type_e type ;    
};




std::vector<std::string> split_the_source_file(const std::string& arg_file_path)
{
    std::ifstream f(arg_file_path); //taking file as inputstream
    std::string str;
    if(f) 
    {
        std::ostringstream ss;
        ss << f.rdbuf(); // reading data
        str = ss.str();
    }

    std::vector<std::string> result; 
    std::istringstream iss(str); 
    for(std::string str; iss >> str;) 
        result.push_back(str);

    return result ;
}

void init_symbol_table(token_spec_t * arg_table_p)
{
	for (size_t i = 0; i < 4096; i++)
	{
		arg_table_p[i].type = KEYWORD;
		arg_table_p[i].value = "";
	}

    arg_table_p[1].type = KEYWORD ;
    arg_table_p[1].value = "for";

    arg_table_p[2].type = KEYWORD ;
    arg_table_p[2].value = "if";

    arg_table_p[3].type = KEYWORD ;
    arg_table_p[3].value = "else";

    arg_table_p[4].type = KEYWORD ;
    arg_table_p[4].value = "return";

    arg_table_p[5].type = KEYWORD ;
    arg_table_p[5].value = "break";

    arg_table_p[6].type = KEYWORD ;
    arg_table_p[6].value = "continue";

    arg_table_p[7].type = KEYWORD ;
    arg_table_p[7].value = "int";

    arg_table_p[8].type = KEYWORD ;
    arg_table_p[8].value = "float";

    arg_table_p[9].type = KEYWORD ;
    arg_table_p[9].value = "void";
}

uint32_t check_keywords(token_spec_t * arg_table , const std::string& arg_word)
{
    for(int i = 1 ; arg_table[i].value != "" ; i++)
    {
        if(arg_word == arg_table[i].value)
        {
            return i ;
        }
        
    }
    return 0;
}


int main()
{
		//preallocating the symbol table 
        token_spec_t* symbol_table = new token_spec_t[4096];

		init_symbol_table(symbol_table);
        std::vector<std::string> words = split_the_source_file("a.txt");
        std::vector<uint32_t> tokens_recognized ;
        for(auto s : words)
        {
            uint32_t index  = check_keywords(symbol_table , s);
            if(index != 0)
            {
                tokens_recognized.push_back(index);
            }

        }

        // for(auto s : words)
        // {
        //     std::cout<<s << std::endl ;
        // }

        for(auto content : tokens_recognized)
        {
            std::cout << "keyword : " << symbol_table[content].value << std::endl ;
        }

    std::cin.get();
}