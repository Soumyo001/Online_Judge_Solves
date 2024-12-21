#include <bits/stdc++.h>

void readFile(const char* fName){
    FILE* file = fopen(fName, "r");
    char c;
    while ((c=fgetc(file))!=EOF)
    {
        std::cout<<c;
    }
    fclose(file); 
}

int main(void){

    std::cout<<"Original File : \n";
    std::cout<<"==================================\n";
    readFile("program.cpp");

    FILE* f1 = fopen("program.cpp", "r");
    FILE* f2 = fopen("removed_newlines_spaces.txt", "w");
    FILE* f3 = fopen("detected_comments.txt", "w");
    char c;
    if(!f1){
        std::cerr<<"Could not open file. \n";
        return EXIT_FAILURE;
    }
    while ((c=fgetc(f1))!=EOF)
    {
        if(c == '/'){
            FILE* temp = f1;
            c = fgetc(temp);
            if(c == '/'){
                fputs("//", f3);
                while((c=fgetc(temp))!='\n') fputc(c, f3);
                fputc('\n',f3);
            }else if(c == '*'){
                fputs("/*", f3);
                while ((c=fgetc(temp))!=EOF)
                {
                    if(c == '*'){
                        fputc(c, f3);
                        c = fgetc(temp);
                        if(c == '/'){
                            fputc(c, f3);
                            break;
                        }
                    }
                    fputc(c, f3);
                }
                fputc('\n', f3);
            }
        }else{
            if(c == '\n'){
                fputc(' ', f2);
                continue;
            }else if(c == ' '){
                long pos = ftell(f1);
                c = fgetc(f1);
                if(c == ' ' || c == '\n') continue;
                else if(c == '/') fseek(f1, pos, SEEK_SET);
                else {
                    fputc(' ', f2);
                    fputc(c, f2);
                }
            }else
                fputc(c, f2);
        }
    }
    std::cout<<"\n\nModified File : \n";
    std::cout<<"==================================\n";
    fclose(f1);
    fclose(f2);
    fclose(f3);
    readFile("removed_newlines_spaces.txt");
    // std::ifstream input("program.cpp");
    // std::ofstream output("removed_newlines_spaces.txt");
    // if (!input.is_open()) {
    //     std::cerr << "Error: Unable to open input file!" << std::endl;
    //     return EXIT_FAILURE;
    // }

    // std::string s, code = "";
    // while(getline(input, s)){
    //     code += s;
    // }
    
    // std::cout<<code;
    // input.close();
}




// Function prototypes
// Function to display the menu
// Function to create a new account
// Check for duplicate account number
// To clear newline from buffer
// Function to deposit money
// Function to withdraw money
/*  this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
    */
// Function to check account balance
// Function to delete an account
// Function to display all accounts
// Main program