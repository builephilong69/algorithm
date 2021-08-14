#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define V 11

string ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";//53
int FREQUENCY[53];

vector<char> character;
vector<int>  frequency;

static vector<char> chara;
static vector<string> code;
class Huffman_Tree
{
private:
    int frequency;
    char character;
    Huffman_Tree* left = NULL;
    Huffman_Tree* right = NULL;
public:
    Huffman_Tree(){}
    ~Huffman_Tree(){}
    Huffman_Tree(char character, int frequency)
    {
        this->frequency = frequency;
        this->character = character;
        this->left = NULL;
        this->right = NULL;
    }
    Huffman_Tree(int frequency, Huffman_Tree* node_1, Huffman_Tree* node_2)
    {
        this->frequency = frequency;
        this->character = '-';
        this->left = node_1;
        this->right = node_2;
    }
    void inOder(Huffman_Tree* root)
    {
        if (root == NULL)
        {
            return ;
        }
        else
        {
            inOder(root->left);
            cout << root->character << "\t" << root->frequency << endl;
            inOder(root->right);
        }
    }
    //MY CODE SUCKS
    /*
    void getCode(Huffman_Tree* root, char character)//, vector<int> code)
    {
        if(root = NULL)
            {
                cout << "NONE";
                return ; }
        if (root->character == character)
        {
            cout << "YES";
            //for(int i=0; i< code.size();i++)
            //{
                //cout << code[i];
            //}
        }
        else
        {
            getCode(root->left, character);//, code);
            getCode(root->right, character);//, code);

        }

    }*/
    //STOLEN FROM GEEKSFORGEEKS
    void printCodes(class Huffman_Tree* root, string str)
    {
        if (!root)
            return;

        if (root->character != '-')
            {
                cout << root->character << ": " << str << "\n";
                chara.push_back(root->character);
                code.push_back(str);
                }
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }
    int getFrequency()
    {
        return this->frequency;
    }

};
int getMinQ(vector<Huffman_Tree*> Q)
{
    int idx = 0;
    int MIN = Q[0]->getFrequency();
    for(int i=1;i < Q.size();i++)
    {
        if (Q[i]->getFrequency() < MIN)
        {
            MIN = Q[i]->getFrequency();
            idx = i;
        }
    }
    return idx;
}



void String2Frequency(string a_string)
{
    for(int i=0; i<ALPHABET.size();i++)
    {
        FREQUENCY[i] = 0;
    }
    for(int i=0; i<a_string.size(); i++)
    {
        for(int j=0; j<ALPHABET.size();j++)
        {
            if (ALPHABET[j] == a_string[i])
            {
                FREQUENCY[j]++;
            }
        }
    }
}
void UpdateCharNFrequency()
{
    for(int i=0; i<ALPHABET.size();i++)
    {
        if (FREQUENCY[i] > 0)
        {
            character.push_back((char) ALPHABET[i]);
            frequency.push_back(FREQUENCY[i]);
        }
    }
}
void Huffman_Coding(string a_string)//char* character, int* frequency)
{

    String2Frequency(a_string);
    UpdateCharNFrequency();
    //Initializing TAble
    vector<Huffman_Tree*> HuffTable;
    for(int i = 0; i< character.size(); i++)
    {
        HuffTable.push_back(new Huffman_Tree(character[i], frequency[i]));
    }

    while(HuffTable.size() > 1)
    {
        //Huffman_Tree* new_node;
        //GET 2 MIN FREQUENCY NODES
        int idx = getMinQ(HuffTable);
        Huffman_Tree* node_1 = HuffTable[idx];
        HuffTable.erase (HuffTable.begin()+idx);
        idx = getMinQ(HuffTable);
        Huffman_Tree* node_2 = HuffTable[idx];
        HuffTable.erase(HuffTable.begin()+idx);


        //ADD THEM INTO ONE
        int Sfrequency = node_1->getFrequency() + node_2->getFrequency();
        Huffman_Tree* new_node = new Huffman_Tree(Sfrequency, node_1, node_2);
        HuffTable.push_back(new_node);
        //HuffTable.insert(HuffTable.begin()+idx, new_node);
    }
    //HuffTable[0]->inOder(HuffTable[0]);
    string a = "";
    HuffTable[0]->printCodes(HuffTable[0], "");
}
//---------------------------------------------------------------------ENCODE
int GetIndex(char character)
{
    for(int i=0; i<chara.size(); i++)
    {
        if (character == chara[i])
        {
            return i;
        }
    }
}
string Encode(string input)
{
    string output = "";
    for(int i=0; i<input.size();i++)
    {
        char temp = (char) input[i];
        output+=code[GetIndex(temp)];
    }
    return output;
}
//---------------------------------------------------------------------END

//---------------------------------------------------------------------DECODE
bool CheckExist(string temp)
{
    for (int i=0; i<code.size();i++)
    {
        if (temp == code[i])
        {
            return true;
        }
    }
    return false;
}
int GET_INDEX(string temp)
{
    for (int i=0; i<code.size();i++)
    {
        if (temp == code[i])
        {
            return i;
        }
    }
}
string Decode(string input)
{
    if(input == "")
    {
        return "";
    }
    else
    {
        string temp = "";
        int count = 0;
        while(CheckExist(temp) == false)
        {
            temp = temp + input[count];
            count++;
        }
        string remain = "";
        for(int i=count; i<input.size(); i++)
        {
            remain = remain + input[i];
        }
        int index = GET_INDEX(temp);
        string result = "";
        result.push_back(chara[index]);
        return result + Decode(remain);
    }
}
//----------------------------------------------------------------------END
int main()
{
    //char character[] = {'i', 'c', 'l', 'n','f', 'o', 'a', 't', 'h', 'p', 'u' };
    //int frequency[] = {9,4,3,3,2,2,2,1,1,1,1};
    //String2Frequency("nicta")
    Huffman_Coding("dak qua adsadsasd adsaasd adsdas aaaa aa aa aa aaa aa a a ");//;//character, frequency);

}
