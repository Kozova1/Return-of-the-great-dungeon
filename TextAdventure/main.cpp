#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

int playerLocation = 2;
int score = 0;
int goblinHP = 10;
int dragonHP = 15;
int trollHP = 5;
int playerHP = 15;

bool riddleSolved = false;
bool trollKilled = false;
bool goblinKilled = false;
bool dragonKilled = false;
bool treasureLooted = false;

void convertInputToCommand(std::string playerInput);
void gameOver();

bool checkIfMoveLegal(int direction)
{
	switch (playerLocation)
	{
	case 1:
		if (riddleSolved)
		{
			if (direction == 2 || direction == 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;

	case 2:
		if (direction == 4 || direction == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case 3:
		if (trollKilled)
		{
			if (direction == 4 || direction == 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;

	case 6:
		if (direction == 1 || direction == 4)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case 5:
		if (direction == 2 || direction == 4)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case 4:
		if (goblinKilled)
		{
			if (direction == 1 || direction == 2 || direction == 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		break;

	case 7:
		if (direction == 1 || direction == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case 8:
		return false;
		break;
	default:
		return false;
		break;
	}
}

void getInputFromPlayerAsString()
{
	std::string playerInput;
	std::cin >> playerInput;
	std::cout << std::endl;
	convertInputToCommand(playerInput);
}

void descRoom()
{
	switch (playerLocation)
	{

	case 1:
		std::cout << "You are in a room with a riddle. The riddle is:" << std::endl;
		std::cout << "When my name is spoken aloud, I go away. Who am I?" << std::endl;
		getInputFromPlayerAsString();
		break;

	case 2:
		std::cout << "You're in a room with a small sign that says:" << std::endl;
		std::cout << "West for a riddle, East for a fight." << std::endl;
		std::cout << "There is a door to the East and a door to the West." << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;

	case 3:
		std::cout << "You're in a room with a door to the east and a door to the south" << std::endl;
		if (!trollKilled)
		{
			std::cout << "There's an angry troll about to attack you." << std::endl;
		}
		else
		{
			std::cout << "There's a troll corpse." << std::endl;
		}
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;

	case 4:
		std::cout << "You're in a room with one door to the west, one to the south and one to the north." << std::endl;
		if (!goblinKilled)
		{
			std::cout << "There's a mad goblin about to attack you." << std::endl;
		}
		else
		{
			std::cout << "There's a goblin corpse." << std::endl;
		}
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;

	case 5:
		std::cout << "You're in a room with a door to the east and a door to the west" << std::endl;
		if (!treasureLooted)
		{
			std::cout << "There's a treasure chest in the middle." << std::endl;
		}
		else
		{
			std::cout << "There's an empty treasure chest in the middle." << std::endl;
		}

		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;
	case 6:
		std::cout << "You're in a room with a small sign that says:" << std::endl;
		std::cout << "Treasure is to the West!. Fight is to the north." << std::endl;
		std::cout << "There is a door to the West and a door to the North." << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;
	case 7:
		std::cout << "You're in a room with a small sign that says:" << std::endl;
		std::cout << "East for the dragon, North for a fight." << std::endl;
		std::cout << "There is a door to the North and a door to the East." << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;
	case 8:
		std::cout << "You're in a room with one door to the East." << std::endl;
		if (!dragonKilled)
		{
			std::cout << "There's a red dragon about to attack you." << std::endl;
		}
		else
		{
			std::cout << "You Won!" << std::endl;
		}
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
		break;
	}
}

void convertInputToCommand(std::string playerInput)
{
	if (playerInput == "gon")
	{
		if (checkIfMoveLegal(1))
		{
			playerLocation -= 3;
			descRoom();
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
		else
		{
			std::cout << "Something is blocking the way." << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}
	else if (playerInput == "goe")
	{
		if (checkIfMoveLegal(2))
		{
			playerLocation += 1;
			descRoom();
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
		else
		{
			std::cout << "Something is blocking the way." << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}
	else if (playerInput == "gos")
	{
		if (checkIfMoveLegal(3))
		{
			playerLocation += 3;
			descRoom();
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
		else
		{
			std::cout << "Something is blocking the way." << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}
	else if (playerInput == "gow")
	{
		if (checkIfMoveLegal(4))
		{
			playerLocation -= 1;
			descRoom();
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
		else
		{
			std::cout << "Something is blocking the way." << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}
	
	else if (playerInput == "attack")
	{
		switch (playerLocation)
		{
			case 3:
				std::cout << "You hit the troll with your sword. It takes 2 points of damage." << std::endl;
				trollHP -= 2;
				if (trollHP <= 0)
				{
					trollKilled = true;
					std::cout << "The troll is now dead." << std::endl;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				else
				{
					std::cout << "It hits you back for 1 point of damage." << std::endl;
					playerHP -= 1;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				std::cout << "What do you do?" << std::endl;
				getInputFromPlayerAsString();
				break;
				
			case 4:
				std::cout << "You hit the goblin with your sword. It takes 2 points of damage." << std::endl;
				goblinHP -= 2;
				if (goblinHP <= 0)
				{
					goblinKilled = true;
					std::cout << "The goblin is now dead." << std::endl;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				else
				{
					std::cout << "It hits you back for 1 point of damage." << std::endl;
					playerHP -= 1;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				std::cout << "What do you do?" << std::endl;
				getInputFromPlayerAsString();
				break;

			case 8:
				std::cout << "You hit the dragon with your sword. It takes 2 points of damage." << std::endl;
				dragonHP -= 2;
				if (dragonHP <= 0)
				{
					dragonKilled = true;
					std::cout << "The dragon is now dead." << std::endl;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				else
				{
					std::cout << "It hits you back for 2 points of damage." << std::endl;
					playerHP -= 2;
					if (playerHP <= 0)
					{
						gameOver();
					}
				}
				std::cout << "What do you do?" << std::endl;
				getInputFromPlayerAsString();
				break;

			default:
				std::cout << "There's nothing to fight here!" << std::endl;
				std::cout << "What do you do?" << std::endl;
				getInputFromPlayerAsString();
				break;
		}
	}

	else if (playerInput == "loot")
	{
		if (playerLocation == 5 && treasureLooted == false)
		{
			score += 100;
			std::cout << "Looting was Successful! You got 100 point to your score!" << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}

	else if (playerInput == "desc")
	{
		descRoom();
		if (playerLocation == 1 && riddleSolved)
		{
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}

	}

	else if (playerInput == "guard")
	{
		if (playerLocation == 3 || playerLocation == 4 || playerLocation == 8)
		{
			std::cout << "You get hit but you manage to block the hit." << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
		else 
		{
			std::cout << "There's nothing to guard from!" << std::endl;
			std::cout << "What do you do?" << std::endl;
			getInputFromPlayerAsString();
		}
	}

	else if (playerInput == "HP")
	{
		std::cout << "You have " << playerHP << "HP" << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
	}

	else if (playerInput == "heal")
	{
		int healAmount = rand() % 3 + 1;
		playerHP += healAmount;
		std::cout << "You just healed yourself for " << healAmount << "HP" <<std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
	}

	else if (playerInput == "silence" && playerLocation == 1)
	{
		riddleSolved = true;
		std::cout << "That's right! The door to the south opens." << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
	}

	else if (playerInput == "exit")
	{
		exit(0);
	}
	else 
	{
		std::cout << "Invalid Command" << std::endl;
		std::cout << "What do you do?" << std::endl;
		getInputFromPlayerAsString();
	}
	
}

void gameOver()
{
	std::cout << "Game Over! You Died." << std::endl;
	std::cout << "Game will restart in 5 seconds." << std::endl;
	std::chrono::seconds sleep_duration(5);
	std::this_thread::sleep_for(sleep_duration);
	playerLocation = 2;
	playerHP = 15;
	descRoom();
}

int main()
{
	descRoom();
	return 0;
}