/*

	bst.cpp

	Manage binary tree structure

	Author: Brooke Czerwinski
	Date: 12/1/2020
	Class: CS 163
	Program #4

*/


#include "bst.h"

Vertex::Vertex()
{
	videoData = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}



Vertex::~Vertex()
{
	if (videoData != nullptr)
	{
		delete videoData;
		videoData = nullptr;
	}
	leftChild = nullptr;
	rightChild = nullptr;
}



ClassVertex::ClassVertex()
{
	classSubRoot = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}



ClassVertex::~ClassVertex()
{
	if (this->classSubRoot != nullptr)
	{
		classSubRoot->videoData = nullptr;
		delete classSubRoot;
		classSubRoot = nullptr;
	}
	leftChild = nullptr;
	rightChild = nullptr;
}



BST::BST()
{
	rootName = nullptr;
	rootClass = nullptr;
}



BST::~BST()
{
	if (rootName != nullptr)
	{
		deleteBST(rootName);
		delete rootName;
		rootName = nullptr;
	}
	if (rootClass != nullptr)
	{
		deleteBST_Class(rootClass);
		delete rootClass;
		rootClass = nullptr;
	}
}



int BST::deleteBST()
{
	int successValue = 0;

	if (rootName != nullptr)
	{
		successValue = deleteBST(rootName);
		rootName = nullptr;
	}

	if (rootClass != nullptr)
	{
		successValue = deleteBST_Class(rootClass);
		rootClass = nullptr;
	}

	return successValue;
}



int BST::deleteBST(Vertex*& root)
{
	int successValue = 0;
	// Use postorder traversal
	if (root != nullptr)
	{
		// First visit the left node
		if (root->leftChild != nullptr)
		{
			successValue = deleteBST(root->leftChild);
			root->leftChild = nullptr;
		}
		// Then visit the right node
		if (root->rightChild != nullptr)
		{
			successValue = deleteBST(root->rightChild);
			root->rightChild = nullptr;
		}
		// Then delete the node itself;
		delete root;
		root = nullptr;
		
		if (root == nullptr)
		{
			successValue = 1;
		}
	}

	return successValue;
}



int BST::deleteBST_Class(ClassVertex*& root)
{
	int successValue = 0;

	if (root != nullptr)
	{
		if (root->leftChild != nullptr)
		{
			successValue = deleteBST_Class(root->leftChild);
			root->leftChild = nullptr;
		}
		if (root->rightChild != nullptr)
		{
			successValue = deleteBST_Class(root->rightChild);
			root->rightChild = nullptr;
		}
		successValue = deleteBST_Class(root->classSubRoot);
		root->classSubRoot = nullptr;
		delete root;
		root = nullptr;

		if (root == nullptr)
		{
			successValue = 1;
		}
	}

	return successValue;
}



int BST::deleteBST_Class(Vertex*& root)
{
	int successValue = 0;
	// Use postorder traversal
	if (root != nullptr)
	{
		// First visit the left node
		if (root->leftChild != nullptr)
		{
			successValue = deleteBST_Class(root->leftChild);
			root->leftChild = nullptr;
		}
		// Then visit the right node
		if (root->rightChild != nullptr)
		{
			successValue = deleteBST_Class(root->rightChild);
			root->rightChild = nullptr;
		}
		// Video data will already get deleted in the deleteBST function
		// so just set it to nullptr here before deleting the root
		root->videoData = nullptr;
		delete root;
		root = nullptr;
		
		if (root == nullptr)
		{
			successValue = 1;
		}
	}

	return successValue;
}



int BST::addVideo(Video& newVideo)
{
	int successValue = 0;
	Video* videoToAdd = new Video(newVideo);

	successValue = addVideoByName(rootName, *videoToAdd);
	
	// If the name already exists then successValue will still be 0 at this point
	if (successValue != 0)
	{
		successValue = addVideoByClass(rootClass, *videoToAdd);
	}
	// If the success Value is 0 then we should delete the video we allocated above
	else
	{
		delete videoToAdd;
		videoToAdd = nullptr;
	}

	return successValue;
}



// Recursive add function
int BST::addVideoByName(Vertex*& root, Video& newVideo)
{
	int successValue = 0;
	int comparisonValue = 0;

	// Use preorder traversal
	// First attend to the node you're at
	// Base case: root is null
	if (root == nullptr)
	{
		root = new Vertex;
		root->videoData = &newVideo;
		successValue = 1;
	}
	else
	{
		comparisonValue = newVideo.compareVideoNames(*root->videoData);
		// Then go to the left node
		if (comparisonValue < 0)
		{
			successValue = addVideoByName(root->leftChild, newVideo);
		}
		else if (comparisonValue == 0)
		{
			// Duplicate names are not allowed
			successValue = 0;
		}
		// Otherwise go to the right node
		else
		{
			successValue = addVideoByName(root->rightChild, newVideo);
		}
	}

	return successValue;
}



