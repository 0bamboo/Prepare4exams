#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator & src) { (void) src; }

TargetGenerator & TargetGenerator::operator=(const TargetGenerator & src) { (void) src; return *this; }

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (std::vector<ATarget*>::iterator it = tags.begin(); it != tags.end();it++)
	{
		delete *it;
	}
	tags.clear();
}

void TargetGenerator::learnTargetType(ATarget * t)
{
	if(t)
	{
		for(std::vector<ATarget*>::iterator it = tags.begin(); it != tags.end(); it++)
		{
			if ((*it)->getType() == t->getType())
				return;
		}
		tags.push_back(t->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const & t)
{
	for(std::vector<ATarget*>::iterator it = tags.begin(); it != tags.end(); it++)
	{
		if ((*it)->getType() == t)
		{
			delete *it;
			tags.clear();
			return;
		}
	}
}

ATarget * TargetGenerator::createTarget(std::string const & t)
{
	for(std::vector<ATarget*>::iterator it = tags.begin(); it != tags.end(); it++)
	{
		if((*it)->getType() == t)
		{
			ATarget *no = (*it)->clone();
			return no;
 		}
	}
	return nullptr;
}