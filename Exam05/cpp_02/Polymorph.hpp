#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"

class Polymorph : public ASpell{
	public:
		Polymorph()
		{
			this->name = "Polymorph";
			this->effects = "turned into a critter";
		}
		~Polymorph() { }

		ASpell* clone() const
		{
			return (new Polymorph());
		}
};

#endif
