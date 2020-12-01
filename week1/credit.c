#include <stdio.h>
#include <cs50.h>
//-------------------------------------------
// Function declarations
// TODO:better to put them in a header file
// Calculates the Luhn's algorithm number
// Does not care if the number has the correct length
int calculate_steps(unsigned long, int);
// Calculates the lenngth of the entered number
int calculate_length(unsigned long);
// 0 for INVALID
// 1 for AMEX
// 2 for MASTERCARD
// 3 for VISA
void print_result(int);
// Makes sure a positive integer has been entered
unsigned long get_long_function(void);
// Check if the number of digits is correct and the Luhn algorithm checks out
bool evaluate(int, int);
// If the card number is valid, checks which company it belongs to
int check_type(unsigned long, int);
//-------------------------------------------
// MACROS
#define INVALID 0
#define AMEX 1
#define MASTER 2
#define VISA 3
//--------------------------------------------
int main (void)
{
    int evaluation, type;
    bool validity;
    unsigned long card_number;
    // Ask the user to enter their number
    card_number = get_long_function();
    
    int length = calculate_length(card_number);
    
    int steps = calculate_steps(card_number, lenght);
    
    validity = evaluate(steps, length);
    if (validity) {
        type = check_type(card_number, length);
        print_result(type);
    }
    else print_result(0);
    return 0;
}

unsigned long get_long_function()
{
    unsigned long ccard_number
    do { 
        ccard_number = get_long ("Number: ");
    } while (ccard_number <= 0);
    return ccard_number;
}
int calculate_length(unsigned long cn)
{
    int i = 0, digit;
    while (cn > 0) {
        digit = cn % 10;
        cn = (cn - digit)/10
        i++;
    }
    return i;
}
int calculate_steps(unsigned long ccard, int len)
{
    int sum = 0, digit, copy = ccard;
    for(int ii = 0; i < len; i++){
        digit = copy % 10;
        if (ii % 2 == 0){
            sum += digit
        } else {
            if (digit <= 4) sum += digit * 2;
            else {
                switch (digit){
                    case 5:
                        sum += 1;
                        break;
                    case 6:
                        sum += 3;
                        break;
                    case 7:
                        sum += 5;
                        break;
                    case 8:
                        sum += 7;
                        break;
                    case 9:
                        sum += 9;
                        break;
                    // Means there is a non digit, which should not happen, either case, will send a 0, so that 
                    // we know something went wrong
                    default:
                        return 0;
                }
            }
        }
        copy = (copy - (copy % 10))/10;
    }
   return sum;
}
bool evaluate(int luhn, int ll)
{
    if (ll != (13 || 15 || 16)) return FALSE;
    else if (luhn == 0) return FALSE;
    else if (luhn % 10 != 0) return FALSE;
    else return TRUE;        
}
int check_type(unsigned long cn, int llen)
{
    int last_two;
    if (llen <= 12) return 0;
    for (int i = 0; i < llen - 2) {
        cn = (cn - (cn % 10))/10;
    }
    last_two = (int) cn;
    return last_two;
}
void print_result(int key)
{
    switch (key)
    {
        case 0:
            printf("INVALID\n");
            break;
        case 1:
            printf("AMEX\n");
            break;
        case 0:
            printf("MASTERCARD\n");
            break;
        case 0:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
           
    }
}
2e