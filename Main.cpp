//
//  main.cpp
//  Z
//
//  Created by Leroy on 27/02/2020.
//  Copyright © 2020 Leroy. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define SIZE 8
using namespace std;
int main(int argc, const char * argv[]) {
    int matrix[SIZE][SIZE] = {0};       //Matrix
    int a[SIZE][SIZE] = {0};        //Go through
    
    
    int *p;
    p = &matrix[0][0];
    
    int i, j, x, y;
    
    /* initial martix */
    for(i = 0; i < SIZE * SIZE; i++)
        *p++ = i;
    
    // print out raw matrix
    cout<<"Initial Martix: "<<endl;
    for(i = 0; i < SIZE; i++){
        for(j = 0;j < SIZE; j++)
            cout<<setw(4)<<*(*(matrix + i) + j);
        cout<<endl;
        
    }
    
    i = 0; j = 0;
    
    // Z arrangment
    for(x = 0; x < SIZE; x++)
        for(y = 0; y < SIZE; y++){
            *(*(a + i) + j) = *(*(matrix + x) + y);
            
            if((i == SIZE-1 || i == 0) && j % 2 == 0){
                j++;
                continue;
            }
            if((j == 0 || j == SIZE-1) && i % 2 == 1){
                i++;
                continue;
            }
            if((i + j) % 2 == 0){
                i--;
                j++;
            }
            else if((i+j)%2 == 1){
                i++;
                j--;
            }
        }
    cout<<endl<<"After Z arrangement"<<endl;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j <SIZE; j++)
            cout<<setw(4)<<*(*(a +i) +j);
        cout<<endl;
    }
    cout << "Hello, World!\n";
    return 0;
}
