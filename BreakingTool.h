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
			// default constructor
			BreakingTool();

			// parametrized constructor
			BreakingTool(
				const char* name, 
				const unsigned damage,
				const unsigned health,
				const BreakingToolType type
			);
			
			// copying constructor
			BreakingTool(BreakingTool &srcTool);

			// destructor
			~BreakingTool();

			// health setter
			void setHealth(unsigned health);

			// name getter
			char* getName() const;

			// name setter
			void setName(const char* name);

			// damage getter
			unsigned getDamage() const;

			// health getter
			unsigned getHealth() const;
			
			// get stringified type
			const char* getTypeString() const;

			// breaking tool type getter			
			BreakingToolType getType() const;

			// info logger
			void logInfo() const;

			// increment global count objects
			static void incrementCount();

			// print count of instances
			static void printCount();

	};
}

