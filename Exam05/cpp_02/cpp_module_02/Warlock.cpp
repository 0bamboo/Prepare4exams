#include "Warlock.hpp"

Warlock::Warlock() : name(""), title("") {}

Warlock::Warlock(const Warlock &src) { (void)src; return; }

Warlock & Warlock::operator=(const Warlock &src) { (void)src; return *this; }

Warlock::Warlock(const std::string & na, const std::string & ty) : name(na), title(ty) {
	std::cout << this->name <<  ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << this->name << ": My job here is done!"<<std::endl;
}

std::string const & Warlock::getName() const { return name; }
std::string const & Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const & ty) { this->title = ty; }

// <NAME>: I am <NAME>, <TITLE> !

void Warlock::introduce() const { std::cout << this->name << ": I am " << this->name<< ", " << this->title << " !"<< std::endl; }


void Warlock::learnSpell(ASpell * sp)
{
	sps.learnSpell(sp);
}

void Warlock::forgetSpell(std::string const & n)
{
	sps.forgetSpell(n);
}

void Warlock::launchSpell(std::string const & n, ATarget & tar)
{
	ASpell * temp = sps.createSpell(n);
	if (temp) 
	{
		temp->launch(tar);
		delete temp;
	}
}