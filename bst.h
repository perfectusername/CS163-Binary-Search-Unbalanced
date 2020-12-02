/*

	bst.h

	Manage binary tree structure

	Author: Brooke Czerwinski
	Date: 12/1/2020
	Class: CS 163
	Program #4

*/


#include "video.h"



// Manages Vertex structure
struct Vertex
{
	// Default constructor
	Vertex();


	// Destructor
	~Vertex();


	Video*	videoData;   // Pointer to Video object
	Vertex*	leftChild;   // Pointer to left Vertex child
	Vertex* rightChild;  // Pointer to right Vertex child
};




// Manages Class Vertex structure (forest)
struct ClassVertex
{
	// Default Constructor
	ClassVertex();


	// Destrutor
	~ClassVertex();


	Vertex* classSubRoot;    // Pointer to Vertex subtree
	ClassVertex* leftChild;  // Pointer to left ClassVertex child
	ClassVertex* rightChild; // Pointer to right ClassVertex child
};



// Manages Binary Tree Structure
class BST
{
public:
	// Default constructor
	BST();



	// Destructor
	~BST();



	// Adds video to binary tree
	/*
		INPUT:	- newVideo - Video object - a new video object to add

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int addVideo(Video& newVideo);



	// Search the binary tree for a matching video name
	/*
		INPUT:	- retrievedVideoDetails - Video object - a video object whose details
								 will be filled in with the
								 found video, if it exists
			- nameToSearch - cstring - a videoName to search for

		OUTPUT:	- returns int
				- -1 if the tree is empty
				- 0 if the video is not in the tree
				- 1 if the video is found in the tree and the details
					have been copied into retrievedVideoDetails
	*/
	int searchByName(Video& retrievedVideoDetails, const char nameToSearch[]) const;



	// Remove a video from the binary tree based on its name
	/*
		INPUT:	- nameToRemove - cstring - name of the video to remove

		OUTPUT:	- returns int
				- -1 if the tree is empty
				- 0 if the video is not in the tree
				- 1 if the video was found and deleted
	*/
	int removeByName(const char nameToRemove[]);



	// Remove all videos of a certain className from the binary tree
	/*
		INPUT:	- classToRemove - cstring - name of the class to remove

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByClass(const char classToRemove[]);



	// Return the height of the tree
	/*
		**NOTE - This implementation counts the root as 1 as Karla Fant requested

		OUTPUT: - returns int - value determined by height of the tree
	*/
	int getHeight() const;



	// Display all videos of a certain class in alphabetical order
	/*
		INPUT:	- classToDisplay - cstring - name of class you want to display

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also asks the videos of that class to display themselves
	*/
	int displayByClass(const char classToDisplay[]) const;



	// Display all videos in the binary tree in alphabetical order
	/*
		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also asks all videos in bst to display themselves
	*/
	int displayAll() const;

private:
	Vertex* rootName;       // Root of the name-organized binary search tree
	ClassVertex* rootClass; // Root of the class-organized binary search tree



	// Recursively add a video to the name-organized bst (rootName) using its name
	/*
		INPUT:	- root - Vertex object - root of the tree or subtree to add to
			- videoToAdd - Video object - video to add to the tree

		OUTPUT: - returns int - 0 for failure, 1 for success
			- will return 0 if name video already exists. duplicates not allowed
	*/
	int addVideoByName(Vertex*& root, Video& videoToAdd);



	// Recursively add a video to the class-organized bst (rootClass) using its className
	/*
		INPUT:	- root - ClassVertex object pointer - root of the tree or subtree to add to
			- videoToAdd - Video object - video to add to the tree

		OUTPUT: - returns int - 0 for failure, 1 for success
	*/
	int addVideoByClass(ClassVertex*& root, Video& videoToAdd);



