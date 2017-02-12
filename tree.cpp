#include "tree.h"


//using namespace std;

tree::tree() {root = nullptr;}
tree::tree(string input) {root->nodeword=input;root->count=1;}

	void tree::insertword(string input)//here we will insert a word into the tree via a selector node

	{
		//first we reset the traversal nodes*
		selector = root;
		previou = selector;
		if (root == nullptr)//if tree is null then add the new word to the tree
		{
			root = new node();
			root->nodeword = input;
			root->count = 1;
			return;

		}

		while (selector != nullptr)//otherwise as long as the selector hasn't fallen off the tree
		{

			if (input == selector->nodeword) // if the word we want to insert is equal to the current node we are at
				//then increment the count and return to the caller
			{
				selector->count++;
				cout << selector->nodeword << " had its count incremented to " << selector->count;
				return;
			}
			//otherwise we will traverse the tree by setting previou to selector and selector to its right or left child
			//depending on whether the input word is less than or greater than the current word we are at.
			else if (input < selector->nodeword)

			{
				previou = selector;
				selector = selector->Lchild;

			}
			else if (input > selector->nodeword)
			{
				previou = selector;
				selector = selector->Rchild;

			}

		}
		//if we fall of the tree however and still need ot add the word then we must add the new word
		//we will make a new node and have it contain the new word and have a count of 1;
		//we then will set previou's child pointer to the new word we made
		//the pointer will be a left or right child depdning on whether the input is less than or greater than the previou nodeword
		node* newleaf = new node();
		newleaf->nodeword = input;
		newleaf->count = 1;
		if (input < previou->nodeword)
		{
			previou->Lchild = newleaf;

			cout << newleaf->nodeword << " was added with a count of " << newleaf->count << "to the left of " << previou->nodeword;

			return;

		}
		else
		{
			previou->Rchild = newleaf;
			cout << newleaf->nodeword << " was added with a count of " << newleaf->count << "to the right of " << previou->nodeword;
			return;
		}



	}
	void tree::removeword(string input) // here we will remove a word from the tree
	{
		//first we reset the selector and previou nodes*
		selector = root;
		previou = selector;

		while (selector != nullptr &&input != selector->nodeword)//while we havent fallen off of the tree and the input isnt equal to the 
			//curent node we are at (selector)
		{

			if (input < selector->nodeword) // keep testing for if the string to remove is less than or greater than the current
				//node we are at and traversing the list based on that comparison 
			{
				previou = selector;
				selector = selector->Lchild;
			}
			else
			{
				previou = selector;
				selector = selector->Rchild;
			}

		}
		//if we found the right string to delete
		if (selector == nullptr) // if we reach the end of the list let he user know the node doesn't exist
		{
			cout << (" the string you whished to delete is not in the tree ");
			return;
		}

		else if (selector->count == 1) // if the correct node has 1 count left we will find the max node to the left of the current node that equaled 
			// the string to delete and then we will switch the max value we find with the current node and remove the reference to the max value 
			//in the left side of the tree and if needed reattach them to the new reassigned node.
			//there are three subcases
		{
			if (selector->Lchild == nullptr&selector->Rchild == nullptr) // subcase one is when the node found to be deleted has no children
				//simply delete the selector and reassign the previou child pointer
			{

				if (input < previou->nodeword)
				{
					previou->Lchild = nullptr;
					delete selector;

				}
				else
				{
					previou->Rchild = nullptr;
					delete selector;
				}
				cout << (" the word " + input + " was deleted from the tree ");
				return;

			}
			else if (selector->Rchild != nullptr) //if the selector has a non null right child then we must traverse the right end of the node
				//to delete going right once and then traversing left for until we find the end of the list, when we find the left end of the 
				//right portion of the node to delete we will switch the value of the far left node with the node to delete and set the right child
				//of the node moved to the left child of its parent.

			{
				node* temp = selector;


				selector = selector->Rchild;
				while (selector->Lchild != nullptr)
				{
					previou = selector;
					selector = selector->Lchild;
				}

				temp->nodeword = selector->nodeword;
				temp->count = selector->count;


				previou->Lchild = selector->Rchild;
				cout << " the word " << input << " was deleted from the tree ";
				return;
			}
			else
				//here is the same story as before except now because the right child of the node to delete is null we must go through the left
				//child of the node to delete and then continually going right down the tree until we hit a nullptr right child. Then we switch the values
				//and have the left child of the last rightchild in the branch now be the right child of the parent of the last right child in the
				//left child of the node to delete
			{
				node* temp = selector;


				selector = selector->Lchild;
				while (selector->Rchild != nullptr)
				{
					previou = selector;
					selector = selector->Rchild;
				}

				temp->nodeword = selector->nodeword;
				temp->count = selector->count;


				previou->Rchild = selector->Lchild;
				cout << " the word " << input << " was deleted from the tree ";
				return;
			}




		}
	}
	void tree::searchstring(string input)//here we will search the tree for a node to print out
	{
		//reset the traversal nodes
		selector = root;
		previou = selector;
		while (selector != nullptr &input != selector->nodeword) // while we haven't found the word or fallen off the list

		{

			if (input < selector->nodeword)  //while searching the list compare the input to the traversed nodes and modify the
				//traversal path based on those results.
			{
				previou = selector;
				selector = selector->Lchild;

			}
			else
			{
				previou = selector;
				selector = selector->Rchild;
			}


		}
		if (selector == nullptr) // if if we fell off the tree then the word isnt in the list
		{
			cout<<" ";
			return;
		}
		//otherwise print our the found string and its count
		
		cout<<" the word"<< selector->nodeword<< "is on the tree" << " with a count of " << selector->count;

	}
	void tree::minword()//here we will find the minimum word in the set
	{
		//reset teh traversal nodes
		selector = root;
		previou = selector;
		if (root == nullptr) // if the root is nullptr then print out a blank line
		{
			cout << " ";
			return;
		}
		else//otherwise
		{
			while (selector != nullptr)//will we arent at the end of the list keep traversing the list through the left children
			{
				previou = selector;
				selector = selector->Lchild;
			}
			cout << " the minimum of the set is " << previou->nodeword; // when we find the last left child then print out its contents
		}

	}
	void tree::maxword()//this function is the exact same as the minimum method except we traverse through the right child to the end of the 
		//tree and when we hot the end we print out the last right childs contents
	{
		previou = selector = root;
		//previou = selector;
		if (root == nullptr)
		{
			cout << " ";
			return;
		}
		else
		{
			while (selector != nullptr)
			{
				previou = selector;
				selector = selector->Rchild;
			}
			cout << " the maximum of the set is " << previou->nodeword;
		}
	}
	void tree::nextstring(string input)//here we will find a given string and when we find it we will print out its sucessor
	{
		//reset the pointers
		selector = root;
		previou = selector;
		while (selector != nullptr ) //while we havent fallen off the list we will traverse the list testing for equality of the
			//curent node and the input we are trying to get to, if we find said input and its right child isnt nullptr then we
			//simply print out its right child word, however if the word we found has no right child pointer and is the left child
			//of its parent then we will print out its parent's word and count as the successor. If the word found has
			//no right child pointer and is the right child of the parent then we output a blank line
			//if we fall off the lsit then output a blank line.
			
		{
			if (input == selector->nodeword&&selector->Rchild!=nullptr) 
			{
				cout<< selector->Rchild->nodeword << " is the sucessor of " << selector->nodeword <<" with a count of " << selector->Rchild->count;			
				return;
			}
			else if (selector->Rchild == nullptr) 
			{	
				if (input < previou->nodeword) 
				{	
					cout<<previou->nodeword<< " is the sucessor of " << selector->nodeword <<" with a count of " << previou->count;
				}
				else 
				{
					cout << " ";
					return;
				}
			}
			if (input < selector->nodeword)
			{
				previou = selector;
				selector = selector->Lchild;

			}
			else
			{
				previou = selector;
				selector = selector->Rchild;
			}
			


		}
		if (selector == nullptr) // if if we fell off the tree then the word isnt in the list
			{
			cout << "  ";
			}

		
		
			
	}
	void tree::previousword(string input)//literally the same code as nextword just changed to use left child pointers instead 
		//of right child pointers
	{
		selector = root;
		previou = selector;
		while (selector != nullptr)

		{
			if (input == selector->nodeword&&selector->Lchild!=nullptr) 
			{
				cout<< selector->Lchild->nodeword << " is the predecesor of " << selector->nodeword <<" with a count of " << selector->Lchild->count;			
				return;
			}
			else if (selector->Lchild == nullptr) 
			{	
				if (input > previou->nodeword) 
				{	
					cout<<previou->nodeword<< " is the predecesor of " << selector->nodeword <<" with a count of " << previou->count;
				}
				else 
				{
					cout << " ";
					return;
				}
			}
			if (input < selector->nodeword)
			{
				previou = selector;
				selector = selector->Lchild;

			}
			else
			{
				previou = selector;
				selector = selector->Rchild;
			}


		}
		if (selector == nullptr) // if if we fell off the tree then the word isnt in the list
		{
			cout << "  ";
		}

		

	}
	node* tree::printall(node* currentkey)//prints all of the nodes in a tree, recursivley 
		//it just tests to see if the left child is null and send the left or right child to the recursive printall function
		//depending on whether one is null or not. When it finds the last left node it will print that node and look for that far left
		//node's right child and print it out at the end it will return the caller and the next level up will print and look for
		//its right child and print that out, returning to the caller as well. This is happen recursivley. 
	{
		
			if (currentkey->Lchild != nullptr)
			{
				printall(currentkey->Lchild);
				cout<<currentkey->nodeword <<" with a count of "<<currentkey->count;
				

			}
			if(currentkey!=nullptr)
			{
				printall(currentkey->Rchild);
				cout<<currentkey->nodeword <<" with a count of "<<currentkey->count;
				

			}
			return currentkey;
		
			
		
	}
	void tree::resettree() //resets the entire tree to null
	{

		root = nullptr;
		return;
	}
void tree::insert(string input) {insertword(input);}
void tree::remove(string input) {removeword(input);}
void tree::search(string input) {searchstring(input);}
void tree::min(string input) {minword();}
void tree::max(string input) {maxword();}
void tree::next(string input) {nextstring(input);}
void tree::previous(string input) {previousword(input);}
void tree::print() {printall(root);}
void tree::reset() { resettree(); }
