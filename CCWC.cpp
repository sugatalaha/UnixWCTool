#include<bits/stdc++.h>
#include<regex>
using namespace std;

void printErrorMessage()
{
    cout<<"Usage: ./ccwc -[option] [filename]"<<endl;
    exit(0);
}

int countBytes(fstream &file)
{
    file.clear();
    file.seekg(0,ios::end);
    auto size=file.tellg();
    return size;
}

int countChars(fstream &file)
{
    file.clear();
    file.seekg(0);
    unsigned char ch;
    int charCount=0;
    while(file.read(reinterpret_cast<char *>(&ch),1))
    {
        if((ch&0xC0)!=0x80)
        {
            charCount++;
        }
    }
    return charCount;
}

int countLines(fstream &file)
{
    file.clear();
    file.seekg(0);
    string line;
    int linecount=0;
    while(getline(file,line))
    {
        linecount++;
    }
    return linecount;
}

int countWords(fstream &file)
{
    file.clear();
    file.seekg(0);
    int wordcount=0;
    char ch;
    string word;
    while(file>>word)
    {
        wordcount++;
    }
    return wordcount;
}

int countBytesFromStream(stringstream &buffer)
{
    char ch;
    buffer.clear();
    buffer.seekg(0,ios::end);
    return buffer.tellg();
}

int countCharsFromStream(stringstream &buffer)
{
    unsigned char ch;
    int charCount=0;
    buffer.clear();
    buffer.seekg(0);
    while(buffer.read(reinterpret_cast<char *>(&ch),1))
    {
        if((ch&0xC0)!=0x80)
        {
            charCount++;
        }
    }
    return charCount;
}

int countLinesFromStream(stringstream &buffer)
{
    int lines=0;
    string line="";
    buffer.clear();
    buffer.seekg(0);
    while(getline(buffer,line))
    {
        lines++;
    }
    return lines;
}

int countWordsFromStream(stringstream &buffer)
{
    int words=0;
    string word="";
    buffer.clear();
    buffer.seekg(0);
    while(buffer>>word)
    {
        words++;
    }
    return words;
}
void printOptionErrorMessage()
{
    cout<<"ccwc: invalid option"<<endl;
    exit(0);
}

void printOneResponse(int val,string &arg)
{
    cout<<val<<" "<<arg<<endl;
}

int main(int argc,char *argv[])
{
    char option='$';
    istream *in=nullptr;
    string filename="";
    fstream file;
    regex optionPattern("-[lcmw]");
    if(argc==1)
    {
        in=(&cin);
    }
    else if(argc==2)
    {
        if(argv[1][0]=='-')
        {
            if(regex_match(argv[1],optionPattern))
            {
                option=argv[1][1];
                in=(&cin);
            }
            else
            {
                printErrorMessage();
            }
        }
        else 
        {
            file.open(argv[1]);
            filename=argv[1];
            if(!file)
            {
                cout<<"Error opening file!"<<endl;
                exit(0);
            }
        }
    }
    else if(argc==3)
    {
        string optionString=argv[1];
        if(!regex_match(optionString,optionPattern))
        {
            printOptionErrorMessage();
            exit(0);
        }
        else
        {
            option=argv[1][1];
        }
        file.open(argv[2]);
        filename=argv[2];
        if(!file)
        {
            cout<<"Error opening file!"<<endl;
            exit(0);
        }
    }
    else
    {
        printErrorMessage();
    }
    if(filename!="")
    {
        switch(option)
        {
            case 'c':
            {
                auto size=countBytes(file);
                printOneResponse(size,filename);
                break;
            }
            case 'l':
            {
                int linecount=countLines(file);
                printOneResponse(linecount,filename);
                break;
            }
            case 'm':
            {   
                int charCount=countChars(file);
                printOneResponse(charCount,filename);
                break;
            }
            case 'w':
            {   
                int wordcount=countWords(file);
                printOneResponse(wordcount,filename);
                break;
            }
            default:
            {
                int lineCount=countLines(file);
                int wordCount=countWords(file);
                int byteCount=countBytes(file);
                cout<<" "<<lineCount<<" "<<wordCount<<" "<<byteCount<<endl;
                break;
            }
        }
    }
    else
    {
        stringstream buffer;
        buffer<<in->rdbuf();
        switch(option)
        {
            case 'c':
            {
                auto size=countBytesFromStream(buffer);
                printOneResponse(size,filename);
                break;
            }
            case 'l':
            {
                int linecount=countLinesFromStream(buffer);
                printOneResponse(linecount,filename);
                break;
            }
            case 'm':
            {   
                int charCount=countCharsFromStream(buffer);
                printOneResponse(charCount,filename);
                break;
            }
            case 'w':
            {   
                int wordcount=countWordsFromStream(buffer);
                printOneResponse(wordcount,filename);
                break;
            }
            default:
            {
                int lineCount=countLinesFromStream(buffer);
                int wordCount=countWordsFromStream(buffer);
                int byteCount=countBytesFromStream(buffer);
                cout<<" "<<lineCount<<" "<<wordCount<<" "<<byteCount<<endl;
                break;
            }
        }
    }
}