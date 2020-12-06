#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
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

int myID(std::vector<std::string> seatID)
{
    int id = 0;
    std::vector<int> bin_seatID;
    
	for (int i = 0; i < seatID.size(); i++)
		bin_seatID.push_back(IDbinaryconvert(seatID[i]));
    std::sort(bin_seatID.begin(), bin_seatID.end());
    for (int i = 0; i < seatID.size() - 1; i++)
    {
        if (bin_seatID[i + 1] - bin_seatID[i] != 1)
            return (bin_seatID[i] + 1);
    }
	return (0);
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
    return (myID(seatID));
}

int  main(void)
{
    int answer = inputcheck();
    std::cout << COLOR_GREEN << "Answer = " << COLOR_RED  << answer << std::endl;
    return (0);
}    