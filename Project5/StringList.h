/*
 * StringList.h
 *
 *  Created on: Jul 14, 2018
 *      Author: timkuelker
 */

#include <string>

#ifndef STRINGLIST_H_
#define STRINGLIST_H_

using namespace std;

class StringList
{
private:
	struct ListNode
	{
		string list;					//data inside ListNode
		ListNode *next;					//recursion of struct ListNode containg "next" information
	};

	ListNode *head;						//head pointer to ListNode

public:
	StringList();						//constructor

	void insertFront(string);
	void insertBack(string);
	void deleteFront();
	void deleteBack();

	void display();

	~StringList();						//destructor
};

#endif /* STRINGLIST_H_ */

