#include<iostream>
#include<string>
using namespace std;

void replaceSpace(char *str,int length) {
    //calc the num of space
    int numOfSpace = 0;
    for(int i = 0; i < length; i++){
        if(str[i] == ' ')
            numOfSpace++;
    }
    //从后往前插入"%20", 最后一个空格后的字符后移numOfSpace*2
    //倒数第二个空格后的字符后移(numOfSpace-1)*2
    for(int i = length - 1; i >= 0; i--){
        if(str[i] != ' '){
            str[i + numOfSpace * 2] = str[i];
        }
        else{
            numOfSpace--;
            str[i + numOfSpace * 2] = '%';
            str[i + 1 + numOfSpace * 2] = '2';
            str[i + 2 + numOfSpace * 2] = '0';
        }
    }
}

int main(){
    char s[101];
    cin.getline(s, sizeof(s));

    // string ss;
    // getline(cin, ss);

    char buffer[101];
    int ch = 0;
    int i = 0;
    while((ch = getchar()) != '#' && i < 100){
        buffer[i++] = ch;   
    }
    buffer[i] = '\0';
    printf("%s\n",buffer);

    replaceSpace(s, 100);
    cout<<s<<endl;  
    return 0;
}