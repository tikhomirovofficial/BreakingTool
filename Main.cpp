#include <iostream>
#include "BreakingTool.h";
#include "ToolsStack.h"

using namespace Tools;
using std::cin;

char* getInputString(const char* label) {
	const int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];
	
	
	cout << label;
	cin.getline(buffer, BUFFER_SIZE);
	cin.ignore(0);

	int length = strlen(buffer);
	char* result = new char[length + 1];
	strcpy_s(result, length + 1, buffer);

	return result;
}

int main() {
	BreakingTool drill = BreakingTool();	
	BreakingTool secondDrill = BreakingTool("Improved drill", 10, 150, DRILLING);
	BreakingTool thirdDrill = BreakingTool(secondDrill);

	thirdDrill.setName("second improved drill");
	
	ToolStack toolsStack = ToolStack(5);

	cout << endl << endl << "::: TEST ADDING:::" << endl;
	toolsStack.push(drill);
	toolsStack.push(secondDrill);
	toolsStack.push(thirdDrill);

	cout << endl << "::: TEST PRINTING:::" << endl;
	toolsStack.print();

	cout << endl << "::: TEST DELETING:::" << endl;
	toolsStack.pop();

	cout << endl << "::: TEST PRINTING:::" << endl;
	toolsStack.print();

	cout << endl << endl << "::: TEST FIND BY NAME:::" << endl;
	
	char* findingName = getInputString("Enter the name for finding: ");
	BreakingTool *foundTool = toolsStack.findByName(findingName);
	
	if (foundTool) {
		foundTool->logInfo();
	}
	
	cout << endl << endl << "::: TEST SORTING:::" << endl;
	toolsStack.sortByDamage();
	toolsStack.print();

	return 0;
}