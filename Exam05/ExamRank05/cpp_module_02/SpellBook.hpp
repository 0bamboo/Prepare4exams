#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
private:
	SpellBook(const SpellBook &);
	SpellBook & operator=(const SpellBook &);
	std::vector<ASpell*> sps;
public:
	SpellBook(/* args */);
	~SpellBook();

	void learnSpell(ASpell*);
	void forgetSpell(std::string const &);
	ASpell* createSpell(std::string const &);
};

#endif