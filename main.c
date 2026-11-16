#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>


//Show hand
void print_hand(int cards[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" Card %i: %i\n", i + 1, cards[i]);
    }
}

//Show result
void print_results(int bank_card[],int bank_count,int bank_sum, int player_card[], int player_count, int player_sum)
{
        {
                        //show bank
                        printf("Bank:\n\n");
                        print_hand(bank_card, bank_count);
                        printf(" Sum: %i\n\n", bank_sum);

                        //show player
                        printf("Player:\n\n");
                        print_hand(player_card, player_count);
                        printf(" Sum: %i\n\n", player_sum);
        }
}

int main(void)
{

	//Money
	int money = 1000;
	int bet;

	//Winner
	int winner = 0;

	//Arrays for 10 cards
	int bank_card[12];
	int player_card[12];

	//Randon number generator
	srand(time(NULL));

	//Save the count of cards and the sum
	int bank_count = 2;
	int player_count = 2;
	int bank_sum = bank_card[0] + bank_card[1];
	int player_sum = player_card[0] + player_card [1];

	//Show hand
	void print_hand(int cards[], int count)
	{
		for (int i = 0; i < count; i++)
		{
			printf(" Card %i: %i\n", i + 1, cards[i]);

		}
	}

	//Start
	printf("\n================================================================================");
	printf("\n                                    BLACKJACK\n\n");
	printf("================================================================================");

	//Game goes until Money < 0
	while (money > 0)
	{

	//set everything to 0
     	for (int i = 0; i < 12; i++)
        {
                player_card[i] = 0;
                bank_card[i] = 0;
        }

       //Karten (Werte)
        bank_card[0] = (rand() % 10) + 2;
        bank_card[1] = (rand() % 10) + 2;

        player_card[0] = (rand() % 10) + 2;
        player_card[1] = (rand() % 10) + 2;

	player_count = 2;
	bank_count = 2;

	player_sum = 0;
	bank_sum = 0;

	winner = 0;

	bank_sum = bank_card[0] + bank_card[1];
        player_sum = player_card[0] + player_card[1];

	//Bet
	{
		printf("\n                                    NEW ROUND\n\n");
		printf("Balance: %i $\n", money);
		bet = get_int("Your bet: ");
		printf("--------------------------------------------------------------------------------");
	}
	while (bet <= 0 || bet > money);

	//Update balance
	money -= bet;

	//Show cards
	printf("\nBank:\n\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n\n", bank_card[0], bank_card[0]);
	printf("Player:\n\n Card 1: %i\n Card 2: %i\n Sum: %i\n\n", player_card[0], player_card[1], player_sum);

	//Hit or stand
	char choice;

	//Player Blackjack
	if (player_card[0] + player_card[1] == 21)
	{
		printf("You have Blackjack!");
		//If it results a tie
		if (bank_card[0] + bank_card[1] == 21)
                {
			print_results(bank_card, bank_count, bank_sum, player_card, player_count, player_sum);
			printf("--------------------------------------------------------------------------------");
                	printf("Push, you both have %i\n\n", bank_sum);
			winner = 3;
		}

		//Player wins
		else
            	{
                	print_results(bank_card, bank_count, bank_sum, player_card, player_count, player_sum);
			printf("--------------------------------------------------------------------------------");
			printf("You Won, the bank has %i!\n\n", bank_sum);
             		winner = 2;
		}
	}
	//Bank Blackjack
	else if (bank_card[0] + bank_card[1] == 21)
	{
                print_results(bank_card, bank_count, bank_sum, player_card, player_count, player_sum);
		printf("--------------------------------------------------------------------------------");
                printf("You Lost, the bank has Blackjack!\n\n");
		winner = 1;
	}

	else if (player_sum < 21)
	{
		do
		{

		 choice = get_char("\nHit (h) or Stand (s)? ");
	                printf("\n");
			printf("--------------------------------------------------------------------------------");

	          	//Invalid input
			if (choice != 'h' && choice != 's')
	                {
	                        printf("Invalid input, please enter Hit (h) or Stand (s)");
	                }

			else if (choice == 'h')
			{
				printf("Bank:\n\n Card 1: %i\n Card 2: ?\n Sum: %i + ?\n\n\n", bank_card[0], bank_card[0]);

				//Player Hit
				player_card[player_count] = (rand() % 10) + 2;
				player_sum += player_card[player_count];
				player_count++;

				//show player
				printf("Player:\n\n");
				print_hand(player_card, player_count);
				printf(" Sum: %i\n\n", player_sum);


				//If player has 21
				if (player_sum == 21)
				{
					printf("You got 21\n\n\n");
					break;
				}
				//If player is over 21
				if (player_sum > 21)
				{
					break;
				}
			}
			else if (choice == 's')
			{

	        }
	}
	while(choice != 's' && player_sum < 21);

	//Player busted
	if (player_sum > 21)
	{
		printf("--------------------------------------------------------------------------------");
		printf("\nRESULTS: \n\n");
		printf("You busted, the bank wins!\n\n");
		winner = 1;
	}

	else
	{
		//Bank sum
	      	while (bank_sum < 17)
		{
	                bank_card[bank_count] = (rand() % 10) + 2;
	               	bank_sum += bank_card[bank_count];
	                bank_count++;
		}
		//Show bank and player
		print_results(bank_card, bank_count, bank_sum, player_card, player_count, player_sum);



		//Bank busted
		if (bank_sum > 21)
		{
			printf("--------------------------------------------------------------------------------");
			printf("\nRESULTS: \n\n");
                	printf("You Won, the bank busted!\n\n");
			winner = 2;
		}

		//If it results a tie
		else if (bank_sum == player_sum)
	  	{
			printf("--------------------------------------------------------------------------------");
		  	printf("\nRESULTS: \n\n");
		       	printf("PUSH! Both have %i!\n\n", bank_sum);
			winner = 3;
		}
		//Bank wins
	       	else if (bank_sum > player_sum)
	     	{
			printf("--------------------------------------------------------------------------------");
	          	printf("RESULTS: \n\n");
	             	printf("You Lost, the bank has %i!\n\n", bank_sum);
	    		winner = 1;
		}
               	//Player wins
	        else if (player_sum > bank_sum)
  	       	{
			printf("--------------------------------------------------------------------------------");
	           	printf("\nRESULTS: \n\n");
	            	printf("You Won, the bank has %i!\n\n", bank_sum);
	   		winner = 2;
		}
	}

	}

	//Money win/loss

	//Bank wins
	if (winner == 1)
	{
		printf("Loss: -%i $\n", bet);
		printf("Balance: %i $\n\n", money);
	}
	//Player wins
	else if (winner == 2)
	{
		printf("Profit: +%i $\n", bet * 2);
		money += bet * 2;
		printf("Balance: %i $\n\n", money);
	}
	//Push
	else if (winner == 3)
	{
		printf("Returned: %i $\n", bet);
		money += bet;
		printf("Balance: %i $\n\n", money);
	}

	//Round over
	printf("\n================================================================================");
        printf("\n                                    ROUND OVER\n\n");
        printf("================================================================================");


	}
}
