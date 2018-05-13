//
//  main.cpp
//  Hill'sCipher
//
//  Created by Mehmet Sahin on 5/12/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdexcept>
using namespace std;

typedef  array < array <int, 2>, 2> Matrix;
typedef  vector<int> Message;

template <typename T>
void print(T , int , int );
void print(Message& );

void string2vector(Message&, string s);
string vector2string(const Message&);

void encrypt(Matrix, int, int , Message& , Message& );
int mod26(int n);


Matrix inverseMatrix(const Matrix , int , int );
int determinant( const Matrix &);
void decrypt(Matrix, int , int , Message& , Message& );

int main()
{
    Matrix key = { {10,2,2,2} } ;
    
    Message encryptedMessage;
    Message decryptedMessage;
    Message intMessage;
    
    string m = "me";
    
    string2vector(intMessage, m);
    print(intMessage);
    encrypt(key, 2, 2, intMessage, encryptedMessage);
    print(encryptedMessage);
    vector2string(encryptedMessage);
    
    Matrix inv = inverseMatrix(key, 2, 2);
    print(key, 2, 2);
    print(inv, 2, 2);
    decrypt(inv, 2, 2, encryptedMessage, decryptedMessage);
    print(decryptedMessage);
}

void decrypt(Matrix inverseKey, int row, int col, Message& encryptedMessage, Message& decryptedMessage)
{
    int rowSum;
    for(int i = 0; i < row; i++){
        rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += inverseKey[i][j] * encryptedMessage[j];
        }
        decryptedMessage.push_back(mod26(rowSum));
    }
}

Matrix inverseMatrix(const Matrix key, int row, int col)
{
    Matrix inverse;
    int determinantNum = determinant(key);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j) {
                inverse[i][j] = - mod26(key[i][j] * determinantNum);
            }else{
                int r = i ? 0 : 1;
                int c = j ? 0 : 1;
                inverse[i][j] = mod26(key[r][c] * determinantNum);
            }
        }
    }
    return inverse;
}

int determinant( const Matrix & m)
{
    return mod26( m[0][0] * m[1][1] - m[0][1] * m[1][0] );
}

void encrypt(Matrix key, int row, int col, Message& intMessage, Message& encrypted)
{
    int rowSum;
    for(int i = 0; i < row; i++){
        rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += key[i][j] * intMessage[j];
        }
        encrypted.push_back(mod26(rowSum));
    }
}

int mod26(int n)
{
    n %= 26;
    if (n < 0) n+= 26;
    return n;
}

string vector2string(const Message& message)
{
    string s;
    for ( const auto i : message)
        s += static_cast<char >(i + 'a');
    cout << s << endl;
    return s;
}

void string2vector(Message& message, string str)
{
    int i = 0;
    while(str[i]){
        message.push_back(str[i] - 'a');
        i++;
    }
}

void print(Message& message)
{
    vector<int>::iterator it = message.begin();
    while(it != message.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

template <typename T>
void print(T key, int row, int col)
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << key[i][j] << " ";
        }
    }
    cout << endl;
}











