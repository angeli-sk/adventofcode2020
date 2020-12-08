#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>
# define COLOR_RED 		"\033[38;5;196m"
# define COLOR_GREEN	"\033[38;5;46m"

int count_dups(std::string &s, std::string &s_dupless, int people, int tots)
{
    int n = 0;
    for (int i = 0; i < (int)s_dupless.length(); i++)
    {
        n = std::count(s.begin(), s.end(), s_dupless[i]);
        // std::cout << "n= "<< n << std::endl;
        // std::cout << "m= " << people << std::endl;
        if (n == people || s.length() == 1)
            tots = tots + 1;
    }
    //std::cout << "tots= " << tots<< std::endl;
    return (tots);
}

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

int double_checkor(std::vector<std::string> v_str, std::vector<int> &v_int)
{
    int tots = 0;
    std::vector<std::string> v_copy;

    for (int i=0; i < (int)v_str.size(); i++)
        v_copy.push_back(remove_dups(v_str[i]));
    for (int i=0; i < (int)v_int.size(); i++)
    {
        //  for(int i = 0; i < v_int.size(); i++)
            // std::cout << v_int[i] << std::endl;
   tots = count_dups(v_str[i], v_copy[i], v_int[i], tots); }
        
    return(tots);
}

std::string    answer_makor(std::ifstream &file, std::vector<int> &v_int)
{
    std::string str;
    std::string line;
    int line_count = 0; //amount of people

    while (getline (file, line))
    {
        if (line == "")
        {
            v_int.push_back(count);
            break;
        }
        str.append(line);
        line_count++;
    }
    return (str);
}

int answerset(std::ifstream &file, std::vector<std::string> v_str)
{
    std::string str;
    std::string line;
    std::string answer = "lemao";
    std::vector<int> v_int;
    while (!answer.empty())
    {
        answer = answer_makor(file, v_int);
        v_str.push_back(answer);
    }
    return (double_checkor(v_str, v_int));
}

int     answer_checkor()
{
    int answer = 0;
    std::vector<std::string> v_str;
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    answer = answerset(file, v_str);
    file.close();
    return (answer);
}

int  main(void)
{
    int answer = answer_checkor();
    std::cout << COLOR_GREEN << "Answer = " << COLOR_RED  << answer << std::endl;
    return (0);
}