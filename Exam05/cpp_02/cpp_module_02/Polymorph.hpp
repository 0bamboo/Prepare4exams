#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
private:
	/* data */
public:
	Polymorph(/* args */);
	virtual ~Polymorph();

	virtual ASpell * clone() const;
};


#endif