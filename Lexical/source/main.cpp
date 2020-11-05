#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

size_t index = 0;
#define DECLARE_MAIN(x) x()


enum token_type_e
{
    KEYWORD  , ID , NUM , ADDOP , MULOP , RELOP , LOGOP , MISC ,
     PARANTHES_BAZ , PARANTHES_BASTE , ACOLAD_BAZ , ACOLAD_BASTE , SEMI_COLON , VIRGULE , ASSIGN
};
typedef struct token_spec_t
{
    std::string value ;
    token_type_e type ;    
};

token_spec_t keywords_and_identifiers_state_machine(std::string arg_input);
token_spec_t numbers_state_machine(std::string arg);


void keyword_test()
{
	std::string a;
	while(std::cin >> a)
    {
        while(index < a.size())
        {
            token_spec_t value = keywords_and_identifiers_state_machine(a);
            std::cout << value.value << std::endl ;
            if(index == 0)
            break ;
        }
    }
    


	std::cout << std::endl;
}


void numbers_test()
{
    std::string a;
	while(std::cin >> a)
    {
        while(index < a.size())
        {
            token_spec_t value = numbers_state_machine(a);
            std::cout << value.value << std::endl ;
            if(index == 0)
            break ;
        }
    }
    
}


#define bind_state( ch , stat) if(arg_input[index]==ch) {state = stat ; break;}
token_spec_t keywords_and_identifiers_state_machine(std::string arg_input )
{
    token_spec_t ret ;
    ret.type = KEYWORD ;
    ret.value = "AAAAA";
	size_t begin = index;

    int state = 0 ;
    while(index != arg_input.size())
    {
		if (!isalnum(arg_input[index]) && !(arg_input[index] == '_'))
		{
			break;
		}
        switch (state)
        {
        case 0 :
        {
            bind_state('i' , 1);
            bind_state('f' , 2);
            bind_state('e' , 3);
            bind_state('r' , 4);
            bind_state('b' , 5);
            bind_state('c' , 6);
            bind_state('v' , 11);
            if(arg_input[index] != 'i' &&
             arg_input[index] != 'f' &&
             arg_input[index] != 'e' &&
             arg_input[index] != 'r' &&
             arg_input[index] != 'b' &&
             arg_input[index] != 'c' &&
             arg_input[index] != 'v')
                state = 10 ;
            
        }
            break;
        case 1 : // case i
        {
            bind_state('n' , 7);
            bind_state('f' , 8);
            if(arg_input[index] != 'n' && arg_input[index] != 'f')
                state = 10 ;
        }
            break ;
        case 2 :
        {
            bind_state('o' , 12);
            bind_state('l' , 13);
			state = 10;
        }
            break ;
        case 3 : // case e
        {
            bind_state('l' , 18);
			state = 10;
        }
            break ;
        case 4 : //case r
        {
            bind_state('e' , 21);
			state = 10;
        }
            break ;
        case 5 : // case b
        {
            bind_state('r' , 26);
			state = 10;
        }
            break ;
        case 6 : // case c
		{
			bind_state('o', 30);
			state = 10;
		}
			break;
        case 7 : // case in
        {
            bind_state('t' , 9);
            if(arg_input[index] != 't')
                state = 10 ;
        }
            break ;
        case 8 : // case if
        {
            state = 10 ;
        }
            break ;
        case 9 : // case int
        {
            state = 10 ;
        }
            break ;
        case 10 :
        {
            //case for identifiers
			std::cout << "in the case 10" << std::endl;
        }
            break ;
        case 11 : // case v
        {
            bind_state('o' , 37);
			state = 10;
        }
        case 12 : // case b
        {
            bind_state('r' , 14);
			state = 10;
        }
            break ;
        case 13 : // case fl
        {
            bind_state('o' , 15);
			state = 10;
        }
            break ;
        case 14 : // case for
        {
            state = 10 ;
        } 
            break ;
        case 15 : // case flo
        {
            bind_state('a' , 16);
			state = 10;

        }
            break ;
        case 16 : //case floa
        {
            bind_state('t' , 17);
			state = 10;
        }
            break ;
        case 17 : // case float
        {
            state = 10 ;
        }
            break ;
        case 18 : // case el
        {
            bind_state('s'  , 19);
			state = 10;
        } 
            break ;
        case 19 : // case els
        {
            bind_state('e' , 20);
			state = 10;
        } 
            break ;
        case 20 : // case else
        {
            state = 10 ;
        } 
            break ;
        case 21 : // case re
        {
            bind_state('t' , 22);
			state = 10;
        }
            break ;
        case 22 : // case ret
        {
            bind_state('u' , 23);
			state = 10;
        }
            break ;
        case 23 : // case retu
        {
            bind_state('r' , 24);
			state = 10;
        }
            break ;
        case 24 : // case retur
        {
            bind_state('n' , 25);
			state = 10;
        }
            break ;
        case 25 : // case return 
        {
            state = 10 ;
        }
            break ;
        case 26 : //case br
        {
            bind_state('e' , 27);
			state = 10;
        }
        case 27 : // case bre
        {
            bind_state('a' , 28);
			state = 10;
        }
            break ;
        case 28 : // case brea
        {
            bind_state('k' , 29);
			state = 10;
        }
            break ;
        case 29 : // case break
        {
            state = 10 ;
        }
            break ;    
        case 30 : // case co
        {
            bind_state('n' , 31);
			state = 10;
        }
            break ;
        case 31 :
        {
            bind_state('t' , 32);
			state = 10;
        }
            break ;
        case 32 :
        {
            bind_state('i' , 33);
			state = 10;
        }
            break ;
        case 33 :
        {
            bind_state('n' , 34);
			state = 10;
        }
            break ;
        case 34 :
        {
            bind_state('u' , 35);
			state = 10;
        }
            break ;
        case 35 :
        {
            bind_state('e' , 36);
			state = 10;
        }
            break ;
        case 36 :
        {
            state = 10 ;
        }
            break ;
        case 37 : // case vo
        {
            bind_state('i' , 38);
			state = 10;
        }
            break ;    
        case 38 : 
        {
            bind_state('d' , 39);
			state = 10;
        }
            break ;
        case 39 : 
        {
            state = 10 ;
        }
    }
	index++;
}

// remember to implement the logic for return tokens ...
    if(state == 8)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 9)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 10)
    {
        ret.type = ID ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 14)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 17)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 20)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 25)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 29)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
    else if(state == 36)
    {
        ret.type = KEYWORD ;
        ret.value = arg_input.substr(begin , index - begin);
    }
	else if (state == 39)
	{
		ret.type = KEYWORD;
		ret.value = arg_input.substr(begin, index - begin);
	}
    else
    {
        ret.type = ID ;
        ret.value = arg_input.substr(begin , index - begin);
    }



    return ret ;
}



