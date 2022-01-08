#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "globals.h"
using namespace std;


string replace_str(string& ss){
    int len = ss.length();
    regex_replace(ss, regex(" +"), " ");
    for(int i = 0; i < len; ++i){
        if(ss[i] == '\n')
            ss[i] = ' ';
    }
    return ss;
}



string isKeyWord(string &word){
    for(auto i: keyWords){
        if(word == i){
            return i;
                break;
        }
    }
    return "NOTDEFINED";
}

string isIdrentifier(string& word){
    if(regex_match(word, regex("[a-zA-Z][a-zA-z|0-9]*")))
        return word;
    return "NOTDEFINED";

}
string isOperator(string& word){
    if(regex_match(word, regex(("[.|;|+|-|!|+|(|)|=|/|*|&|^|%]"))))
        return word;
    return "NOTDEFINED";
}

string isDigit(string& word){
    if(regex_match(word, regex("[-+]?[0-9]*?\\.?[0-9]*")))
        return word;
    return "NOTDEFINED";
}

void scan(string code){

    vector<string> words;
    code = replace_str(code);
    stringstream ssin(code);
    
    for(string s; ssin >> s;)
        words.push_back(s);
    
    int len = words.size();
    
    for(int i = 0; i < len; ++i){
        
        
        
        if (isKeyWord(words[i]) != "NOTDEFINED"){
            cout << "-> " << words[i] << ": Keyword" << '\n';continue;
        }
        else if (isIdrentifier(words[i]) != "NOTDEFINED"){
            cout << "-> " << words[i] << ": Identifier" << '\n';continue;
        }
        
        else if (isOperator(words[i]) != "NOTDEFINED"){
            cout << "-> " << words[i] << ": Operator" << '\n';continue;
        }
        
          else if (isDigit(words[i]) != "NOTDEFINED"){
            cout << "-> " << words[i] << ": Digit" << '\n';continue;
            
            /*Comment implementation*/
        }else if(words[i][0] == '/' && words[i][1] == '/'){
            cout << "Is a one line comment";
            break;  
            /*Comment implementation*/
        }else if(words[i][0] == '/' && words[i][1] == '*'){
            string input = "";
            int j = i; 
            int w = 0;
            bool stop = true; 
            for(; j < len && stop; j++){
                w = 0;
                input += words[j] + ' ';
                for(; w < words[j].size(); ++w)
                    if(words[j][w] == '*' && words[j][w+1] == '/')
                    {
                        if(words[j][w+2] == '/' && words[j][w+3] == '*'){stop=true;}
                        else {cout << input << ": " << "Is an multiline comment\n";i=j;stop=false;break;}
                    }
                
            }
        }
        
        else
            cout << "(!)-> Misinterpret in the syntax: " << words[i] << '\n';


    }
}
#endif // HELPER_H_INCLUDED
