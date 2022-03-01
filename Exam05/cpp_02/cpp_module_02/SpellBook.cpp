#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &src) {(void)src;} 

SpellBook & SpellBook::operator=(const SpellBook &src) {(void)src; return *this;}

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (std::vector<ASpell*>::iterator it = sps.begin(); it != sps.end(); it++)
	{
		delete *it;
	}
	sps.clear();
}

void SpellBook::learnSpell(ASpell * sp)
{
	if (sp)
	{
		for (std::vector<ASpell*>::iterator it = sps.begin(); it != sps.end(); it++)
		{
			if((*it)->getName() == sp->getName())
				return ;
		}
		sps.push_back(sp->clone());
	}
}

void SpellBook::forgetSpell(std::string const & n)
{
	for (std::vector<ASpell*>::iterator it = sps.begin(); it != sps.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			delete *it;
			sps.erase(it);
			return ;
		}
	}
}

ASpell * SpellBook::createSpell(std::string const &n)
{
	for (std::vector<ASpell*>::iterator it = sps.begin(); it != sps.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			ASpell* no = (*it)->clone();
			return no;
		}
	}
	return nullptr;
}