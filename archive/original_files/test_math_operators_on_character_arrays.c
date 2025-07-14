#include <stdio.h>
#include <string.h>

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    const char* str[] = {"Halloween Candy", "David"};   // You can use the keyword 'const' and 'static'.
                                                        // What is the * doing here?
                                                        // Is the dimension of the array set by
                                                        // parsing the list? Is it irrevocably
                                                        // two terms wide and one row long?
    
    printf("str[0]: %s\n", str[0]);
    printf("str[1]: %s\n", str[1]);
   
    x = str[0] - str[1];

    printf("Result of subtracting one string from another: %d\n\n", x);

    y = strcmp(str[0], str[1]);

    printf("Result of strcmp (string comparison) function: %d\n\n", y);

    printf("This shows that the strcmp() function is not the same as "
        "simply subtracting two strings.\n\n");

    /* 
    z = str[0];  // This does not work. Even though you can "subtract" two string
                    // (i.e., character arrays) you cannot set one equal to an
                    // integer variable. You also cannot add them. The minus sign (-)
                    // calls a special comparative function. It's not subtraction. Even 
                    // though the value returned by the minus sign is an integer, the 
                    // individual elements do not have an integer value. It's just a 
                    // handy way to compare the equality of two strings without needing 
                    // the strcmp() function from <string.h>.

    printf("Integer value of str[0]: %d\n\n", z);
    */
    return 0;
}