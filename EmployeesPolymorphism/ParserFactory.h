#pragma once
#include "Object.h"
#include "IParsable.h"
#include "Utils.h"

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

    if ("DailyEmployee" == type)
    {
        parser = new DailyEmployeeParser();
    }
    else if ("ProductEmployee" == type)
    {
        parser = new ProductEmployeeParser();
    }
    else if ("Manager" == type)
    {
        parser = new ManagerParser();
    }

    return parser;
}
