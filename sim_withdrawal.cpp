#include <iostream>
using namespace std;

void getWithdrawal(int amount);

int main()
{
	int wAmount; // This is the amount user wants to withdrawal
	char response; // The response of the user

	do {

		do {
			cout << "Please select withdrawal ammount. [$1-$300]" << endl;
			cout << "No coins will be deposited." << endl;

			cin >> wAmount;
			if (cin.fail())
			{
				do {
					cout << "Please put in a dollar amount" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> wAmount;
				} while (cin.fail());

			}
			//There's a bug where if you put a decimal number or a symbol, the app goes crazy
			//This is where cin.fail comes into play. It'll prevent that from happening.
			// Added in a do while loop within the if statement so that it can repeat if needed
			//cin.clear() clears the error flag so I/O will work properly
			//cin.ignore(numeric_limits<streamsize>::max(), '\n') ignores the maximum input before the null.
			//cin.ignore(num, '\n') skips to the next newline while ignoring the num of characters before the null.

			cout << "Your request is for " << wAmount << " dollars." << endl;
			
			if (wAmount < 1 || wAmount > 300) //If the amount is less than $1 or more than $300
			{
				cout << "That is an invald amount." << endl;
			}

		} while (wAmount < 1 || wAmount > 300);
		//The line above will ask the user to put in a valid value if they didn't do it already.

		system("pause");

		getWithdrawal(wAmount); //This is calling for the getWithdrawal function

		system("pause");

		cout << "Would you like to make another withdrawal? [Enter in 'Y', if yes." <<
			" Enter in any other key to exit.]"
			<< endl;
		cin >> response;
	} while (response == 'y' || response == 'Y'); // this is to give the user the choice to repeat withdrawal

	return 0;
}

void getWithdrawal(int amount)
{
	int trackCount = amount; 
	
	/*trackCount is used to track how much of the total is left
	//each output variable (output, output 1, etc) is meant to multiply itself by the remaining trackCount...
	so that in the line below it, trackCount has the output multiplied by the bill type subtracted from it
	So for instance 275/50 = 5 -> 275 - (5*50) = 25. Next line would be: 25 / 20 = 1 -> 25 - (1*20) = 5.
	The logic continues on until the one dollar bills are accounted for.*/

	int output = trackCount / 50; //For the $50s 
	trackCount -= (output * 50);

	int output1 = trackCount / 20; //For the $20s
	trackCount -= (output1 * 20);

	int output2 = trackCount / 10; //For the $10s
	trackCount -= (output2 * 10);

	int output3 = trackCount / 5; //For the $5s
	trackCount -= (output3 * 5);

	int output4 = trackCount / 1; //For the $1s
	trackCount -= (output4 * 1);

	cout << "You're receiving:" << endl; // This line and the following lines print out the number of each bill
	cout << output << " $50 bills" << endl;
	cout << output1 << " $20 bills" << endl;
	cout << output2 << " $10 bills" << endl;
	cout << output3 << " $5 bills" << endl;
	cout << output4 << " $1 bills" << endl;
	

}