	// Recursively Search for a video in the binary tree by name
	/*
		INPUT:	- retrievedVideo - Video object - a video object whose details
							  will be filled in with the
							  found video, if it exists
			- searchName - cstring - videoName to search for
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int searchByName(Video& retrievedVideo, const char searchName[], Vertex* root) const;



	// Recursively search the BST for the name of the item to remove and then retrieve its className
	/*
		INPUT:	- searchName - cstring - name of the video to retrieve the class of
			- classNameRetrieved - cstring - name of the class will be added here
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int retrieveClassName(const char searchName[], char classNameRetrieved[], Vertex* root) const;



	// Recursively remove an object from the rootName BST bsed on its name
	/*
		INPUT:	- nameToRemove - cstring - name of the video to remove
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByName(const char nameToRemove[], Vertex*& root);



	// Recursively remove an object from the className BST bsed on its name
	/*
		INPUT:	- nameToRemove - cstring - name of the video to remove
			- root - ClassVertex object pointer - root of the tree or subtree to search in
			- classToRemove - cstring - name of the class the video is in 
						    (found automatically using retrieveClassName)

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByName_Class(const char nameToRemove[], ClassVertex*& root, const char classToRemove[]);



	// Recursively remove an object from the rootClass classSubRoot BST bsed on its name
	/*
		INPUT:	- nameToRemove - cstring - name of the video to remove
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByName_Class(const char nameToRemove[], Vertex*& root);



	// Recursively remove an object from the rootName BST bsed on its className
	/*
		INPUT:	- classToRemove - cstring - className to remove
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByClass(const char classToRemove[], Vertex*& root);



	// Recursively remove an object from the className BST bsed on its className
	/*
		INPUT:	- classToRemove - cstring - className to remove
			- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int removeByClass_Class(const char classToRemove[], ClassVertex*& root);



	// Recursively delete a Vertex node from a rootName BST
	/*
		INPUT:	- root - Vertex object pointer - root of the tree or subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteFromBST(Vertex*& root);



	// Recursively delete a Vertex node from a classSubRoot BST
	/*
		INPUT:	- root - Vertex object pointer - root of the subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteFromBST_Class(Vertex*& root);



	// Recursively delete a ClassVertex node from a rootClass BST
	/*
		INPUT:	- root - ClassVertex object - root of the subtree to search in

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteFromBST_Class(ClassVertex*& root);



	// Recursively find and delete the inorder successor of the rootName tree
	/*
		INPUT:	- root - Vertex object - root of the tree or subtree to search in
			- inorderSuccessor - Video object pointer - pointer to the IOS's video data object

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also alters poitner so it points to the video data of the IOS node into inorderSuccessor
	*/
	int findDeleteIOS(Vertex*& root, Video*& inorderSuccessor);



	// Recursively find and delete the inorder successor of the rootClass's classSubRoot tree
	/*
		INPUT:	- root - Vertex object - root of the subtree to search in
			- inorderSuccessor - Video object pointer - pointer to the IOS's video data object

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also alters poitner so it points to the video data of the IOS node into inorderSuccessor
	*/
	int findDeleteIOS_Class(Vertex*& root, Video*& inorderSuccessor);



	// Recursively find and delete the inorder successor of the rootClass tree
	/*
		INPUT:	- root - ClassVertex object - root of the tree or subtree to search in
			- inorderSuccessor - Video object pointer - pointer to the IOS's video data object

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also alters poitner so it points to the video data of the IOS node into inorderSuccessor
	*/
	int findDeleteIOS_Class(ClassVertex*& root, Vertex*& inorderSuccessor);



	// Recursively deletes and deallocates dynamic memory for the entire BST structure
	/*
		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteBST();



	// Recursively deletes and deallocates dynamic memory for the rootName BST
	/*
		INPUT:	- root - Vertex object - root of the tree or subtree to search

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteBST(Vertex*& root);



	// Recursively deletes and deallocates dynamic memory for the rootClass BST
	/*
		INPUT:	- root - ClassVertex object - root of the tree or subtree to search

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteBST_Class(ClassVertex*& root);



	// Recursively deletes and deallocates dynamic memory for the classSubRoot BST
	/*
		INPUT:	- root - Vertex object - root of the subtree to search

		OUTPUT:	- returns int - 0 for failure, 1 for success
	*/
	int deleteBST_Class(Vertex*& root);



	// Recursively finds the number nodes in rootName BST from the root to farthest leaf
	// **NOTE** Root IS counted in this version. If you only have a root, the height wil 
	// be 1, as Karla requested
	/*
		INPUT: - root - Vertex object - root of the subtree to search

		OUTPUT:	- returns int - value determined by the height of thet reee
	*/
	int getHeight(Vertex* root) const;



	// Recursively display all videos in rootName BST alphabetically
	/*
		INPUT:	- root - Vertex object - root of the tree or subtree to search

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also displays all of the videos alphabetically which are in the tree
	*/
	int displayAll(Vertex* root) const;



	// Recursively display all videos in a rootClass' classSubRoot BST alphabetically
	/*
		INPUT:	- root - ClassVertex object - root of the tree to search
			- classToDisplay - cstring - name of the class to display

		OUTPUT:	- returns int - 0 for failure, 1 for success
			- also displays all of the videos alphabetically which are 
			  in the tree that match teh class
	*/
	int displayByClass(ClassVertex* root, const char classToDisplay[]) const;
};
