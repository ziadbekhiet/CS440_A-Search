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
#include <algorithm>

#include <fstream>
#include <string>
#include <sstream>
#include <deque>

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
                val[make_pair(i,j)] = 0;
            }
        }
    }
    val[make_pair(startx,starty)] = -1;
    
    int current_nodex = startx;
    int current_nodey = starty;
    int f_g = 0;
    int pval = -1;
    vector<pair<int,int>> :: const_iterator iter;
    while(current_nodex != finishx || current_nodey != finishy){
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
    pair<int,int> minp = make_pair(current_nodex,current_nodey);
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if (val[make_pair(i,j)] < minv && val[make_pair(i,j)] > 0){
                minv = val[make_pair(i,j)];
                minp = make_pair(i,j);
                    }
                }
   //     cout << endl;
    }
    // if goal node can not be reached
    if(minv == 99 && minp == make_pair(current_nodex,current_nodey)){
        vector<pair<int,int>> empty;
        //outputs the final explored nodes number
        //unnecessary
        int opened_nodes = 0;
        int explored_nodes = 0;
        for(int i = 0; i < 10; i++){
            for(int j =0; j < 10; j++){
                if(val[make_pair(i,j)] >= -1 && val[make_pair(i,j)]< 99){
                    opened_nodes++;
                }
                if(val[make_pair(i,j)] < 0){
                    explored_nodes++;
                }
            }
        }
        cout << endl << endl;
        for(int i = 0; i < 10; i++){
            for(int j =0; j < 10; j++){
                cout << val[make_pair(i,j)] << " ";
            }
            cout << endl;
        }
        cout << "on the map, -1 gives explored nodes and -2 represents an obstacle\n";
        cout << "opened nodes: " << opened_nodes << endl;
        cout << "explored nodes: " << explored_nodes << endl;
        // unnecessary
        return empty;
            break;
    }
        // end if goal node can not be reached
    
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
 //           cout << val[make_pair(i,j)] << " ";
        }
        cout << endl;
   }
    explored.push_back(minp);
    pval--;
    val[minp] = pval;
        
    current_nodex = minp.first;
    current_nodey = minp.second;
//    cout << "current_nodex: " << current_nodex << endl;
//    cout << "current_nodey: " << current_nodey << endl;
    }
    
    val[make_pair(current_nodex,current_nodey)] = pval;
    int opened_nodes = 0;
    int explored_nodes = 0;
    //outputs the number of explored nodes
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if(val[make_pair(i,j)] >= -1 && val[make_pair(i,j)]< 99){
                opened_nodes++;
            }
            if(val[make_pair(i,j)] <0){
                explored_nodes++;
            }
        }
    }
    // outputs the final val matrix
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
        for(int j =0; j < 10; j++){
            if(val[make_pair(i,j)] == 0){
                val[make_pair(i,j)] = -99;
            }
            cout << val[make_pair(i,j)] << " ";
        }
        cout << endl;
    }
    cout << "on the map, -x gives explored nodes, 0 represents an obstacle and 99 represents an unexplored node\n";
    cout << "opened nodes: " << opened_nodes << endl;
    cout << "explored nodes: " << explored_nodes << endl;

    //redo search while moving along the most negative values to find the searh path.
    vector<pair<int,int>> final_path;
    current_nodex = finishx;
    current_nodey = finishy;
    final_path.push_back(make_pair(current_nodex,current_nodey));
    while(current_nodex != startx || current_nodey != starty){
    int upy = current_nodey + 1;
    if(upy>=9){
        upy = 9;
        }
    int upx = current_nodex;
    
    int rx = current_nodex + 1;
    int ry = current_nodey;
    if(ry >= 9){
        ry = 9;
        }
    
    int dx = current_nodex;
    int dy = current_nodey - 1;
    if(dy <= 0){
        dy = 0;
        }
    
    int lx = current_nodex-1;
    int ly= current_nodey;
    if(lx <= 0){
        lx = 0;
        }
        int valup = val[make_pair(upx,upy)];
        if (valup >= 0){
            valup = -99;
        }
        int vald = val[make_pair(dx,dy)];
        if (vald >= 0){
            vald = -99;
        }

        int vall = val[make_pair(lx,ly)];
        if (vall >= 0){
            vall = -99;
        }
        

        int valr = val[make_pair(rx,ry)];
        if (valr == 0){
            valr = -99;
        }
        

    
        
    if (valup >= vald && valup >= vall && valup >= valr){
        current_nodex = upx;
        current_nodey = upy;
        }
    else if (vald >= valup && vald >= vall & vald >= valr){
            current_nodex = dx;
            current_nodey = dy;
        }
    else if (valr >= valup && valr >= vald && valr >= vall){
            current_nodex = rx;
            current_nodey = ry;}
    else if (vall >= valup && vall >= vald && vall >= valr){
            current_nodex = lx;
            current_nodey = ly;
        }
        final_path.push_back(make_pair(current_nodex,current_nodey));
 //       cout << "current_nodex: " << current_nodex << endl;
 //       cout << "current_nodey: " << current_nodey << endl;;
    }
    
    reverse(final_path.begin(), final_path.end());
    cout << endl<< endl;
//    vector<pair<int,int>>::const_iterator itf;
    int itf;
    for(itf = 0; itf < final_path.size(); itf++){
        cout << final_path[itf].first << endl;
        cout << final_path[itf].second << endl << endl;
    }
    
    return final_path;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    // file reader
    int cnt = 0;
    int X;
    int Y;
    int Ar[10][10];
    string line;
    ifstream myfile("/Users/HabibullahShaik/Desktop/xcode/Learn/maze.txt");
    if (myfile.is_open()){
        while(getline(myfile,line)){
            cnt++;
            if(cnt == 1){
                stringstream convert(line);
                convert >> X;
// prints read x                cout << X << endl;
            }
            else if(cnt == 2){
                stringstream convert2(line);
                convert2 >> Y;
// prints read y                cout << Y << endl;
            }
        }
        myfile.close();
    }
    Ar[X][Y];
    cnt = 0;
    ifstream myfile2("/Users/HabibullahShaik/Desktop/xcode/Learn/maze.txt");
    if (myfile2.is_open()){
        while(getline(myfile2,line)){
            cnt++;
            if(cnt > 2){
                stringstream c (line);
                int ycount = 0;
                while(1){
                    int n;
                    c >> n;
                    if(!c){
                        break;
                    }
                    Ar[cnt-3][ycount] = n;
                    ycount++;
                }
            }
        }
        myfile2.close();
    }
    //prints file reader input
//    for(int i = 0; i < X; i++){
//        for(int j = 0; j < Y; j++){
//            cout << Ar[i][j] << " ";
//        }
//        cout << endl;
//    }
    //end print file reader input
    // end file reader

    

    
   path(1,2,9,9,Ar);
    
    
    
    return 0;
}
