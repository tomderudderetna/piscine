#include <my.h>
#include <evalexpr.h>

int is_expr_valid(char* expr, char* base, char* operators)
{
    int i;

    i = 0;
    while (expr[i])
    {
        if (expr[i] != ' ' && my_strchr(base, expr[i]) == 0 
            && my_strchr(operators, expr[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int is_operator(char* word, char* operators)
{
    if(my_strlen(word) != 1)
        return (0);
    return (my_strstr(&operators[2], word) != 0);
}

/**
** A valider l'odre des opérateurs prioritaire avec le sujet de la bistro
** Pour l'instant c'est ()/*-+%
*/
int is_operator_prioritary(char* op_1, char* op_2, char* operators)
{
    int pos_1;
    int pos_2;

    pos_1 = get_char_pos(operators, *op_1);
    pos_2 = get_char_pos(operators, *op_2);
    if((pos_1 < 4 || pos_1 > 5) || (pos_2 > 3 && pos_2 < 6))
        return (1);
    return (0);
}

int is_operand(char* word, char* base)
{
    int i;

    i = 0;
    while(word[i])
    {
        if(my_strchr(base, word[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int is_parenthesis(char* word, char* operators, int open)
{
    if(my_strlen(word) != 1)
        return (0);
    if(open)
        return (word[0] == operators[0]);
    else
        return (word[0] == operators[1]);
}