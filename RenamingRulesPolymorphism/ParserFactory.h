#include "Object.h"
#include "IParsable.h"

#include <map>

class ParserFactory : public Object
{
private:
    map<string, IParsable*> _container;

public:
    void registerWith(IParsable* parser);
    IParsable* create(string type);
    string toString() { return "ParserFactory"; }
};

void ParserFactory::registerWith(IParsable* parser)
{
    _container.insert({ parser->parsedObjectName(), parser });
}

IParsable* ParserFactory::create(string type)
{
    IParsable* parser = NULL;

    if ("RemoveSpecialCharsParser" == type)
    {
        parser = new RemoveSpecialCharsParser();
    }
    else if ("OneSpaceOnlyParser" == type)
    {
        parser = new OneSpaceOnlyParser();
    }
    else if ("AddCurrentMonthParser" == type)
    {
        parser = new AddCurrentMonthParser();
    }
    else if ("AddCurrentMonthParser" == type)
    {
        parser = new AddPrefixParser();
    }
    else if ("AddCurrentMonthParser" == type)
    {
        parser = new ReplaceParser();
    }

    return parser;
}