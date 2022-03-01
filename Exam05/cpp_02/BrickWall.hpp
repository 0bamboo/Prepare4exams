#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
# include "ATarget.hpp"

class BrickWall : public ATarget{
	public:
		BrickWall()
		{
			this->type = "Inconspicuous Red-brick Wall";
		}
		~BrickWall() { }

		ATarget* clone() const
		{
			return (new BrickWall());
		}
};
#endif
