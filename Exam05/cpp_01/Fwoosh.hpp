#ifndef FWOOSH_HPP
#define FWOOSH_HPP

# include "ASpell.hpp"

class Fwoosh : public ASpell{
	public:
		Fwoosh()
		{
			this->name= "Fwoosh";
			this->effects = "fwooshed";
		}
		~Fwoosh(){ }

		ASpell* clone() const
		{
			return (new Fwoosh());
		}

};
#endif