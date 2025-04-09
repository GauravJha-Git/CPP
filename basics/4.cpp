#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;

    cout<<"enter your string:"<<endl;
    getline(cin,str);
    // cin>>str;

    int start=0;
    int end = str.length()-1;
    bool isPallindrome = true;

    while(start<end){
        if(str[start]!=str[end]){
            isPallindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPallindrome)
    cout << "Palindrome String" << endl;
    else
    cout << "Not a Palindrome" << endl;

return 0;
}