/*
 * StringList.cpp
 *
 *  Created on: Jul 14, 2018
 *      Author: timkuelker
 */
#include <iostream>
#include "StringList.h"

using namespace std;

StringList::StringList()
{
	head = nullptr;
}

void StringList::insertFront(string list)
{
	ListNode *newNode;													//Point to new node

	newNode = new ListNode;												//allocating a new node and storing newlist there

	newNode-> next = nullptr;											//Removing the next pointer
	newNode-> list = list;												//newNode
	newNode-> next = head;												//reinitializing the inserted ptr to head
	head = newNode;

	cout << "Inserting Node in Front: ";
}

void StringList::insertBack(string list)
{
	ListNode *newNode;													//To point to a new node
	ListNode *nodePtr;													//To move through the list

	newNode = new ListNode;												//Allocate a new node and store new list there
	newNode-> list = list;
	newNode-> next = nullptr;

	if (!head)															//If no nodes in list, make newNode the first node
		head = newNode;
	else																//otherwise, insert newNode at end.
	{
		nodePtr = head;													//initialize nodePtr to head of list

		while(nodePtr-> next)											//find the last node in the list
			nodePtr = nodePtr-> next;

		nodePtr-> next = newNode;										//insert newNode as the last node.
	}
	cout << "Inserting Node in Back : ";
}

void StringList::deleteFront()
{
	if(head == nullptr)													//if trying to delete from empty list
	{
		cout << "StringList::deleteFront() called with empty list\n";
		return;
	}

	ListNode *nodePtr = head-> next;									//setting new nodePtr to next node
	delete head;														//deleting old head
	head = nodePtr;														//setting head as next nodePtr

	cout << "Deleting Front Node: ";
}

void StringList::deleteBack()
{
	if (head == nullptr)												//if trying to delete from empty list
	{
		cout << "StringList::deleteBack() called with empty list\n";
		return;
	}

	ListNode *nodePtr = head;											//to move through list
	ListNode *prevNode;													//to point to previous node

	if(nodePtr-> next == nullptr)										//if one item in list, delete head, set head to null ptr
	{
		delete head;
		head = nullptr;
	}
	else
	{
		while(nodePtr-> next != nullptr)								//while next isnt nullptr, move through list until end
		{
			prevNode = nodePtr;
			nodePtr = nodePtr-> next;
		}
		delete prevNode-> next;											//delete last node
		prevNode-> next = nullptr;										//adding the nullptr on end
	}
	cout << "Deleting Back Node : ";
}

void StringList::display()												//displaying nodes
{
	ListNode *nodePtr;

	nodePtr = head;

	while(nodePtr)
	{
		cout << nodePtr-> list << " ";
		nodePtr = nodePtr-> next;
	}
	cout << endl << endl;
}

StringList::~StringList()
{
	ListNode *nodePtr;													//To traverse the list
	ListNode *nextNode;													//To point to the next node

	nodePtr = head;														//Position nodePtr at head of list

	while (nodePtr != nullptr)											//while nodePtr is not at end of list
	{
		nextNode = nodePtr-> next;										//Save ptr to the next node
		delete nodePtr;													//delete current node
		nodePtr = nextNode;												//Position nodePtr at next node
	}
	cout << "\nALL NODES HAVE BEEN DELETED!";
}

