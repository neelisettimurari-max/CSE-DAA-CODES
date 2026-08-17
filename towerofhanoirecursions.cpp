#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct Move
{
    int disk;
    char from;
    char to;
};

void moveDisk(int disk, char from, char to)
{
    cout << "Move disk " << disk
         << " from " << from
         << " to " << to << endl;
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';

    if (n % 2 == 0)
    {
        char temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    int totalMoves = pow(2, n) - 1;

    for (int i = 1; i <= totalMoves; i++)
    {
        int disk = 1;

        int position = i;

        while (position % 2 == 0)
        {
            disk++;
            position = position / 2;
        }

        if (disk % 2 == 1)
        {
            // Move smallest disk
            static char current = source;

            char next;

            if (current == source)
                next = destination;
            else if (current == destination)
                next = auxiliary;
            else
                next = source;

            moveDisk(disk, current, next);
            current = next;
        }
    }

    return 0;
}