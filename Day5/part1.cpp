#include <string>
#include <iostream>
#include <fstream>
#include <vector>
# define COLOR_RED 		"\033[38;5;196m"
# define COLOR_GREEN	"\033[38;5;46m"

int IDbinaryconvert(std::string boardiepass)
{
	for (int i = 0; i < 10 ; i++)
    {
		if (boardiepass[i] == 'F' || boardiepass[i] == 'L')
			boardiepass[i] = '0';
		else 
			boardiepass[i] = '1';
    }

	return (stoi(boardiepass, 0, 2));
}

int highestID(std::vector<std::string> boardiepass)
{
	int highest = 0;

	for (int i = 0; i < boardiepass.size(); i++)
    {
		int id = IDbinaryconvert(boardiepass[i]);
		if (id > highest)
			highest = id;
	}
	return (highest);
}

int    inputcheck()
{
    std::string line;
    std::vector<std::string> seatID;
    std::ifstream file("input");
    if(file.fail())
        return (-1);
    while (getline (file, line))
        seatID.push_back(line);
    file.close();
    return (highestID(seatID));
}

int  main(void)
{
    int answer = inputcheck();
    std::cout << COLOR_GREEN << "Answer = " << COLOR_RED  << answer << std::endl;
    return (0);
}    