//Virtual casino game
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Global variable
int cash = 100;

void play(int bet) {
	char ch[] = {'J', 'K', 'Q'};
	int i,player_guess;
	srand(time(NULL));

	//shuffle the cards
	for(i = 0; i < 5; i++) {
		int x = rand() % 3;
		int y = rand() % 3;
		int temp;
		temp = ch[x];
		ch[x] = ch[y];
		ch[y] = temp;
	}
	printf("Enter the Queen Postion 1, 2, or 3 ? ");
	scanf("%d", &player_guess);
	if (ch[player_guess - 1] == 'Q') {
		cash += 3*bet;
		printf("WOW!!..you won! Result = %c %c %c  Total cash = %d\n",ch[0],ch[1],ch[2], cash);
	}
       else {
	       cash -= bet;
		printf("Better Luck next time!!..you lost! Result = %c %c %c  Total cash = %d\n",ch[0],ch[1],ch[2], cash);
	}

}	


int main(void)
{
	int bet;
	printf("\n\t\t !! Welcome to Virtual casino !!\n");

	while(cash) {
		printf("\nEnter the bet amount : ");
		scanf("%d", &bet);
		if (cash < bet || bet == 0) {
			printf("Entered the wrong betting amount\n");
			break;
		}

		play(bet);
	}	

return 0;
}
