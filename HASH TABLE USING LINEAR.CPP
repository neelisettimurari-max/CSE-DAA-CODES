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

        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
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
    h.insert(25);
    h.insert(35);
    h.insert(45);

    h.display();

    return 0;
}