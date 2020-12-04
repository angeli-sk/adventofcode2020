#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "colors.h/colors.h"
#include <sstream>
#include "struct.hpp"

int     line_count(std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    int i = 0;

    while (getline (file, line))
        i++;
    file.close(); 
    return (i);
}

void    map_checkor(t_struct &str)
{
    int x = 3;
    int y = 1;
    str.count = 0;
    while(y < str.length)
    {
        if (str.Vmap[y][x%str.Vmap[y].length()] == '.')
            str.Vmap[y].replace(x%str.Vmap[y].length(), 1, "\033[38;5;196mO\033[38;5;46m");
        else if (str.Vmap[y][x%str.Vmap[y].length()] == '#')
        {   
            str.Vmap[y].replace(x%str.Vmap[y].length(), 1, "\033[38;5;220mX\033[38;5;46m");
            str.count++;
        }
        x = x + 3;
        y++;
    }
    for (int i = 0; i < str.length; i++)
        std::cout << str.Vmap[i] << std::endl;
}

void    map_reader(t_struct &str)
{
    std::string line;
    str.length = 0;
    std::ifstream file("input");
    if(file.fail())
        return;
    str.length = line_count("input");
    std::string map[str.length];

    for (int i = 0; i < str.length; i++)
    {
        getline (file, line);
        map[i] = line;
    }
    str.Vmap.assign(map, map+str.length);
    str.Vmap[0].insert(0, "\033[38;5;46m");
}

int  main(void)
{
    t_struct str;
   
    map_reader(str);
    map_checkor(str);
    std::cout << COLOR_YELLOW << "answer = " << COLOR_RED << str.count << std::endl;
    return (0);
}    