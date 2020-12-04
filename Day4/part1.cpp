#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include "colors.h/colors.h"

std::string    passp_makor(std::ifstream &file)
{
    std::string str;
    std::string line;

    while (getline (file, line))
    {
        if (line == "")
            break;
        str.append(line);
    }
    return (str);
}

int    map_reader()
{
    std::string array[7] = {"eyr", "byr", "hcl", "ecl", "hgt", "iyr", "pid"};
    std::string line;
    int count = 0;
    int valid = 0;
    std::string pp = "lemao"; 
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    while (pp != "")
    {
        pp = passp_makor(file);
        for (int i = 0; i < 7; i++)
        {
            if (pp.find(array[i]) != std::string::npos)
                count++;
        }
        if(count == 7)
            valid++;
        count = 0;
    }
    return (valid);
}

int  main(void)
{
    int answer = map_reader();
    
    std::cout << COLOR_GREEN << "answer = " << COLOR_RED << answer << std::endl;
    return (0);
}    