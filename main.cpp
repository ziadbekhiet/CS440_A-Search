//
//  main.cpp
//  practice
//
//  Created by 206452150 on 7/28/18.
//  Copyright © 2018 206452150. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int manhattan_distance(int ci, int cj, int di, int dj){

    int x = abs(di - ci);
    int y = abs(dj - cj);
    
    return x+y;
};

vector<pair<int,int>> eliminateDuplicates(vector<pair<int,int>> generation)
{
    vector<pair<int,int>>::const_iterator iter;

    for(int i = 0; i < generation.size(); i++)
    {
        int current = generation.at(i).first;
        
        for(int j = i; j < generation.size(); j++)
        {
            if(j == i)
            {
                continue;
            }
            else
            {
                int temp = generation.at(j).first;
                if(current == temp)
                {
                    iter = generation.begin() + j;
                    generation.erase(iter);
                }
            }
        }
    }
    
    return generation;
}


vector<pair<int , int >> path(int i, int j, int k ,int l, int X[10][10]){
    
    vector<pair<int,int>> x;
    x.push_back(make_pair(i,j));
    int current_nodei = i;
    int current_nodej = j;
    
    int f = 0;
    
    vector<pair<int,int>> explored;
    explored.push_back(make_pair(i,j));
    vector<pair<int,int>>::iterator ptr;
    string move;
    bool cont = true;
    while((current_nodei != k || current_nodej != l) && cont){
    
    int up_j = current_nodej + 1;

    if(up_j>=9){
        up_j = 9;
    };
    int up_i = current_nodei;
    

    int right_i = current_nodei + 1;
    int right_j = current_nodej;
    if(right_j >= 9){
        right_j = 9;
    }

    int down_i = current_nodei;
    int down_j = current_nodej - 1;
    if(down_j <= 0){
        down_j = 0;
        }
    int left_i = current_nodei-1;
    int left_j = current_nodej;
    if(left_i <= 0){
        left_i = 0;
        }
    
    int md_up = manhattan_distance(up_i, up_j, k, l);
    int md_down = manhattan_distance(down_i, down_j, k,l);
    int md_left = manhattan_distance(left_i, left_j, k,l);
    int md_right = manhattan_distance(right_i, right_j, k,l);
//        cout << "(" << i << "," << j <<")" <<endl;
  //      cout << X[current_nodei][current_nodej] <<endl;
    //    cout << md_up << endl;
      //  cout << "(" << up_i << "," << up_j <<")" <<endl;
        //cout << X[up_i][up_j]<<endl;
        //cout << md_down << endl;
//        cout << "(" << down_i << "," << down_j <<")" <<endl;
  //      cout << X[down_i][down_j] << endl;
    //    cout << md_right <<endl;
      //  cout << "(" << right_i << "," << right_j <<")" <<endl;
//        cout << X[right_i][right_j]<<endl;
  //      cout << "(" << left_i << "," << left_j <<")" <<endl;
    //    cout << md_left << endl;
      //  cout << X[left_i][left_j] << endl;
        
    // Randomly switches between case 0-4 so that the same next path isn't chosen every time
    // in case of tie, algorithm will shift randomly between equivalent next step nodes until it finds the correct sequence
        int n = rand() % 4;
    switch(n){
        case 0:
            cout << "case 0" << endl;

                if (min({md_up,md_down,md_left,md_right}) == md_down && X[down_i][down_j] == 1){
                    cout << "move down" << endl;
                    move = "move down";
                    current_nodei = down_i;
                    current_nodej = down_j;
                    break;
                }
                else if (min({md_up,md_left,md_right}) == md_up && X[up_i][up_j] == 1){
                    cout << "move up" << endl;
                    move = "move up";
                    current_nodei = up_i;
                    current_nodej = up_j;
                    break;
                    }
                else if (min({md_left,md_right}) == md_left && X[left_i][left_j] == 1){
                    cout << "move left" << endl;
                    move = "move left";
                    current_nodei = left_i;
                    current_nodej = left_j;
                    break;
                    }
                else if (X[right_i][right_j] == 1){
                    cout << "move right" << endl;
                    move = "move right";
                    current_nodei = right_i;
                    current_nodej = right_j;
                    break;
                    }
        case 1:
            cout << "case 1" << endl;

            if (min({md_up,md_down,md_left,md_right}) == md_up && X[up_i][up_j] == 1){
                cout << "move up" << endl;
                move = "move up";
                current_nodei = up_i;
                current_nodej = up_j;
                break;
            }
            else if (min({md_down,md_left,md_right}) == md_left && X[left_i][left_j] == 1){
                cout << "move left" << endl;
                move = "move left";
                current_nodei = left_i;
                current_nodej = left_j;
                break;
            }
            else if (min({md_down,md_right}) == md_right && X[right_i][right_j] == 1){
                cout << "move right" << endl;
                move = "move right";
                current_nodei = right_i;
                current_nodej = right_j;
                break;
            }
            else if (X[down_i][down_j] == 1){
                cout << "move down" << endl;
                move = "move down";
                current_nodei = down_i;
                current_nodej = down_j;
                break;
            }
        case 2:
            cout << "case 2" << endl;
            if (min({md_up,md_down,md_left,md_right}) == md_right && X[right_i][right_j] == 1){
                cout << "move right" << endl;
                move = "move right";
                current_nodei = right_i;
                current_nodej = right_j;
                break;
            }
            else if (min({md_up,md_left,md_right}) == md_up && X[up_i][up_j] == 1){
                cout << "move up" << endl;
                move = "move up";
                current_nodei = up_i;
                current_nodej = up_j;
                break;
            }
            else if (min({md_left,md_right}) == md_down && X[down_i][down_j] == 1){
                cout << "move right" << endl;
                move = "move right";
                current_nodei = right_i;
                current_nodej = right_j;
                break;
            }
            else if (X[left_i][left_j] == 1){
                cout << "move left" << endl;
                move = "move left";
                current_nodei = left_i;
                current_nodej = left_j;
                break;
            }
        case 3:
            cout << "case 3" << endl;

            if (min({md_up,md_down,md_left,md_right}) == md_down && X[down_i][down_j] == 1){
                cout << "move down" << endl;
                move = "move down";
                current_nodei = down_i;
                current_nodej = down_j;
                break;
            }
            else if (min({md_up,md_left,md_right}) == md_up && X[up_i][up_j] == 1){
                cout << "move up" << endl;
                move = "move up";
                current_nodei = up_i;
                current_nodej = up_j;
                break;
            }
            else if (min({md_left,md_right}) == md_left && X[left_i][left_j] == 1){
                cout << "move left" << endl;
                move = "move left";
                current_nodei = left_i;
                current_nodej = left_j;
                break;
            }
            else if (X[right_i][right_j] == 1){
                cout << "move right" << endl;
                move = "move right";
                current_nodei = right_i;
                current_nodej = right_j;
                break;
            }
    }
    cout<< "current node i:" << current_nodei << endl;
    cout <<"current node j:" << current_nodej << endl;
        cout << X[current_nodei][current_nodej] << endl;
    x.push_back(make_pair(current_nodei,current_nodej));
        
        //breaks if loop iterates > 200 times
    f +=1;
        if(f > 200){ cont = false;}
    }
    cout << endl <<endl;
    for(int i = 0; i < x.size(); i++)
    {
        cout << x[i].first << ", " << x[i].second << endl;
    }
  //  x.erase( unique( x.begin(), x.end() ), x.end() );
    
    cout << endl <<endl;
    
    for(int i = 0; i < x.size(); i++)
    {
        cout << x[i].first << ", " << x[i].second << endl;
        
    }
    
    //need to clean output for repeated values before returning


    return x;
    

};




int main(int argc, const char * argv[]) {

    
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
};
