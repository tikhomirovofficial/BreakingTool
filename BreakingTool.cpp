#include "BreakingTool.h";
#include <stdio.h>

using namespace Tools;

BreakingTool::BreakingTool() : damage(DEFAULT_TOOL_DAMAGE), health(DEFAULT_TOOL_HEALTH), type(DEFAULT_TOOL_TYPE) 
{
	this->setName(DEFAULT_TOOL_NAME);
	incrementCount();	
}

BreakingTool::BreakingTool(
	const char* name, 
	const unsigned damage, 
	const unsigned health, 
	const BreakingToolType type

) : damage(damage), health(health), type(type) 
{
	this->setName(name);
	incrementCount();
}

BreakingTool::BreakingTool(BreakingTool& srcTool) : damage(srcTool.damage), health(srcTool.health), type(srcTool.type) 
{
	this->setName(srcTool.name);
	incrementCount();
}

BreakingTool::~BreakingTool() { delete[] this->name; }


// getters
char* BreakingTool::getName() const { return this->name; }
unsigned BreakingTool::getHealth() const { return this->health; }
BreakingToolType BreakingTool::getType() const { return this->type; }


// setters
void BreakingTool::setName(const char* name)  {
	int nameLength = strlen(name);
	this->name = new char[nameLength + 1];
	strcpy_s(this->name, nameLength + 1, name);
}

void BreakingTool::setHealth(unsigned health) {
	if (health > 100) {
		this->health = 100;
		return;
	}
	this->health = health;
}

// other methods
const char* BreakingTool::getTypeString() const {
	switch (this->getType())
	{
		case DRILLING: return "Drilling";
		case CUTTING: return "Cutting";
		default: return "Drilling";
	}
}

void BreakingTool::logInfo() const {
	cout << "name: " << this->name << endl;
	cout << "damage: " << this->damage << endl;
	cout << "type: " << this->type << endl;
	cout << "health: " << this->health << endl << endl;
}

void BreakingTool::incrementCount() { 
	++count; 
};

void BreakingTool::printCount() {
	cout << "BreakingTool objects count: " << count << endl;
}
