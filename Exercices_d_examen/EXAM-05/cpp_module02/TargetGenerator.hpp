#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:

		TargetGenerator(TargetGenerator const &ref);
		TargetGenerator &operator=(TargetGenerator const &ref);
		std::map<std::string, ATarget*>	listTarget;

	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *ptrATarget);
		void forgetTarget(std::string const &refATarget);
		ATarget* createTarget(std::string const &refATarget);

};
#endif