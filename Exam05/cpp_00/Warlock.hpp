
#ifndef WARLOCK_HPP
#define WARLOCK_HPP
# include <iostream>
# include <string>

class Warlock{
	private:
		std::string name;
		std::string title;
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

};
#endif
