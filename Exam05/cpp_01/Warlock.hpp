
#ifndef TEST_HPP
#define TEST_HPP
# include <iostream>
# include <string>
# include <vector>
# include "ASpell.hpp"

class Warlock{
	private:
		std::string name;
		std::string title;
		std::vector<ASpell *> spells;
		Warlock():name(""), title("") { }
		Warlock(const Warlock& war) { *this = war; }
		Warlock& operator = (const Warlock& war) { (void)war; return *this; }
	public:
		Warlock(std::string const& n, std::string const& t) : name(n), title(t) 
		{ 
			std::cout << this->name << ": This look like another boring day." << std::endl;
		}
		~Warlock() 
		{
			std::cout << this->name << ": My job here is done!" << std::endl;
		}
		const std::string& getName() const
		{
			return (this->name);
		}

		void	setTitle(std::string const& title)
		{
			this->title = title;
		}

		const std::string& getTitle() const
		{
			return (this->title);
		}

		void introduce () const
		{
			std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
		}

		void	learnSpell(ASpell* asp)
		{
			if (asp)
			{
				std::vector<ASpell *>::iterator it = this->spells.begin();
				for (; it!= spells.end(); it++)
				{
					if ((*it)->getName() == asp->getName())
						return ;
				}
				this->spells.push_back(asp);
			}
		}

		void	forgetSpell(const std::string& str)
		{
			std::vector<ASpell *>::iterator it = this->spells.begin();
			for (; it != this->spells.end(); it++)
			{
				if ((*it)->getName() == str)
				{
					delete *it;
					this->spells.erase(it);
					return ;
				}
			}
		}

		void	launchSpell(const std::string& str, const ATarget& at)
		{
			std::vector<ASpell *>::iterator it = this->spells.begin();
			for (; it != this->spells.end(); it++)
			{
				if ((*it)->getName() == str)
				{
					(*it)->launch(*at.clone());
				}
			}
		}

};
#endif