token_spec_t numbers_state_machine(std::string arg)
{
    token_spec_t ret ;

    int state = 0 ;
    size_t begin = index ;
    bool token_ended = false ;
    while(index != arg.size())
    {

        switch (state)
        {
            case 0: // entry
            {
                if(isdigit(arg[index]))
                {
                    state = 1 ;
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }

            }
                break;
            case 1 : // first digits
            {
                if(arg[index] == 'E')
                {
                    state = 3 ;
                    break ;
                }    
                else if (arg[index] == '.')
                {
                    state = 2 ;
                    break ;
                }

            }
                break ;

            case 2 : // optional fraction
            {
                if(isdigit(arg[index]))
                {
                    state = 2 ;
                    break ;
                }
                else if (arg[index] == 'E')
                {
                    state = 3 ;
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }
                

            } 
            break ;
            
            case 3 : // optional exponent  
            {
                if(arg[index] == '+' || arg[index] == '-')
                {
                    state = 4 ;
                    break ;   
                }
                else if(isdigit(arg[index]))
                {
                    state = 5 ;
                    break ;
                }
                else
                {
                    token_ended = true; 
                    break ;
                }
                

            }
            break ;
            
            case 4 : // optional exponent  +-
            {
                if(isdigit(arg[index]))
                {
                    state = 5 ;
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }
                
            }
            break ; 
            case 5 : // optional exponent -+ digit
            {
                if(isdigit(arg[index]))
                {
                    state = 5 ;   
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }
                
            }
            break ;
        }

       
        if(token_ended)
            break ;

		index++;

        
    }

    if(state == 0)
    {
        ret.type = NUM ;
        ret.value = "";
    }
    else if(state == 1)
    {
        ret.type = NUM ;
        ret.value = arg.substr(begin , index - begin);
    }
    else if(state == 2)
    {
        ret.type = NUM ;
        index -- ;
        ret.value = arg.substr(begin , index - begin);
    }
    else if(state == 3)
    {
        ret.type = NUM ;
        index -- ;
        ret.value = arg.substr(begin , index - begin);
    }
    else if(state == 4)
    {
        ret.type = NUM ;
        index -- ;
        ret.value = arg.substr(begin , index - begin);
    }
    else if (state == 5)
    {
        ret.type = NUM ;
        ret.value = arg.substr(begin , index - begin);
    }


    return ret;
}

