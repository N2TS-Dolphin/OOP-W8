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

    if ("RemoveSpecialChars" == type)
    {
        parser = new RemoveSpecialCharsParser();
    }
    else if ("OneSpaceOnly" == type)
    {
        parser = new OneSpaceOnlyParser();
    }
    else if ("AddCurrentMonth" == type)
    {
        parser = new AddCurrentMonthParser();
    }
    else if ("AddPrefix" == type)
    {
        parser = new AddPrefixParser();
    }
    else if ("Replace" == type)
    {
        parser = new ReplaceParser();
    }

    return parser;
}