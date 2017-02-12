// Binary tree.cpp : Defines the entry point for the console application.
//
#include "tree.h"




using namespace std;
class console
{
public:	
	tree* binarytree = new tree(); // make a new tree to work with

	 void main()
	{
		cout << (" welcome to my binary tree string console interface! ");
		string in = ""; // string for getting user input
		while (true) // keep the program running

		{
			cout << ("\n please input a command or type \"help\" for options "); //prompt for input
			cin >> in; // store input
			if (in == "help") // if the user wants help with commnads give them the information
			{
				cout << "The following commands are allowed for the tree " << "\n" << "insert- will insert a word to the list and print it with the count "
					<< "\n" << "delete- which will delete one count of the word from the list,when all counts of a word are deleted then the word will be deleted from the list "
					<< "\n" << "search- which will search for and print the desired string as well as its count" << "\n" << "print- which will print the entire tree"
					<< "out as well as the nodes counts " << "\n" << "census-which will print the number of unique words of the list out" << "\n" << "reset- which will "
					<< " reset the binary tree to a null value" << "\n" << "please note that whenever you add a word or delete a word or even search for a word"
					<< "the program will format your String you input and trim any leading or trailing white space and then remove any punctuation from the string, also all word"
					<< " are set to lower case" << "\n" << "if you whish to end the program simply type end";

			}
			//here we test for if the user wants to do one of the 10 commands for the binary tree and executre the correct command if the correct
			//string is inputed through the console. 
			else if (in == "insert") { cout << " please input a single string to be added to the tree \n "; cin >> in; binarytree->insert(in); continue; }
			else if (in == "delete") { cout << " please input a single string to be deleted to the tree \n "; cin >> in; binarytree->remove(in); continue; }
			else if (in == "search") { cout << " please input a single string to be searched for in the tree \n "; cin>>in;binarytree->search(in);continue;}
			else if (in == "list") { cout << " the tree contains the following words "; binarytree->print(); continue; }
			else if (in == "reset") { binarytree->reset(); cout << " the tree was reset to null "; continue; }
			else if (in == "end") { exit(0); }
			else if (in == "next") { cout << "please input a word to get the sucessor of."; cin >> in; binarytree->next(in); continue; }
			else if (in == "previous") { cout << "please input a word to get the predecesor of."; cin >> in; binarytree->previous(in); continue; }
			else if (in == "max") { binarytree->max(in); continue; }
			else if (in == "min") { binarytree->min(in); continue; }
			
			else { cout << " unknown command please type a valid command- type help to display commands accepted "; continue; }



		}
		
	}

};