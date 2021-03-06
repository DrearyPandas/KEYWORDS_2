// KEYWORDS_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Project Initialization

#include "pch.h" 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>
#include <time.h> 
#include <cctype>

using namespace std;


int main()
{
	const int MAX_WRONG = 8;  //maximum number of incorrect guesses allowed
	string User; // holds the user's name
	// Create an int var to count the number of simulations being run starting at 1
	int simCount = 1; // holds number of sims run
	int Quit = 1; // variable to continue game

	// Display Title of program to user
	cout << "Welcome to CIA Recruit Code Breaker Training Simulation Program.\n";// outputs text to console
	// Ask the recruit to login using their name
	cout << "Please login with your name: ";// outputs text to console
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> User; // gets user input
	// Display an overview of what Keywords II is to the recruit 
	cout << "The CIA Recruit Code Breaker Training Simulation Program is designed to train recruits to manually guess keywords used by the enemy.\n";// outputs text to console
	// Display an directions to the recruit on how to use Keywords
	cout << User << ", you will have " << MAX_WRONG << " chances to guess three words by entering letters one at a time.";// outputs text to console with variables inserted
	
	
	
	while (Quit == 1)
	{
		
		
		int wrong = 0;    //number of incorrect guesses

		// Create a collection of 10 words you had wrote down manually
		vector<string> words; // creats a vector names words to hold strings
		words.push_back("APE");// adds string object to vector 
		words.push_back("GRAIN");// adds string object to vector
		words.push_back("BANANA");// adds string object to vector
		words.push_back("EXECUTE");// adds string object to vector
		words.push_back("REVERSE"); // adds string object to vector
		words.push_back("APPLE"); // adds string object to vector
		words.push_back("BAT"); // adds string object to vector
		words.push_back("TRAP"); // adds string object to vector
		words.push_back("GUY"); // adds string object to vector
		words.push_back("ITCH"); // adds string object to vector

		srand(time(0)); // seeding time to be random
		int shuffleTimes = rand() %50 + 1; // generates a random number of times to shuffle the list of words
		int shuffleCount = 0; // the current times the list has been shuffled
		while(shuffleCount < shuffleTimes)
		{
			random_shuffle(words.begin(), words.end()); // shuffles word list
			shuffleCount += 1; // increments var
		}

		// Display the simulation # is staring to the recruit. 
		cout << "\n\nSimulation #" << simCount << " beginning.\n\n";// outputs text to console with variables inserted



		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		const string CHOSEN_WORD1 = words[0];      //1st word to guess
		string soFar1(CHOSEN_WORD1.size(), '-');      // 1sd word guessed so far
		string usedLetters1 = "";					//1st letters already guessed

		const string CHOSEN_WORD2 = words[1];           //2nd word to guess
		string soFar2(CHOSEN_WORD2.size(), '-');         //2nd word guessed so far
		string usedLetters2 = "";                           //2nd letters already guessed

		const string CHOSEN_WORD3 = words[2];           //3rd word to guess
		string soFar3(CHOSEN_WORD3.size(), '-');         //3rd word guessed so far
		string usedLetters3 = "";                           //3rd letters already guessed



		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong < MAX_WRONG) && (soFar1 != CHOSEN_WORD1))
		{
			//Tell recruit how many incorrect guesses he or she has left
			cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n";// outputs text to console with variables inserted

			//Show recruit the letters he or she has guessed
			cout << "\nYou've used these letters:\n" << usedLetters1 << endl;// outputs text to console with variables inserted
			//Show player how much of the secret word he or she has guessed
			cout << "\nSo far, the word is:\n" << soFar1 << endl;// outputs text to console with variables inserted

			//Get recruit's next guess
			char guess; // creates variable for user input
			cout << "\n\nEnter your guess: ";// outputs text to console
			cin >> guess; // take user input
			guess = toupper(guess); // makes user input uppercase
			
			//While recruit has entered a letter that he or she has already guessed
			while (usedLetters1.find(guess) != string::npos)
			{
				cout << "\nYou've already used " << guess << endl;// outputs text to console with variables inserted
				cout << "Enter your guess: "; // outputs text to console
				//Get recruit ’s guess
				cin >> guess; // take user input
				guess = toupper(guess); // makes the user's input uppercase
			}
			//Add the new guess to the group of used letters
			usedLetters1 += guess; 

			//If the guess is in the secret word
			if (CHOSEN_WORD1.find(guess) != string::npos)
			{
				//Tell the recruit the guess is correct
				cout << "That's right! " << guess << " is in the word.\n";// outputs text to console with variables inserted

				//Update the word guessed so far with the new letter
				for (int i = 0; i < CHOSEN_WORD1.length(); ++i)

				{
					if (CHOSEN_WORD1[i] == guess)
					{
						soFar1[i] = guess;
					}
				}
			}

			//     Otherwise
			else
			{
				//Tell the recruit the guess is incorrect
				cout << "Sorry, " << guess << " isn't in the word.\n";// outputs text to console with variables inserted
				//Increment the number of incorrect guesses the recruit has made
				++wrong;
			}
		}

		if (wrong < MAX_WRONG)
		{
			cout << "You guessed the word " << CHOSEN_WORD1 << " with " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n";// outputs text to console with variables inserted
			system("pause");//waits for user input
			cout << "\n-------------------------------------------------------------------------------------------------------------"; // outputs text to console
		}



		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		// THIS IS A COPY OF THE ABOVE WHILE LOOP, WITH THE 2ND WORD'S VARIABLES INSERTED INSTEAD. IT BEHAVES EXACTLY THE SAME AS THE FIRST WHILE LOOP AND THE COMMENTS ARE THE SAME AS WELL
		while ((wrong < MAX_WRONG) && (soFar2 != CHOSEN_WORD2))
		{
			cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n";

			cout << "\nYou've used these letters:\n" << usedLetters2 << endl;
			cout << "\nSo far, the word is:\n" << soFar2 << endl;


			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess); 
			while (usedLetters2.find(guess) != string::npos)
			{
				cout << "\nYou've already used " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			usedLetters2 += guess;

			if (CHOSEN_WORD2.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word.\n";

				for (int i = 0; i < CHOSEN_WORD2.length(); ++i)

				{
					if (CHOSEN_WORD2[i] == guess)
					{
						soFar2[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}

		if (wrong < MAX_WRONG)
		{
			cout << "You guessed the word " << CHOSEN_WORD2 << " with " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n"; // outputs text to console with variables inserted
			system("pause"); //waits for user input
			cout << "\n-------------------------------------------------------------------------------------------------------------"; // outputs text to console
		}


		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		// THIS IS A COPY OF THE ABOVE WHILE LOOP, WITH THE 3ND WORD'S VARIABLES INSERTED INSTEAD. IT BEHAVES EXACTLY THE SAME AS THE FIRST WHILE LOOP AND THE COMMENTS ARE THE SAME AS WELL
		while ((wrong < MAX_WRONG) && (soFar3 != CHOSEN_WORD3))
		{
			cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n";

			cout << "\nYou've used these letters:\n" << usedLetters3 << endl;
			cout << "\nSo far, the word is:\n" << soFar3 << endl;

			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess); 
			while (usedLetters3.find(guess) != string::npos)
			{
				cout << "\nYou've already used " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			usedLetters3 += guess;

			if (CHOSEN_WORD3.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word.\n";

				for (int i = 0; i < CHOSEN_WORD3.length(); ++i)

				{
					if (CHOSEN_WORD3[i] == guess)
					{
						soFar3[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}

		if (wrong < MAX_WRONG)
		{
			cout << "You guessed the word " << CHOSEN_WORD3 << " with " << (MAX_WRONG - wrong) << " incorrect guesses remaining.\n"; // outputs text to console with variables inserted
			system("pause");
			cout << "\n-------------------------------------------------------------------------------------------------------------"; // outputs text to console
		}


		// If the recruit has made too many incorrect guesses
		if (wrong == MAX_WRONG)
		{
			//Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nYou've failed the CIA Recruit Code Breaker Training Simulation Program. Better luck next time!"; // outputs text to console
			simCount += 1;
		}

		// Otherwise
		else
		{
			//Congratulate the recruit on guessing the secret words
			cout << "\n Congratulations, you've passed the CIA Recruit Code Breaker Training Simulation Program.";  // outputs text to console
			simCount += 1;
		}

		// Ask the recruit if they would like to run the simulation again
		cout << "\n\nEnter '1' to try again, or enter any key to quit\n";
		cin >> Quit;

	}
	cout << "\n\n----------------------------------------------------------------------------------------------------------------------"; // outputs text to console

	//     Display End of Simulations to the recruit
	cout << "\nEnd of Simulations\n"; // outputs text to console
	cout << "\n Goodbye " << User << ".\n";// outputs text to console with variables inserted
	system("pause"); // waits for user input
	return 0; // returns 0 to main function
}