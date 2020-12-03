#include "video.h"



struct Vertex
{
        Vertex();
        ~Vertex();

        Video*  videoData;

        Vertex* leftChild;
        Vertex* rightChild;
};



struct ClassVertex
{
        ClassVertex();
        ~ClassVertex();

        Vertex* classSubRoot;

        ClassVertex* leftChild;
        ClassVertex* rightChild;
};



class BST
{
public:
        BST();
        ~BST();

        int addVideo(Video& newVideo);

        // Return -1 if the tree is empty
        // Return 0 if the video is not in the tree
        // Return 1 if the video is in the tree
        int searchByName(Video& retrievedVideoDetails, const char nameToSearch[]) const;

        // Return -1 if the tree is empty
        // Return 0 if the video is not in the tree
        // Return 1 if the video was found and deleted.
        int removeByName(const char nameToRemove[]);
        int removeByClass(const char classToRemove[]);
	
        int getHeight() const;

        // Display Functions
        int displayByClass(const char classToDisplay[]) const;
        int displayAll() const;

private:
        Vertex* rootName;  // Root of the name-organized binary search tree
        ClassVertex* rootClass; // Root of the class-organized binary search tree

        // Add video
        int addToNameBST(const Vertex aVertexToAdd);
        int addToClassBST(const Vertex& aVertexToAdd);
        int addVideoByName(Vertex*& root, Video& videoToAdd);
        int addVideoByClass(ClassVertex*& root, Video& videoToAdd);

        // Search Functions
        int searchByName(Video& retrievedVideo, const char searchName[], Vertex* root) const;
        int retrieveClassName(const char searchName[], char classNameRetrieved[], Vertex* root) const;

        int getHeight(Vertex* root) const;

        // Display Functions
        int displayAll(Vertex* root) const;
        int displayByClass(ClassVertex* root, const char classToDisplay[]) const;

        // Remove Functions
        int removeByName(const char nameToRemove[], Vertex*& root);
        int removeByName_Class(const char nameToRemove[], ClassVertex*& root, const char classToRemove[]);
        int removeByName_Class(const char nameToRemove[], Vertex*& root);
        int removeByClass(const char classToRemove[], Vertex*& root);
        int removeByClass_Class(const char classToRemove[], ClassVertex*& root);


        // Delete Video from BST
        int deleteFromBST(Vertex*& root);
        int deleteFromBST_Class(Vertex*& root);
        int deleteFromBST_Class(ClassVertex*& root);
        int findDeleteIOS(Vertex*& root, Video*& inorderSuccessor);
        int findDeleteIOS_Class(Vertex*& root, Video*& inorderSuccessor);
        int findDeleteIOS_Class(ClassVertex*& root, Vertex*& inorderSuccessor);

        // Delete Full BST
        int deleteBST();
        int deleteBST(Vertex*& root);
        int deleteBST_Class(ClassVertex*& root);
        int deleteBST_Class(Vertex*& root);
};
