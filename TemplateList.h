/*
 *     Author : The Alex Camejo
 *     Last Modifed : Decemeber 17 , 2013 5:09PM EST
 *     Description: A simple template link list that
 *                  utilizes "smart nodes" to complete
 *                  list methods.Tested using CATCH
 *                  Unit testing Framework by philsquared
 *                  (catch includes not included)
 */

#ifndef _TEMPLATELIST_H_
#define _TEMPLATELIST_H_
#include <iostream>

template <class T> class TLinkedList{
	//class private members
	int listSize;  //keeps track of listSize when remove(), append(), or prepend() are used.
	
	public:

	struct node{
	  //node member variables		
	  T data;
	  node * next;
		
	  //node constructors
	node(T value):data(value), next(NULL){}
	node():data(NULL) , next(NULL){}

	  //node member functions
	  void append(T value);
	  void remove(T value);
	  node * search(T value);
	  void print();
	  std::string toString(std::string output);

	};

	//class constructor
	TLinkedList(): head(NULL) , listSize(0) {}	
	
	//class public member variables
	node * head;
	
	//class member variables
	void prepend(T value);  //adds a node to the beginning of the list
	void append(T value);   //adds a node to the end of the list
	void remove(T value);   //removes a node with the selected data value.
	node * search(T value);      //searches for a node with the selected data value and returns it
	int size();             //gets listSize
	void print();           //prints the entire list in order of how the nodes were added (prepended nodes at the front, etc.)
	std::string toString(); //Returns the entire list as a string in the same order as print.
	node * pop(T value);    //Returns node and deletes it from the list
};

#endif // _TEMPLATELIST_H_
		
		