token_spec_t operators_state_machine(std::string arg)
{
    token_spec_t ret ;
    bool token_ended = false ;
    int state = 0 ;
    size_t begin = index ;

    while(index != arg.size())
    {

        switch (state)
        {
            case 0:
            {
                if(arg[index] == '+' || arg[index] == '-')
                {
                   state = 1 ;
                   token_ended = true ;
                   break ; 
                }
                else if(arg[index] == '*' || arg[index] == '/')
                {
                    state = 2 ;
                    token_ended = true ;
                    break ;
                }
                else if(arg[index] == '>')
                {
                    state = 3 ;
                    break ;
                }
                else if(arg[index] == '=')
                {
                    state = 5 ;
                    break ;
                }
                else if(arg[index] == '<')
                {
                    state = 7 ;
                    break ;
                }
                else if(arg[index] == '!')
                {
                    state = 9 ;
                    token_ended = true ;
                    break ;
                }
                else if(arg[index] == '|')
                {
                    state = 10 ;
                    break ;
                }
                else if(arg[index] == '&')
                {
                    state = 11 ;
                    break ;
                }
            }
                break;
            case 1:
            {
                // nobody gets here
            }
                break;
            case 2:
            {
                // nobody gets here
            }
                break;
            case 3: // greater than
            {
                if(arg[index] == '=')
                {
                    state = 4 ;
                    token_ended = true ;
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }
                
            }
                break;
            case 4: // greater than or equal to
            {
                // nobody gets here
            }
                break;
            case 5: // assign
            {
                if(arg[index] == '=')
                {
                    state = 6 ;
                    token_ended = true ;
                    break ;
                }else
                {
                    token_ended = true ;
                }
                
            }
                break;
            case 6: // equality
            {
                // nobody gets here ...
            }
                break;
            case 7: // less than
            {
                if(arg[index] == '=')
                {
                    state = 8 ;
					token_ended = true;
                    break ;
                }
                else
                {
                    token_ended = true ;
                    break ;
                }
                
            }
                break ;
            case 8 : // less than or equal to
            {
                //nobody gets here 
            }
                break;

            case 9 : // not
            {
                // nobody gets here
            }
                break ;
            case 10 : // or
            {
                if(arg[index] == '|')
                {
                    state = 12 ;
                    token_ended = true ;
                    break ;
                }
            }
                break ;
            case 11 : // and
            {
                if(arg[index] == '&')
                {
                    state = 13 ;
                    token_ended = true ;
                    break ;
                }
            }
                break ;
            case 12 : // or or
            {
                // nobody gets here
            }
                break ;
            case 13 : // and and
            {
                // nobody gets here
            }
                break ;
            

        }

    if(token_ended)
        break ;

    index ++ ;


    }

        if(state = 1)
        {
            ret.type = ADDOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 2)
        {
            ret.type = MULOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 3)
        {
            ret.type = RELOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 4)
        {
            ret.type = RELOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 5)
        {
            ret.type = ASSIGN ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 6)
        {
            ret.type = RELOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 7)
        {
            ret.type = RELOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 8)
        {
            ret.type = RELOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 9)
        {
            ret.type = LOGOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 12 )
        {
            ret.type = LOGOP ;
            ret.value = arg.substr(begin , index - begin);
        }
        else if(state == 13)
        {
            ret.type = LOGOP ;
            ret.value = arg.substr(begin , index - begin);
        }




    return ret ;
}


void operator_test()
{
    std::string a;
	while(std::cin >> a)
    {
        while(index < a.size())
        {
            token_spec_t value = operators_state_machine(a);
            std::cout << value.value << std::endl ;
            if(index == 0)
            break ;
        }
    }
}

void test_main()
{
    std::string input ;
    std::vector<std::string> total_input ;
	std::getline(std::cin, input);
    while(input != "")
    {
		total_input.push_back(input);
        std::getline(std::cin , input) ;
    }


    bool terminal = false ;

    // here goes the logic 

    
    std::cin.get();
}

