#ifndef DUMMY_HPP
#define DUMMY_HPP
#include "ATarget.hpp"

class Dummy: public ATarget{
	public:
		Dummy() { this->type = "Target Practice Dummy"; }
		~Dummy() { }
		
		ATarget* clone() const
		{
			return (new Dummy());
		}
};

#endif