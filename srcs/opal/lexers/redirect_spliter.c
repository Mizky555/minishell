#include "minishell.h"

int len_token(t_token *token)
{
    t_token *tmp;
    int len;

    len = 0;
    tmp = token;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        len++;
    }
    return (len);
}

int check_redirect(char *str)
{
    int i;
    char c;

    i = 0;
    c = 0;
    while (str[i])
    {
        if (c == 0 && (str[i] == '\'' || str[i] == '\"'))
        {
            c = str[i];
        }
        else if (str[i] == c)
        {
            c = 0;
        }
        else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
        {
            return (1);
        }
        i++;
    }
    return (0);

}

            // "1|2|3" , 1234|5678"|" -> 1|2|3 , 1234 , | , 5678|
            // "1 , | , 2 , | , 3" , 1234 , | , 5678" , | , "

bool redirect_spliter(t_env *env)
{
    t_token *tmp; // หัว
    t_token *del;
    t_token *token;
    char *str;
    size_t i;
    int index;

    tmp = env->token;
    index = 0;
    while (tmp)
    {
        str = tmp->token;
        i = 0;
        if (check_redirect(str))
        {
            while (ft_strlen(str) > i)
            {
                // printf("str = %s i = %zu\n\n",str, i);
                if (get_check(str[i]) == 1) //alpha
                {
                    token = token_new(get_alpha(str + i, env), EMPTY);
                }
                else //redirect
                {
                    // printf("hihihihihi\n");
                    token = token_new(get_redirect(str + i, env), EMPTY);
                }
                token_insert(&env->token, token, index++);
                i += ft_strlen(token->token);
                // printf(">>%s\n", token->token);
            }
            if (tmp->next)
            {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }
            else
                tmp->prev->next = NULL;
            del = tmp;
            tmp = tmp->next;
            free(del->token);
            free(del);
        }
        else
        {
            tmp = tmp->next;
            index++;
        }
        // token_print(env->token);

    }
    return (0);
}
// bool redirect_spliter(t_env *env)
// {
//     t_token *tmp; // หัว
//     t_token *del;
//     t_token *token;
//     char *str;
//     size_t i;
//     int index;

//     tmp = env->token;
//     index = 0;
//     while (tmp)
//     {
//         str = tmp->token;
//         i = 0;
//         if (check_redirect(str))
//         {
//             while (ft_strlen(str) > i)
//             {
//                 printf("str = %s i = %zu\n\n",str, i);
//                 if (get_check(str[i]) == 1) //alpha
//                 {
//                     token = token_new(get_alpha(str + i, env), EMPTY);
//                 }
//                 else //redirect
//                 {
//                     printf("hihihihihi\n");
//                     token = token_new(get_redirect(str + i, env), EMPTY);
//                 }
//                 token_insert(&env->token, token, index++);
//                 i += ft_strlen(token->token);
//                 // printf(">>%s\n", token->token);
//             }
//             if (tmp->next)
//             {
//                 tmp->next->prev = tmp->prev;
//                 tmp->prev->next = tmp->next;
//             }
//             else
//                 tmp->prev->next = NULL;
//             del = tmp;
//             tmp = tmp->next;
//             free(del->token);
//             free(del);
//         }
//         else
//             tmp = tmp->next;
//         // token_print(env->token);

//     }
//     return (0);
// }
// bool redirect_spliter(t_env *env)
// {
//     t_token *tmp; // หัว
//     t_token *del;
//     t_token *token;
//     char *str;
//     size_t i;
//     int index;

//     tmp = env->token;
//     index = 0;
//     while (tmp)
//     {
//         str = tmp->token;
//         i = 0;
//         if (check_redirect(str))
//         {
//             while (ft_strlen(str) > i)
//             {
//                 printf("str = %s i = %zu\n\n",str, i);
//                 if (get_check(str[i]) == 1) //alpha
//                 {
//                     token = token_new(get_alpha(str + i, env), EMPTY);
//                 }
//                 else //redirect
//                 {
//                     printf("hihihihihi\n");
//                     token = token_new(get_redirect(str + i, env), EMPTY);
//                 }
//                 token_insert(&env->token, token, index++);
//                 i += ft_strlen(token->token);
//                 // printf(">>%s\n", token->token);
//             }
//             if (tmp->next)
//             {
//                 tmp->next->prev = tmp->prev;
//                 tmp->prev->next = tmp->next;
//             }
//             else
//                 tmp->prev->next = NULL;
//             del = tmp;
//             tmp = tmp->next;
//             free(del->token);
//             free(del);
//         }
//         else
//             tmp = tmp->next;
//         // token_print(env->token);

