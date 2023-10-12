#include <stdio.h>

void print_possible_score_counts(int val)
{
    int total = 0;
    for (int td = 0; td < val; td = td + 6)
    { // touchdowns
        for (int fg = 0; fg < val; fg = fg + 3)
        { // field goals
            for (int sfty = 0; sfty < val; sfty = sfty + 2)
            { // safetys
                for (int td_cn = 0; td_cn < val; td_cn = td_cn + 8)
                { // touchdown 2-point conversions
                    for (int td_fg = 0; td_fg < val; td_fg = td_fg + 7)
                    { // touchdown + fieldgoals
                        total += td_cn + td_fg + td + fg + sfty;
                        // printf("%d", total);
                        if (total == val)
                        {
                            printf("%d (TD + 2pt), %d (TD + FG), %d TD, %d 3pt FG, %d Safety\n", td_cn / 8, td_fg / 7, td / 6, fg / 3, sfty / 2);
                        }
                        total = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    int val = 0;
    int looping = 1;
    while (looping == 1)
    {

        printf("\nWhat was the score? \n");
        scanf("%d", &val);

        if (val <= 1)
        {
            printf("That's not possible!!!!");
            break;
        }

        printf("Possible combinations were:\n");
        print_possible_score_counts(val);
    }

    return 0;
}
