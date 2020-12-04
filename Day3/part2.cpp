#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "colors.h/colors.h"
#include <sstream>
#include "struct2.hpp"

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

int    map_checkor(t_struct &str, int xx, int yy, std::vector<std::string> Vmap)
{
    int x = xx;
    int y = yy;
    str.count = 0;
    while(y < str.length)
    {
        if (Vmap[y][x%Vmap[y].length()] == '.')
            Vmap[y].replace(x%Vmap[y].length(), 1, "\033[38;5;196mO\033[38;5;46m");
        else if (Vmap[y][x%Vmap[y].length()] == '#')
        {   
            Vmap[y].replace(x%Vmap[y].length(), 1, "\033[38;5;220mX\033[38;5;46m");
            str.count++;
        }
        x = x + xx;
        y = y + yy;
    }
    for (int i = 0; i < str.length; i++)
        std::cout << Vmap[i] << std::endl;
    return (str.count);
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
    str.Vmap1.assign(map, map+str.length);
    str.Vmap2.assign(map, map+str.length);
    str.Vmap3.assign(map, map+str.length);
    str.Vmap4.assign(map, map+str.length);
    str.Vmap5.assign(map, map+str.length);
    str.Vmap1[0].insert(0, "\033[38;5;46m");
    str.Vmap2[0].insert(0, "\033[38;5;46m");
    str.Vmap3[0].insert(0, "\033[38;5;46m");
    str.Vmap4[0].insert(0, "\033[38;5;46m");
    str.Vmap5[0].insert(0, "\033[38;5;46m");
}

int  main(void)
{
    t_struct str;
 
    map_reader(str);
    unsigned int first = map_checkor(str, 1, 1, str.Vmap1);
    unsigned int second = map_checkor(str, 3, 1, str.Vmap2);
    unsigned int third = map_checkor(str, 5, 1, str.Vmap3);
    unsigned int forth = map_checkor(str, 7, 1, str.Vmap4);
    unsigned int fifth = map_checkor(str, 1, 2, str.Vmap5);
    std::cout << COLOR_YELLOW << "answer = " << COLOR_RED << (first * second * third * forth * fifth) << std::endl;
    return (0);
}    