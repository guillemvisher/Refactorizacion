// VideoJuegoM16.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>;
using namespace std;

//Hero atributes
int heroHP = 250;
int heroDmg;
string heroName;
string atackOption;
bool heroIsAlive = true;

//Enemy1 Atributes
int enemy1Hp = 100;
int enemy1Dmg = 15;
string enemy1Name = "Thanos";
bool enemy1IsAlive = true;

//Enemy2 Atributes
int enemy2Hp = 120;
int enemy2Dmg = 20;
string enemy2Name = "Sauron";
bool enemy2IsAlive = true;

//Game atributes
int punchDmg = 25;
int swordDmg = 50;
int magicDmg = 60;
int magicPoints = 3;
int enemyChoosed = 0;

void gameStart() {
	cout << "Introduce your hero name\n";
		cin >> heroName;
		Sleep(1000);
		cout << "Your hero name is " << heroName << "\n";
		Sleep(1000);
		cout << "The game is about to start...\n";
		Sleep(1000);
		cout << "Wild " << enemy1Name << " has apeared\n";
		Sleep(1000);
		cout << "Wild " << enemy2Name << " has apeared\n";

}	

bool checkEnemyStatus1() {
	if (enemy1Hp <= 0) {
		cout << "You killed " << enemy1Name << "\n";
		enemy1Hp = 0;
		return false;
	}
	else {
		cout << enemy1Name << " has " << enemy1Hp << " health points\n\n";
			return true;
	}
}

bool checkEnemyStatus2() {
	if (enemy2Hp <= 0) {
		cout << "You killed " << enemy2Name << "\n";
		enemy2Hp = 0;
		return false;
	}
	else {
		cout << enemy2Name << " has " << enemy2Hp << " health points\n\n";
		return true;
	}
}

int chooseEnemy() {
	int enemyChoose = 0;
	while (enemyChoose != 1 && enemyChoose != 2) {
		cout << "Which enemy do you want to attack?\n";
		if (enemy1IsAlive) {
			cout << "1. " << enemy1Name << "\n";
		}
		if (enemy2IsAlive) {
			cout << "2. " << enemy2Name << "\n";
		}
		cin >> enemyChoose;
		if (enemyChoose <= 0 || enemyChoose > 2) {
			cout << "This option is not aviable. Try again \n";
		}
		if (!enemy1IsAlive && enemyChoose == 1) {
			cout << enemy1Name << " is already dead, choose an enemy who is still alive\n";
			enemyChoose = 0;
		}
		if (!enemy2IsAlive && enemyChoose == 2) {
			cout << enemy2Name << " is already dead, choose an enemy who is still alive\n";
			enemyChoose = 0;
		}
	}return enemyChoose;
}
	

int chooseAttack() {
	int attackChoose = 0;
	while (attackChoose != 1 && attackChoose != 2 && attackChoose != 3) {
		cout << "Which attack would you like to use?\n";
		cout << "1. Sword attack \n";
		cout << "2. Punch\n";
		if (magicPoints > 0) {
			cout << "3. Magic attack\n";
		}
		cin >> attackChoose;
		if (attackChoose <= 0 || attackChoose > 3) {
			cout << "This option is not aviable. Choose a valid one\n";
		}
		if (attackChoose == 3) {
			if (magicPoints > 0) {
				magicPoints--;
			}
			else {
				attackChoose = 0;
					cout << "You have not enough energy to use magic, chose another attack\n";
			}
		}
	}
	if (attackChoose == 1) {
		return swordDmg;
	}
	else if (attackChoose == 2) {
		return punchDmg;
	}
	else {
		return magicDmg;
	}
}

int heroAttackEnemy1(int dmg) {
	cout << "You attacked " << enemy1Name << " and dealt " << dmg << " damage points\n";
	return enemy1Hp - dmg;
}

int heroAttackEnemy2(int dmg) {
	cout << "You attacked " << enemy2Name << " and dealt " << dmg << " damage points\n";
	return enemy2Hp - dmg;
}

void enemy1Attack(int dmg) {
	heroHP = heroHP - dmg;
	if (heroHP > 0) {
		cout << enemy1Name << " attacked you and you have " << heroHP << " health point left\n";
	}
	else {
		cout << enemy1Name <<  " attacked and now you are dead. You failed your mission to save the world :( \n";
			heroIsAlive = false;
	}
}

void enemy2Attack(int dmg) {
	heroHP = heroHP - dmg;
	if (heroHP > 0) {
		cout << enemy2Name << " attacked you and you have " << heroHP << " health points left\n";
	}
	else {
		cout << enemy2Name << " attacked and now you are dead. You failed your mission to save the world :( \n";
		heroIsAlive = false;
	}
}
int main() {
	gameStart();
	//chooseEnemy();
	while (heroIsAlive && (enemy1IsAlive || enemy2IsAlive)) {
		enemyChoosed = chooseEnemy();
		heroDmg = chooseAttack();

		if (enemyChoosed == 1) {
			enemy1Hp = heroAttackEnemy1(heroDmg);
			enemy1IsAlive = checkEnemyStatus1();
		}
		else {
			enemy2Hp = heroAttackEnemy2(heroDmg);
			enemy2IsAlive = checkEnemyStatus2();
		}
		//Enemy1 attack
		if (enemy1IsAlive && heroIsAlive) {
			enemy1Attack(20 + rand() % 20);
		}
		if (enemy2IsAlive && heroIsAlive) {
			enemy2Attack(20 + rand() % 20);
		}
	}
	if (!enemy1IsAlive && !enemy2IsAlive) {
		cout << "Congratulations, you completed the game!\n";
	}
}