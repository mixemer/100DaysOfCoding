//
//  HillCipher.hpp
//  HillCipherNew
//
//  Created by Mehmet Sahin on 5/14/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#ifndef HillCipher_hpp
#define HillCipher_hpp

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
using namespace std;

typedef  array < array <int, 2>, 2> Matrix;
typedef  vector<int> Message;

class HillCipher{
private:
    Matrix key = { {7,8,11,11} } ;
    int const row = 2;
    int const col = 2;
    Message encryptedMessage;
    Message decryptedMessage;
    
    string message;
    Message s2vector;
    
    string s_encryptedMessage;
    string s_decryptedMessage;
public:
    HillCipher();
    HillCipher(string);
    void print(int , int );
    void print(Message& );
    
    void string2vector();
    string vector2string(const Message message);
    
    void encrypt();
    int mod26(int n);
    
    
    Matrix inverseMatrix();
    int determinant( const Matrix &);
    void decrypt(Matrix);
};



#endif /* HillCipher_hpp */
