#include <iostream>

#include "binaryTree.h"
#include "OperationParser.h"
using namespace std;

/*
insert 12 qqq qqq
insert 5 www www
insert 45 eee eee
insert 120 rrr rrr
insert 15 ttt ttt
insert 45 yyy yyy
insert 12 uuu uuu
insert 55 iii iii
insert 30 ooo ooo
insert 10 ppp ppp
insert 50 aaa aaa
insert 150 sss sss
find 3
find 15
find 444
find 120
traverseInorder
delete 45
traverseInorder
*/


int main()
{
    BinaryTree students;
    OperationParser parser;

    //asks for operation (insert, delete, find, traverseInorder, exit)
    cin >> parser;

    //asks the user to enter an operation till entering exit
    while (parser.getOperation() != "exit")
	{
		parser.doOperation(students);
		//asks for operation (insert, delete, find, traverseInorder, exit)
		cin >> parser;
	}
    return 0;
}
