//
//  HillCipher.cpp
//  HillCipherNew
//
//  Created by Mehmet Sahin on 5/14/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include "HillCipher.hpp"

HillCipher::HillCipher(){
    throw string("You need to send an message!");
}

HillCipher::HillCipher(string message){
    this->message = message;
    
    string2vector();
    encrypt();
    s_encryptedMessage = vector2string(encryptedMessage);
    cout << "encrypted: " << s_encryptedMessage<< endl;
    
    Matrix inv = inverseMatrix();
    
    decrypt(inv);
    s_decryptedMessage = vector2string(decryptedMessage);
    cout << "decrypted : " << s_decryptedMessage<< endl;
    
}

void HillCipher::decrypt(Matrix inverseKey)
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

Matrix HillCipher::inverseMatrix()
{
    Matrix inverse;
    int determinantNum = determinant(key);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j) {
                int r = i ? 0 : 1;
                int c = j ? 0 : 1;
                inverse[i][j] = mod26(mod26(key[r][c]) * determinantNum);
            }else{
                inverse[i][j] = mod26(mod26(-(key[i][j])) * determinantNum);
            }
        }
    }
    return inverse;
}

int HillCipher::determinant( const Matrix & m)
{
    int determinantWithMod = mod26( m[0][0] * m[1][1] - m[0][1] * m[1][0] );
    int x = 2;
    if(determinantWithMod % 26 != 1){
        while((determinantWithMod * x) % 26 != 1){
            x+=1;
        }
    }
    return x;
}

void HillCipher::encrypt()
{
    int rowSum;
    for(int i = 0; i < row; i++){
        rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += key[i][j] * s2vector[j];
        }
        encryptedMessage.push_back(mod26(rowSum));
    }
}

int HillCipher::mod26(int n)
{
    n %= 26;
    if (n < 0) n+= 26;
    return n;
}

string HillCipher::vector2string(const Message message)
{
    string s;
    for ( const auto i : message)
        s += static_cast<char >(i + 'a');
    return s;
}

void HillCipher::string2vector()
{
    int i = 0;
    while(message[i]){
        s2vector.push_back(message[i] - 'a');
        i++;
    }
}

void HillCipher::print(Message& message)
{
    vector<int>::iterator it = message.begin();
    while(it != message.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void HillCipher::print(int row, int col)
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << key[i][j] << " ";
        }
    }
    cout << endl;
}
