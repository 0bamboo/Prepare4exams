#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"

#include <vector>

class TargetGenerator
{
private:
	std::vector<ATarget*> tags;

	TargetGenerator(const TargetGenerator &);
	TargetGenerator &operator=(const TargetGenerator &);
public:
	TargetGenerator(/* args */);
	~TargetGenerator();

	void learnTargetType(ATarget*);
	void forgetTargetType(std::string const &);
	ATarget* createTarget(std::string const &);
};

#endif