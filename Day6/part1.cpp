#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
# define COLOR_RED 		"\033[38;5;196m"
# define COLOR_GREEN	"\033[38;5;46m"

std::string remove_dups(const std::string &s)
{
    std::string str;
    std::unordered_set<char> set; //unordered_set avoids duplicates by comparing values uwu!    
    auto end = s.end();
    std::pair<std::unordered_set<char>::iterator, bool> result;
    for (auto i = s.begin(); i != end; i++) //<
    {                                       //<
        const char &el = *i;                //< can be written as -> for (const char &el:s){
        result = set.insert(el);            // el will be the iterator through s
        if(result.second == true)           //checks if unordered_set insert was a succes(no duplicate ;P)
                str = str + el;
    }    
    return (str);
}

std::vector<std::string> double_checkor(std::vector<std::string> v_str)
{
    for (int i=0; i < v_str.size(); i++)
        v_str[i] = remove_dups(v_str[i]);

    return(v_str);
}

std::string    answer_makor(std::ifstream &file)
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

std::vector<std::string> answerset(std::ifstream &file, std::vector<std::string> v_str)
{
    std::string str;
    std::string line;
    std::string answer = "lemao";
    while (answer != "")
    {
        answer = answer_makor(file);
        v_str.push_back(answer);         
    } 
    return (double_checkor(v_str));
}

int     answer_checkor()
{
    int i = 0;
    int ii = 0;
    int count = 0;
    std::vector<std::string> v_str;
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    v_str = answerset(file, v_str);
    while (i < v_str.size())
    {
        count = count + v_str[i].length();
        i++;
    }
    file.close();
    return (count);
}

int  main(void)
{
    int answer = answer_checkor();
    std::cout << COLOR_GREEN << "Answer = " << COLOR_RED  << answer << std::endl;
    return (0);
}    