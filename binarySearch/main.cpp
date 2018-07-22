//
//  main.cpp
//  binarySearch
//
//  Created by Mehmet Sahin on 7/22/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int valueToFind){ // any accurance
    int start = 0;
    int end = size - 1;
    
    int location = -1;
    
    while (start <= end){
        int mid = (start + end)/2;
        if (arr[mid] == valueToFind){
            location = mid;
            break;
        }else if (arr[mid] > valueToFind){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    
    return location;
}

int binarySearch(int arr[], int size, int valueToFind, bool first){ // first or last accurance
    int start = 0;
    int end = size - 1;
    
    int location = -1;
    
    while (start <= end){
        int mid = (start + end)/2;
        if (arr[mid] == valueToFind){
            location = mid;
            if (first){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
            continue;
        }else if (arr[mid] > valueToFind){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    
    return location;
}

void binarySearchQuery(int arr[], const int SIZE){ // ask user for input for how many time to find numbers and what are the numbers that the user wants the algorithm to find.
    int numOfQuesties = 0;
    cout << "How many queries you have? ";
    cin >> numOfQuesties;
    
    for (int i = 0; i < numOfQuesties; i++){
        int query = 0;
        cout << "Query " << (i+1) << ": ";
        cin >> query;
        cout << "Location: " << binarySearch(arr, SIZE, query, true) << endl;
    }
}

int binarySearchNumOfAccurance(int arr[], const int SIZE, int number){
    int firstAccurance = binarySearch(arr, SIZE, number, true);
    int lastAccurance = binarySearch(arr, SIZE, number, false);
    
    return  (lastAccurance - firstAccurance + 1);
}

int main(int argc, const char * argv[]) {
    
    const int SIZE = 5;
    int arr[SIZE] = {2, 4, 7, 7, 9};
    
//    cout << binarySearch(arr, 7, 32) << endl; // find any
//    cout << binarySearch(arr, 7, 32, true) << endl; // find the first accurance
//    cout << binarySearch(arr, 7, 32, false) << endl; // find the last accurance
    
    //binarySearchQuery(arr, SIZE);
    
    const int SIZE2 = 10;
    int arr2[SIZE2] = {1,1,1,3,3,3,3,3,5,5};
    
    cout << binarySearchNumOfAccurance(arr2, SIZE2, 5) << endl;
    
    
    
    return 0;
}
