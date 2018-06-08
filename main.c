#include <stdio.h>
#include <string.h>

#define SALT 7;
char* encode(char code[]);
char* decode(char code[]);

int main() 
{
    char prim[100], *code, *primary;
    printf("please enter:");
    gets(prim);
    code = encode(prim);
    printf("The encoded words are: \t%s\n", code);
    primary = decode(code);
    printf("The decoded words are: \t%s\n", primary);
    return 0;
}

char* encode(char prim[])
{
    int i, n, len;
    char code[100];
    char temp_char, trans_char;
    len = strlen(prim);

    for(i = 0; i < len; i++)
    {
        temp_char = prim[i];
        trans_char = temp_char ^ SALT;
        code[i] = trans_char;
    }
    code[len] = '\0';
    return code;
}

char* decode(char code[])
{
    int i, n, len;
    char prim[100];
    char temp_char, trans_char;
    len = strlen(code);

    for(i = 0; i < len; i++)
    {
        temp_char = code[i];
        trans_char = temp_char ^ SALT;
        prim[i] = trans_char;
    }
    prim[len] = '\0';
    return prim;
}
