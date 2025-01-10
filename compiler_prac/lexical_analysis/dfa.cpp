// we use deterministic finite automata for lexical analysis
#include <bits/stdc++.h>
using namespace std;

const char* scan(const char* file, const char* mFile){
    FILE* code = fopen(file,"r");
    FILE* mdf = fopen(mFile, "w");
    if(!code){
        cerr<<"Error Opening File.";
        exit(EXIT_FAILURE);
    }
    char c;
    char temp;
    while ((c=fgetc(code))!=EOF)
    {
        if(c == '/'){
            temp = fgetc(code);
            if(temp == '/'){
                while(fgetc(code)!='\n');
                fputc('\n',mdf);
            }else if(temp == '*'){
                while ((c=fgetc(code))!=EOF)
                {
                    if(c=='*' && fgetc(code)=='/') break;
                }
                fputc('\n',mdf);
            }else{
                fputc('/', mdf);
                fseek(code, -1, SEEK_CUR);
            }
        }
        else if(c == '<' || c == '>' || c == '=' || c == '!')  // should implement for the dot operator
        {
            temp = fgetc(code);
            if((c == '>' && temp == '>') || (c == '<' && temp == '<') || (temp == '=' && c != '.')) 
            {
                fprintf(mdf, " %c%c ", c,temp);
            }
            // else if(c == '.')
            // {
            //     if(temp=='\n' || temp==' ' || temp=='"' || temp=='\''){
            //         continue;
            //     }else{
            //         fprintf(mdf, " %c ", c);
            //         fseek(code, -1, SEEK_CUR);
            //     }
            // }
            else
            {
                fprintf(mdf, " %c ", c);
                fseek(code, -1, SEEK_CUR);
            }
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
        {
            temp = fgetc(code);
            if(temp == '=')
            {
                fprintf(mdf, " %c%c ", c,temp);
            }
            else
            {
                fprintf(mdf, " %c ", c);
                fseek(code, -1, SEEK_CUR);
            }
        }
        else if(c == '&' || c == '|' || c == '~')
        {
            temp = fgetc(code);
            if(temp == '&' || temp == '|') fprintf(mdf, " %c%c ", c,temp);
            else
            {
                fprintf(mdf, " %c ", c);
                fseek(code, -1, SEEK_CUR);
            }
        }
        else if(c == ':')
        {
            temp = fgetc(code);
            if(temp == ':') fprintf(mdf, " %c%c ", c,temp);
            else
            {
                fprintf(mdf, " %c ", c);
                fseek(code, -1, SEEK_CUR);
            }
        }
        else if(c == '\'' || c == '(' || c == ')' || c == '{' || c == '}'
        || c == '"' || c == ';' || c == '[' || c == ']' || c == ',')
        {
            fprintf(mdf, " %c ", c);
        }
        else fputc(c,mdf);
    }
    fclose(code);
    fclose(mdf);
    return mFile;
}

int kw_rec(const char* lexeme){
    int i = 0, s = 0;
    if((lexeme[i] == 'i' && lexeme[i+1] == 'f')
    || (lexeme[i] == 'd' && lexeme[i+1] == '0')
    || (lexeme[i] == 'i' && lexeme[i+1] == 'n' && lexeme[i+2] == 't')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'i' && lexeme[i+2] == 'n')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'o' && lexeme[i+2] == 't')
    || (lexeme[i] == 's' && lexeme[i+1] == 't' && lexeme[i+2] == 'd')
    || (lexeme[i] == 'm' && lexeme[i+1] == 'a' && lexeme[i+2] == 'x')
    || (lexeme[i] == 'm' && lexeme[i+1] == 'i' && lexeme[i+2] == 'n')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'a' && lexeme[i+2] == 's' && lexeme[i+3] == 'e')
    || (lexeme[i] == 'e' && lexeme[i+1] == 'l' && lexeme[i+2] == 's' && lexeme[i+3] == 'e')
    || (lexeme[i] == 'l' && lexeme[i+1] == 'o' && lexeme[i+2] == 'n' && lexeme[i+3] == 'g')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'h' && lexeme[i+2] == 'a' && lexeme[i+3] == 'r')
    || (lexeme[i] == 'v' && lexeme[i+1] == 'o' && lexeme[i+2] == 'i' && lexeme[i+3] == 'd')
    || (lexeme[i] == 'w' && lexeme[i+1] == 'h' && lexeme[i+2] == 'i' && lexeme[i+3] == 'l' && lexeme[i+4 == 'e'])
    || (lexeme[i] == 'f' && lexeme[i+1] == 'l' && lexeme[i+2] == 'o' && lexeme[i+3] == 'a' && lexeme[i+4] == 't')
    || (lexeme[i] == 'b' && lexeme[i+1] == 'r' && lexeme[i+2] == 'e' && lexeme[i+3] == 'a' && lexeme[i+4] == 'k')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'l' && lexeme[i+2] == 'a' && lexeme[i+3] == 's' && lexeme[i+4] == 's')
    || (lexeme[i] == 'd' && lexeme[i+1] == 'o' && lexeme[i+2] == 'u' && lexeme[i+3] == 'b' && lexeme[i+4] == 'l' && lexeme[i+5] == 'e')
    || (lexeme[i] == 's' && lexeme[i+1] == 'w' && lexeme[i+2] == 'i' && lexeme[i+3] == 't' && lexeme[i+4] == 'c' && lexeme[i+5] == 'h')
    || (lexeme[i] == 's' && lexeme[i+1] == 't' && lexeme[i+2] == 'r' && lexeme[i+3] == 'i' && lexeme[i+4] == 'n' && lexeme[i+5] == 'g')
    || (lexeme[i] == 'r' && lexeme[i+1] == 'e' && lexeme[i+2] == 't' && lexeme[i+3] == 'u' && lexeme[i+4] == 'r' && lexeme[i+5] == 'n')
    || (lexeme[i] == 'i' && lexeme[i+1] == 'g' && lexeme[i+2] == 'n' && lexeme[i+3] == 'o' && lexeme[i+4] == 'r' && lexeme[i+5] == 'e')
    || (lexeme[i] == 's' && lexeme[i+1] == 't' && lexeme[i+2] == 'r' && lexeme[i+3] == 'u' && lexeme[i+4] == 'c' && lexeme[i+5] == 't')
    || (lexeme[i] == 'g' && lexeme[i+1] == 'e' && lexeme[i+2] == 't' && lexeme[i+3] == 'l' && lexeme[i+4] == 'i' && lexeme[i+5] == 'n' && lexeme[i+6] == 'e')
    || (lexeme[i] == 'c' && lexeme[i+1] == 'o' && lexeme[i+2] == 'n' && lexeme[i+3] == 't' && lexeme[i+4] == 'i' && lexeme[i+5] == 'n' && lexeme[i+6] == 'u' && lexeme[i+7] == 'e')
    || (lexeme[i] == '#' && lexeme[i+1] == 'i' && lexeme[i+2] == 'n' && lexeme[i+3] == 'c' && lexeme[i+4] == 'l' && lexeme[i+5] == 'u' && lexeme[i+6] == 'd' && lexeme[i+7] == 'e')
    || (lexeme[i] == 's' && lexeme[i+1] == 't' && lexeme[i+2] == 'r' && lexeme[i+3] == 'e' && lexeme[i+4] == 'a' && lexeme[i+5] == 'm' && lexeme[i+6] == 's' && lexeme[i+7] == 'i' && lexeme[i+8] == 'z' && lexeme[i+9] == 'e')
    || (lexeme[i] == 's' && lexeme[i+1] == 't' && lexeme[i+2] == 'a' && lexeme[i+3] == 't' && lexeme[i+4] == 'i' && lexeme[i+5] == 'c' && lexeme[i+6] == '_' && lexeme[i+7] == 'c' && lexeme[i+8] == 'a' && lexeme[i+9] == 's' && lexeme[i+10] == 't')
    || (lexeme[i] == 'n' && lexeme[i+1] == 'u' && lexeme[i+2] == 'm' && lexeme[i+3] == 'e' && lexeme[i+4] == 'r' && lexeme[i+5] == 'i' && lexeme[i+6] == 'c' && lexeme[i+7] == '_' && lexeme[i+8] == 'l' && lexeme[i+9] == 'i' && lexeme[i+10] == 'm' && lexeme[i+11] == 'i' && lexeme[i+12] == 't' && lexeme[i+13] == 's')
    ){
        s = 1;
    }
    return s;
}

