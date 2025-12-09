#include "BreakingTool.h";
#include <stdio.h>

using namespace Tools;

// Конструктор по умолчанию
BreakingTool::BreakingTool() : damage(DEFAULT_TOOL_DAMAGE), health(DEFAULT_TOOL_HEALTH), type(DEFAULT_TOOL_TYPE) 
{
	this->setName(DEFAULT_TOOL_NAME);
	incrementCount();	
}

// Параметризованный конструктор
BreakingTool::BreakingTool( const char* name, const unsigned damage, const unsigned health, const BreakingToolType type
) : damage(damage), health(health), type(type) 
{
	this->setName(name);
	incrementCount();
}

// Копирующий конструктор
BreakingTool::BreakingTool(BreakingTool& srcTool) : 
	damage(srcTool.damage), 
	health(srcTool.health), 
	type(srcTool.type) 
{
	this->setName(srcTool.name);
	incrementCount();
}

// Оператор присваивания
BreakingTool& BreakingTool::operator=(const BreakingTool& src) {
	if (this == &src) {
		return *this;
	}

	damage = src.damage;
	health = src.health;
	type = src.type;

	if (src.name != nullptr) {
		this->setName(src.name);
	}
	else {
		name = nullptr;
	}

	// 5. Возвращаем *this для цепочки присваиваний (a = b = c)
	return *this;
}

// Деструктор
BreakingTool::~BreakingTool() { delete[] this->name; }

// Геттеры
char* BreakingTool::getName() const { return this->name; }
unsigned BreakingTool::getHealth() const { return this->health; }
unsigned BreakingTool::getDamage() const { return this->damage; }
BreakingToolType BreakingTool::getType() const { return this->type; }


// Сеттеры
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

// Служебные методы
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
