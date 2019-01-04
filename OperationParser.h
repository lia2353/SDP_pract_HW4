#ifndef OPERATIONPARSER_H_INCLUDED
#define OPERATIONPARSER_H_INCLUDED

#include "binaryTree.h"
#include<string>

using namespace std;

class OperationParser
{
private:
	string operation;
public:
	OperationParser();
	string getOperation() const;
	void doOperation(BinaryTree&);
	friend istream& operator>>(istream&, OperationParser&);
};

//the default operation for the parser is insert
OperationParser::OperationParser()
{
	operation = "insert";
}

inline string OperationParser::getOperation() const
{
	return operation;
}

//receives a string with an operation and parses it to its respective function
//if "exit" program will end in main's while clause
inline void OperationParser::doOperation(BinaryTree& students)
{
	if(operation == "insert")
	{
		students.insert();
	}
	else if(operation == "delete")
	{
		students.deleteStudent();
	}
	else if(operation == "find")
    {
        students.find();
    }
    else if (operation == "traverseInorder")
    {
        students.traverse();
    }
	else
	{
		operation = "exit";
	}
}

istream& operator>>(istream& is, OperationParser& parcer)
{
	is >> parcer.operation;
	return is;
}

#endif // OPERATIONPARSER_H_INCLUDED
