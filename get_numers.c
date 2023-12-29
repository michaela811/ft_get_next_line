#include "get_next_line.h"

char get_last(char *line)
{
    int len = 0;
    while (line[len])
        len++;
    while(len >= 0)
    {
        if (line[len] >= '0' && line[len] <= '9')
            return (line[len]);
        else if (line[len] == 'o')
            {
                if (line[len + 1] == 'n' && line[len + 2] == 'e')
                    return ('1');
            }
        else if (line[len] == 't')
            {
                if (line[len + 1] == 'w' && line[len + 2] == 'o')
                    return ('2');
                else if (line[len + 1] == 'h' && line[len + 2] == 'r' && line[len + 3] == 'e' && line[len + 4] == 'e')
                    return ('3');
            }
        else if (line[len] == 'f')
            {
                if (line[len + 1] == 'o' && line[len + 2] == 'u' && line[len + 3] == 'r')
                    return ('4');
                else if (line[len + 1] == 'i' && line[len + 2] == 'v' && line[len + 3] == 'e')
                    return ('5');
            }
        else if (line[len] == 's')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'x')
                    return ('6');
                else if (line[len + 1] == 'e' && line[len + 2] == 'v' && line[len + 3] == 'e' && line[len + 4] == 'n')
                    return ('7');
            }
        else if (line[len] == 'e')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'g' && line[len + 3] == 'h' && line[len + 4] == 't')
                    return ('8');
            }
        else if (line[len] == 'n')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'n' && line[len + 3] == 'e')
                    return ('9');
            }
        len--;        
    }
}

char get_first(char *line)
{
    int len = 0;
    while(line[len])
    {
        if (line[len] >= '0' && line[len] <= '9')
            return (line[len]);
                else if (line[len] == 'o')
            {
                if (line[len + 1] == 'n' && line[len + 2] == 'e')
                    return ('1');
            }
        else if (line[len] == 't')
            {
                if (line[len + 1] == 'w' && line[len + 2] == 'o')
                    return ('2');
                else if (line[len + 1] == 'h' && line[len + 2] == 'r' && line[len + 3] == 'e' && line[len + 4] == 'e')
                    return ('3');
            }
        else if (line[len] == 'f')
            {
                if (line[len + 1] == 'o' && line[len + 2] == 'u' && line[len + 3] == 'r')
                    return ('4');
                else if (line[len + 1] == 'i' && line[len + 2] == 'v' && line[len + 3] == 'e')
                    return ('5');
            }
        else if (line[len] == 's')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'x')
                    return ('6');
                else if (line[len + 1] == 'e' && line[len + 2] == 'v' && line[len + 3] == 'e' && line[len + 4] == 'n')
                    return ('7');
            }
        else if (line[len] == 'e')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'g' && line[len + 3] == 'h' && line[len + 4] == 't')
                    return ('8');
            }
        else if (line[len] == 'n')
            {
                if (line[len + 1] == 'i' && line[len + 2] == 'n' && line[len + 3] == 'e')
                    return ('9');
            }
        len++;        
    }
}

int get_cubes(char *line)
{
    int len = 0;
    while (line[len])
        len++;
    while (len >= 0)
    {
        if (line[len] > '2' && line[len] <= '9' && line[len - 1] == '1')
                if (line[len + 2] == 'r')
                    return (1);
        else if (line[len] > '3' && line[len] <= '9' && line[len - 1] == '1')
                if (line[len + 2] == 'g')
                    return (1);
        else if (line[len] > '4' && line[len] <= '9' && line[len - 1] == '1')
                if (line[len + 2] == 'b')
                    return (1);
        len--;
    }
    return (0);
}

int get_number(char *line)
{
    int len = 0;
    int pos = 0;
    char buffer[4];
    while (line[len] != ':')
    {
        if (line[len] >= '0' && line[len] <= '9')
        {
            buffer[pos] = line[len];
            pos++;
        }
        len++;
    }
    buffer[pos] = '\0';
    int num = atoi(buffer);
    //printf("%d\n", num);
    return (num);
}