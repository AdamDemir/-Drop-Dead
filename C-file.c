#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mohamad.h / Ibrahim 2643344
int role_a_dice(void);

int play_computer(int sum, int dice1, int dice2, int dice3, int dice4, int dice5, int dice6);

int play_user(int sum, int dice1, int dice2, int dice3, int dice4, int dice5, int dice6);

void scorsheet(int Csum, int Usum, int n);

int main() {
    srand(time(NULL)); //seed the rand fun()
    int sumC = 0, sumU = 0, n = 1;    // the sum for the computer and user and number of rounds

    int round = 0, cTurn = role_a_dice(), uTurn = role_a_dice();   // turn the dice to determine who's going to start first
    while (cTurn == uTurn) cTurn = role_a_dice(), uTurn = role_a_dice(); // ensure that both get different dice num
    printf("Welcome to the Drop Dead game.\n"
           "Let's get started!\n\n");
    printf("How many rounds would you like to play? ");
    scanf("%d", &round);
    printf("\n");
    printf("I've rolled the dice and got %d!\n ", cTurn);
    printf("I have rolled the dice for you and you got %d!\n\n\n", uTurn);

    if (cTurn > uTurn) {//if it's computer's turn
        while (n <= round) {//until n becomes num of round
            printf("Round %d -- My Turn: \n", n);
            printf("==================================\n");
            sumC = play_computer(sumC, 1, 1, 1, 1, 1, 1);
            printf("Round %d -- Your Turn: \n", n);
            printf("==================================\n");
            printf("Are you ready to play?\n");
            sumU = play_user(sumU, 1, 1, 1, 1, 1, 1);
            scorsheet(sumC, sumU, n);
            n++;
        }
    } else if (uTurn > cTurn) { //if it's user's turn
        while (n <= round) {
            printf("Round %d -- Your Turn: \n", n);
            printf("==================================\n");
            printf("Are you ready to play?\n");
            sumU = play_user(sumU, 1, 1, 1, 1, 1, 1);
            printf("Round %d -- My Turn: \n", n);
            printf("==================================\n");
            sumC = play_computer(sumC, 1, 1, 1, 1, 1, 1);
            scorsheet(sumC, sumU, n);
            n++;
        }
    }
    (sumC > sumU) ? printf("I am the Winner!!\n") : printf("You're the Winner!!\n"); // print who is the winner
    return 0;
}

int role_a_dice(void) {
    // gives us a random num between 1 - 6
    return 1 + rand() % 6;
}

int play_computer(int sum, int dice1, int dice2, int dice3, int dice4, int dice5, int dice6) {
    int myScore = 0;
    if (!dice1 && !dice2 && !dice3 && !dice4 && !dice5 && !dice6) { // if all dices are zero, return the sum
        printf("Drop dead!\n\n");
        return sum;
    } else {
        // check whether there the dice is equal to 0 or not, if it's 0 skip it
        printf("I got => ");
        if (dice1) {
            dice1 = role_a_dice();
            printf("[Dice 1]: %d,", dice1);
            myScore += dice1;
        }
        if (dice2) {
            dice2 = role_a_dice();
            printf("[Dice 2]: %d,", dice2);
            myScore += dice2;
        }
        if (dice3) {
            dice3 = role_a_dice();
            printf("[Dice 3]: %d,", dice3);
            myScore += dice3;
        }
        if (dice4) {
            dice4 = role_a_dice();
            printf("[Dice 4]: %d,", dice4);
            myScore += dice4;
        }
        if (dice5) {
            dice5 = role_a_dice();
            printf("[Dice 5]: %d,", dice5);
            myScore += dice5;
        }
        if (dice6) {
            dice6 = role_a_dice();
            printf("[Dice 6]: %d,", dice6);
            myScore += dice6;
        }
        printf("\n");
        //check whether if any of the numbers assigned to the dices are equal to either 2 or 5, if it's equal set myScore to 0
        // and exclude the dice from the game by setting it to 0
        if (dice1 == 2 || dice1 == 5) {
            dice1 = 0;
            myScore = 0;
            printf("Dice 1 is excluded  ");
        }
        if (dice2 == 2 || dice2 == 5) {
            dice2 = 0;
            myScore = 0;
            printf("Dice 2 is excluded  ");
        }
        if (dice3 == 2 || dice3 == 5) {
            dice3 = 0;
            myScore = 0;
            printf("Dice 3 is excluded  ");
        }
        if (dice4 == 2 || dice4 == 5) {
            dice4 = 0;
            myScore = 0;
            printf("Dice 4 is excluded  ");
        }
        if (dice5 == 2 || dice5 == 5) {
            dice5 = 0;
            myScore = 0;
            printf("Dice 5 is excluded  ");
        }
        if (dice6 == 2 || dice6 == 5) {
            dice6 = 0;
            myScore = 0;
            printf("Dice 6 is excluded  ");
        }
        // add my score to the total
        sum += myScore;
        printf("\nMy score: %d Total score: %d\n", myScore, sum);
        printf("\n");
        // return the sum with the dice num
        return play_computer(sum, dice1, dice2, dice3, dice4, dice5, dice6);
    }


}

