#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{

	//Arrays for 10 cards 
	int bank_card[10];
	int player_card[10];

	//Randon number generator
	srand(time(NULL));

	//Karten (Werte)
	bank_card[0] = (rand() % 10) + 2;
	bank_card[1] = (rand() % 10) + 2;

	player_card[0] = (rand() % 10) + 2;
	player_card[1] = (rand() % 10) + 2;

	//Save the count of cards and the sum
	int player_count = 2;
	int bank_sum = bank_card[0] + bank_card[1];
	int player_sum = player_card[0] + player_card [1];

	//Show cards
	printf("BLACKJACK \n");
	printf("Bank:\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n", bank_card[0], bank_card[0]);
	printf("Player:\n Card 1: %i\n Card 2: %i\n Sum: %i\n", player_card[0], player_card[1], player_sum);

	//Hit or stand
	char choice;

	do
	{
		choice = get_char("\n Hit (h) or Stand (s)? ");
		printf("\n");

		if (choice == 'h')
		{
			//Bank
			printf("Bank:\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n", bank_card[0], bank_card[0]);

			player_card[player_count] = (rand() % 10) + 2;
			player_sum += player_card[player_count];
			player_count++;
			printf("Player:\n");
			for (int i = 0; i < player_count; i++)
			{
				printf(" Card %i: %i\n", i + 1, player_card[i]);
			}
			printf("\n");
			printf(" Sum: %i\n", player_sum);

		}
		else if (choice == 's')
		{
			


		}
	}
	while("input missing");



















}

