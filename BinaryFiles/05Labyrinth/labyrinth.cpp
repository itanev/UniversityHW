#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void decode(char* secret, unsigned char* code) {
    for (int i = 0; i < 16; i++) {
   	 for (int j = 0; j < 8; j++) {
   		 secret[i * 8 + j] ^= code[j];
   	 }
    }
}

enum POSITION_OFFSET_TYPE {
    BEGINNING,
    CURRENT,
    END
};

struct Node {
    int sign;
    POSITION_OFFSET_TYPE offsetType;
    int left;
    int right;
    unsigned char code[8];
};

int convertBytes(char * sector)
{
    return ((int)sector[0] | ((int)sector[1] << 8) | ((int)sector[2] << 16) | ((int)sector[3] << 24));
}

int main()
{
    //############################
    //Not sure if it is correct
    //############################

    ifstream file("labyrinth.bin", ios::in|ios::binary);

    Node node;
    int firstInt, secondInt;
    char * secret = new char[128];
    long long size;
    int nodeStartPoint = sizeof(int)*2 + sizeof(secret);
    int firstNodeNum = 0, secondNodeNum = 0;

    if(file.is_open())
    {
        file.seekg(0, ios::end);
        size = file.tellg();

        file.seekg(0, ios::beg);
        file.read((char*)&firstInt, sizeof(int));
        firstInt = convertBytes((char*)&firstInt);

        file.seekg(sizeof(int), ios::beg);
        file.read((char*)&secondInt, sizeof(int));

        file.seekg(sizeof(int)*2, ios::beg);
        file.read(secret, sizeof(secret));

        while(nodeStartPoint <= size)
        {
            //check if we have to decode current node
            if(firstNodeNum == firstInt)
            {
                decode(secret, node.code);
                cout << node.code << endl;
            }

            if(secondNodeNum == secondInt)
            {
                decode(secret, node.code);
                cout << node.code << endl;
            }

            firstNodeNum++; secondNodeNum++;
            //read nodes
            file.seekg(nodeStartPoint, ios::beg);
            file.read((char*)&node, sizeof(node));

            //get the position of next node
            if(convertBytes((char*)&node.sign) % 2 == 0)
            {
                if(convertBytes((char*)&node.offsetType) == BEGINNING)
                {
                    nodeStartPoint = convertBytes((char*)&node.left);
                }
                else if(convertBytes((char*)&node.offsetType) == CURRENT)
                {
                    nodeStartPoint += sizeof(node);
                    nodeStartPoint += convertBytes((char*)&node.left);
                }
                else if(convertBytes((char*)&node.offsetType) == END)
                {
                    nodeStartPoint = size - convertBytes((char*)&node.left);
                }
                else
                {
                    nodeStartPoint += sizeof(node);
                }
            }
            else
            {
                if(convertBytes((char*)&node.offsetType) == BEGINNING)
                {
                    nodeStartPoint = convertBytes((char*)&node.right);
                }
                else if(convertBytes((char*)&node.offsetType) == CURRENT)
                {
                    nodeStartPoint += sizeof(node);
                    nodeStartPoint += convertBytes((char*)&node.right);
                }
                else if(convertBytes((char*)&node.offsetType) == END)
                {
                    nodeStartPoint = size - convertBytes((char*)&node.right);
                }
                else
                {
                    nodeStartPoint += sizeof(node);
                }
            }
        }
    }

    file.close();
    delete[] secret;
    return 0;
}
