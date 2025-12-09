#pragma once

#include <iostream>;

namespace Tools {
	using std::cout;
	using std::endl;

	enum BreakingToolType {
		DRILLING,
		CUTTING,
	};

	inline const char* DEFAULT_TOOL_NAME = "Drill";
	inline const unsigned int DEFAULT_TOOL_DAMAGE = 5;
	inline const unsigned int DEFAULT_TOOL_HEALTH = 100;
	inline const BreakingToolType DEFAULT_TOOL_TYPE = BreakingToolType::DRILLING;


	class BreakingTool {
		private:
			static inline unsigned count;
			char* name;
			unsigned damage;
			unsigned health;
			BreakingToolType type;

		public:
			// Конструктор по умолчанию
			BreakingTool();

			// Параметризованный конструктор
			BreakingTool(
				const char* name, 
				const unsigned damage,
				const unsigned health,
				const BreakingToolType type
			);
			
			// Копирующий конструктор
			BreakingTool(BreakingTool &srcTool);

			// Перегрузка оператора присваивания
			BreakingTool& operator=(const BreakingTool& other);

			// Деструктор
			~BreakingTool();

			// Установка здоровья
			void setHealth(unsigned health);

			// Получение имени
			char* getName() const;

			// Установка имени
			void setName(const char* name);

			// Получение урона
			unsigned getDamage() const;

			// Получение здоровья
			unsigned getHealth() const;
			
			// Получить тип инструмента в виде строки
			const char* getTypeString() const;

			// Получить тип инструмента		
			BreakingToolType getType() const;

			// Вывод информации
			void logInfo() const;

			// Увеличить количество объектов класса
			static void incrementCount();

			// Вывести количество объектов класса
			static void printCount();
	};
}

