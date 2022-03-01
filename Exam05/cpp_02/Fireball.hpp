#ifndef FIREBALL_HPP
#define FIREBALL_HPP

# include "ASpell.hpp"

class Fireball: public ASpell{
	public:
		Fireball(){
			this->name = "Fireball";
			this->effects = "burnt to a crisp";
		}
		~Fireball() { }
		ASpell* clone() const 
		{
			return (new Fireball());
		}
};

#endif