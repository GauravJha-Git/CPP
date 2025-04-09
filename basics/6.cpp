#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cout<<"enter your string"<<endl;
    cin>>str;

    int vowels =0;
    int consonants =0;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = tolower(str[i]);
        if(ch>='a' && ch<='z'){
            if ( ch  == 'a' || ch  == 'e' ||ch=='i' || ch =='o' || ch =='u'){
                vowels++;
            }
            else{
                consonants++;
            }
    }
    }

    cout<<"Total Vowels:"<<vowels<<endl;
    cout<<"Total consonants:"<<consonants<<endl;
    return 0;
}