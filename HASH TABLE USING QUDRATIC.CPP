#include <iostream>
using namespace std;

#define SIZE 10

class HashTable
{
    int table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int key)
    {
        int index = key % SIZE;
        int i = 0;

        while (table[(index + i * i) % SIZE] != -1)
        {
            i++;
        }

        table[(index + i * i) % SIZE] = key;
    }

    void display()
    {
        cout << "Hash Table:\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : " << table[i] << endl;
        }
    }
};

int main()
{
    HashTable h;

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(25);
    h.insert(35);

    h.display();

    return 0;
}