typedef std::vector<token_spec_t>  symbol_table ;

void init_table(symbol_table& table)
{
    token_spec_t token_spec_if;
    token_spec_t token_spec_int;
    token_spec_t token_spec_id;
    token_spec_t token_spec_for;
    token_spec_t token_spec_float;
    token_spec_t token_spec_else;
    token_spec_t token_spec_return;
    token_spec_t token_spec_break;
    token_spec_t token_spec_continue;
    token_spec_t token_spec_void;
    
    token_spec_if.type = KEYWORD ;
    token_spec_int.type = KEYWORD ;
    token_spec_id.type = KEYWORD ;
    token_spec_for.type = KEYWORD ;
    token_spec_float.type = KEYWORD ;
    token_spec_else.type = KEYWORD ;
    token_spec_return.type = KEYWORD ;
    token_spec_break.type = KEYWORD ;
    token_spec_continue.type = KEYWORD ;
    token_spec_void.type = KEYWORD ;

    token_spec_if.value = "if";
    token_spec_int.value = "int";
    token_spec_for.value = "for";
    token_spec_float.value = "float";
    token_spec_else.value = "else";
    token_spec_return.value = "return";
    token_spec_break.value = "break";
    token_spec_continue.value = "continue";
    token_spec_void.value = "void" ;

    



    

    table.push_back(token_spec_if);
	table.push_back(token_spec_int);
	table.push_back(token_spec_for);
	table.push_back(token_spec_float);
	table.push_back(token_spec_else);
	table.push_back(token_spec_return);
	table.push_back(token_spec_break);
	table.push_back(token_spec_continue);
	table.push_back(token_spec_void);

    token_spec_t semi_colon_spec;
    semi_colon_spec.type = SEMI_COLON;
    semi_colon_spec.value = ";" ;
    table.push_back(semi_colon_spec);

    token_spec_t acolad_baz_spec;
    acolad_baz_spec.type = ACOLAD_BAZ ;
    acolad_baz_spec.value = "{" ;
    table.push_back(acolad_baz_spec);

    token_spec_t acolad_baste_spec;
    acolad_baste_spec.type = ACOLAD_BASTE ;
    acolad_baste_spec.value = "}" ;
    table.push_back(acolad_baste_spec);

    token_spec_t paranthes_baz_spec;
    paranthes_baz_spec.type = PARANTHES_BAZ ;
    paranthes_baz_spec.value = "(" ;
    table.push_back(paranthes_baz_spec);

    token_spec_t paranthes_baste_spec;
    paranthes_baste_spec.type = PARANTHES_BASTE ;
    paranthes_baste_spec.value = ")" ;
    table.push_back(paranthes_baste_spec);

}

size_t find(symbol_table& table , std::string arg)
{
    for (size_t i = 0; i < table.size() ; i++)
    {
        if(table[i].value == arg)
            return i ;
    }
    return 200000 ;
}

class token
{
private:
    token_type_e token_type ;
    uint32_t index ;
public:
    token(token_type_e arg_type , uint32_t arg_index )
    {
        token_type = arg_type ;
        index = arg_index ;
    }
};




void integrate_three_machines()
{
    symbol_table table ;
    init_table(table);

    std::vector<token> tokens ;

    std::string a;
	while(std::cin >> a)
    {   
        while(index < a.size())
        {
            if(isalpha(a[index]))
            {
                token_spec_t temp = keywords_and_identifiers_state_machine(a);
                uint32_t i = find(table , temp.value) ;
                if(i == 200000)
                {
                    table.push_back(temp);
                }
            }
            else if(isdigit(a[index]))
            {
               token_spec_t temp = numbers_state_machine(a); 
               uint32_t i = find(table , temp.value);
               if(i == 200000)
               {
                    table.push_back(temp);
               }
            }
            else if(a[index] == ';')
            {
                index ++ ;

            }
            else if(a[index] == '{')
            {
                index ++ ;

            }
            else if(a[index] == '}')
            {
                index ++ ;

            }
            else if(a[index] == '(')
            {
                index ++ ;

            }
            else if(a[index] == ')')
            {
                index ++ ;

            }
            else 
            {
                token_spec_t temp = operators_state_machine(a);
                uint32_t i = find(table , temp.value);
                if(i == 200000)
                {
                    table.push_back(temp);
                }
            }
        }
		index = 0;
    }
}


int main()
{
    DECLARE_MAIN(integrate_three_machines);
}


