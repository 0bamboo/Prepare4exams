# include "ATarget.hpp"

		void	ATarget::getHitBySpell(const ASpell& asp) const
		{
			std::string effe = asp.getEffects();
			std::cout << this->type << " has been " << asp.getEffects() <<"!"<< std::endl;
		}
		