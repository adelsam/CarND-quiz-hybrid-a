#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "hybrid_breadth_first.h"

using namespace std;


int X = 1;
int _ = 0;

int NUM_THETA_CELLS = 90;
double SPEED = 1.45;
double LENGTH = 0.5;

vector< vector<int> > MAZE = {
        {_,X,X,_,_,_,_,_,_,_,X,X,_,_,_,_,},
        {_,X,X,_,_,_,_,_,_,X,X,_,_,_,_,_,},
        {_,X,X,_,_,_,_,_,X,X,_,_,_,_,_,_,},
        {_,X,X,_,_,_,_,X,X,_,_,_,X,X,X,_,},
        {_,X,X,_,_,_,X,X,_,_,_,X,X,X,_,_,},
        {_,X,X,_,_,X,X,_,_,_,X,X,X,_,_,_,},
        {_,X,X,_,X,X,_,_,_,X,X,X,_,_,_,_,},
        {_,X,X,X,X,_,_,_,X,X,X,_,_,_,_,_,},
        {_,X,X,X,_,_,_,X,X,X,_,_,_,_,_,_,},
        {_,X,X,_,_,_,X,X,X,_,_,X,X,X,X,X,},
        {_,X,_,_,_,X,X,X,_,_,X,X,X,X,X,X,},
        {_,_,_,_,X,X,X,_,_,X,X,X,X,X,X,X,},
        {_,_,_,X,X,X,_,_,X,X,X,X,X,X,X,X,},
        {_,_,X,X,X,_,_,X,X,X,X,X,X,X,X,X,},
        {_,X,X,X,_,_,_,_,_,_,_,_,_,_,_,_,},
        {X,X,X,_,_,_,_,_,_,_,_,_,_,_,_,_,},
};

vector< vector<int> > HEURISTIC = {
        {30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,},
        {29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,},
        {28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,},
        {27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,},
        {26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,},
        {25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,},
        {24,23,22,21,20,19,18,17,16,15,14,13,12,11,10, 9,},
        {23,22,21,20,19,18,17,16,15,14,13,12,11,10, 9, 8,},
        {22,21,20,19,18,17,16,15,14,13,12,11,10, 9, 8, 7,},
        {21,20,19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6,},
        {20,19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5,},
        {19,18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4,},
        {18,17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3,},
        {17,16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2,},
        {16,15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1,},
        {15,14,13,12,11,10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,},
};

vector< vector<int> > GRID = MAZE;

vector<double> START = {0.0,0.0,0.0};
vector<int> GOAL = {(int)GRID.size()-1, (int)GRID[0].size()-1};

int main() {

  cout << "Finding path through grid:" << endl;

  // TODO:: Create an Empty Maze and try testing the number of expansions with it

  for(int i = 0; i < GRID.size(); i++)
  {
    cout << GRID[i][0];
    for(int j = 1; j < GRID[0].size(); j++)
    {
      cout << "," << GRID[i][j];
    }
    cout << endl;
  }

  HBF hbf = HBF();

  HBF::maze_path get_path = hbf.search(GRID,
                                       HEURISTIC,
                                       START, GOAL);

  vector<HBF::maze_s> show_path = hbf.reconstruct_path(get_path.came_from, START, get_path.final);

  cout << "show path from start to finish" << endl;
  for(int i = show_path.size()-1; i >= 0; i--)
  {

    HBF::maze_s step = show_path[i];
    cout << "##### step " << step.g << " #####" << endl;
    cout << "x " << step.x << endl;
    cout << "y " << step.y << endl;
    cout << "theta " << step.theta << endl;

  }

  return 0;
}