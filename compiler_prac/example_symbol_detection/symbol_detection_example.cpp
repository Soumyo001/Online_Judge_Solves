//this is a simple symbol detection program

#include<iostream>
#include<stdio.h>

int main(void){
    FILE *f1, *f2, *f3, *f4;
    char c;
    f1 = fopen("program.cpp", "r");
    f2 = fopen("detected_brackets.txt", "w");
    f3 = fopen("detected_imports.txt", "w");
    f4 = fopen("detected_line_numbers.txt", "w");

    if(!f1){
        std::cout<<"Could not open file. \n";
        return EXIT_FAILURE;
    }else{
        int line_count = 1;
        fprintf(f4, "%d:\t", line_count);
        while((c = fgetc(f1))!=EOF){
            fputc(c, f4);
            if(c == '{' || c == '}' ||  c == '(' || c == ')'){
                fputc(c, f2);
            }else if(c == '#'){
                while((c=fgetc(f1)) != '<') {fputc(c,f4);}
                fputc(c, f4);
                while ((c=fgetc(f1))!='>') {fputc(c, f3);fputc(c, f4);}
                fputc(c,f4);
                fputc('\n',f3);
            }else if(c == '\n'){
                ++line_count;
                fprintf(f4, "%d:\t", line_count);
            }
        }
    }
    return EXIT_SUCCESS;
}