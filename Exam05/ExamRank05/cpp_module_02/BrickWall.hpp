#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall: public ATarget
{
private:
	/* data */
public:
	BrickWall(/* args */);
	virtual ~BrickWall();

	virtual ATarget * clone() const;
};


#endif