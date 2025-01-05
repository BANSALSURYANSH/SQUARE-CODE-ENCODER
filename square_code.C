#include <stdio.h>
#include <math.h>

int stringLength(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

void normalizeText(const char *input, char *normalized)
{
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {

        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9'))
        {

            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                normalized[index++] = input[i] + 32;
            }
            else
            {
                normalized[index++] = input[i];
            }
        }
    }

    normalized[index] = '\0';
}

void encodeSquareCode(const char *normalized, char *encoded)
{
    int length = stringLength(normalized);
    int columns = (int)ceil(sqrt(length));
    int rows = (length + columns - 1) / columns;

    int k = 0;

    for (int c = 0; c < columns; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            int pos = r * columns + c;
            if (pos < length)
            {
                encoded[k++] = normalized[pos];
            }
        }
        encoded[k++] = ' ';
    }
    encoded[k - 1] = '\0';
}

int main()
{
    char input[256];
    printf("Enter the input text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '\n')
        {
            input[i] = '\0';
            break;
        }
    }

    char normalized[256];
    normalizeText(input, normalized);

    char encoded[512];
    encodeSquareCode(normalized, encoded);

    printf("Encoded message: %s\n", encoded);

    return 0;
}
