/*****************************************************************************/
/*Program: Project 1 B                                                       */
/*Author: Kurt Andersen                                                      */
/*Date: 4 February 2015                                                      */
/*Revisions: Version 1.0                                                     */
/*Purpose: Allow user to navigate a menu system to randomize a new slot set, */
/*  or to read in an old setting                                             */
/*****************************************************************************/
//////////////////Header Files///////////////////////////////////
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
//allows use of command without using "std::"
using namespace std;


////////////////////Global Variables/////////////////////////////


///////////////////Function Prototypes///////////////////////////
/*****************************************************************************/
/*Function:This Function allows the user to copy the contenets of one c-style*/
/*	string and place it into another                                        */
/*Purpose:Allows for a quick and easy function to copy strings to another    */
/*	location                                                                */
/*****************************************************************************/
void stringCopy ( char destination[] , const char location[] );

/*****************************************************************************/
/*Function: This Function reads in the original symbols file so we have the  */
/*	proper information for our slot machine                                 */
/*Purpose: To obtain the proper item information to use when we randomly     */
/*	generate a new machine                                                  */
/*****************************************************************************/
void readInSymbols (char location[][10]);

/*****************************************************************************/
/*Function: This Function takes the current machine and outputs it to a file */
/*	specified by the user                                                   */
/*Purpose: To allow the user to store randomized machines to a file location */ 
/*	as specified by the user                                                */
/*****************************************************************************/
void fileOut (char reels[][3][10] , bool loaded);

/*****************************************************************************/
/*Function: This function takes the original symbol information and randomly */
/*	stores the information on a 10 row X 3 Column slot machine              */
/*Purpose: To allow the user to simply generate a new machine at the users   */
/*	discretion                                                              */
/*****************************************************************************/
void randomizeReel (char reels[][3][10] , const char symbols[][10] ,
				 bool &loaded);

/*****************************************************************************/
/*Function: This Funtion prints the current loaded data and prints it to the */
/*	console so the user may see what their reel set looks like              */
/*Purpose: To allow the user to visually see what information has been stored*/
/*	in which location.  A visual grid                                       */
/*****************************************************************************/
void printToScreen (char reels[][3][10] , bool loaded);

/*****************************************************************************/
/*Function: This function allows the user to print just a singular piece of  */
/*	the currently loaded slot machine of the users choice                   */
/*Purpose: Allows the user to see what specific piece of information is      */
/*	stored in a specified location                                          */
/*****************************************************************************/
void reelLocation (char reels[][3][10] , bool loaded);

/*****************************************************************************/
/*Function: This function allows the user to read in a previous made file    */
/*	that contains old machines information                                  */
/*Purpose: Allow the user to work with and see what his/her old machine      */
/*	layouts consisted of                                                    */
/*****************************************************************************/
void readInOld (char reels[][3][10] , bool &loaded);


///////////////////////Main Function//////////////////////////////
int main()
	{
	//variable declaration
	int selection = 0;
	
	//array to store symbols
	char symbols[6][10];
	
	//array for slot machine layout
	char reels[10][3][10];
	
	//output filename
	char output[50];
	
	//input filename
	char input[50];
	
	//checks to see if data is loaded
	bool dataLoaded = 0;
	
	//read in the symbols file for randomization use	
	readInSymbols (symbols);
	
	//menu will loop until exit option is selected
	do
		{
		cout << "WELCOME TO SLOTS!!!!!!!" << endl;
		cout << "Please make a selection from the following list" << endl;
		cout << "1. Populate New Slot Machine" << endl;
		cout << "2. Read in an Existing Machine Configuration." << endl;
		cout << "3. Print current configuration to screen." << endl;
		cout << "4. Print Current Configuration to File." << endl;
		cout << "5. Print Specific Reel and Stop Location." << endl;
		cout << "6. Exit" << endl;
		cout << "Please Enter Your Selection Here ---> ";
		//takes in users selection from menu
		cin >> selection;
			
			//takes selection and compares it to each case
			switch (selection){
			
			case 1:
				randomizeReel (reels , symbols , dataLoaded);
				break;
				
			case 2:
				readInOld (reels , dataLoaded);
				break;
				
			case 3:
				printToScreen (reels , dataLoaded);
				break;
				
			case 4:
				fileOut (reels , dataLoaded);
				break;
				
			case 5:
				reelLocation(reels , dataLoaded);
				break;
				
			case 6:
				cout << "Well Then I Suppose We Are Done Here..." << endl;
				//changes selection to 0 so it breaks the loop
				selection = 0;
				break;
				
			default:
				cout << "Please Make a Proper Selection." << endl;
				//changes selection to 10 so the loop does not break if an
					//improper selection is made
				selection = 10;
			}
				
		} while (selection !=0);
	//end of program
	return 0;
	}

