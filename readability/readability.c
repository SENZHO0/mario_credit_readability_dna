#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Dapat input dari user
    string text = get_string("Text: ");

    //Pemosisian karakter, huruf, dan kalimat
    int characters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        //Hitung huruf dan angka sebagai karakter yang akan diproses
        if (isalnum(c))
        {
            characters++;
        }

        //Hitung spasi sebagai pemisah kata yang nantinya menjadi tanda bahwa kata itu bertambah
        if (c == ' ')
        {
            words++;
        }

        //Hitung tanda .!? sebagai pemisah kalimat yang antinya menjadi tanda bahwa kalimat itu bertambah
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    //Rumus dari readability
    float formula = 4.71 * ((float) characters / words) + 0.5 * ((float) words / sentences) - 21.43;

    //Pembulatan ke yang terdekat
    int grade = round(formula);

    //Hasil
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