int op_rec(const char* lexeme){
    int i = 0, s = 0;
    if( (lexeme[i] == '+' && lexeme[i+1] == '=') || (lexeme[i] == '-' && lexeme[i+1] == '=')
     || (lexeme[i] == '*' && lexeme[i+1] == '=') || (lexeme[i] == '/' && lexeme[i+1] == '=')
     || (lexeme[i] == '=' && lexeme[i+1] == '=') || (lexeme[i] == '<' && lexeme[i+1] == '<')
     || (lexeme[i] == '>' && lexeme[i+1] == '>') || (lexeme[i] == '^' && lexeme[i+1] == '=')
     || (lexeme[i] == '+' && lexeme[i+1] == '+') || (lexeme[i] == '-' && lexeme[i+1] == '-')
     || (lexeme[i] == '!' && lexeme[i+1] == '=') || (lexeme[i] == '<' && lexeme[i+1] == '=')
     || (lexeme[i] == '>' && lexeme[i+1] == '=') || (lexeme[i] == '%' && lexeme[i+1] == '=')
     || lexeme[i] == '+' || lexeme[i] == '-' || lexeme[i] == '*' || lexeme[i] == '/' || lexeme[i] == '&' 
     || lexeme[i] == '|' || lexeme[i] == '^' || lexeme[i] == '%' || lexeme[i] == '~' || lexeme[i] == '='
     || lexeme[i] == '!' || lexeme[i] == ':' || lexeme[i] == '<' || lexeme[i] == '>' || (lexeme[i] == ':' && lexeme[i+1] == ':')
    ){
        s = 1;
    }
    return s;
}

