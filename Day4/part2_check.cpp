#include <string>

int time_check(std::string str, std::string check, int find)
{
    int i = find;
     if (check == "byr")
    {
        if (!(std::stoi(str.substr(i+4, 4)) >= 1920 && std::stoi(str.substr(i+4, 4)) <= 2002))
            return (-1);
    }
    else if (check == "iyr")
    {
        if (!(std::stoi(str.substr(i+4, 4)) >= 2010 && std::stoi(str.substr(i+4, 4)) <= 2020))
            return (-1);
    }
    else if (check == "eyr")
    {
        if (!(std::stoi(str.substr(i+4, 4)) >= 2020 && std::stoi(str.substr(i+4, 4)) <= 2030))
            return (-1);
    }
    return (0);
}

int eye_check(std::string str, std::string check, int find)
{
    int i = find;
    int c = 0;
    std::string eye[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    
    while (c < 7)
    {
        if (str.substr(i+4, 3) == eye[c])
            break;
        c++;
    }
    if (c == 7)
        return(-1);
    return (0);
}

int pid_check(std::string str, std::string check, int find)
{
    int i = find;

    while(str[i + 4] != ' ' && str[i + 4] != '\0')
        {    
            if (!(str[i+4] >= '0' && str[i+4] <= '9'))
                return (-1);
            i++;
        }
        if ((i - find) != 9)
            return(-1);
    return (0);
}

int hcl_check(std::string str, std::string check, int find)
{
    int i = find;
    if (str[i + 4] != '#')
        return (-1);
    while(str[i + 5] != ' ' && str[i + 5] != '\0')
        i++;
    if ((i - find) != 6)
        return (-1);
    i = find + 5;
    while(i < (find + 11))
    {
        if (!((str[i] >= 'a' && str[i] <= 'f')||(str[i] >= '0' && str[i] <= '9') ))
            return (-1);
        i++;
    }
    return (0);
}

int hgt_check(std::string str, std::string check, int find)
{
    int i = find;

    if (str.find("cm", i) != std::string::npos)
    {
        if (!(std::stoi(str.substr(i+4, 3)) >= 150 && std::stoi(str.substr(i+4, 3)) <= 193))
            return (-1);
    }
    else if (str.find("in", i) != std::string::npos)
    {
        if (!(std::stoi(str.substr(i+4, 3)) >= 59 && std::stoi(str.substr(i+4, 3)) <= 76))
            return (-1);
    }
    else
        return (-1);
    return (0);
}