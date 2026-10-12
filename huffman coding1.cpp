
#include <iostream>
using namespace std;

int f[20], l[20], r[20];
char ch[20];
int used[20] = {0};
int totalBits = 0;

void printCode(int root, char code[], int top)
{
    if (l[root] == -1 && r[root] == -1)
    {
        code[top] = '\0';

        cout << ch[root] << " : " << code << endl;

        totalBits += f[root] * top;
        return;
    }

    code[top] = '0';
    printCode(l[root], code, top + 1);

    code[top] = '1';
    printCode(r[root], code, top + 1);
}

int main()
{
    int n = 9, i, j, x, y;
    char code[20];

    char letters[] = {
        'a', 'c', 'd', 'e', 'o',
        'm', 's', 't', 'u'
    };

    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};

    for (i = 0; i < n; i++)
    {
        ch[i] = letters[i];
        f[i] = freq[i];
        l[i] = r[i] = -1;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        x = y = -1;

        for (j = 0; j < i; j++)
        {
            if (!used[j])
            {
                if (x == -1 || f[j] < f[x])
                {
                    y = x;
                    x = j;
                }
                else if (y == -1 || f[j] < f[y])
                {
                    y = j;
                }
            }
        }

        used[x] = used[y] = 1;

        f[i] = f[x] + f[y];
        ch[i] = '*';
        l[i] = x;
        r[i] = y;
    }

    cout << "Huffman Codes:" << endl;

    printCode(2 * n - 2, code, 0);

    cout << "\nWeighted bits = " << totalBits << endl;
    cout << "Total bits in file = " << totalBits * 100 << endl;

    cout << "Memory in bytes = "
         << (totalBits * 100 + 7) / 8 << endl;

    return 0;
}