//     }
//     return (0);
// }


int get_check(char c) // เช็คว่าเป็นตัวอักษรไหม
{
    if (c == '>' || c == '<' || c == '|')
        return (0);
    return (1);
}




char *get_alpha(char *token, t_env *env)
{
    char *alpha;
    char    c;
    int i;
    int index;

    i = 0;
    c = 0;
    index = 0;
    alpha = (char *)malloc(get_alpha_size(token) + 1);
    if (!alpha)
        return (NULL);
    while (token[i])
    {
        if ((token[i] == '<' || token[i] == '>' || token[i] == '|') && c == 0)
            break;
        else if ((token[i] == '\'' || token[i] == '\"') && c == 0)
        {
            c = token[i];
        }
        else if (token[i] == c)
        {
            c = 0;
        }
        alpha[index] = token[i];
        index++;
        i++;
    }
    alpha[index] = '\0';
    index = 0;
    while (alpha[index])
    {
        printf("%c ",alpha[index++]);
    }
    printf("\n");
    env->token->i_insert++;
    return (alpha);
}

char *get_redirect(char *token, t_env *env) // ต่อ1 ทำเก็บตัวแปร <,<<,>,>>,| แล้วส่งกลับไปหา redirect_spliter
{
    char *redirect;
    char c;
    int i;

    i = 0;
    c = 0;
    redirect = (char *)malloc(get_redirect_size(token) + 1);
    if (!redirect)
        return (NULL);
    if (token[i] == '<' || token[i] == '>')
    {
        redirect[i] = token[i];
        c = token[i];
        printf("ssss = %c\n",c);
        i++;
        if (token[i] == c)
        {
            redirect[i] = token[i];
            i++;
        }
    }
    else if (token[i] == '|')
        redirect[i++] = '|';
    redirect[i] = '\0';
    env->token->i_insert++;
    // printf("redi = %s\n",redirect);
    return (redirect);
}

size_t get_redirect_size(char *token) // วัดความยาวของ token โดยดัก space กับ ',"
{
    char c;
    int i;

    c = 0;
    i = 0;
    if (token[i] == '<' || token[i] == '>')
    {
        c = token[i];
        i++;
        if (token[i] == c)
            i++;
    }
    else if (token[i] == '|')
        i++;
    return (i);
}

size_t get_alpha_size(char *str) // วัดความยาวของ token โดยดัก space กับ ',"
{
    int i;
    char    c;

    i = 0;
    c = 0;
    while (str[i]) // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
    {
        if ((str[i] == '\'' || str[i] == '\"') && c == 0)
        {
            c = str[i];
        }
        else if ((str[i] == '<' || str[i] == '>' || str[i] == '|' )&& c == 0)
        {
            return (i);
        }
        else if (str[i] == c)
        {
            c = 0;
        }
        i++;
    }
    printf("alpha size = %d\n",i);
    return (i);
}

// char *get_alpha(char *token, t_env *env)
// {
//     char *alpha;
//     int i;

//     i = 0;
//     alpha = (char *)malloc(get_alpha_size(token) + 1);
//     if (!alpha)
//         return (NULL);
//     while (token[i] != '\0' && token[i] != '|')
//     {
//         if (token[i] == '<' || token[i] == '>')
//             break;
//         alpha[i] = token[i];
//         i++;
//     }
//     alpha[i] = '\0';
//     env->token->i_insert++;
//     return (alpha);
// }

// size_t get_alpha_size(char *token) // วัดความยาวของ token โดยดัก space กับ ',"
// {
//     int i;

//     i = 0;
//     // printf("\nlen = %d\n",i);
//     while (token[i] != '\0' && token[i] != '|') // ไม่หมดบรรทัดและ(หยุดเมื่อspaceหรือ เจอ ",'||)
//     {
//         if (token[i] == '<' || token[i] == '>') // เมื่อเจอ ',"" แรกจะวนจนกว่าจะเจอตัวปิด else if
//             return (i);
//         i++;
//     }

//     return (i);
// }
// bool    redirect_spliter(t_env *env)
// {
//     t_token *tmp;

//     tmp = env->token;

//     printf("\n\n\n--- %s ---\n\n\n",tmp->token);
//     printf("\n\n\n--- %s ---\n\n\n",tmp->next->token);

//     return(0);
// }