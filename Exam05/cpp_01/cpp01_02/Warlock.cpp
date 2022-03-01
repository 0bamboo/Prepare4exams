#include "Warlock.hpp"

Warlock::Warlock() : name(""), title("") {}

Warlock::Warlock(const Warlock &src) { (void)src; return; }

Warlock & Warlock::operator=(const Warlock &src) { (void)src; return *this; }

Warlock::Warlock(const std::string & na, const std::string & ty) : name(na), title(ty) {
	std::cout << this->name <<  ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << this->name << ": My job here is done!"<<std::endl;
	for (std::vector<ASpell*>::iterator it = sps.begin(); it != sps.end(); it++) {
		delete *it;
	}
	sps.clear();
}

std::string const & Warlock::getName() const { return name; }
std::string const & Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const & ty) { this->title = ty; }

// <NAME>: I am <NAME>, <TITLE> !

void Warlock::introduce() const { std::cout << this->name << ": I am " << this->name<< ", " << this->title << " !"<< std::endl; }


void Warlock::learnSpell(ASpell * sp)
{
	if (sp)
	{
	for (std::vector<ASpell *>::iterator it = sps.begin(); it != sps.end(); it++) {
		if ((*it)->getName() == sp->getName())
			return ;
	}
	this->sps.push_back(sp->clone());
	}
}

void Warlock::forgetSpell(std::string const & n)
{
	for (std::vector<ASpell *>::iterator it = sps.begin(); it != sps.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			delete *it;
			sps.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string const & n, ATarget & tar)
{
	for (std::vector<ASpell *>::iterator it = sps.begin(); it != sps.end(); it++)
	{
		if ((*it)->getName() == n)
		{
			(*it)->launch(tar);
			return ;
		}
	}
}