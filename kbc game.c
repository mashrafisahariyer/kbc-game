#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char question[200];
    char options[4][50];
    char correct_option;
    long long prize;
    char level[10];
} Question;

int main() {
    printf(" Welcome to KBC Game.\n");
    printf("Total Prize Pool: 7,00,00,000 TK\n\n");

    long long prize_list[] = {5000, 10000, 20000, 50000, 100000, 500000, 1000000, 5000000, 20000000, 70000000};

    Question q[10] = {

        {"What is the capital of Bangladesh?", {"Dhaka", "Chittagong", "Khulna", "Sylhet"}, 'A', 5000, "Easy"},
        {"Which is the national fruit of Bangladesh?", {"Mango", "Banana", "Jackfruit", "Litchi"}, 'C', 10000, "Easy"},
        {"How many days are in a leap year?", {"364", "365", "366", "367"}, 'C', 20000, "Easy"},
        {"Which animal is known as the 'Ship of the Desert'?", {"Horse", "Camel", "Elephant", "Lion"}, 'B', 50000, "Easy"},


        {"Which is the longest sea beach in the world?", {"Patenga", "Kuakata", "Cox's Bazar", "Goa"}, 'C', 100000, "Medium"},
        {"Who is the author of 'Gitanjali'?", {"Nazrul", "Tagore", "Jibananda", "Lalon"}, 'B', 500000, "Medium"},
        {"Which gas do plants absorb from the atmosphere?", {"Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen"}, 'C', 1000000, "Medium"},

        {"In which year did the Battle of Palashi take place?", {"1757", "1857", "1947", "1764"}, 'A', 5000000, "Hard"},
        {"What is the chemical symbol for Gold?", {"Ag", "Au", "Pb", "Fe"}, 'B', 20000000, "Hard"},
        {"Which scientist discovered the Law of Gravity?", {"Einstein", "Tesla", "Newton", "Galileo"}, 'C', 70000000, "Hard"}
    };

    long long current_money = 0;
    char user_ans, choice;
    int lifeline_used = 0;

    for (int i = 0; i < 10; i++) {
        printf("\n Question %d | Level: %s | Prize: %lld TK \n", i + 1, q[i].level, q[i].prize);

        if (strcmp(q[i].level, "Medium") == 0 || strcmp(q[i].level, "Hard") == 0) {
            printf("(!) WARNING: Wrong answer = 50%% deduction of your current money!\n");
        }
        if (strcmp(q[i].level, "Hard") == 0 && lifeline_used == 0) {
            printf("(!) LIFELINE: You have one 'Second Chance' available for this Hard level!\n");
        }

        printf("Q: %s\n", q[i].question);
        printf("A) %-15s B) %-15s\n", q[i].options[0], q[i].options[1]);
        printf("C) %-15s D) %-15s\n", q[i].options[2], q[i].options[3]);


        int attempt = 0;
        while (attempt < 2) {
            while (1) {
                printf("Your answer (A/B/C/D): ");
                scanf(" %c", &user_ans);
                user_ans = toupper(user_ans);
                if (user_ans >= 'A' && user_ans <= 'D') break;
                printf("Error: Invalid alphabet! Please use A, B, C, or D.\n");
            }

            if (user_ans == q[i].correct_option) {
                current_money = q[i].prize;
                printf("CORRECT! You earned %lld TK.\n", q[i].prize);
                break;
            } else {

                if (strcmp(q[i].level, "Hard") == 0 && lifeline_used == 0) {
                    printf("WRONG! But wait... your Lifeline is active! Try one more time.\n");
                    lifeline_used = 1;
                    attempt++;
                    continue;
                }

                printf("WRONG ANSWER! The correct answer was %c.\n", q[i].correct_option);
                if (strcmp(q[i].level, "Easy") != 0) {
                    current_money = current_money / 2;
                    printf("Penalty: Money halved! Total: %lld TK\n", current_money);
                } else {
                    current_money = 0;
                    printf("Total: 0 TK\n");
                }
                break;
            }
        }


        if (i < 9) {
            while (1) {
                printf("\nDo you want to proceed to Question %d? (Y/N): ", i + 2);
                scanf(" %c", &choice);
                choice = toupper(choice);
                if (choice == 'Y' || choice == 'N') break;
                printf("Error: Please enter 'Y' or 'N'.\n");
            }

            if (choice == 'N') {
                printf("You quit the game. Final Prize: %lld TK\n", current_money);
                break;
            }
        } else {
            printf("\n*** CONGRATULATIONS! You have won the ultimate prize of 70,000,000 TK! ***\n");
        }
        printf("--------------------------------------\n");
    }

    printf("\nThanks for playing! Final Amount: %lld TK\n", current_money);
    return 0;
}
