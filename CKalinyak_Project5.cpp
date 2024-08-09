/*
 * Class: CMSC140 CRN 10016
 * Instructor: Margaret Tseng
 * Project 5
 * Description: Determing a magic quare through arrays and functions
 * Due Date: 09Aug24
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Christina Kalinyak
*/

#include <iostream>

using namespace std;

// Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int TOTAL_ELE = 9; //total number of elements across all the arrays
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

//global booleans
bool check1, check2, check3, check4, check5;

// Function prototypes
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void swap(int& element1, int& element2);

int main()
{

	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	int arrayRow1[COLS], arrayRow2[COLS], arrayRow3[COLS];

	// Your code goes here
	fillArray(arrayRow1, arrayRow2, arrayRow3, COLS);
	showArray(arrayRow1, arrayRow2, arrayRow3, COLS);

	isMagicSquare(arrayRow1, arrayRow2, arrayRow3, COLS);

	//ask if you want to repeat/ retry
	char retry;

	cout << "Would you like to try again? Enter Y for yes or N for no.\n";
	retry = cin.get();
	while ((retry != 'Y') && (retry != 'y') && (retry != 'n') && (retry != 'N'))
	{
		cout << "Invalid selection, please try again.\n";
		cout << "Enter Y for yes or N for no\n";
		retry = cin.get();
	}
	if ((retry == 'Y') || (retry == 'y'))
		{
			fillArray(arrayRow1, arrayRow2, arrayRow3, COLS);
			showArray(arrayRow1, arrayRow2, arrayRow3, COLS);

			isMagicSquare(arrayRow1, arrayRow2, arrayRow3, COLS);
			cout << "Would you like to try again? Enter Y for yes or N for no.\n";
			retry = cin.get();
			while ((retry != 'Y') && (retry != 'y') && (retry != 'n') && (retry != 'N'))
			{
				cout << "Invalid selection, please try again.\n";
				cout << "Enter Y for yes or N for no\n";
				retry = cin.get();
			}
			if ((retry == 'Y') || (retry == 'y'))
			{
				fillArray(arrayRow1, arrayRow2, arrayRow3, COLS);
				showArray(arrayRow1, arrayRow2, arrayRow3, COLS);

				isMagicSquare(arrayRow1, arrayRow2, arrayRow3, COLS);
				cout << "Would you like to try again? Enter Y for yes or N for no.\n";
				retry = cin.get();
			}
			else if ((retry == 'n') || (retry == 'N'))
			{
				cout << "Name: Christina Kalinyak\n";
				cout << "Project 5\n";
				cout << "Due Date: 09Aug24\n";

				return 0;
			}
		}
	else if ((retry == 'n') || (retry == 'N'))
		{
			cout << "Name: Christina Kalinyak\n";
			cout << "Project 5\n";
			cout << "Due Date: 09Aug24\n";

			return 0;
		}
	
	
}
// Function definitions go here
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	bool magicBool;
	checkRange(arrayRow1, arrayRow2, arrayRow3, COLS, MIN, MAX);
	checkUnique(arrayRow1, arrayRow2, arrayRow3, TOTAL_ELE);

	checkRowSum(arrayRow1, arrayRow2, arrayRow3, COLS);
	checkColSum(arrayRow1, arrayRow2, arrayRow3, ROWS);
	checkDiagSum(arrayRow1, arrayRow2, arrayRow3, COLS);

	if ((check1 && check2 && check3 && check4 && check5) == true)
	{
		magicBool = true;
		cout << "This is a magic square!\n";
		return magicBool;
	}
	else
	{
		magicBool = false;
		cout << "This is not a magic square\n";
		return magicBool;
	}
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max)
{
	int x;
	bool rangeBool1;
	for (x = 0; x < COLS; x++)
	{
		if ((arrayRow1[x] > MAX) || (arrayRow1[x] < MIN))
		{
			rangeBool1=false;
		}
		else
			rangeBool1=true;
	}

	int y;
	bool rangeBool2;
	for (y = 0; y < COLS; y++)
	{
		if ((arrayRow2[y] > MAX) || (arrayRow2[y] < MIN))
		{
			rangeBool2 = false;
		}
		else
			rangeBool2 = true;
	}

	int z;
	bool rangeBool3;
	for (z = 0; z < COLS; z++)
	{
		if ((arrayRow3[z] > MAX) || (arrayRow3[z] < MIN))
		{
			rangeBool3 = false;
		}
		else
			rangeBool3 = true;
	}
	
	if ((rangeBool1 == true) && (rangeBool2 == true) && (rangeBool3 == true))
	{
		check1 = true;
	}
	else
	{
		check1 = false;
	}
	return check1;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	//Step 1: concatenate arrays into one to use for check unique
	int totalArray[9];
	int uniqueArray[9];
	int nelly;  //counter
	for (nelly = 0; nelly < TOTAL_ELE; nelly++) //9 because that is the total number of elements across all 3 arrays
	{
		if (nelly < 3)
			totalArray[nelly] = arrayRow1[nelly];
		else if (nelly > 2 && nelly < 6)
			totalArray[nelly] = arrayRow2[nelly - 3];
		else
			totalArray[nelly] = arrayRow3[nelly - 6];
	}
	//Step 2: Sort Total Array
	int minSub = 0;
	int minVal = 0;
	int x = 0;  //count variable
	int sub;
	for (x = 0; x < (TOTAL_ELE - 1); x++)
	{
		minSub = x;
		minVal = totalArray[x];
		for (sub = x + 1; sub < TOTAL_ELE; sub++)
		{
			if (totalArray[sub] < minVal)
			{
				minVal = totalArray[sub];
				minSub = sub;
			}
		}
		swap(totalArray[minSub], totalArray[x]);
	}
	//Step 3: Print only distint values of totalArray
	int y = 0; //yet another counter
	int sundae = 0; //counter for the unique array
	for (y = 0; y < TOTAL_ELE; y++)
	{
		uniqueArray[sundae++] = totalArray[y];
		while (y < (TOTAL_ELE - 1) && totalArray[y] == totalArray[y + 1])
			y++;
	}

	/*Step 4: Check sum of uniqueArray values vs sum totalArray
	in theory, if there are duplicates, the duplicate is removed and replaced with 0
	so the sums wouldn't match if the values aren't unique
	*/
	int sumUnique = 0;
	int sumTotalArr = 0;

	for (x = 0; x < TOTAL_ELE; x++)
	{
		sumUnique += uniqueArray[x];
		sumTotalArr += totalArray[x];
	}
	//If same size, all elements are distinct
	if (sumUnique == sumTotalArr)
	{
		check2 = true;
		return check2;
	}
	else
	{
		check2 = false;
		return check2;
	}
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int x;  //counter for arrayRow1
	int rowSum1 = 0; //accumulator
	for (x = 0; x < COLS; x++)
	{
		rowSum1 += arrayRow1[x];
	}

	int y;  //counter for arrayRow2
	int rowSum2 = 0; //accumulator
	for (y = 0; y < COLS; y++)
	{
		rowSum2 += arrayRow2[y];
	}

	int z;  //counter for arrayRow3
	int rowSum3 = 0; //accumulator
	for (z = 0; z < COLS; z++)
	{
		rowSum3 += arrayRow3[z];
	}
	
	if ((rowSum1 == rowSum2)&& (rowSum1 == rowSum3)&& (rowSum2 == rowSum3))
	{
		check3 = true;
	}
	else
	{
		check3 = false;
	}
	return check3;
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int x = 0;
	int colSum1=0;
	int colSum2=0;
	int colSum3=0;

	colSum1 = arrayRow1[x] + arrayRow2[x] + arrayRow3[x];
	colSum2 = arrayRow1[x + 1] + arrayRow2[x + 1] + arrayRow3[x + 1];
	colSum3 = arrayRow1[x + 2] + arrayRow2[x + 2] + arrayRow3[x + 2];
	
	if ((colSum1 == colSum2) && (colSum1 == colSum3) && (colSum2==colSum3))
	{
		check4 = true;
	}
	else
	{
		check4 = false;
	}
	return check4;
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int diagSum1 = 0;
	int x;
	for (x = 2; x < COLS; x++)
	{
		diagSum1 = arrayRow1[x - 2] + arrayRow2[x - 1] + arrayRow3[x];
	}

	int diagSum2 = 0;
	int y;
	for (y = 2; y < COLS; y++)
	{
		diagSum2 = arrayRow1[y] + arrayRow2[y - 1] + arrayRow3[y-2];
	}

	if (diagSum1 == diagSum2)
	{
		check5 = true;
		return check5;
	}
	else
	{
		check5 = false;
		return check5;
	}
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int x; //x is the counter for arrayRow1
	for (x = 0; x < COLS; x++)
	{
		cout << "\n Enter a number for row 0 and column " << x <<": ";
		cin >> arrayRow1[x];
	}
	int y; //y is the counter for arrayRow2
	for (y = 0; y < COLS; y++)
	{
		cout << "\n Enter a number for row 1 and column " << y << ": ";
		cin >> arrayRow2[y];
	}
	int z; //z is the counter for arrayRow3
	for (z = 0; z < COLS; z++)
	{
		cout << "\n Enter a number for row 2 and column " << z << ": ";
		cin >> arrayRow3[z];
	}
}

void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size)
{
	int x; //x is the counter for arrayRow1
	for (x = 0; x < COLS; x++)
	{
		cout << arrayRow1[x] << "  ";
	}
	cout << endl;

	int y;  //y is the counter for arrayRow2
	for (y = 0; y < COLS; y++)
	{
		cout << arrayRow2[y] << "  ";
	}
	cout << endl;

	int z;  //z is the counter for arrayRow3
	for (z = 0; z < COLS; z++)
	{
		cout << arrayRow3[z] << "  ";
	}
	cout << endl;
}

void swap(int &element1,int &element2)
{
	int temp=element1;
	element1=element2;
	element2=temp;
}