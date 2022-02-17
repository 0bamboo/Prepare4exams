#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
private:
	/* data */
public:
	Fireball(/* args */);
	virtual ~Fireball();

	virtual ASpell * clone() const;
};


#endif