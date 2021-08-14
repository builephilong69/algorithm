#include<vector>
#include<iostream>
#include<string>

using namespace std;

string ALPHABET=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int FREQUENCY[53];


vector<char>used_chars;
vector<int>used_frequency;

vector<string>encode_message;

class HuffmanNode
{
private:

    int frequency;
    HuffmanNode* left = NULL;
    HuffmanNode* right = NULL;
public:
        char data;
    HuffmanNode()
    {

    }
    HuffmanNode(char data, int frequency)
    {
        this->data = data;
        this->frequency = frequency;
    }
    int getFrequency()
    {
        return this->frequency;
    }
    HuffmanNode(HuffmanNode* left, HuffmanNode* right)
    {
        this->left = left;
        this-> right = right;
        this->data = '-';
        this->frequency = left->getFrequency()+ right->getFrequency();
    }
    void printCodes(class HuffmanNode* root, string str )
    {
        if (!root)
            return;

        if (root->data != '-')
            {
                cout << root->data << ": " << str << "\n";
                for(int i  = 0 ; i< used_chars.size(); i++)
                {
                    if(root->data == used_chars[i])
                    {
                        encode_message[i] = str;
                    }
                }
            }
        printCodes(root->left, str + "0");
        printCodes(root->right, str + "1");
    }
};
int GetMinQ(vector<HuffmanNode*>HuffmanTable)
{
    int index = 0;
    HuffmanNode* MIN = HuffmanTable[0];
    for(int i = 1; i < HuffmanTable.size();i++)
    {
        if(HuffmanTable[i]->getFrequency() < MIN->getFrequency())
        {
            MIN = HuffmanTable[i];
            index = i;
        }
    }
    return index;
}


string Huffman_encode(string input)
{
    for(int i = 0 ; i < ALPHABET.size();i++)
    {
        FREQUENCY[i] = 0;

    }
    for(int i = 0 ; i < input.size() ;i++)
    {
        encode_message.push_back("");
        for(int j = 0 ; j < ALPHABET.size(); j++)
        {
            if(input[i] == (char)ALPHABET[j])
            {
                FREQUENCY[j]++;
            }
        }
    }

    for( int i = 0 ; i <53; i++)
    {
        if(FREQUENCY[i]>0)
        {
            used_chars.push_back((char)ALPHABET[i]);
            used_frequency.push_back(FREQUENCY[i]);
        }
    }

    // initialize the huffman tree
    vector<HuffmanNode*>HuffmanTable;
    for( int i = 0 ; i < used_chars.size(); i++)
    {
        HuffmanTable.push_back(new HuffmanNode(used_chars[i], used_frequency[i]));
    }

    // creating a huffman tree
    while(HuffmanTable.size() > 1)
    {
        int idx=GetMinQ(HuffmanTable);
        HuffmanNode* min_1 = HuffmanTable[idx];
        HuffmanTable.erase(HuffmanTable.begin() + idx);
        idx = GetMinQ(HuffmanTable);
        HuffmanNode* min_2 = HuffmanTable[idx];
        HuffmanTable.erase(HuffmanTable.begin() + idx);

        HuffmanNode* newNode = new HuffmanNode(min_1,min_2);
        HuffmanTable.push_back(newNode);

    }
    HuffmanTable[0]->printCodes(HuffmanTable[0],"");
    string encoded_result ="";
    for(int i = 0 ; i< input.size();i++)
    {
        for(int j  = 0 ; j< used_chars.size() ; j++)
            if(used_chars[j]==input[i])
        {
            encoded_result+=encode_message[j];
        }
    }

    return encoded_result;
}
string Huffman_decode(string input)
{
    string decoded_result="";

    while(input.size()>0)
    {
        for(int i = 0 ; i<encode_message.size(); i++)
        {
            string code =encode_message[i];
            int code_size = code.size();
            if(input.substr(0,code_size) == code)
            {
                decoded_result += used_chars[i];
                input.erase(0, code_size);
                break;
            }
        }
    }
    return decoded_result;
}

int main()
{
    string input;
    string decode_input;

    cout<<"Enter the string you want to encode: ";
    getline(std::cin,input);
    cout<<"Input size: "<<input.size()<<input<<endl;;
    string encoded_result = Huffman_encode(input);
    cout<<"Encoded Result: "<< encoded_result<<endl;;



    cout<<"Enter the binary string you want to decodee: ";
    cin>>decode_input;
    string decoded_result = Huffman_decode(decode_input);
    cout<<" Decoded Result: "<< decoded_result;

}
