#ifndef ASPELL_HPP
#define ASPELL_HPP
# include <iostream>
# include <string>
#  include "ATarget.hpp"

class ATarget;

class ASpell{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell() : name(""), effects("") { }
		ASpell(std::string const& n, std::string const& ef) : name(n), effects(ef) { }
		ASpell(const ASpell& as) { *this = as; }
		ASpell&	operator = (const ASpell& asp)
		{
			if (this != &asp)
			{
				this->name = asp.name;
				this->effects = asp.effects;
			}
			return (*this);
		}
		virtual ~ASpell() { }

		std::string const& getName() const { return this->name; }

		std::string const& getEffects() const { return (this->effects); }

		void	launch(const ATarget& at) const;
		// {
			// at.getHitBySpell(*this);
		// }

		virtual ASpell* clone() const = 0;
};
#endif
