#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <conio.h>
#define max_num_lines 52

using namespace std;

//node structure definition
typedef struct node
{
  int data;
  char letter=' ';
  bool bitValue;
  struct node *left;
  struct node *right;
};

//new node inserting only a value
node* newNode(int value, bool bitValue)
{
  node* tempNode= new (node);

  // Assign data to this node
  tempNode->data = value;
  tempNode->bitValue=bitValue;
  tempNode->left=NULL;
  tempNode->right=NULL;

  return(tempNode);
};

node* newNode(int value, char letterIn, bool bitValue)
{
  node* tempNode= new (node);

  // Assign data to this node
  tempNode->data = value;
  tempNode->letter= letterIn;
  tempNode->bitValue=bitValue;
  tempNode->left=NULL;//initialize left to null
  tempNode->right=NULL;//initializer right to null
  return(tempNode);
};

//reading data
void getData(char filename[], string str[max_num_lines])
{
    ifstream ins;
    ins.open(filename);
    int i=0;
    while (!ins.eof())
    {
        getline(ins, str[i]);
        i++;
    }
}

//gets first line from text file as a string converts it to in and sets that as num lines
int getNumLines(string data[max_num_lines])
{
    int tempNumber;
    tempNumber=atoi(data[0].c_str());
    return(tempNumber);
}

//parses data such that we have letters in one array and frequencies in another(a char array and a str array)
void parseData(int numLines,string data[max_num_lines], char letters[max_num_lines], string frequencyStr[max_num_lines])
{
    int i,strLength=0;
    string tempStr1;
    for(i=0;i<numLines;i++)
    {
        tempStr1=data[i+1];
        strLength=tempStr1.length()-1;
        letters[i]=tempStr1[0];
        frequencyStr[i]=tempStr1.substr(2,strLength);
    }
}

//converts frequency str array to an int array
void convStrtoInt(int numLines, int frequencyNum[max_num_lines], string frequencyStr[max_num_lines])
{
    int tempNumber,i;
    string tempStr;
    for(i=0;i<numLines;i++)
    {
        tempStr=frequencyStr[i];
        tempNumber=atoi(tempStr.c_str());
        frequencyNum[i]=tempNumber;
        cout<<frequencyNum[i]<<endl;
    }
}

void buildNodes(int numLines, node* root[max_num_lines], int frequencyNum[max_num_lines], char letters[max_num_lines])
{
    int i;
    for(i=0;i<numLines;i++)
    {
        root[i]=newNode(frequencyNum[i+1],letters[i]);
    }
}

