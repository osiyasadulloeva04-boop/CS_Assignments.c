#include <cs50.h> 
#include <stdio.h> 
int main(void)
{
    

    int height; 
    do 
    {
        height = get_int("Height: "); 
    }
    while (height < 1 || height > 8); 



    for (int row = 0; row < height; row++)
    {
       
        for (int space_count = 0; space_count < height - 1 - row; space_count++)
        {
            printf(" "); 
        for (int hash_left_count = 0; hash_left_count <= row; hash_left_count++)
        {
            printf("#"); 
        printf("  "); 
        for (int hash_right_count = 0; hash_right_count <= row; hash_right_count++)
        {
            printf("#"); 
        }

        
        printf("\n"); 
    }
}