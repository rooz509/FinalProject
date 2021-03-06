/*Algorithm
Start
	intro() called
	help() called
	do
		lvl1()
			if dead()
				then again() called and start over
		lvl2()
			if dead()
				then again() called and start over
		lvl3()
			if dead()
				then again() called and start over
		win()
	while again()
End
*/
/*
Created by: Micahel Ruzicka
CS131 8:30
6/14/18
Final Program
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>//for random number gen
#include <ctime>

using namespace std;
//declaring my functions
void intro();
bool again();
void lost();
void help();
void help2();
void dead();
void lvl1();
void lvl2();
void lvl3();
void win();



int main()
{
	
	intro();//call intro funtion
	help();//call help menu funtion
	do
	{
		lvl1();//level 1
		lvl2();//level 2
		lvl3();//level 3
		win();//win screen
		
	} while (again());//asks user if they want to play again
	system("pause");//good for testing
	return 0;
}//*****************end of main*****************

void intro()//introduction to what the program is about
{
	cout << "***********************************************************\n"
		<< "This is my final project, a game where you make the choices.\n"
		<< "You start your journey trapped in a room, and your goal is to escape.\n"
		<< "*********************************************************************\n" << endl;
}

void help()//a help menu with controls on how to play
{
	cout << "In this game you can only input two words, then press enter.\n"
		<< "There are only 4 commands words you can use: go, move, look and take.\n"
		<< "And you can combine those words with either a direction or something that's in the story.\n"
		<< "for example: go north, move table or look around \n" << endl;
}

void help2()//help menu for level 3, gives hint on how get to win()
{
	cout << "This room is different from the others. \n"
		<< "There is nothing to take or move in this room.\n"
		<< "You will have to figure another way out\n"
		<< "Choose your words wisely.\n"
		<< "Hint: Sometimes there is nothing you can do\n" << endl;
}

bool again()//asks user if they want to run the program again
{
	string input;

	cout << "\n\nWant to run program again? (y/n) ";
	cin >> input;
	input = input[0];
	while (input != "n" && input != "N" && input != "y" && input != "Y")
	{
		cout << "\n********Error Input!***********\n"
			<< "Enter 'y' for yes or 'n' for no.\n";
		cin >> input;

	}
	if (input == "Y" || input == "y")
		return true;
	else 
		return false;
}

void lost()//default sayings for incorrect text input 
{
	srand((unsigned)time(0));
	int rng = (rand()%10)+1;// random number generator to generate numbers 1 -10
	//cout << rng << endl; //used for testing
	switch (rng)//switch case statmemt depending on what rng equals, then random output is given
	{
		case 1: cout << "You're lost.(Type 'help me' for help)\n";
			break;
		case 2: cout << "You're really lost.(Type 'help me' for help)\n";
			break;
		case 3: cout << "That does nothing.(Type 'help me' for help)\n ";
			break;
		case 4: cout << "Umm, What?(Type 'help me' for help)\n ";
			break;
		case 5: cout << "Maybe check your spelling.(Type 'help me' for help)\n ";
			break;
		case 6: cout << "What chu talkin' bout?(Type 'help me' for help)\n ";
			break;
		case 7: cout << "Hmmm, interesting choice(Type 'help me' for help)\n ";
			break;
		case 8: cout << "Why?(Type 'help me' for help)\n ";
			break;
		default: cout << "Good luck with that.(Type 'help me' for help)\n";
	}
	

}

void dead()//death screen for when user dies in game, then again() called to see if they want to play again
{
	cout << "You have died\n"
		<<"Maybe you shouldn't have done that\n" << endl;
	again();
}

void win()//win screen if user makes it past level 3
{
	cout <<"\n**********************\n" 
		<< "CONGRATULATIONS!!!\n"
		<< "You have escaped!\n"
		<< "************************\n\n"
		<< endl;
}

void lvl1()//level 1
{
	string in1, in2;//user input
	string const choice[4]{ "go", "move", "take", "look" };//array for holding the command words
	string const direction[5]{ "north", "east", "south", "west", "around" };//array for direction words
	string const stuff[5]{ "painting", "cookie", "door", "table", "statue"};//array for story words
	bool item = false;//boolean for checking if item was used(true) or not
	do//second do while loop to get out of lvl1(). only after first do while loop is broken through
	{
		do//first do while loop, checks if bool item is true 
		{

			cout << "\nWhat would you like to do? \n";//only question that gets asked thoughout entire game
			cin >> in1 >> in2;//user input

			if (in1 == choice[3] && in2 == direction[4])
			{
				cout << "As you look around, you are in a room with north, east\n"
					<< "south and west walls. To inspect further type 'go' and the direction\n\n";
			}
			else if (in1 == choice[0] && in2 == direction[0])//notice this combo has two different outcomes depending if bool is triggered
			{
				if (item != true)
				{
					cout << "You are at the North wall, you see a door, but it is locked.\n";//will be output until user finds the bool item
				}
				else cout << "You open the door and go through it. You have escaped the first room!\n";//after bool item = true
			}
			else if (in1 == choice[1] && in2 == stuff[2])
			{
				cout << "The door is immovable. \n";
			}
			else if (in1 == choice[2] && in2 == stuff[2])
			{
				cout << "You can't take the door, it's a door. \n";
			}
			else if (in1 == choice[3] && in2 == stuff[2])
			{
				cout << "You look at the door,and see that it's locked. \n";
			}
			else if (in1 == choice[0] && in2 == direction[1])
			{
				cout << "You are at East wall, you see a suspicious cookie on a table. \n";
			}
			else if (in1 == choice[1] && in2 == stuff[1])
			{
				cout << "You move the cookie to one side of the table to the other. Then you wonder why you would do that\n";
			}
			else if (in1 == choice[2] && in2 == stuff[1])
			{
				cout << "You take the cookie and eat it. As you're eating it, you notice you don't feel good...\n";
				dead(); //if this choice is made, dead() function is called and player has to restart level
			}
			else if (in1 == choice[3] && in2 == stuff[1])
			{
				cout << "You look at the cookie and see it is chocolate chip.\n";
			}
			else if (in1 == choice[1] && in2 == stuff[3])
			{
				cout << "You move the table, but nothing else happens\n";
			}
			else if (in1 == choice[2] && in2 == stuff[3])
			{
				cout << "You can't take the table, it dosen't belong to you.\n";
			}
			else if (in1 == choice[3] && in2 == stuff[3])
			{
				cout << "You look at the table, and notice the fine craftsmanship.\n";
			}
			else if (in1 == choice[0] && in2 == direction[2])
			{
				cout << "You are at the South wall, you see a statue of a dog on the floor.\n";
			}
			else if (in1 == choice[1] && in2 == stuff[4])
			{
				cout << "You can't move the statue, it is too heavy\n";
			}
			else if (in1 == choice[2] && in2 == stuff[4])
			{
				cout << "You can't take the statue, it ties the room together.\n";
			}
			else if (in1 == choice[3] && in2 == stuff[4])
			{
				cout << "You look at the statue for anything useful, but there dosen't seem to be anything that can help you. \n";
			}
			else if (in1 == choice[0] && in2 == direction[3])
			{
				cout << "You are at the West wall, you see a painting of a boat that is hung askew\n";
			}
			else if (in1 == choice[1] && in2 == stuff[0])
			{
				cout << "When you move the painting, you hear a clicking noise from the North door.\n";
				item = true;//when this choice is made, bool item becomes true, which breaks you out of first do while loop
			}
			else if (in1 == choice[2] && in2 == stuff[0])
			{
				cout << "You can't take the painting. It's not yours, thief.\n";
			}
			else if (in1 == choice[3] && in2 == stuff[0])
			{
				cout << "You look at the painting and feel good for taking the time to admire the artwork.\n";
			}
			else if ((in1 == "help" && in2 == "me") || (in1 == "get" && in2 == "help"))
			{
				help(); //calls help function to display help menu
			}
			else
			{
				lost();//calls lost function for default error messages
			}

		} while (item != true);
	} while (in1 != choice[0] && in2 != direction[0]);
}//***************end of lvl1()*****************************************************

void lvl2()
{
	string in1, in2;// same as lvl1()
	string const choice[4]{ "go", "move", "take", "look" };
	string const direction[5]{ "north", "east", "south", "west", "around" };
	string const stuff[5]{ "keyhole", "painting", "bottle", "table", "key" };//different story words for lvl2()
	string const special[3]{ "push", "button", "drink" };//specail words that are not listed in help menu
	bool item = false;
	bool item2 = false;//second bool to be triggered before escape from first do while loop
	
	cout << "\n\nAs you enter the next room, the door behind you closes, and the handle dissapears.\n"
		<< "You are now trapped...again\n\n";//quick intro to lvl2()
	do
	{
		do
		{

			cout << "\nWhat would you like to do? \n";
			cin >> in1 >> in2;

			if (in1 == choice[3] && in2 == direction[4])
			{
				cout << "As you look around, it looks similar to the room before, there are still north, east\n"
					<< "south and west walls. To inspect further type 'go' and the direction\n\n";
			}
			else if (in1 == choice[0] && in2 == direction[0])
			{
				if (item != true)//same as lvl1(), with different output depending on bool item
				{
					cout << "You are at the North wall, you see empty wall, except for a keyhole in the center of the wall.\n";
				}
				else
					cout << "You use the key to unlock the keyhole. A door appears where the keyhole was, and you enter. You have escaped the second room!";
			}
			else if (in1 == choice[1] && in2 == stuff[0])
			{
				cout << "You can't move a keyhole. \n";
			}
			else if (in1 == choice[2] && in2 == stuff[0])
			{
				cout << "You can't take the keyhole, it's a keyhole. \n";
			}
			else if (in1 == choice[3] && in2 == stuff[0])
			{
				cout << "You look in the keyhole, but can't see through it.  \n";
			}
			else if (in1 == choice[0] && in2 == direction[1])
			{
				cout << "You are at East wall, you see a painting of a dog statue hung properly. \n";
			}
			else if (in1 == choice[1] && in2 == stuff[1])
			{
				cout << "You move the painting, but nothing happens.\n";
			}
			else if (in1 == choice[2] && in2 == stuff[1])
			{
				cout << "You take the painting off the wall, then the painting explodes. \n";
				dead();//just another way to die
			}
			else if (in1 == choice[3] && in2 == stuff[1])
			{
				cout << "You look at the painting, and it looks like the statue from the previous room.\n";
			}
			else if (in1 == choice[0] && in2 == direction[2])
			{
				cout << "You are at the South wall, you see a bottle of mysterious liquid, and a sign that says 'drink me'\n";
			}
			else if (in1 == choice[1] && in2 == stuff[2])
			{
				cout << "You move the bottle around the table, nothing else happens.\n";
			}
			else if ((in1 == choice[2] || in1 == special[2]) && in2 == stuff[2])
			{
				cout << "You take the bottle and drink it. You start to grow, then you shrink back down to normal size.\n" 
					<< "Then you get the urge to watch Alice in Wonderland.\n";
			}
			else if (in1 == choice[3] && in2 == stuff[2])
			{
				cout << "You look at the bottle, it seems like a normal bottle, but with a strange blue liquid.\n";
			}
			else if (in1 == choice[1] && in2 == stuff[3])
			{
				cout << "You move the table, and can tell that something is underneath it. \n";
			}
			else if (in1 == choice[2] && in2 == stuff[3])
			{
				cout << "You can't take the table, it dosen't belong to you.\n";
			}
			else if (in1 == choice[3] && in2 == stuff[3])
			{
				cout << "You look at the table, and notice that underneath it is a key.\n";
				item2 = true;//this choice unlocks bool item2 to get to bool item
			}
			else if (in1 == choice[1] && in2 == stuff[4])
			{
				cout << "You move the key to the top of the table. \n";
			}
			else if (in1 == choice[2] && in2 == stuff[4])
			{
				if (item2 != true)//defualt saying if item2 is not found(true)
				{
					cout << "What key?\n";
				}
				else
				{
					cout << "You take the key. It seems to fit in the North keyhole\n";//once you unlock item2, you can move on past do while loop
					item = true;//only unlocked when item2 is unlocked
				}
			}
			else if (in1 == choice[3] && in2 == stuff[4])
			{
				cout << "You look at the key, and it seems to fit the keyhole.\n";
			}
			else if (in1 == choice[0] && in2 == direction[3])
			{
				cout << "You are at the West wall, you see a big red button and a sign thats says 'Do Not Push Button'.\n";
			}
			else if (in1 == choice[1] && in2 == special[1])
			{
				cout << "You can't move the button.\n";
			}
			else if (in1 == choice[2] && in2 == special[1])
			{
				cout << "You can't take the button.\n";
			}
			else if (in1 == choice[3] && in2 == special[1])
			{
				cout << "You look at the button. It's red. And the sign is ominous.\n";
			}
			else if (in1 == special[0] && in2 == special[1])
			{
				cout << "You push the button and hear a beeping noise. When the beeping ends, the room explodes.\n";
				dead();//a special way to die
			}
			else if ((in1 == "help" && in2 == "me") || (in1 == "get" && in2 == "help"))
			{
				help();
			}
			else
			{
				lost();
			}

		} while (item != true);
	} while (in1 != choice[0] && in2 != direction[0]);
}//**********************************end of lvl2()************************************************

void lvl3()
{
	string in1, in2;
	string const choice[6]{ "go", "pull", "flip", "look", "push", "turn" };//new command words
	string const direction[5]{ "north", "east", "south", "west", "around" };
	string const stuff[5]{ "button", "switch", "lever", "dial" };//new story words
	string const special[4]{ "do", "nothing", "leave", "room" };//end game words
	bool item = false;

	cout << "\n\nAs you enter the last room, the door behind you closes and locks.\n"//intro to lvl3()
		<< "You are trapped once again, but this time you get the feeling like anything you do will cause certain doom.\n\n";

	do
	{
		do
		{

			cout << "\nWhat would you like to do? \n";
			cin >> in1 >> in2;

			if (in1 == choice[3] && in2 == direction[4])
			{
				cout << "As you look around, it seems to be the most empty of all the rooms, but there \n"
					<< "are still north, east, south and west walls. To inspect further type 'go' and the direction\n\n";
			}
			else if (in1 == choice[0] && in2 == direction[0])
			{
				cout << "You are at the North wall, you see a blue button with a sign that reads 'Push Me'\n ";
			}
			else if (in1 == choice[4] && in2 == stuff[0])
			{
				cout << "\nYou push the button, the room explodes. You shouldn't do whatever a sign tells you.\n";
				dead();//death 1
			}
			else if ((in1 == choice[2] || in1 == choice[3] || in1 == choice[5]) && in2 == stuff[0])
			{
				cout << "Nothing happens.\n";
			}
			else if (in1 == choice[0] && in2 == direction[1])
			{
				cout << "You are at the East wall, you see a switch that is flipped in the 'off' position.\n";
			}
			else if (in1 == choice[2] && in2 == stuff[1])
			{
				cout << "\nYou flip the switch to the 'on' position. A pile of snakes falls on top of you and all start biting you.\n"
					<< "Why'd it have to be snakes?\n";
				dead(); //death 2
			}
			else if ((in1 == choice[1] || in1 == choice[3] || in1 == choice[5]) && in2 == stuff[1])
			{
				cout << "Nothing happens.\n";
			}
			else if (in1 == choice[0] && in2 == direction[2])
			{
				cout << "You are at the South wall, and see a lever that you can pull. With a sign that says 'Watch out'.\n";
			}
			else if (in1 == choice[1] && in2 == stuff[2])
			{
				cout << "\nA trap door opens up beneath your feet. You fall into a pit of lava.\n"
					<< "The sign did tell you to watch out.\n";
				dead(); // death 3
			}
			else if ((in1 == choice[2] || in1 == choice[3] || in1 == choice[5]) && in2 == stuff[2])
			{
				cout << "Nothing happens.\n";
			}
			else if (in1 == choice[0] && in2 == direction[3])
			{
				cout << "You are at the West wall, there is a dial that is set to 0 and goes up to 11\n";
			}
			else if (in1 == choice[5] && in2 == stuff[3])
			{
				cout << "\nYou turn the dial to 11. A strange band starts playing that you've probably never heard of.\n"
					<< "A Liger (lion and tiger mix) comes out of the wall and eats you.\n";
				dead();//death 4
			}
			else if ((in1 == choice[1] || in1 == choice[2] || in1 == choice[3]) && in2 == stuff[3])
			{
				cout << "Nothing happens.\n";
			}
			else if (in1 == special[0] && in2 == special[1])//the way out
			{
				cout << "You stand there doing nothing with the fear that, whatever you may do may kill you.\n"
					<< "As you are about to give up hope, you hear a bell ding.\n"
					<<"All four walls drop and reveal the outside world.\n "
					<<"The only thing left to do is leave the room.\n";
				item = true;
			}
			else if ((in1 == "help" && in2 == "me") || (in1 == "get" && in2 == "help"))
			{
				help2();//new help menu for this level, gives hint on how to escape
			}
			else
			{
				lost();
			}

		} while (item != true);
	} while (in1 != special[2] && in2 != special[3]);//new escape route

}//**********************end of lvl3()*****************************************