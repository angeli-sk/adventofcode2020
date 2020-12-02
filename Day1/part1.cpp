#include <fstream>
#include <string.h>
#include <iostream>
#include "colors.h/colors.h"

int line_count(std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    int i = 0;

    while (getline (file, line))
        i++;
    file.close(); 
    return (i);
}

int twoOtwoO_finder(int *array, int length)
{
    int x = 0;
    int y = 1;

    while (x < length)
    {
        while (y < length)
        {
            if ((array[x] + array[y]) == 2020)
                return (array[x] * array[y]);
            y++;
        }
       
        x++; 
        y = x + 1;
    }
    return(-1);
}

int main(void)
{
    std::string line;
    int *array;
    int num = 0;
    int length = 0;
  
    std::ifstream file("input.txt");
    if(file.fail())
        return (-1);
    length = line_count("input.txt");
    array = new int[length];
    for (int i = 0; i < length; i++)
    {
        getline (file, line);
        num = std::stoi(line);
        array[i] = num;
    }
    num = twoOtwoO_finder(array, length);
    if (num == -1)
    {
        std::cout << COLOR_RED << "IT FAIL LOSER!" << std::endl;
        return(-1);
    }
    std::cout << COLOR_YELLOW << "part1: 2020 " 
        << COLOR_RED << "vision "
        << COLOR_GREEN <<  "be like: " 
        << COLOR_GREEN << num << std::endl;
    delete[] array;
    file.close(); 

//TREE ASCII ART
    std::cout << "\033[38;5;220m      .\n\
   __/ \\__\n\
   \\     /\n\
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