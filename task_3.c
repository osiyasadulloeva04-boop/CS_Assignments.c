#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_num = get_long("Number: ");

    long temp_luhn = card_num;
    int sum_mult = 0;
    int sum_norm = 0;
    int pos = 0;

    while (temp_luhn > 0)
    {
        int digit = temp_luhn % 10;

        if (pos % 2 == 1)
        {
            int doubled = digit * 2;
            sum_mult = sum_mult + (doubled % 10) + (doubled / 10);
        }
        else
        {
            sum_norm = sum_norm + digit;
        }

        temp_luhn = temp_luhn / 10;
        pos = pos + 1;
    }

    int total_sum = sum_mult + sum_norm;

    if (total_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long temp_count = card_num;
    int count = 0;
    if (card_num == 0)
    {
        count = 1;
    }
    else
    {
        while (temp_count > 0)
        {
            temp_count = temp_count / 10;
            count = count + 1;
        }
    }

    long first_two = card_num;
    while (first_two >= 100)
    {
        first_two = first_two / 10;
    }
    int first_one = first_two / 10;

    if (count == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && first_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}