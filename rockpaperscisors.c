#include <stdio.h>
#include <time.h>

int wins = 0;
int computerWins = 0;
int draw = 0;
int computerChoice;
int rounds = 0;
int userChoiceAsInt;
char userChoiceAsChar;

int checkResults();
int checkWins();
int computerMove();
int playerMove();
int roundsCount();

int main()
{

    printf("Welcome!!! \n");
    roundsCount();
    printf("Rounds = %d,Player_Wins = %d, Computer_Wins = %d, Draw = %d\n",rounds,wins,computerWins,draw);

    return 0;

}
int roundsCount()
{
    printf("How many rounds would you like to play?\n");
    scanf("%d",&rounds);

    for(int i = 1; i <= rounds;i++ )
    {
        if(i <= rounds)
        {
            playerMove();
        }
    }
}

int computerMove()
{
    srand(time(NULL));


    computerChoice = rand() % 3 + 1;


    if (computerChoice == 1)
    {
       printf("Computer draws Rock\n");
    }


    else if (computerChoice == 2)
    {
        printf("Computer draws Paper\n");
    }

    else
    {
         printf("Computer draws Scissors\n");
    }

}

int playerMove()
{
    do
   {
        printf("Player enter (r)ock, (p)aper, (s)cissors\n");
        scanf(" %c",&userChoiceAsChar);
        if (userChoiceAsChar == 'r' || userChoiceAsChar == 'R')
    {
        userChoiceAsInt = 1;
        printf("Player draws Rock\n");
    }
    else if(userChoiceAsChar == 'p' || userChoiceAsChar == 'P')
    {
        userChoiceAsInt = 2;
        printf("Player draws Paper\n");
    }
    else if(userChoiceAsChar == 's' || userChoiceAsChar == 'S')
    {
        userChoiceAsInt = 3;
        printf("Player draws Scissors\n");
    }
    else
    {
        printf("Invalid character\n");
        continue;
    }
    computerMove();
    checkResults();
    break;
   }while(userChoiceAsChar != ' ');
}


int checkResults()
{
    int results;

    if ((userChoiceAsInt == 1 && computerChoice == 1) || (userChoiceAsInt == 2 && computerChoice == 2) || (userChoiceAsInt == 3 && computerChoice == 3))
    {
        results = 0;
    }

    else if ((userChoiceAsInt == 1 && computerChoice == 3) || (userChoiceAsInt == 2 && computerChoice == 1) || (userChoiceAsInt == 3 && computerChoice == 2))
    {
        results = 1;
    }
     else if ((userChoiceAsInt == 3 && computerChoice == 1) || (userChoiceAsInt == 1 && computerChoice == 2) || (userChoiceAsInt == 2 && computerChoice == 3))
    {
        results = -1;
    }

        switch(results)
    {
       case 1 :
        printf("Player Wins\n\n");
        wins = wins + 1;
        break;
       case -1:
        printf("Computer Wins\n\n");
        computerWins = computerWins + 1;
        break;
       case 0:
        printf("It is a Draw\n\n");
        draw = draw + 1;
        break;
       }

    }
