//
//  main.cpp
//  A*Search
//
//  Created by 206452150 on 7/31/18.
//  Copyright © 2018 206452150. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;


int manhattan_distance(int ci, int cj, int di, int dj){
    
    int x = abs(di - ci);
    int y = abs(dj - cj);
    
    return x+y;
};

vector< pair<int,int>> path(int startx, int starty, int finishx, int finishy, int X[10][10]){
    vector<pair<int,int>> explored;
    explored.push_back(make_pair(startx,starty));
    
    
    map<pair<int,int>,int> val;
    
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if(X[i][j] == 1){
                val[make_pair(i,j)] = 99;}
            if(X[i][j] == 0){
                val[make_pair(i,j)] = -2;
            }
        }
    }
    val[make_pair(startx,starty)] = -1;
    
    int current_nodex = startx;
    int current_nodey = starty;
    
    vector<pair<int,int>> :: const_iterator iter;
    while(current_nodex != finishx || current_nodey != finishy){
    int lowf = 0;
    pair<int,int> pos;
    for(iter = explored.begin(); iter < explored.end(); iter++){
        int ex = iter -> first;
        int ey = iter -> second;
        
        int upy = ey + 1;
        if(upy>=9){
            upy = 9;
        };
        int upx = ex;
        
        int rx = ex + 1;
        int ry = ey;
        if(ry >= 9){
            ry = 9;
        }
        
        int dx = ex;
        int dy = ey - 1;
        if(dy <= 0){
            dy = 0;
        }
        
        int lx = ex-1;
        int ly= ey;
        if(lx <= 0){
            lx = 0;
        }
        
        if(val[make_pair(upx,upy)] > manhattan_distance(upx,upy,finishx,finishy) && X[upx][upy] ==1){
            val[make_pair(upx,upy)] = manhattan_distance(upx,upy,finishx,finishy) + 1;
        }
        
        if(val[make_pair(dx,dy)] > manhattan_distance(dx,dy,finishx,finishy) && X[dx][dy] ==1){
            val[make_pair(dx,dy)] = manhattan_distance(dx,dy,finishx,finishy) + 1;
        }
        if(val[make_pair(rx,ry)] > manhattan_distance(rx,ry,finishx,finishy)&& X[rx][ry] ==1){
            val[make_pair(rx,ry)] = manhattan_distance(rx,ry,finishx,finishy) + 1;
        }
        if(val[make_pair(lx,ly)] > manhattan_distance(lx,ly,finishx,finishy)&& X[lx][ly] ==1){
            val[make_pair(lx,ly)] = manhattan_distance(lx,ly,finishx,finishy) + 1;
        }
    }
    
    int minv = 99;
    pair<int,int> minp = make_pair(startx,starty);
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if (val[make_pair(i,j)] < minv && val[make_pair(i,j)] > 0){
                minv = val[make_pair(i,j)];
                minp = make_pair(i,j);
                    }
                }
        cout << endl;
    }
    
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            cout << val[make_pair(i,j)] << " ";
        }
        cout << endl;
    }
    explored.push_back(minp);
    val[minp] = -1;
        
    current_nodex = minp.first;
    current_nodey = minp.second;
    cout << "current_nodex: " << current_nodex << endl;
    cout << "current_nodey: " << current_nodey << endl;
    }
    val[make_pair(current_nodex,current_nodey)] = -1;
    int opened_nodes = 0;
    int explored_nodes = 0;
    //outputs the final explored nodes number
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if(val[make_pair(i,j)] >= -1 && val[make_pair(i,j)]< 99){
                opened_nodes++;
            }
            if(val[make_pair(i,j)] == -1){
                explored_nodes++;
            }
        }
    }
    // outputs the final val matrix
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            cout << val[make_pair(i,j)] << " ";
        }
        cout << endl;
    }
    cout << opened_nodes << endl;
    cout << explored_nodes << endl;
    
    return explored;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int X[10][10] = {1,1,1,1,1,1,1,1,1,1,
        1,1,1,0,1,0,1,1,1,1,
        0,0,0,1,1,0,1,1,1,1,
        0,1,0,1,1,1,1,1,1,1,
        1,0,1,1,0,1,1,1,1,0,
        1,1,1,1,0,1,1,1,1,1,
        1,1,0,1,1,1,1,1,1,1,
        1,1,1,1,1,0,1,1,1,1,
        1,1,1,1,1,0,1,1,1,1,
        1,1,1,1,1,0,1,1,1,1};
    
    
    
    path(1,2,9,9,X);
    
    
    
    return 0;
}
