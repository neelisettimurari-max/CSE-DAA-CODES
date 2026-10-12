#include <iostream>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};
Node* createNode(char ch, int freq) {
    Node* n = new Node;
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}
void sortNodes(Node* a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j]->freq > a[j + 1]->freq) {
                Node* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
Node* buildHuffman(char ch[], int freq[], int n) {
    Node* a[100];
    for (int i = 0; i < n; i++)
        a[i] = createNode(ch[i], freq[i]);
    int size = n;
    while (size > 1) {
        sortNodes(a, size);
        Node* left = a[0];
        Node* right = a[1];
        Node* parent = createNode(
            '$', left->freq + right->freq
        );
        parent->left = left;
        parent->right = right;

        a[0] = parent;
        a[1] = a[size - 1];
        size--;
    }
    return a[0];
}
void printCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        cout << root->ch << " : ";
        for (int i = 0; i < top; i++)
            cout << code[i];
        cout << endl;
    }
}
int main() {
    char ch[] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't', 'u'};
    int freq[] = {20, 11, 2, 10, 15, 8, 10, 22, 2};
    int n = 9;
    int code[100];
    Node* root = buildHuffman(ch, freq, n);
    cout << "Huffman Codes:\n";
    printCodes(root, code, 0);
    return 0;
}