///////////////////////////Function Implementatons/////////////////////////////
void stringCopy (char destination[] , const char location[])
	{
	//counter for the while loop
	int i = 0;
	//statement checker
	char letter = 'a';
	
	//copies letter from string1 to string2 until a null charecter is copied
	while (letter != '\0')
		{
		//set checker
		letter = location[i];
		
		//copy letter
		destination[i] = location[i];
		
		//increment loop number
		i++;
		}	
	destination[i] = '\0';
	}

	
void readInSymbols (char location[][10])
	{
	//create ifstream variable
	ifstream fin;
	
	// Clear all
	fin.clear();
	
	// Open the file
	fin.open ("symbols");
	
	// Initiate a loop to store values from the f stream in a corresponding
	  //position
	for (int i=0; i<6; i++)
		{
		
		//read in per line instead of just the first word
		fin.getline (location[i] , 10);
		
		}
	// Close the File
	fin.close();
	}

	
void fileOut (char reels[][3][10] , bool loaded)
	{
	
	//checks to see if information has been loaded
	if (loaded != 0)
		{
		//create output file name
		char output[50];
	
		//prompt for file name and store
		cout << "Please Input a File Name to Export Data to: ";
		cin >> output;
	
		//Creates ofstream variable
		ofstream fout;
	
		//Creates and opens the file previously named by the user
		fout.open(output);
	
		//Initiate a loop to print values
		for (int i=0; i<10; i++)
			{
			for (int j=0; j<3; j++)
				{
			
				//Using fstream, prints the current value to the file
				fout << reels[i][j] << endl;
			
				}

			}
		//Close the file
		fout.close();
		
		//tells user that data has been sent to file
		cout << "Your Data Has Been Sent To The File With The Name: "
			<< output << endl;
		}
		
		else
			{
			//prints error message
			cout << "Data Can Not Be Exported Without Data Being Loaded."
				<< endl;
			}
		

	}
	
void randomizeReel (char reels[][3][10] , const char symbols[][10] ,
				 bool &loaded)
	{
		
	//variable for the random spot
	int x = 0;
	//initialize random
	srand(time(NULL));
	
	//loop to fill each location with a random symbol
	for (int i=0; i<10; i++)
		{
		for (int j=0; j<3; j++)
			{
			
			//generates random number between 0 and 5
			x = rand()%6;
			
			//copies information from symbols to reels
			stringCopy (reels[i][j] , symbols[x]);
			
			}
		}
	//tells program that data has been loaded
	loaded = 1;
	
	//tells user that random reels have been generated
	cout << "A New Machine Has Been Generated!" << endl;
	}
	
void printToScreen (char reels[][3][10] , bool loaded)
	{
	
	//checks to see if data is loaded
	if (loaded != 0)
		{
		//initiate loop to print each piece of reels
		for (int i=0; i<10; i++)
			{
			for (int j=0; j<3; j++)
				{
				//print symbol and add spaces
				cout << reels[i][j] << " || ";
				}
			//start new row
			cout << endl;
			}
		}
	else
		{
		//prints error message
		cout << "Data Has Not Been Loaded In Yet." << endl;;
		}
	}
	
void reelLocation (char reels[][3][10] , bool loaded)
	{
	
	//check to see if data has been loaded
	if (loaded != 0)
		{
		//create variables to determine location
		int row;
		int column;
		
		//obtain which row and column the user would like printed
		cout << "Please Input Which Row You Would Like Printed(1-10): ";
		cin >> row;
		cout << "Please Input Which Column You Would Like Printed(1-3): ";
		cin >> column;
	
		//determine if user input exists
		if (row > 10 || row < 1 || column > 3 || column < 0)
			{
			//prints out error
			cout << "Your Input is Invald, Please Make a Proper Selection."
				<< endl;
				
			//Loops back through the function if user input is invalid
			reelLocation (reels , loaded);
			}
		else
			{
			//prints users location
			cout << "The Item at Your Specific Location Is : "
				<< reels[(row-1)][(column-1)] << endl;
			}
		}
	else
		{
		//prints error message
		cout << "I Can Not Search For a Specific Point Since Data Has Not"
			<< " Been Loaded Yet!" << endl;
		}
	}

void readInOld (char reels[][3][10] , bool &loaded)
	{
	//create memory for filename to be loaded from
	char filename[50];
	
	//prompt and receive filename
	cout << "Please Input The File To Be Read From: ";
	cin >> filename;
	
	//create fstream variable
	ifstream fin;
	
	//clears fstream
	fin.clear();
	
	//open file inputted by user
	fin.open (filename);
	
	//checks to see if the file name exists
	if (fin.good())
		{
		//set data entry to true
		loaded = 1;
		
		//loops to read in data from previous file
		for (int i=0; i<10; i++)
			{
			for (int j=0; j<3; j++)
				{
				fin.getline (reels[i][j] , 10);
				}
			
			}
			
		//confirmms file has been read in from destination
		cout << "Your File Has Been Read In From: " << filename << endl;
		
		}
	else if (!fin.good())
		{
		//prints error message if file does not exist
		cout << "The Data File Does Not Exist!!!" << endl;
		}
	
	
	}
