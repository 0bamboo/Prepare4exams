#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"
class ASpell;

class ATarget
{
protected:
	std::string type;

public:
	ATarget(/* args */);
	ATarget(std::string const &ty);
	ATarget(const ATarget &);
	ATarget & operator=(const ATarget &);
	virtual ~ATarget();

	std::string const & getType() const;
	virtual ATarget* clone() const = 0;

	void getHitBySpell(const ASpell &) const;
};

#endif