int sep_rec(const char* lexeme){
    int i = 0, s = 0;
    if(lexeme[i] == '\'' ||  lexeme[i] == '"' || lexeme[i] == ';'  || lexeme[i] == ',')
    {
        s = 1;
    }
    return s;
}

int par_rec(const char* lexeme){
    int i = 0, s = 0;
    if(lexeme[i] == '(' || lexeme[i] == ')' || lexeme[i] == '{' || lexeme[i] == '}' || lexeme[i] == '[' || lexeme[i] == ']')
    {
        s = 1;
    }
    return s;
}

int id_rec(const char* lexeme){
    int i = 0, s = 0;
    int l = strlen(lexeme);
    if(isalpha(lexeme[i]) || lexeme[i] == '_')
    {
        s = 1;
        ++i;
    }
    else
    {
        s = 0;
    }
    if(s == 1)
    {
        for (; i < l; ++i)
        {
            if(isalpha(lexeme[i]) || lexeme[i] == '_' || isdigit(lexeme[i])){
                s = 1;
            }else{
                s = 0;
                break;
            }
        }
    }
    return s;
}

int num_rec(const char* lexem){
    int i = 0, s = 0;
    int l = strlen(lexem);
    if(lexem[i] == '.'){
        s = 2;
        i++;
    }else if(isdigit(lexem[i])){
        s = 1;
        i++;
    }
    if(s == 1){
        for(;i<l;++i){
            if(isdigit(lexem[i])){
                s = 1;
            }else if(lexem[i] == '.'){
                s = 2;
                ++i;
                break;
            }else{
                s = 0;
                break;
            }
        }
    }
    if(s == 2){
        if(isdigit(lexem[i])){
            s = 3;
            ++i;
        }
        else
            s = 0;
    }
    if(s == 3){
        for(;i<l;++i){
            if(isdigit(lexem[i]))
            {
                 s = 3;
            }
            else{
                s = 0;
                break;
            }
        }
    }
    return s;
}

int main(void){
    const char* mFile = scan("program.cpp", "program-m.txt");
    FILE* f = fopen(mFile, "r");
    FILE* o = fopen("tokens.txt", "w");
    if(!f){
        cerr<<"Error Opening File.";
        exit(EXIT_FAILURE);
    }
    char lexem[100];
    string s, b;
    while (fscanf(f, "%s", lexem)!=EOF)
    {
        if(kw_rec(lexem))
        {
            printf("\t[kw %s]", lexem);
            fprintf(o, "\t[kw %s]", lexem);
        }
        else if(id_rec(lexem))
        {
            printf("\t[id %s]", lexem);
            fprintf(o, "\t[id %s]", lexem);
        }
        else if(op_rec(lexem))
        {
            printf("\t[op %s]", lexem);
            fprintf(o, "\t[op %s]", lexem);
        }
        else if(sep_rec(lexem))
        {
            printf("\t[sep %s]", lexem);
            fprintf(o, "\t[sep %s]", lexem);
        }
       else  if(num_rec(lexem))
        {
            printf("\t[num %s]", lexem);
            fprintf(o, "\t[num %s]", lexem);
        }
        else if(par_rec(lexem))
        {
            printf("\t[par %s]", lexem);
            fprintf(o, "\t[par %s]", lexem);
        }
        else
        {
            printf("\t[unkwn %s]", lexem);
            fprintf(o, "\t[unkwn %s]", lexem);
        }
    }
}