#ifndef CONSOLE_PARSER
#define CONSOLE_PARSER

class ConsoleParser : public Parser
{
public:
    std::vector<int> Parse(std::string input)
    {
        std::vector<int> result;
        std::string currCoords, newCoords;
        std::istringstream parts(input);
        getline(parts, currCoords, ' ');
        getline(parts, newCoords, ' ');

        int currCol = currCoords.at(0) - 'a';
        int currRow = currCoords.at(1) - '0';

        int newCol = newCoords.at(0) - 'a';
        int newRow = newCoords.at(1) - '0';

        result.push_back(currRow);
        result.push_back(currCol);
        result.push_back(newRow);
        result.push_back(newCol);

        return result;
    }
};

#endif // CONSOLE_PARSER
