#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include "ATarget.hpp"
class ATarget;

class ASpell
{
protected:
	std::string name;
	std::string effects;

public:
	ASpell(/* args */);
	ASpell(std::string const &nam, std::string const &effect);
	ASpell(const ASpell &);
	ASpell & operator=(const ASpell &);
	virtual ~ASpell();

	std::string const & getName() const;
	std::string const & getEffects() const;

	virtual ASpell * clone() const = 0;

	void launch(const ATarget & target) const;
};

#endif