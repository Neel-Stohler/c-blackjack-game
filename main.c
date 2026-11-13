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
	int bank_card[0] = (rand() % 10) + 2;
	int bank_card[1] = (rand() % 10) + 2;

	int player_card[0] = (rand() % 10) + 2;
	int player_card[1] = (rand() % 10) + 2;

	int draw_card = (rand() % 10) + 2;

	//Save the count of cards and the sum
	int player_count = 2;
	int bank_sum = bank_card[0] + bank_card[1];
	int player_sum = player_card[0] + player_card [1];

	//Calculate sum
	int bank_sum = bank_card1 + bank_card2;
	int player_sum = player_card1 + player_card2;

	//Show cards
	printf("Blackjack");
	printf("Bank:\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n", bank_card[1], bank_card[1]);
	printf("Player:\n Card 1: %i\n Card 2: %i\n Sum: %i\n", player_card[1], player_card[2], player_sum);

	//Hit or stand
	char choice;

	do
	{
		choice == get_char("\n Hit (h) or Stand (s)? ");

		if (choice == 'h')
		{
			player_card[player_count] = (rand() % 10) + 2;
			player_sum + player_cards[player_count];
			player_count ++;
			printf("Player:\n Cards: %i\n Sum: %i\n", player_cards, player_sum);
		}
		else if (choice == 's')
		{

		}
	}
	while ();



















}

