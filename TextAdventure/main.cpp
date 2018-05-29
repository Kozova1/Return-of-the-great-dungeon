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
std::string playerInput;
bool riddleSolved = false;
bool trollKilled = false;
bool goblinKilled = false;
bool dragonKilled = false;
bool treasureLooted = false;
bool wantToExit = false;
void convertInputToCommand();
void gameOver();
void move(int direction);
void descRoom();
void HP();
void heal();
void guard();
void attack();
void loot();

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
	std::cin >> playerInput;
	std::cout << "\n";
}

void move(int direction)
{
	switch (direction)
	{
	case 1:
		if (checkIfMoveLegal(1))
		{
			playerLocation -= 3;
			descRoom();
			
		}
		else
		{
			std::cout << "Something is blocking the way.\n";
			
		}
		break;
	case 2:
		if (checkIfMoveLegal(2))
		{
			playerLocation += 1;
			descRoom();
			
		}
		else
		{
			std::cout << "Something is blocking the way.\n";
		}
		break;
	case 3:
		if (checkIfMoveLegal(3))
		{
			playerLocation += 3;
			descRoom();
		}
		else
		{
			std::cout << "Something is blocking the way.\n";
		}
		break;
	case 4:
		if (checkIfMoveLegal(4))
		{
			playerLocation -= 1;
			descRoom();
		}
		else
		{
			std::cout << "Something is blocking the way.\n";
		}
		break;
	default:
		break;
	}
}

void descRoom()
{
	switch (playerLocation)
	{

	case 1:
		std::cout << "You are in a room with a riddle. The riddle is:\n";
		std::cout << "When my name is spoken aloud, I go away. Who am I?\n";
		break;

	case 2:
		std::cout << "You're in a room with a small sign that says:\n";
		std::cout << "West for a riddle, East for a fight.\n";
		std::cout << "There is a door to the East and a door to the West.\n";
		break;

	case 3:
		std::cout << "You're in a room with a door to the east and a door to the south\n";
		if (!trollKilled)
		{
			std::cout << "There's an angry troll about to attack you.\n";
		}
		else
		{
			std::cout << "There's a troll corpse.\n";
		}
		break;

	case 4:
		std::cout << "You're in a room with one door to the west, one to the south and one to the north.\n";
		if (!goblinKilled)
		{
			std::cout << "There's a mad goblin about to attack you.\n";
		}
		else
		{
			std::cout << "There's a goblin corpse.\n";
		}
		break;

	case 5:
		std::cout << "You're in a room with a door to the east and a door to the west\n";
		if (!treasureLooted)
		{
			std::cout << "There's a treasure chest in the middle.\n";
		}
		else
		{
			std::cout << "There's an empty treasure chest in the middle.\n";
		}
		break;
	case 6:
		std::cout << "You're in a room with a small sign that says:\n";
		std::cout << "Treasure is to the West!. Fight is to the north.\n";
		std::cout << "There is a door to the West and a door to the North.\n";
		break;
	case 7:
		std::cout << "You're in a room with a small sign that says:\n";
		std::cout << "East for the dragon, North for a fight.\n";
		std::cout << "There is a door to the North and a door to the East.\n";
		break;
	case 8:
		std::cout << "You're in a room with one door to the East.\n";
		if (!dragonKilled)
		{
			std::cout << "There's a red dragon about to attack you.\n";
		}
		else
		{
			std::cout << "You Won!\n";
		}
		break;
	}
}

void convertInputToCommand()
{
	if (playerInput == "gon") 
	{
		move(1);
	}

	else if (playerInput == "goe")
	{
		move(2);
	}

	else if (playerInput == "gos")
	{
		move(3);
	}

	else if (playerInput == "gow")
	{
		move(4);
	}
	
	else if (playerInput == "attack")
	{
		attack();
	}

	else if (playerInput == "loot")
	{
		loot();
	}

	else if (playerInput == "desc")
	{
		descRoom();
	}

	else if (playerInput == "guard")
	{
		guard();
	}

	else if (playerInput == "HP")
	{
		HP();
	}

	else if (playerInput == "heal")
	{
		heal();
	}

	else if (playerInput == "silence" && playerLocation == 1)
	{
		riddleSolved = true;
		std::cout << "That's right! The door to the south opens.\n";
	}

	else if (playerInput == "exit")
	{
		wantToExit = true;
	}
	else 
	{
		std::cout << "Invalid Command\n";
	}
	
}

void guard()
{
	if (playerLocation == 3 || playerLocation == 4 || playerLocation == 8)
	{
		std::cout << "You get hit but you manage to block the hit.\n";
		playerHP += 2;
	}
	else
	{
		std::cout << "There's nothing to guard from!\n";
	}
}

void loot()
{
	if (playerLocation == 5 && treasureLooted == false)
	{
		score += 100;
		std::cout << "Looting was Successful! You got 100 point to your score!\n";
		treasureLooted = true;
	}
}

void attack()
{
	switch (playerLocation)
	{
	case 3:
		if (!trollKilled)
		{
			std::cout << "You hit the troll with your sword. It takes 2 points of damage.\n";
			trollHP -= 2;
			if (trollHP <= 0)
			{
				trollKilled = true;
				std::cout << "The troll is now dead.\n";
			}
		}
		else
		{
			std::cout << "There's nothing to fight here!\n";
		}
		break;

	case 4:
		if (!goblinKilled)
		{
			std::cout << "You hit the goblin with your sword. It takes 2 points of damage.\n";
			goblinHP -= 2;
			if (goblinHP <= 0)
			{
				goblinKilled = true;
				std::cout << "The goblin is now dead.\n";
			}
		}
		else
		{
			std::cout << "There's nothing to fight here!\n";
		}
		break;

	case 8:
		if (!dragonKilled)
		{
			std::cout << "You hit the dragon with your sword. It takes 2 points of damage.\n";
			dragonHP -= 2;
			if (dragonHP <= 0)
			{
				dragonKilled = true;
				std::cout << "The dragon is now dead.\n";
			}
		}
		else 
		{
			std::cout << "There's nothing to fight here!\n";
		}
		break;

	default:
		std::cout << "There's nothing to fight here!\n";
		break;
	}
}

void gameOver()
{
	std::cout << "That hit was too much for you.";
	std::cout << "You Died.\n";
	std::cout << "Game will restart in 5 seconds.\n";
	playerHP = 15;
	playerLocation = 2;
	playerInput = "";
	std::chrono::seconds sleep_duration(5);
	std::this_thread::sleep_for(sleep_duration);
	descRoom();
}

void heal()
{
	int healAmount = rand() % 3 + 1;
	playerHP += healAmount;
	std::cout << "You just healed yourself for " << healAmount << "HP\n";
}

void HP()
{
	std::cout << "You have " << playerHP << "HP\n";
}

int main()
{
	descRoom();
	while (!wantToExit)
	{
		if (playerHP > 0)
		{
			std::cout << "What do you do?\n";
			getInputFromPlayerAsString();
			convertInputToCommand();
			switch (playerLocation)
			{
				case 3:

					if (!trollKilled)
					{
						std::cout << "It hits you for 2 points of damage.\n";
						playerHP -= 2;
					
					}

					break;
			
				case 4:

					if (!goblinKilled)
					{
						std::cout << "It hits you for 2 points of damage.\n";
						playerHP -= 2;
					}

					break;
				case 8:

				if (!dragonKilled)
				{
					std::cout << "It hits you for 2 points of damage.\n";
					playerHP -= 2;
				}

				break;


				default:

				break;
			}
		}
		else
		{
			gameOver();
		}
	}
	return 0;
}
	