#ifndef PARSER
#define PARSER

class Parser
{
public:
    virtual std::vector<int> Parse(std::string input) = 0;
};

#endif // PARSER
