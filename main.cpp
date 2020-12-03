#include "bst.h"

using namespace std;

// Function prototypes
void userInterface(); // User interface
void mainMenuContent(char& input); // Menu options
void addVideoUI(BST& aBST);  // UI function to call add Video
void searchByNameUI(BST& aBST);
void removeByNameUI(BST& aBST);
void removeByClassNameUI(BST& aBST);
void getHeightUI(BST& aBST);
void displayByClassUI(BST& aBST);
void displayAllUI(BST& aBST);

void testingUI(BST& aBST);



int main()
{
	userInterface();

	return 0;
}



// User interface
void userInterface()
{
        BST*	aBST = new BST;
        char	input;

        input = '\0';

        while (quitCheck(input) != true)
        {
                mainMenuContent(input);
                if (quitCheck(input) != true)
                {
                        switch (input)
                        {
                        case '1':
				addVideoUI(*aBST);
                                break;
                        case '2':
				searchByNameUI(*aBST);
                                break;
                        case '3':
				removeByNameUI(*aBST);
                                break;
			case '4':
				removeByClassNameUI(*aBST);
				break;
                        case '5':
				getHeightUI(*aBST);
				break;
			case '6':
				displayByClassUI(*aBST);
                                break;
			case '7':
				displayAllUI(*aBST);
				break;
                        default:
                                cout << "Invalid input. Please try again." << endl;
                        }
                }
        }
	delete aBST;
}



// Menu and input
void mainMenuContent(char& input)
{
      char prompt[MAX_CHAR];

	cout << "=========================================================" << endl << endl;
	cout << "Enter a number or 'q' to quit" << endl;
	cout << endl;
	strcpy(prompt, "1. Add a video\n2. Search for a video by name\n3. Remove a video by name\n4. Remove videos by class name\n5. Get the height of the tree\n6. Display videos by class name\n7. Display all video details\nq. Quit\n\nPlease enter your menu choice: ");

        takeInput(input, prompt);
	cout << endl << endl;
	cout << "=========================================================" << endl << endl;
}



// Add Alert
void addVideoUI(BST& aBST)
{
	char 		videoName[MAX_CHAR];
	char		className[MAX_CHAR];
	char		videoDescription[MAX_CHAR];
	
	int		hours;
	int		minutes;
	int		seconds;
	Length		videoLength;

	char		nextVideoName[MAX_CHAR];

	char		prompt[MAX_CHAR]; // Used in UI only as a prompt in error checking
        Video           videoBuffer;  // packages user input into alert
	int		successFlag = 0;		// success/failure of functions


	strcpy(prompt, "Ehter the video name: ");
	takeInput(videoName, prompt);
	
	strcpy(prompt, "Enter the name of the class the video is for: ");
	takeInput(className, prompt);

	strcpy(prompt, "Enter a description of the video (256 character max): ");
	takeInput(videoDescription, prompt);

	strcpy(prompt, "Enter a length (must enter a whole numbers):\nHours: ");
	takeInput(hours, prompt);

	strcpy(prompt, "Minutes: ");
	takeInput(minutes, prompt);

	strcpy(prompt, "Seconds: ");
	takeInput(seconds, prompt);

	videoLength.hours = hours;
	videoLength.minutes = minutes;
	videoLength.seconds = seconds;

	strcpy(prompt, "Enter the name of the next video in the series: ");
	takeInput(nextVideoName, prompt);

	videoBuffer.createVideo(videoName, 
				className, 
				videoDescription, 
				videoLength, 
				nextVideoName);

	successFlag = aBST.addVideo(videoBuffer);

	if (successFlag == 1)
	{
		cout << endl << "Add successful!!" << endl << endl;
	}
	else
	{
		cout << endl << "Add failed. Video name already exists." << endl << endl;
	}
}



// Search by name
void searchByNameUI(BST& aBST)
{
	int	successFlag = 0;      // failure or success of functions
	char	nameToSearch[MAX_CHAR]; // search name buffer
	char	prompt[MAX_CHAR];
	Video	retrievedVideoDetails;
	
	strcpy(prompt, "Enter the video name to search for: ");
	takeInput(nameToSearch, prompt);

	successFlag = aBST.searchByName(retrievedVideoDetails, nameToSearch);



	if (successFlag == -1)
	{
		cout << "Search failed. There are no videos saved." << endl;
		cout  << endl << endl;
	}
	if (successFlag == 0)
	{
		cout << "Search failed. ";
		cout << "Video name \"" << nameToSearch << "\" does not exist.";
		cout  << endl << endl;
	}
	if (successFlag == 1)
	{
		cout << "Search Results:";
		cout << endl << endl;
		successFlag = retrievedVideoDetails.displayVideo();
	
		if (successFlag == 0)
		{
			cout << "Unable to display video." << endl;
		}
	}
}



// Display alert that is on top of the stack without changing the stack
void removeByNameUI(BST& aBST)
{
	int	successFlag = 0;      // failure or success of functions
	char	nameToRemove[MAX_CHAR]; // search name buffer
	char	prompt[MAX_CHAR];
	
	strcpy(prompt, "Enter the video name to remove: ");
	takeInput(nameToRemove, prompt);
	
	successFlag = aBST.removeByName(nameToRemove);

	if (successFlag == -1)
	{
		cout << "Remove failed. There are no videos to remove." << endl;
		cout  << endl << endl;
	}
	if (successFlag == 0)
	{
		cout << "Remove failed. ";
		cout  << endl << endl;
	}
	if (successFlag == 1)
	{
		cout << "Success!! Video name \"" << nameToRemove << "\" was removed.";
		cout << endl << endl;
	}
}

void removeByClassNameUI(BST& aBST)
{
	int	successFlag = 0;      // failure or success of functions
	char	classToRemove[MAX_CHAR]; // search name buffer
	char	prompt[MAX_CHAR];
	
	strcpy(prompt, "Enter the class name to remove videos for: ");
	takeInput(classToRemove, prompt);
	
	successFlag = aBST.removeByClass(classToRemove);

	if (successFlag == -1)
	{
		cout << "Remove failed. There are no videos to remove." << endl;
		cout  << endl << endl;
	}
	if (successFlag == 0)
	{
		cout << "Remove failed. ";
		cout  << endl << endl;
	}
	if (successFlag == 1)
	{
		cout << "Success!! Video for class name \"" << classToRemove << "\" was removed.";
		cout << endl << endl;
	}
}


// Get the height of the tree
void getHeightUI(BST& aBST)
{
	cout << "The height of the tree is: " << aBST.getHeight() << endl << endl;
}



// Display by class
void displayByClassUI(BST& aBST)
{
	int 	successFlag = 0;
	char	classToDisplay[MAX_CHAR]; // search name buffer
	char	prompt[MAX_CHAR];


	strcpy(prompt, "Enter the name of the class whose videos you want to display: ");
	takeInput(classToDisplay, prompt);
	
	successFlag = aBST.displayByClass(classToDisplay);

	
	if (successFlag == -1)
	{
		cout << "Display failed. There are no videos in the list." << endl << endl;
	}
	if (successFlag == 0)
	{
		cout << "Display failed. That class name does not exist.";
		cout << endl << endl;
	}
}



void displayAllUI(BST& aBST)
{
	int	successFlag = 0;
	successFlag = aBST.displayAll();

	if (successFlag == 0)
	{
		cout << "Display failed. No video details to display." << endl << endl;
	}
}
