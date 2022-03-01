#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
# include <vector>

#include "ATarget.hpp"

class TargetGenerator{
	private:
		TargetGenerator(const TargetGenerator& cpy) { *this = cpy; }
		TargetGenerator& operator =  (const TargetGenerator& cpy) { (void)cpy; return (*this); }
		std::vector<ATarget *> targets;
	public:
		TargetGenerator() { }
		~TargetGenerator() { }

		void	learnTargetType(ATarget* tar)
		{
			std::vector<ATarget* >::iterator it = targets.begin();

			for (;it != targets.end(); it++)
			{
				if ((*it)->getType() == tar->getType())
					return ;
			}
			this->targets.push_back(tar->clone());
		}

		void	forgetTargetType(std::string const & str)
		{
			std::vector<ATarget *>::iterator it = targets.begin();
			for (;it != targets.end(); it++)
			{
				if ((*it)->getType() == str)
				{
					delete *it;
					this->targets.erase(it);
					return ;
				}
			}
		}

		ATarget* createTarget(std::string const& str)
		{
			for (std::vector<ATarget*>::iterator it = this->targets.begin(); it != this->targets.end(); it++)
			{
				if ((*it)->getType() == str)
				{
					ATarget* t = (*it)->clone();
					return (t);
				}
			}
			return nullptr;
		}
};

#endif
