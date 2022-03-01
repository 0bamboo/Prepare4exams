#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <vector>

class Warlock
{
private:
	std::string name;
	std::string title;
	std::vector<ASpell*> sps;
	Warlock(/* args */);
	Warlock(Warlock const &); 
	Warlock & operator=(Warlock const &);

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const & getName() const;
	std::string const & getTitle() const;
	void setTitle(std::string const & title);
	void introduce() const;

	void learnSpell(ASpell *);
	void forgetSpell(std::string const &nam);
	void launchSpell(std::string const & na, ATarget &);
};



#endif