#include <stdio.h>
#include <math.h>


typedef struct s_complex
{
    double re;
    double im;
} t_complex;


int main()
{
    
    int column, row, i;
    t_complex c, z;
    double temp, density;
    
    density = 15.0;
    row = 0;
    while (row <= 4 * density)
    {
        c.im = 2 - ( row / density );
        column = 0;
        while (column <= 4 * density )
        {
            c.re = -2 + ( column / density );
            z.re = 0;
            z.im = 0;
            for (i = 1; i <= 1000; i++)
            {
                temp = z.re;
                z.re = (z.re * z.re) - (z.im * z.im) + c.re;
                z.im = (2 * temp * z.im) + c.im;
                if ((z.re * z.re) + (z.im * z.im) > 4)
                    break;
            }
            if (i == 1001)
                printf(".");
            else
                printf(" ");
            column += 1;
        }  
        printf("\n"); 
        row += 1;
    }
    return (0);
}

//a and IMc are the constant.

