#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
struct node //this is the node data structure
	//it contains pointers to its left and right child and the payload
	//the payload consists of the count of the word and the string for holding the word itself.
{

	node* Rchild;
	node* Lchild;
	int count;
	string nodeword;
};

class tree
{


private:
	
	void insertword(string input) ; // will insert word into binary tree
	void removeword(string input) ; // will remove word from binary tree
	void searchstring(string dat); // will search binary tree for a word and print it out
	void minword(); // will find the minimum word in a tree
	void maxword(); // will find the maximum word in a tree
	void nextstring(string input); //will print out hte next word in the tree
	void previousword(string input); // will print out the previous of a word in the string
	node* printall(node* currentkey); // will print all words in the tree
	void resettree(); // will reset to tree to null
public:
	
	tree();
	tree(string input);
	~tree();
	node* root;	//the top of the tree
	node* previou; // previous node for traversing the tree
	node* selector; // selector for traversing the tree
	void insert(string input);
	void remove(string input);
	void search(string input);
	void min(string input);
	void max(string input);
	void next(string input);
	void previous(string input);
	void print();
	void reset();



};