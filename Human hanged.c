#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
//Get letter of user play
char getChr()
{
	char letter = getchar();
	letter = toupper(letter);
	while (getchar() != '\n');
	return letter;
}
// Check letter have exist in strings
bool checkLetter(char str[], char letter, int check[])
{
	int letterPresent = false;
	for (int i = 0; i < 8; i++)
	{
		if (letter == str[i])
		{
			check[i] = true;
			letterPresent = true;
		}

	}
	return letterPresent;
}
bool win(char checkLetter[])
{
	bool trimpuh = true;
	for (int i = 0; i < 8; i++)
	{
		if (checkLetter[i] == false)
			trimpuh = false;
	}
	return trimpuh;
}
int randomNumber(int number)
{
	srand(time(NULL));
	int random = rand() % number + 1;
	return random;
}
int selectString(char* beSelect)
{
	int saveLetter = 0;
	int serialNum = 0;
	int serialNum_Select = 0;
	FILE* list = NULL;
	errno_t list_;
	list_ = fopen_s(&list, "list.txt", "r");
	if (list == NULL)
		return 0;
	else
	{
		do
		{
			saveLetter = fgetc(list);
			if (saveLetter == '\n')
				serialNum++;

		} while (saveLetter != EOF);
	}
	serialNum_Select = randomNumber(serialNum);
	rewind(list);
	while (serialNum_Select > 0)
	{
		saveLetter = fgetc(list);
		if (saveLetter == '\n')
			serialNum_Select--;
	}
	fgets(beSelect, 1000, list);
	beSelect[strlen(beSelect - 1)] = '\0';
	fclose(list);
	return 1;
}
int main(int argc, char* argv[])
{
	printf("Welcom to play game Humaned Hanged!\n");
	//Turn play game is 10
	int turnNum = 10;
	//Array check letter have exist in strings
	int* check = NULL;
	//Strings secret of program
	char chrSecret[100] = { 0 };
	//Store diganose player
	char letterUser = 0;
	int len = 0;
	if (!selectString(chrSecret))
		exit(0);
	else
	{
		len = strlen(chrSecret);
		check = malloc(len * sizeof(int));
		if (check == NULL)
			exit(0);
		else
		{
			for (int i = 0; i < len; i++)
				check[i] = 0;
		}
	}
	while (turnNum > 0 && !win(check))
	{
		printf("You have %d turn diagnose\n", turnNum);
		printf("String number is: ");
		for (int i = 0; i < len; i++)
		{
			if (check[i])
				printf("%c", chrSecret);
			else
				printf("*");
		}
		printf("\nPlease diagnose letter any think is true: ");
		letterUser = getChr();
		if (!checkLetter(chrSecret, letterUser, check))
			turnNum--;
	}
	if (turnNum > 0 || win(check))
		printf("Congratulation! strings secret is '%s'\n", chrSecret);
	else
		printf("Condolatory:(! strings secret is '%s'\n", chrSecret);

}
