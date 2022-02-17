#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	this->name = "Fwoosh";
	this->effects = "Fwooshed";
}

Fwoosh::~Fwoosh() {}

ASpell * Fwoosh::clone() const { return new Fwoosh(); }