#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
struct huffmanNode
{
    char data;
    int freq;
    huffmanNode *left, *right;
    huffmanNode(char data, int freq)
    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(huffmanNode *l, huffmanNode *r)
    {
        return (l->freq > r->freq);
    }
};

struct huffmanNode *tree(char data[], int freq[], int size)
{
    struct huffmanNode *left, *right, *top;
    priority_queue<huffmanNode *, vector<huffmanNode *>, compare> pq;
    for (int i = 0; i < size; ++i)
        pq.push(new huffmanNode(data[i], freq[i]));

    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new huffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    return pq.top();
}

void printCodes(struct huffmanNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct huffmanNode *head = tree(data, freq, size);

    printCodes(head, "");
}

void pre(struct huffmanNode *head)
{
    if (head == NULL)
    {
        return;
    }

    pre(head->left);
    pre(head->right);
    if (head->data != '$')
    {
        cout << head->data << " ";
    }
}

void preorder(char data[], int freq[], int size)
{
    struct huffmanNode *head = tree(data, freq, size);

    pre(head);
}

int main()
{
    int ch, n;

    char arr[MAX];
    int freq[MAX];
    int size = MAX;

    while (1)
    {
        cout << "0.Quit\n";
        cout << "1.Input the n characters with frequency\n";
        cout << "2.Display the array\n";
        cout << "3.Generate the hoffman tree and traverse it in preorder\n";
        cout << "4.Generate the hoffman code for n characters and display the same\n";
        cout << "5.Compare hoffman code with fixed length code\n";
        cout << "Enter your choice\n";
        cin >> ch;
        switch (ch)
        {
        case 0:
        {
            exit(0);
            break;
        }

        case 1:
        {
            cout << "Enter the number of characters\n";
            cin >> n;

            size = n;

            cout << "Enter the character and it's frequency\n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
                cin >> freq[i];
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
            break;
        }
        case 3:
        {
            HuffmanCodes(arr, freq, size);
            cout << "Now printing in preorder : ";
            preorder(arr, freq, size);
            cout << "\n";
            break;
        }
        case 4:
        {
            HuffmanCodes(arr, freq, size);
            cout << "\n";
            break;
        }
        case 5:
        {
            cout << "Enter the fixed length\n";
            string s = "010011";
            cin >> s;
            cout << "input string = " << s << endl;
            struct huffmanNode *head = tree(arr, freq, size);
            for (int i = 0; i <= s.size(); i++)
            {
                char c = s[i];
                if (s[i] == '0')
                {
                    if (head->left == NULL)
                    {
                        if (head->data == '$')
                        {
                            cout << "\n Invalid String\n";
                            break;
                        }
                        else
                        {
                            cout << head->data << " ";
                            head = tree(arr, freq, size);
                            i--;
                        }
                    }
                    else
                    {
                        head = head->left;
                    }
                }
                else
                {
                    if (head->right == NULL)
                    {
                        if (head->data == '$')
                        {
                            cout << "\n Invalid String\n";
                            break;
                        }
                        else
                        {
                            cout << head->data << " ";
                            head = tree(arr, freq, size);
                            i--;
                        }
                    }
                    else
                    {
                        head = head->right;
                    }
                }
            }
            cout << endl;
            break;
        }
        default:
        {
            cout << "The Entered input is invalid\n";
            break;
        }
        }
    }

    return 0;
}