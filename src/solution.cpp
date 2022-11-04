#include "solution.h"
#include <stack>

using namespace std;

bool arePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}

bool isCorrect(const char* expression)
{
	stack<char> temp;

	for (int i = 0; i < strlen(expression); i++)
	{
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
			temp.push(expression[i]);
		else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
		{
			if (temp.empty() || !arePair(temp.top(), expression[i]))
				return false;
			else
				temp.pop();
		}
	}
	return temp.empty() ? true : false;
}