// Recursive add function
int BST::addVideoByClass(ClassVertex*& root, Video& newVideo)
{
	int successValue = 0;
	int comparisonValue = 0;

	// Use preorder traversal
	// First attend to the node you're at
	// Base case: root is null
	if (root == nullptr)
	{
		root = new ClassVertex;
		root->classSubRoot = new Vertex;
		// Save the video data as a pointer to the incoming video
		root->classSubRoot->videoData = &newVideo;
		successValue = 1;
	}
	else
	{
		comparisonValue = newVideo.compareClassNames(*root->classSubRoot->videoData);
		// Then go to the left node
		if (comparisonValue < 0)
		{
			successValue = addVideoByClass(root->leftChild, newVideo);
		}
		else if (comparisonValue == 0)
		{
			successValue = addVideoByName(root->classSubRoot, newVideo);
		}
		// Then go to the right node
		else if (comparisonValue > 0)
		{
			successValue = addVideoByClass(root->rightChild, newVideo);
		}
	}

	return successValue;
}



int BST::searchByName(Video& retrievedVideoDetails, const char nameToSearch[]) const
{
	return searchByName(retrievedVideoDetails, nameToSearch, rootName);
}



int BST::searchByName(Video& retrievedVideoDetails, const char nameToSearch[], Vertex* root) const
{
	int successValue = 0;
	int comparisonValue;

	// Look through the tree until either
	// Matching data is found
	// OR
	// We know that it's not present
	if (root != nullptr)
	{
		comparisonValue = root->videoData->compareVideoNames(nameToSearch);
		if (comparisonValue < 0)
		{
			if (root->leftChild != nullptr)
			{
				successValue = searchByName(retrievedVideoDetails, nameToSearch, root->leftChild);
			}
		}	
		else if (comparisonValue == 0)
		{
			successValue = retrievedVideoDetails.copyVideo(*root->videoData);
		}
		else if (comparisonValue > 0)
		{
			if (root->rightChild != nullptr)
			{
				successValue = searchByName(retrievedVideoDetails, nameToSearch, root->rightChild);
			}
		}
	}

	return successValue;
}



int BST::retrieveClassName(const char nameToSearch[], char classNameRetrieved[], Vertex* root) const
{
        int successValue = 0;
        int comparisonValue;

        if (root != nullptr)
        {
                comparisonValue = root->videoData->compareVideoNames(nameToSearch);
                if (comparisonValue < 0)
                {
                        if (root->leftChild != nullptr)
                        {
                                successValue = retrieveClassName(nameToSearch, classNameRetrieved, root->leftChild);
                        }
                }
                else if (comparisonValue == 0)
                {
                        successValue = root->videoData->copyClassName(classNameRetrieved);
                }
                else if (comparisonValue > 0)
                {
                        if (root->rightChild != nullptr)
                        {
                                successValue = retrieveClassName(nameToSearch, classNameRetrieved, root->rightChild);
                        }
                }
        }

        return successValue;
}



int BST::removeByName(const char nameToRemove[])
{
	int successValue = 0;
	char classToRemove[MAX_CHAR];

	successValue = retrieveClassName(nameToRemove, classToRemove, rootName);

	if (successValue != 0)
	{
		successValue = removeByName_Class(nameToRemove, rootClass, classToRemove);
		if (successValue != 0)
		{
			successValue = removeByName(nameToRemove, rootName);
		}
	}

	return successValue;
}



int BST::removeByName(const char nameToRemove[], Vertex*& root)
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{
		comparisonValue = root->videoData->compareVideoNames(nameToRemove);

		if (comparisonValue == 0)
		{
			successValue = deleteFromBST(root);
		}
		else if (comparisonValue < 0)
		{
			successValue = removeByName(nameToRemove, root->leftChild);
		}
		else
		{
			successValue = removeByName(nameToRemove, root->rightChild);
		}
	}

	return successValue;
}



int BST::removeByName_Class(const char nameToRemove[], ClassVertex*& root, const char classToRemove[])
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{
		comparisonValue = root->classSubRoot->videoData->compareClassNames(classToRemove);

		if (comparisonValue < 0)
		{
			successValue = removeByName_Class(nameToRemove, root->leftChild, classToRemove);
		}
		else if (comparisonValue == 0)
		{
			// WE NEED TO REMOVE A NODE IN THIS SUBROOT
			successValue = removeByName_Class(nameToRemove, root->classSubRoot);

			// If, after removal, the subRoot is empty
			// Then we need to delete the ClassNode and restructure the BST
			if (root->classSubRoot == nullptr)
			{
				successValue = deleteFromBST_Class(root);
			}
		}
		else
		{
			successValue = removeByName_Class(nameToRemove, root->rightChild, classToRemove);
		}
	}

	return successValue;
}



