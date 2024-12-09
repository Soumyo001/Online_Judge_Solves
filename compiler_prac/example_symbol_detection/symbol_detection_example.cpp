//this is a simple symbol detection program

#include<iostream>
#include<stdio.h>

int main(void){
    FILE *f1, *f2, *f3, *f4, *f5;
    char c;
    f1 = fopen("program.cpp", "r");
    f2 = fopen("detected_brackets.txt", "w");
    f3 = fopen("detected_imports.txt", "w");
    f4 = fopen("detected_line_numbers.txt", "w");
    f5 = fopen("detected_comments.txt", "w");
    
    if(!f1){
        std::cout<<"Could not open file. \n";
        return EXIT_FAILURE;
    }
    int line_count = 1;
    fprintf(f4, "%d:\t", line_count);
    while((c = fgetc(f1))!=EOF){
        fputc(c, f4);
        if(c == '{' || c == '}' ||  c == '(' || c == ')'){
            fputc(c, f2);
        }else if(c == '#'){
            long pos = ftell(f1);
            FILE* temp = f1;
            while((c=fgetc(temp)) != '<') ;
            while ((c=fgetc(temp))!='>') fputc(c, f3);
            fputc('\n',f3);
            fseek(f1, pos, SEEK_SET);
        }else if(c == '\n'){
            ++line_count;
            fprintf(f4, "%d:\t", line_count);
        }else if(c == '/'){
            long pos = ftell(f1);
            FILE* temp = f1;
            c = fgetc(temp);
            if(c == '/'){
                fputs("//", f5);
                while ((c=fgetc(temp))!= '\n') fputc(c, f5);
                fputc(c, f5);
            }else if (c == '*'){
                fputs("/*", f5);
                while ((c=fgetc(temp))!=EOF) {
                    fputc(c, f5);
                    if(c=='*' && (c=fgetc(temp))=='/'){ 
                        fputc(c, f5);
                        break;
                    }
                }
                fputc('\n', f5);
            }
            fseek(f1, pos, SEEK_SET);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    return EXIT_SUCCESS;
}