void bubbleSortNode(int numLines,node* tree[max_num_lines])
{
    int i,j;
    node* tempNode=new (node);
    for(i=0;i<numLines;i++)
    {
        for(j=0;j<numLines-i;j++)
        {
            if(tree[j]->data<tree[j+1]->data)
            {
                tempNode->data=tree[j]->data;
                tree[j]->data=tree[j+1]->data;
                tree[j+1]->data=tempNode->data;
            }
            delete(tempNode);
        }

    }
}
//build the tree data
void buildTreeData(int numLines, node* root[max_num_lines])
{
    int i=numLines-1;

    root[i]=newNode(9+20,true);
    root[i]->left=newNode(9,'p',true);
    root[i]->right=newNode(20,'n',false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(29+33,true);
    root[i]->left=newNode(29,true);
    root[i]->right=newNode(33,'m',false);
    i--;
     //--------------------------------------------------------
    root[i]=newNode(44+55,true);
    root[i]->left=newNode(44,'l',true);
    root[i]->right=newNode(55,'m',false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(62+68,true);
    root[i]->left=newNode(62,true);
    root[i]->right=newNode(68,'j',false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(71+92,true);
    root[i]->left=newNode(71,'i',true);
    root[i]->right=newNode(92,'h',false);
    i--;
     //--------------------------------------------------------
    root[i]=newNode(99+119,true);
    root[i]->left=newNode(99,true);
    root[i]->right=newNode(119,'g',false);
    i--;
     //--------------------------------------------------------
    root[i]=newNode(127+130,true);
    root[i]->left=newNode(127,'f',true);
    root[i]->right=newNode(130,'g',false);
    i--;
     //--------------------------------------------------------
    root[i]=newNode(163+169,true);
    root[i]->left=newNode(163,true);
    root[i]->right=newNode(169,'e',false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(191+218,true);
    root[i]->left=newNode(191,'j',true);
    root[i]->right=newNode(218,false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(237+257,true);
    root[i]->left=newNode(237,'c',true);
    root[i]->right=newNode(257,false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(289+332,true);
    root[i]->left=newNode(289,'b',true);
    root[i]->right=newNode(332,false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(409+494,true);
    root[i]->left=newNode(409,true);
    root[i]->right=newNode(494,false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(621+903,true);
    root[i]->left=newNode(621,true);
    root[i]->right=newNode(903,false);
    i--;
    //--------------------------------------------------------
    root[i]=newNode(1524+99999,true);
    root[i]->left=newNode(1524,true);
    root[i]->right=newNode(99999,'a',false);

}

void printTree(int numLines, node* tree[max_num_lines])
{
    int i;
    for(i=1;i<numLines;i++)
    {
        if(tree[i]->letter==' ')
        {
            cout<<endl<<tree[i]->data<<", "<<tree[i]->bitValue<<endl;
            if(tree[i]->left->letter==' ')
            {
                cout<<tree[i]->left->data<<", "<<tree[i]->left->bitValue<<"\t";
                if(tree[i]->right->letter==' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<endl;
                else if (tree[i]->right->letter!=' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<", "<<tree[i]->right->letter<<endl;
            }
            else if(tree[i]->left->letter!=' ')
            {
                cout<<tree[i]->left->data<<", "<<tree[i]->left->bitValue<<", "<<tree[i]->left->letter<<"\t";
                 if(tree[i]->right->letter==' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<endl;
                else if (tree[i]->right->letter!=' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<", "<<tree[i]->right->letter<<endl;
            }

        }
        else if(tree[i]->letter!=' ')
        {
            cout<<tree[i]->data<<", "<<tree[i]->bitValue<<", "<<tree[i]->letter<<endl;
            if(tree[i]->left->letter==' ')
            {
                cout<<tree[i]->left->data<<", "<<tree[i]->left->bitValue<<"\t";
                if(tree[i]->right->letter==' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<endl;
                else if (tree[i]->right->letter!=' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<", "<<tree[i]->right->letter<<endl;
            }
            else if(tree[i]->left->letter!=' ')
            {
                cout<<tree[i]->left->data<<", "<<tree[i]->left->bitValue<<", "<<tree[i]->left->letter<<"\t";
                 if(tree[i]->right->letter==' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<endl;
                else if (tree[i]->right->letter!=' ')
                    cout<<tree[i]->right->data<<", "<<tree[i]->right->bitValue<<", "<<tree[i]->right->letter<<endl;
            }
        }

    }
}

string getBitString ()
{
    ifstream ins;
    string tempStr;
    ins.open("a4-2.txt");
    while (!ins.eof())
    {
        getline(ins, tempStr);
    }
    return(tempStr);
}

void searchTree(node* root[max_num_lines], string bitString)
{
    int i, strLength;
    strLength=bitString.length();
    for(i=0;i<strLength;i+3)
    {
        if(root[i]->bitValue==bitString[i])
        {
            if(root[i]->letter!=' ')
                cout<<root[i]->letter;
            else
            {
                if(root[i]->left->bitValue==bitString[i+1])
                    cout<<endl;
            }
        }
    }
}

//sort data
void bubbleSort(int numLines,int frequencyNum[max_num_lines])
{
    int i,j,temp;
    for(i=0;i<=numLines;i++)
    {
        for(j=0;j<numLines-i;j++)
        {
            if(frequencyNum[j]<frequencyNum[j+1])
            {
                temp=frequencyNum[j];
                frequencyNum[j]=frequencyNum[j+1];
                frequencyNum[j+1]=temp;
            }
        }
    }
}

int main()
{
    system("color a");
    string data[max_num_lines],frequencyStr[max_num_lines],bitString;
    node* root[max_num_lines];
    char letters[max_num_lines];
    int numLines=0, frequencyNum [max_num_lines];
    getData("a4-1.txt",data);
    numLines=getNumLines(data);
    parseData(numLines,data,letters,frequencyStr);
    cout<<"************************ Actual data stored in array********************"<<endl;
    convStrtoInt(numLines,frequencyNum,frequencyStr);
    bubbleSort(numLines,frequencyNum);
    buildNodes(numLines,root,frequencyNum,letters);
    bubbleSortNode(numLines,root);
    buildTreeData(numLines, root);
    cout<<"************************Tree********************"<<endl;
    printTree(numLines,root);
    cout<<"************************bit string********************"<<endl;
    bitString=getBitString();
    cout<<bitString<<"    "<<bitString.length();

    return 0;
}