int BST::removeByName_Class(const char nameToRemove[], Vertex*& root)
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{
		comparisonValue = root->videoData->compareVideoNames(nameToRemove);

		if (comparisonValue == 0)
		{
			root->videoData = nullptr;
			successValue = deleteFromBST_Class(root);
		}
		else if (comparisonValue < 0)
		{
			successValue = removeByName_Class(nameToRemove, root->leftChild);
		}
		else
		{
			successValue = removeByName_Class(nameToRemove, root->rightChild);
		}
	}

	return successValue;
}



int BST::deleteFromBST_Class(ClassVertex*& root)
{
	int successValue = 0;
	ClassVertex* holdVertex;
	
	if (root != nullptr)
	{
		// If there are no children
		if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
		{
			deleteBST_Class(root->classSubRoot);
			delete root;
			root = nullptr;

			successValue = 1;
		}
		// If the node has only one child
		// If there is only a leftChild
		else if ((root->leftChild != nullptr) && (root->rightChild == nullptr))
		{
			holdVertex = root;
			root = root->leftChild;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there is only a rightChild
		else if ((root->rightChild != nullptr) && (root->leftChild == nullptr))
		{
			holdVertex = root;
			root = root->rightChild;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there are two children
		else if ((root->rightChild != nullptr) && (root->leftChild != nullptr))
		{
			// Find the smallest value in the right subtree
			// (inorder successor)
			if (root->classSubRoot != nullptr)
			{
				deleteBST_Class(root->classSubRoot);
				root->classSubRoot = nullptr;
			}
			
			// Will set the root->classSubRoot pointer to the IOS
			successValue = findDeleteIOS_Class(root->rightChild, root->classSubRoot);
		}
	}

	return successValue;
}



// Find the inorder successor (the smallest value in the given subtree)
int BST::findDeleteIOS_Class(ClassVertex*& root, Vertex*& inorderSuccessor)
{
	int successValue = 0;

	// Go left until you cant anymore
	// That will be the smallest value in this tree
	if (root->leftChild != nullptr)
	{
		successValue = findDeleteIOS_Class(root->leftChild, inorderSuccessor);
	}
	else
	{
		inorderSuccessor = root->classSubRoot;
		root->classSubRoot = nullptr;
		successValue = deleteFromBST_Class(root);
		root = nullptr;
	}
	return successValue;
}



int BST::removeByClass(const char classToRemove[])
{
	int successValue = 0;

	successValue = removeByClass_Class(classToRemove, rootClass);
	if (successValue != 0)
	{
		successValue = removeByClass(classToRemove, rootName);
	}

	return successValue;	
}



int BST::removeByClass(const char classToRemove[], Vertex*& root)
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{
		// First visit the left child
		if (root->leftChild != nullptr)
		{
			successValue = removeByClass(classToRemove, root->leftChild);
		}
		// Then visit the right child
		if (root->rightChild != nullptr)
		{
			successValue = removeByClass(classToRemove, root->rightChild);
		}
		// Then check to see if the class matches
		// And delete it if it does
		comparisonValue = root->videoData->compareClassNames(classToRemove);

		if (comparisonValue == 0)
		{
			successValue = deleteFromBST(root);
		}
	}

	return successValue;
}



int BST::removeByClass_Class(const char classToRemove[], ClassVertex*& root)
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{
		
		if (root->leftChild != nullptr)
		{
			successValue = removeByClass_Class(classToRemove, root->leftChild);
		}
		else if (root->rightChild != nullptr)
		{
			successValue = removeByClass_Class(classToRemove, root->rightChild);
		}

		comparisonValue = root->classSubRoot->videoData->compareClassNames(classToRemove);

		if (comparisonValue == 0)
		{
			successValue = deleteBST_Class(root->classSubRoot);
			if (successValue == 1)
			{
				successValue = deleteFromBST_Class(root);
			}
		}
	}

	return successValue;
}



