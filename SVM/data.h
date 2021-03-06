#ifndef DATA_HEADER
#define DATA_HEADER
#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

class Phoneme{
public:
    float value[48];
    int tag;
    int ans;
    Phoneme* prev = 0;
    Phoneme* next = 0;
};

struct Sequence{
    string name;
    char* result = 0;
    Phoneme* head = 0;
    Phoneme* end = 0;
};

typedef typename std::map<string,Sequence*> Sequences;
typedef typename std::pair<string,Sequence*> SequencePair;

void LoadSequences(Sequences&, const char*);
void LoadAnswers(Sequences&, const char*);
//char* trim(Answer&);
//char* trim_3(Answer&);
class TypeTableFunctor{
public:
    TypeTableFunctor(const char* path = 0){
        if(stringMap48_Int.size() != 0)
            return;
        int count = 0;
        ifstream file(path);
        char line[8];
        for(;file.getline(line, 8);){
            char* tok39 = strchr(line, '\t') + 1;
            tok39[-1] = '\0';
            table39[count] = tok39;
            table48[count] = line;
            stringMap48_Int.insert(pair<string,int>(line,count));
            stringMap48_39.insert(pair<string,string>(line,tok39));
            ++count;
            memset(line, 0, 8);
        }
    }
    int operator()(const string& tok) const{return stringMap48_Int[tok];}
    string& operator()(int i) const{return table48[i];}
    string& to39(int i) const{return table39[i];}
    string& to39(const string& tok) const{return stringMap48_39[tok];}
private:
    static std::map<string,int> stringMap48_Int;
    static std::map<string,string> stringMap48_39;
    static string table39[48];
    static string table48[48];
};
#endif
