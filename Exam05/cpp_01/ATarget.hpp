#ifndef ATARGET_HPP
#define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget{
	protected:
		std::string type;
	public:
		ATarget() : type("") { }
		ATarget(std::string const& t): type(t) { }
		ATarget(const ATarget& at) { *this = at; }
		ATarget& operator = (const ATarget& at)
		{
			if (this != & at)
				this->type = at.type;
			return (*this);
		}
		virtual ~ATarget() { }

		std::string const& getType() const { return (this->type); }
		
		void	getHitBySpell(const ASpell& asp) const;
		
		virtual ATarget* clone() const = 0;
};
#endif
