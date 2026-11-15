#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{

	//Arrays for 10 cards 
	int bank_card[12];
	int player_card[12];

	//Randon number generator
	srand(time(NULL));

	//Karten (Werte)
	bank_card[0] = (rand() % 10) + 2;
	bank_card[1] = (rand() % 10) + 2;

	player_card[0] = (rand() % 10) + 2;
	player_card[1] = (rand() % 10) + 2;

	//Save the count of cards and the sum
	int bank_count = 2;
	int player_count = 2;
	int bank_sum = bank_card[0] + bank_card[1];
	int player_sum = player_card[0] + player_card [1];

	//Show cards
	printf("\n\nBLACKJACK \n\n");
	printf("Bank:\n\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n\n", bank_card[0], bank_card[0]);
	printf("Player:\n\n Card 1: %i\n Card 2: %i\n Sum: %i\n", player_card[0], player_card[1], player_sum);

	//Hit or stand
	char choice;

	do
	{

	  choice = get_char("\nHit (h) or Stand (s)? ");
                printf("\n");

          	
		if (choice != 'h' && choice != 's')
                {
                        printf("Invalid input, please enter Hit (h) or Stand (s)"); 
                }

		else if (choice == 'h')
		{

	               //Bank
        	        printf("Bank:\n\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n\n", bank_card[0], bank_card[0]);

			//Player Hit
			player_card[player_count] = (rand() % 10) + 2;
			player_sum += player_card[player_count];
			player_count++;

			printf("Player:\n\n");

			for (int i = 0; i < player_count; i++)
			{
				printf(" Card %i: %i\n", i + 1, player_card[i]);
			}
			printf(" Sum: %i\n", player_sum);

			//If player is over 21
			if (player_sum > 21)
			{
				printf("\nYou busted! The bank wins!\n\n");
				break;
			}
		}
		else if (choice == 's')
		{
			//If bank < 17
			while (bank_sum < 17)
			{
				bank_card[bank_count] = (rand() % 10) + 2;
				bank_sum += bank_card[bank_count];
				bank_count++;

				printf("Bank:\n\n");

 	                      	for (int i = 0; i < bank_count; i++)
        	                {
         	                       printf(" Card %i: %i\n", i + 1, bank_card[i]);
				}
		                printf(" Sum: %i\n\n\n", bank_sum);
			}
			//Player
			printf("Player:\n\n");

                        for (int i = 0; i < player_count; i++)
                        {
                                printf(" Card %i: %i\n", i + 1, player_card[i]);
                        }
                        printf(" Sum: %i\n\n\n", player_sum);


		      //If bank is over 21
                        if (bank_sum > 21)
			{
                                printf("\nYou Win, the bank busted!\n\n");
                                break;

			}
				//If it results a tie
				else if (bank_sum == player_sum)
				{
					printf("\nResults: \n\n");
                                        printf("PUSH! Both have %i!\n\n", bank_sum);
				}

				//Bank wins
				else if (bank_sum > player_sum)
				{
					printf("\nResults: \n\n");
					printf("You Lost, the bank has %i!\n\n", bank_sum);
				}

				//Player wins
				else if (player_sum > bank_sum)
				{
					printf("\nResults: \n\n");
                        	        printf("You Won, the bank has %i!\n\n", bank_sum);
				}

		}
	}
	while(choice != 's' && player_sum <= 21);










}
