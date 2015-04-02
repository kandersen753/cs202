/****************************************************************************/
/*Program: Project1                                                         */
/*Author: Kurt Andersen                                                     */
/*Date:                                                                     */
/*Revisions: 1.0                                                            */
/*Purpose: Read in information from a file, place it in an array and have it*/ 
/*export the information into a file the user creates                       */
/****************************************************************************/

//Header Files
#include <iostream>
#include <fstream>
using namespace std;

/////////////////////////// Funtion Prototypes //////////////////////////

/*****************************************************************************/
/* Function:This function will use the array from the main function and store*/
/*   information from the file labeled "symbols"                             */ 
/* Purpose: To satisfy the project requirements of passing something through */
/* a function by reference                                                   */
/*****************************************************************************/

void readIn (char (&table)[10][3][20]);


/*****************************************************************************/
/* Function:This function uses the same array as the previous function as    */
/*   well as the variable created for the ofstream, and will print everything*/  
/*   within the area to a file named by the user in a table that is 3 columns*/  
/*   wide and 10 columns long                                                */  
/* Purpose: To satisfy the project requirements of passing something through */ 
/*   a function by reference.                                                */  
/*****************************************************************************/
   
void fileOut (char (&table)[10][3][20] , ofstream &fout);

///////////////////////////// Main Function ////////////////////////////

int main()
{
	// Initialize Variables
	char symbolTable[10][3][20];
	ofstream fout;

	// Read in the values from file
	readIn(symbolTable);

	// Exports the symbols to a file defined by the User
	fileOut (symbolTable , fout);

	// Initiate a loop to print all symbols to the console in a tabled
	  //format
	for (int i=0; i<10; i++)
		{
		for (int j=0; j<3; j++)
			{
			// Prints the current symbol that represents the 
			  //position in the table
			cout << symbolTable[i][j] << "    ";
			}
			
		// Makes a new line to print the next row of symbols on
		cout << endl; 
		}

	// End of Program
	return 0;
}

//////////////////Function Definitions////////////////////

void readIn (char (&table)[10][3][20])
	{
	// Initialize Variables
	ifstream fin;
	
	// Clear all
	fin.clear();
	
	// Open the file
	fin.open ("symbols");
	
	// Initiate a loop to store values from the f stream in a corresponding
	  //position
	for (int i=0; i<10; i++)
		{
		for (int j=0; j<3; j++)
			{
			//places value from f stream file to corresponding spot
			  //in array
			fin >> table[i][j];
			}
		}
	// Close the File
	fin.close();
	}


void fileOut (char (&table)[10][3][20] , ofstream &fout)
	{
	// Initialize Variables
	char fileName[100];
	
	// Asks the user to input the name for a file to export information to
	cout << "Please input the name of the file you want to export to: ";
	
	// Stores the users input under the variable "fileName"
	cin >> fileName;
	
	// Creates and opens the file previously named by the user
	fout.open(fileName);
	
	// Initiate a loop to print values
	for (int i=0; i<10; i++)
		{
		for (int j=0; j<3; j++)
			{
			// Using fstream, prints the current value to the file
			fout << table[i][j] << "     ";
			}
			
		// Creates a new line to output the data
		fout << endl;
		}
		
	// Close the file
	fout.close();
	
	//confirm that data has been export
	cout << "Your Data has been exported to file : " << fileName << endl;
	}
