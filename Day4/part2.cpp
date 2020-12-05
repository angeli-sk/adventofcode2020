#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include "colors.h/colors.h"

int time_check(std::string str, std::string check, int find);
int eye_check(std::string str, std::string check, int find);
int pid_check(std::string str, std::string check, int find);
int hcl_check(std::string str, std::string check, int find);
int hgt_check(std::string str, std::string check, int find);

std::string    passp_makor(std::ifstream &file)
{
    std::string str;
    std::string line;

    while (getline (file, line))
    {
        if (line == "")
            break;
        
        str += " " + line;
    }
    return (str);
}

int pp_checkor(std::string str, std::string check, int find)
{
    int i = find;

    if (check == "byr" || check == "iyr" || check == "eyr")
    {
        if (time_check(str, check, find) == -1)
            return(-1);
    }    
    else if (check == "ecl")
    {
        if (eye_check(str, check, find) == -1)
            return(-1);
    }    
    else if (check == "pid")
    {
        if (pid_check(str, check, find) == -1)
            return(-1);
    }
    else if (check == "hcl")
    {
        if (hcl_check(str, check, find) == -1)
            return(-1);
    }
    else if (check == "hgt")
    {
        if (hgt_check(str, check, find) == -1)
            return(-1);
    }
    return (0);
}

int    map_reader()
{
    std::string array[7] = {"eyr", "byr", "hcl", "ecl", "hgt", "iyr", "pid"};
    std::string line;
    int count = 0;
    int valid = 0;
    int find = 0;
    std::string pp = "lemao"; 
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    while (pp != "")
   {
        pp = passp_makor(file);
        for (int i = 0; i < 7; i++)
        {
            find = pp.find(array[i]);
            if (find != std::string::npos)
            {
                if (pp_checkor(pp, array[i], find) != -1) 
                    count++;
            }
        }
        if(count == 7)
            valid++;
        count = 0;
        find = 0;
    }
    return (valid);
}

int  main(void)
{
    int answer = map_reader();
    
    std::cout << COLOR_GREEN << "answer = " << COLOR_RED << answer << std::endl;
    return (0);
}    