#include <fstream>
#include <string>
#include <iostream>
#include "struct.h"

void    struct_init(t_struct &pw)
{
    pw.min = 0;
    pw.max = 0;
    pw.c = 0;
}

void lazy_linereader(std::string line, t_struct &pw, int count)
{
    std::string::size_type sz;
    int check = 0;
    int len = 1;

   for(int i = 0; i < line.length(); i++)
    {
        if (line[i] >= '0' && line[i] <= '9' && pw.min == 0)
        {
            pw.min = std::stoi(&line[i],&sz);
            i = sz;
        }   
        if (line[i] >= '0' && line[i] <= '9' && pw.min != 0 && pw.max == 0)
        {
            pw.max = std::stoi(&line[i], &sz);
            i = sz;
        }
        if (line[i] >= 'a' && line[i] <= 'z' && pw.c == 0)
        {
            pw.c = line[i];
            i++;
        }
        while (line[i] >= 'a' && line[i] <= 'z' && pw.c != 0)
        {   
            if(line[i] == pw.c && (len == pw.min || len == pw.max ) && check == 1)
                pw.correct--;
            if(line[i] == pw.c && (len == pw.min || len == pw.max ) && check == 0)
            {
                pw.correct++;
                check = 1;
            }
            len++;    
            i++;
        }
    }
}

int password_checkor()
{
    t_struct pw;
    std::string line;
    int count = 0;
    std::ifstream file("input.txt");
    if(file.fail())
        return (-1);
    struct_init(pw);
    pw.correct = 0;
    while(getline (file, line)) 
    {
        lazy_linereader(line, pw, count);
        struct_init(pw);       
    } 
    file.close();
    return (pw.correct);
}

int main(void)
{
    int answer = password_checkor();    
    std::cout << "\033[38;5;46m" << "    part 2: " << std::endl;
//TREE ASCII ART WITH THE ANSWER INSIDE
    std::cout << "\033[38;5;220m      .\n\
   __/ \\__\n\
   \\ " << answer << " /\n\
   /.\033[38;5;46m\'\033[38;5;196mo\033[38;5;46m\'\033[38;5;220m.\\\033[38;5;46m\n\
    .\033[38;5;196mo\033[38;5;46m.\'.\n\
   .\'.\'\033[38;5;196mo\033[38;5;46m\'.\n\
  \033[38;5;196mo\033[38;5;46m\'.\033[38;5;196mo\033[38;5;46m.\'.\033[38;5;196mo\033[38;5;46m.\n\
 .\'.\033[38;5;196mo\033[38;5;46m.\'.\'.\033[38;5;196mo\033[38;5;46m.\n\
.\033[38;5;196mo\033[38;5;46m.\'.\033[38;5;196mo\033[38;5;46m.\'.\033[38;5;196mo\033[38;5;46m.\'.\n\
   \033[38;5;130m[_____]\n\
    \\___/    " << std::endl;
//END OD TREE ART

    return(0);
}