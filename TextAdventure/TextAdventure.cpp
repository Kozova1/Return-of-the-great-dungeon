// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>

//here we get the input from the user as a single word because I'm too lazy to make it work otherwise
std::string getInputFromUser() 
{
	std::string inputReceived;
	std::getline(std::cin, inputReceived);
	return inputReceived;
}

//here we convert the input to an Int because switch() doesnt work with std::string :(
int convertInputToInt()
{
	std::string userInput = getInputFromUser();
	if (userInput == "yes") {
		return 0;
	}
	else if (userInput == "no") {
		return 1;
	}
	else if (userInput == "gon") {
		
	}
	else if (userInput == "goe") {
		
	}
	else if (userInput == "gos") {
		
	}
	else if (userInput == "gow") {
		
	}
	//loot the room
	else if (userInput == "loot") {
		return 2;
	}
	else if (userInput == "attackmelee") {
		return 3;
	}
	else if (userInput == "attackmagic") {
		return 4;
	}
	else if (userInput == "attackranged") {
		return 5;
	}
	//describe again the room
	else if (userInput == "desc") {
		desc(room);
	}
	//answer to riddle in room NW
	else if (userInput == "silence") {
		return 7;
	}
	//invalid command
	else {
		
		return 42;
	}

}

//answer is silence
void descRoom1() 
{
	std::cout << "This room is disturbingly silent. There's a locked door to the south." << std::endl; 
	std::cout << " There's a small sign with the sentence: When my name is spoken aloud I disappear." << std::endl;
	std::cout << "What am I?(Type the answer)" << std::endl;
}

//starting room
void descRoom2() 
{
	std::cout << "You stand in a room. there are two unlocked doors which lead both east and west." << std::endl;
	std::cout << "Where do you go?" << std::endl;
}

//Fight room, fight with troll
void descRoomNETNotDead()
{
	std::cout << "You've entered a small room with a troll and two doors, one to the west and one to the south." << std::endl;
	std::cout << "The troll swings it's mace at you and misses. what do you do?" << std::endl;
}

void descRoomNETDead()
{
	std::cout << "You've entered a small room with a troll corpse and two doors, one to the west and one to the south." << std::endl;
	std::cout << "What do you do?" << std::endl;
}

//Empty room E
void descRoomE()
{
	std::cout << "You enter an empty room. there is a door to the north, a door to the south and one to the west." << std::endl;
	std::cout << "Where do you go?" << std::endl;
}

//Treasure room
void descRoomC() 
{
	std::cout << "You enter a big room with a door to the east and a door to the west. there's an unlocked chest in the middle." << std::endl;
	std::cout << "What do you do?" << std::endl;
}

//Fight room W fight with goblin
void descRoomWGNotDead() 
{
	std::cout << "You enter a big room with a goblin. there are doors to the north, east and south." << std::endl;
	std::cout << "The goblin swings his sword at you and misses. what do you do?" << std::endl;
}

void descRoomWGDead()
{
	std::cout << "You enter a big room with a goblin corpse. there are doors to the north, east and south." << std::endl;
	std::cout << "What do you do?" << std::endl;
}

//Empty room SW
void descRoomSW() 
{
	std::cout << "You enter an empty room. there's a door to the north and a door to the east" << std::endl;
	std::cout << "There's an engraved sentenceon the door to the east: Don't annoy the red dragon." << std::endl;
	std::cout << "What do you do?" << std::endl;
}
//Dragon Boss Room
void descRoomSDNotDead()
{
	std::cout << "You enter a large room with a red dragon. The dragon looks angry at you for annoying him" << std::endl;
	std::cout << "He guards a portal to the unknown. What do you do?" << std::endl;
}

void dragonKilled() 
{
	std::cout << "The dragon falls to the ground, dead. The portal draws you in." << std::endl;
	std::cout << "The End...               Or is it???" << std::endl;
	std::cout << "Thanks for playing this game made by Kozova1" << std::endl;
}



int main()
{
    return 0;
}