int BST::deleteFromBST(Vertex*& root)
{
	int successValue = 0;
	Vertex* holdVertex;
	
	if (root != nullptr)
	{
		// If there are no children
		if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
		{
			delete root->videoData;
			root->videoData = nullptr;
			delete root;
			root = nullptr;

			successValue = 1;
		}
		// If the node has only one child
		// If there is only a leftChild
		else if ((root->leftChild != nullptr) && (root->rightChild == nullptr))
		{
			holdVertex = root;
			root = root->leftChild;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there is only a rightChild
		else if ((root->rightChild != nullptr) && (root->leftChild == nullptr))
		{
			holdVertex = root;
			root = root->rightChild;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there are two children
		else if ((root->rightChild != nullptr) && (root->leftChild != nullptr))
		{
			// Find the smallest value in the right subtree
			// (inorder successor)
			if (root->videoData != nullptr)
			{
				delete root->videoData;
				root->videoData = nullptr;
			}
			successValue = findDeleteIOS(root->rightChild, root->videoData);		
		}
	}

	return successValue;
}



int BST::deleteFromBST_Class(Vertex*& root)
{
	int successValue = 0;
	Vertex* holdVertex;
	
	if (root != nullptr)
	{
		// If there are no children
		if ((root->leftChild == nullptr) && (root->rightChild == nullptr))
		{
			root->videoData = nullptr;
			delete root;
			root = nullptr;

			successValue = 1;
		}
		// If the node has only one child
		// If there is only a leftChild
		else if ((root->leftChild != nullptr) && (root->rightChild == nullptr))
		{
			holdVertex = root;
			root = root->leftChild;
			holdVertex->videoData = nullptr;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there is only a rightChild
		else if ((root->rightChild != nullptr) && (root->leftChild == nullptr))
		{
			holdVertex = root;
			root = root->rightChild;
			holdVertex->videoData = nullptr;
			delete holdVertex;
			holdVertex = nullptr;

			successValue = 1;
		}
		// If there are two children
		else if ((root->rightChild != nullptr) && (root->leftChild != nullptr))
		{
			// Find the smallest value in the right subtree
			// (inorder successor)
			if (root->videoData != nullptr)
			{
				root->videoData = nullptr;
			}
			successValue = findDeleteIOS_Class(root->rightChild, root->videoData);	
		}
	}
	return successValue;
}



// Find the inorder successor (the smallest value in the given subtree)
int BST::findDeleteIOS(Vertex*& root, Video*& inorderSuccessor)
{
	int successValue = 0;

	// Go left until you cant anymore
	// That will be the smallest value in this tree
	if (root->leftChild != nullptr)
	{
		successValue = findDeleteIOS(root->leftChild, inorderSuccessor);
	}
	else
	{
		inorderSuccessor = root->videoData;
		root->videoData = nullptr;
		successValue = deleteFromBST(root);
		root = nullptr;
	}
	return successValue;
}



int BST::findDeleteIOS_Class(Vertex*& root, Video*& inorderSuccessor)
{
	int successValue = 0;

	// Go left until you cant anymore
	// That will be the smallest value in this tree
	if (root->leftChild != nullptr)
	{
		successValue = findDeleteIOS_Class(root->leftChild, inorderSuccessor);
	}
	else
	{
		inorderSuccessor = root->videoData;
		root->videoData = nullptr;
		successValue = deleteFromBST_Class(root);
		root = nullptr;
	}
	return successValue;
}



int BST::getHeight() const
{
	return getHeight(rootName);
}



int BST::getHeight(Vertex* root) const
{
	int count = 0;
	int countLeft = 0;
	int countRight = 0;

	if (root != nullptr)
	{
		if (root->leftChild != nullptr)
		{
			countLeft = count + getHeight(root->leftChild);
		}
		if (root->rightChild != nullptr)
		{
			countRight = count + getHeight(root->rightChild);
		}
		
		if (countLeft > countRight)
		{
			count = countLeft;
		}
		else if (countRight >= countLeft)
		{
			count = countRight;
		}
	
		++count;
	}

	return count;
}



int BST::displayByClass(const char classToDisplay[]) const
{
	return displayByClass(rootClass, classToDisplay);
}



int BST::displayByClass(ClassVertex* root, const char classToDisplay[]) const
{
	int successValue = 0;
	int comparisonValue = 0;

	if (root != nullptr)
	{	
		comparisonValue = root->classSubRoot->videoData->compareClassNames(classToDisplay);
		if (comparisonValue < 0)
		{
			successValue = displayByClass(root->leftChild, classToDisplay);
		}
		else if (comparisonValue == 0)
		{
			successValue = displayAll(root->classSubRoot);
		}
		else if (comparisonValue > 0)
		{
			successValue = displayByClass(root->rightChild, classToDisplay);
		}
	}
	return successValue;
}



int BST::displayAll() const
{
	return displayAll(rootName);
}



int BST::displayAll(Vertex* root) const
{
	int successValue = 0;

	// Use inorder traversal
	if (root != nullptr)
	{
		// First visit the left child
		if (root->leftChild != nullptr)
		{
			successValue = displayAll(root->leftChild);
		}
		// Then display your own data
		successValue = root->videoData->displayVideo();
		// Then visit the right child
		if (root->rightChild != nullptr)
		{
			successValue = displayAll(root->rightChild);
		}
	}
	
	return successValue;
}