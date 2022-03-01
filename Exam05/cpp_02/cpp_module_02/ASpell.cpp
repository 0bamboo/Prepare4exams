#include "ASpell.hpp"

ASpell::ASpell() : name(""), effects("") {}

ASpell::ASpell(std::string const &nam, std::string const &effect) : name(nam), effects(effect) {}

ASpell::ASpell(const ASpell &other) { *this = other; }

ASpell & ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->effects = other.effects;
	}
	return *this;
}

ASpell::~ASpell() {}

std::string const & ASpell::getName() const { return name;}
std::string const & ASpell::getEffects() const { return effects;}


void ASpell::launch(const ATarget & src) const{
	src.getHitBySpell(*this);
}