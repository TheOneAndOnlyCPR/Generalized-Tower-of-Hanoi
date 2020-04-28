#include <iostream>
#include <string>
using namespace std;

class Tower {
private:
	int rings;
	string initialTower;
	string finalTower;
	int stepcount;

	char getInitialMiddleTower(int height, string initialTower) {
		if ((initialTower[initialTower.length() - height] == 'A' && initialTower[initialTower.length() - height - 1] == 'B') || (initialTower[initialTower.length() - height] == 'B' && initialTower[initialTower.length() - height - 1] == 'A'))
			return 'C';
		if ((initialTower[initialTower.length() - height] == 'B' && initialTower[initialTower.length() - height - 1] == 'C') || (initialTower[initialTower.length() - height] == 'C' && initialTower[initialTower.length() - height - 1] == 'B'))
			return 'A';
		if ((initialTower[initialTower.length() - height] == 'A' && initialTower[initialTower.length() - height - 1] == 'C') || (initialTower[initialTower.length() - height] == 'C' && initialTower[initialTower.length() - height - 1] == 'A'))
			return 'B';
	}

	char getFinalMiddleTower(int height, string initialTower, string finalTower) {
		if ((initialTower[height - 1] == 'A' && finalTower[height - 1] == 'B') || (finalTower[height - 1] == 'A' && initialTower[height - 1] == 'B'))
			return 'C';
		if ((initialTower[height - 1] == 'B' && finalTower[height - 1] == 'C') || (finalTower[height - 1] == 'B' && initialTower[height - 1] == 'C'))
			return 'A';
		if ((initialTower[height - 1] == 'A' && finalTower[height - 1] == 'C') || (finalTower[height - 1] == 'A' && initialTower[height - 1] == 'C'))
			return 'B';
	}

	string adjustInitialTowerString(int height, string initialTower) {
		char replaceWith = initialTower[initialTower.length() - height - 1];
		while (height > 0) {
			initialTower[initialTower.length() - height] = replaceWith;
			height--;
		}
		return initialTower;
	}
	
	string adjustFinalTowerString(int height, string initialTower, string finalTower) {
		char replaceWith = finalTower[height - 1];
		while (height <= initialTower.length()) {
			initialTower[height - 1] = replaceWith;
			height++;
		}
		return initialTower;
	}

	void moveMiniTower(int height, char startTower, char middleTower, char endTower, int &testcount) {
		if (height == 0) {
			return;
		}
		moveMiniTower(height - 1, startTower, endTower, middleTower, testcount);
		cout << testcount++ << ". " << "Move " << startTower << " to " << endTower << "." << endl;
		moveMiniTower(height - 1, middleTower, startTower, endTower, testcount);
	}

	void sortInitialTower() {
		int height = 1;
		for (int i = initialTower.length(); i > 1; i--) {
			cout << "The tower is currently " << initialTower << "." << endl;
			if (initialTower[initialTower.length() - height] != initialTower[initialTower.length() - height - 1]) {
				char middleTower = getInitialMiddleTower(height, initialTower);
				moveMiniTower(height, initialTower[initialTower.length() - height], middleTower, initialTower[initialTower.length() - height - 1], stepcount);
				initialTower = adjustInitialTowerString(height, initialTower);
			}
			cout << "The tower is now " << initialTower << "." << endl;
			height++;
		}
		cout << "The tower is now stacked on peg " << initialTower[0] << "." << endl;
	}

	void sortFinalTower() {
		int height = 1;
		for (int i = 1; i <= initialTower.length(); i++) {
			cout << "The tower is currently " << initialTower << "." << endl;
			if (initialTower[i - 1] != finalTower[i - 1]) {
				char middleTower = getFinalMiddleTower(height, initialTower, finalTower);
				moveMiniTower(initialTower.length() - height + 1, initialTower[height - 1], middleTower, finalTower[height - 1], stepcount);
				initialTower = adjustFinalTowerString(height, initialTower, finalTower);
			}
			cout << "The tower is now " << initialTower << "." << endl;
			height++;
		}
		cout << "The tower is now arranged in the order " << initialTower << "." << endl;
	}

public:
	Tower() {
		rings = 3;
		initialTower = "AAA";
		finalTower = "AAA";
		stepcount = 1;
	}
	Tower(int n, string initial, string final) {
		rings = n;
		initialTower = initial;
		finalTower = final;
		stepcount = 1;
	}

	void arrangeTower() {
		sortInitialTower();
		sortFinalTower();
	}
};

int main() {

	string initialTower;
	string finalTower;
	cout << "Enter the inital position of the Tower of Hanoi." << endl;
	cin >> initialTower;
	cout << "Enter the desired final position of the Tower of Hanoi." << endl;
	cin >> finalTower;

	for (int i = 0; i < initialTower.length(); i++)
	{initialTower[i] = toupper(initialTower[i]);}
	for (int i = 0; i < finalTower.length(); i++)
	{finalTower[i] = toupper(finalTower[i]);}

	if (initialTower.length() == finalTower.length()) {
		cout << "Moving the tower from " << initialTower << " to " << finalTower << "." << endl;
		Tower Hanoi(initialTower.length(), initialTower, finalTower);

		Hanoi.arrangeTower();
	}
	else {
		cout << "The sizes of your towers do not match." << endl;
	}
	
	return 0;
}
