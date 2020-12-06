#include <string>
#include <iostream>
#include <fstream>
//#include <utility>
# define COLOR_RED 		"\033[38;5;196m"
# define COLOR_GREEN	"\033[38;5;46m"
# define lower first
# define upper second

int    rowcheck(std::string line)
{
    std::pair <int,int> half;
    bool    uporlow;

    half.lower = 0;
    half.upper = 127;
    for(int i = 0; i < 7; i++)
    {
        if (line[i] == 'F')
        {
            half.upper = half.upper - ((half.upper - half.lower) / 2);
            uporlow = true;
        }    
        else if (line[i] == 'B')
        {
            half.lower = half.lower + ((half.upper - half.lower) / 2);
            uporlow = false;
        }
    }
    if (uporlow == false)
        return (half.second);
    else
        return (half.first);
    return (0);
}

int    columncheck(std::string line)
{
    std::pair <int,int> half;
    bool    uporlow;

    half.lower = 0;
    half.upper = 7;
    for (int i = 7; i < 10; i++)
    {
        if (line[i] == 'R')
        {
            half.upper = half.upper - ((half.upper - half.lower) / 2);
            uporlow = true;
        }    
        else if (line[i] == 'L')
        {
            half.lower = half.lower + ((half.upper - half.lower) / 2);
            uporlow = false;
        }
    }
    if (uporlow == false)
        return (half.second);
    else
        return (half.first);
    return (0);
}

int    inputcheck()
{
    std::string line;
    int row = 0;
    int column = 0;
    int highest = 0;
    int current = 0;
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    while (getline (file, line))
    {
        row = rowcheck(line);
        column = columncheck(line);
        current = row * 8 + column;
        if (current > highest)
            highest = current;
    }
    file.close();
    return (highest);
}

int  main(void)
{
    int answer = inputcheck();
    
    std::cout << COLOR_GREEN << "answer = " << COLOR_RED << answer + 1 << std::endl;
    return (0);
}    