#include <iostream>
#include "BreakingTool.h";

using namespace Tools;


int main() {
	// use default constructor
	BreakingTool drill = BreakingTool();	

	// use parametrized constructor
	BreakingTool secondDrill = BreakingTool("Improved drill", 10, 150, DRILLING);

	// use copying constructor
	BreakingTool thirdDrill = BreakingTool(secondDrill);
	cout << endl;

	thirdDrill.setName("Renamed drill");

	drill.logInfo();
	secondDrill.logInfo();
	thirdDrill.logInfo();

	
	secondDrill.logInfo();

	BreakingTool::printCount();


	return 0;
}