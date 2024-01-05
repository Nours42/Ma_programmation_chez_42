#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it_begin = this->listTarget.begin();
	std::map<std::string, ATarget*>::iterator it_end = this->listTarget.end();
	while (it_begin != it_end)
	{
		delete it_begin->second;
		++it_begin;
	}
	this->listTarget.clear();
}

void TargetGenerator::learnTargetType(ATarget *ptrATarget)
{
	if (ptrATarget)
		listTarget.insert(std::pair<std::string, ATarget *>(ptrATarget->getType(), ptrATarget->clone()));
}

void TargetGenerator::forgetTarget(std::string const &TargetName)
{
	std::map<std::string, ATarget*>::iterator it = listTarget.find(TargetName);
	if (it != listTarget.end())
		delete it->second;
	listTarget.erase(TargetName);
}

ATarget* TargetGenerator::createTarget(std::string const &TargetName)
{
	std::map<std::string, ATarget*>::iterator it = listTarget.find(TargetName);
	if (it != listTarget.end())
		return listTarget[TargetName];
	return NULL;
}