int play_user(int sum, int dice1, int dice2, int dice3, int dice4, int dice5, int dice6) {
    int myScore = 0;
    // if all dices are zero, return the sum
    if (!dice1 && !dice2 && !dice3 && !dice4 && !dice5 && !dice6) {
        printf("Drop dead!\n\n");
        return sum;
    } else {
        // check whether there the dice is equal to 0 or not, if it's 0 skip it
        printf("I rolled and you got => ");
        if (dice1) {
            dice1 = role_a_dice();
            printf("[Dice 1]: %d,", dice1);
            myScore += dice1;
        }
        if (dice2) {
            dice2 = role_a_dice();
            printf("[Dice 2]: %d,", dice2);
            myScore += dice2;
        }
        if (dice3) {
            dice3 = role_a_dice();
            printf("[Dice 3]: %d,", dice3);
            myScore += dice3;
        }
        if (dice4) {
            dice4 = role_a_dice();
            printf("[Dice 4]: %d,", dice4);
            myScore += dice4;
        }
        if (dice5) {
            dice5 = role_a_dice();
            printf("[Dice 5]: %d,", dice5);
            myScore += dice5;
        }
        if (dice6) {
            dice6 = role_a_dice();
            printf("[Dice 6]: %d,", dice6);
            myScore += dice6;
        }
        printf("\n");
        //check whether if any of the numbers assigned to the dices are equal to either 2 or 5, if it's equal set myScore to 0
        // and exclude the dice from the game by setting it to 0
        if (dice1 == 2 || dice1 == 5) {
            dice1 = 0;
            myScore = 0;
            printf("Dice 1 is excluded  ");
        }
        if (dice2 == 2 || dice2 == 5) {
            dice2 = 0;
            myScore = 0;
            printf("Dice 2 is excluded  ");
        }
        if (dice3 == 2 || dice3 == 5) {
            dice3 = 0;
            myScore = 0;
            printf("Dice 3 is excluded  ");
        }
        if (dice4 == 2 || dice4 == 5) {
            dice4 = 0;
            myScore = 0;
            printf("Dice 4 is excluded  ");
        }
        if (dice5 == 2 || dice5 == 5) {
            dice5 = 0;
            myScore = 0;
            printf("Dice 5 is excluded  ");
        }
        if (dice6 == 2 || dice6 == 5) {
            dice6 = 0;
            myScore = 0;
            printf("Dice 6 is excluded  ");
        }
        // add my score to the total
        sum += myScore;
        printf("\nYour score: %d Total score: %d\n", myScore, sum);
        printf("\n");
        // return the sum with the dice num
        return play_user(sum, dice1, dice2, dice3, dice4, dice5, dice6);
    }

}

void scorsheet(int Csum, int Usum, int n) {
    // get the sum of the computer, user and the num of rounds then displays them
    printf("\n\n\n");
    printf("Our scoresheet after round %d :\n", n);
    printf("=============================\n");
    printf("My score            Your score\n");
    printf("    %d                     %d\n\n", Csum, Usum);
}




