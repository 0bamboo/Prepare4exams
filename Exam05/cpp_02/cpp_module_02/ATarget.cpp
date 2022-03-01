#include "ATarget.hpp"

ATarget::ATarget() : type("") {}

ATarget::ATarget(const std::string & ty) : type(ty) {}

ATarget::ATarget(const ATarget & src) { *this = src;}

ATarget & ATarget::operator=(const ATarget & src)
{
	if (this != &src) this->type = src.type;
	return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const { return type;}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << '!' << std::endl;
}
