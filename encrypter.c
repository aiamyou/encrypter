#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char text[5000];
    char result[5000] = "";
    char md[5];
    int ans;
    int j =0;
    //Array of all the alphabets to conversion
    char alp[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    char values[][4] = {"32;", "1@3", "111", "c9!", "o0o", "7ns", "88d", "32x", "m#y", "v2(", "dq2", "3w1", "(ce", "*f2", "10x", "m$s", "v0h", "210", "m^w", "l-1", "l02", "d8&", "k&w", "cr8", "mm2", "1x*", "#0f", "cwo", "l=z", "9!a", "gg-", "$mq", "7b1", "z*#", "v)s", "q1v", "nn8", "k@a"};
    printf("Which method you want to use:\n1.Encryption\n2.Decryption\nEnter your Answer(1/2): ");
    scanf("%d", &ans);
    while (getchar() != '\n')
        ;

    if (ans == 1)
    {
        printf("Enter the Text you want to Encrypt: ");
        fgets(text, 2000, stdin);

        for (int i = 0; text[i] != '\0'; i++)
        {
            if(text[i]>='A' && text[i]<='Z'){
                text[i]+=32;
            }
            
            for (int v = 0; v <= 38; v++)
            {
                
                if (text[i] == alp[v])
                {

                    strcat(result, values[v]);
                    // printf("The value is %s\n",values[v]);
                }
            }
        }
        printf("\nHere is your encrypted Text:\n");
        printf("%s", result);
    }
    else if (ans == 2)
    {
        printf("Enter the Text you want to Decrypt: ");
        fgets(text, 5000, stdin);
        
        
        for (int i = 0; text[i] != '\0'; i++)
        {

            for (int s = 0; s < 3; s++)
            {
                md[s] = text[i++];
                //printf("%d",strlen(md));
            }

            if (strlen(md) == 3){
                //printf("%s\n",md);
                for (int v = 0; v <= 38; v++){
                    //printf("md = %s value = %s\t",md,values[v]);
                    if (strcmp(md,values[v])==0)
                    {
                        result[j++]= alp[v];
                        //printf("Found Value %s\n",result);
                        

                        // printf("The value is %s\n",values[v]);
                    }
                    else{
                        //printf("False\n");
                    }
                }
                memset(md,0,sizeof(md));
                i--;
                //printf("Cleared the memory, current memory is:%d",strlen(md));
            }

        }
        printf("Here is your Decrypted Text:\n");
        printf("%s", result);
    }
    else
    {
        printf("Please Enter a valid Answer!");
    }
    getch();
}
