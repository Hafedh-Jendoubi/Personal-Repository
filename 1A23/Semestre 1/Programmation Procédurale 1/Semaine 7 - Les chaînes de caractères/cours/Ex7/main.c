#include <stdio.h>
#include <string.h>

int main()
{
    char c, ch[100];
    int i, s[26];

    //Initialisation du tableau s
    for(i=0; i<26; i++)
        s[i] = 0;

    printf("Taper votre texte: "); gets(ch);

    for(i=0; i<strlen(ch); i++){
        c = ch[i];
        switch(c){
            case('a'): case('A'):
                s[0] = s[0] + 1;
                break;

            case('b'): case('B'):
                s[1] = s[1] + 1;
                break;

            case('c'): case('C'):
                s[2] = s[2] + 1;
                break;

            case('d'): case('D'):
                s[3] = s[3] + 1;
                break;

            case('e'): case('E'):
                s[4] = s[4] + 1;
                break;

            case('f'): case('F'):
                s[5] = s[5] + 1;
                break;

            case('g'): case('G'):
                s[6] = s[6] + 1;
                break;

            case('h'): case('H'):
                s[7] = s[7] + 1;
                break;

            case('i'): case('I'):
                s[8] = s[8] + 1;
                break;

            case('j'): case('J'):
                s[9] = s[9] + 1;
                break;

            case('k'): case('K'):
                s[10] = s[10] + 1;
                break;

            case('l'): case('L'):
                s[11] = s[11] + 1;
                break;

            case('m'): case('M'):
                s[12] = s[12] + 1;
                break;

            case('n'): case('N'):
                s[13] = s[13] + 1;
                break;

            case('o'): case('O'):
                s[14] = s[14] + 1;
                break;

            case('p'): case('P'):
                s[15] = s[15] + 1;
                break;

            case('q'): case('Q'):
                s[16] = s[16] + 1;
                break;

            case('r'): case('R'):
                s[17] = s[17] + 1;
                break;

            case('s'): case('S'):
                s[18] = s[18] + 1;
                break;

            case('t'): case('T'):
                s[19] = s[19] + 1;
                break;

            case('u'): case('U'):
                s[20] = s[20] + 1;
                break;

            case('v'): case('V'):
                s[21] = s[21] + 1;
                break;

            case('w'): case('W'):
                s[22] = s[22] + 1;
                break;

            case('x'): case('X'):
                s[23] = s[23] + 1;
                break;

            case('y'): case('Y'):
                s[24] = s[24] + 1;
                break;

            case('z'): case('Z'):
                s[25] = s[25] + 1;
                break;
        }
    }

    printf("A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |\n");
    for(i=0; i<26; i++)
        printf("%d | ", s[i]);

    return 0;
}
