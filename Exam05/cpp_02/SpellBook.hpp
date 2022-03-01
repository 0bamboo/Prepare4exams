#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
# include <vector>

class SpellBook{
	private:
		SpellBook(const SpellBook& sb) { *this= sb; }
		SpellBook& operator = (const SpellBook& sb) { (void)sb; return (*this); }
		std::vector<ASpell *> book;
	public:
		SpellBook() { }
		~SpellBook() { }

		void	learnSpell(ASpell *s)
		{
			if (!s)
				return ;
			std::vector<ASpell *>::iterator it = book.begin();
			for (; it != book.end(); it++)
			{
				if ((*it)->getName() == s->getName())
					return ;
			}
			this->book.push_back(s->clone());
		}

		void	forgetSpell(std::string const& str)
		{
			std::vector<ASpell *>::iterator it = book.begin();
			for(; it != book.end(); it++)
			{
				if ((*it)->getName() == str)
				{
					delete *it;
					book.erase(it);
					return ;
				}
			}
		}

		ASpell* createSpell(std::string const& str)
		{
			std::vector<ASpell *>::iterator it = book.begin();
			for (; it != book.end(); it++)
			{
				if ((*it)->getName() == str)
				{
					ASpell* sp = (*it)->clone();
					return sp;
				}
			}
			return nullptr;
		}
};

#endif
