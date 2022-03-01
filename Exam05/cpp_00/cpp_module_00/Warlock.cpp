#include "Warlock.hpp"

Warlock::Warlock() : name(""), title("") {}

Warlock::Warlock(const Warlock &src) { (void)src; return; }

Warlock & Warlock::operator=(const Warlock &src) { (void)src; return *this; }

Warlock::Warlock(const std::string & na, const std::string & ty) : name(na), title(ty) {
	std::cout << this->name <<  ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << this->name << ": My job here is done!"<<std::endl; }

std::string const & Warlock::getName() const { return name; }
std::string const & Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const & ty) { this->title = ty; } 

// <NAME>: I am <NAME>, <TITLE> !

void Warlock::introduce() const { std::cout << this->name << ": I am " << this->name<< ", " << this->title << " !"<< std::endl; }

int main()
{
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	return (0);
}
