#include <iostream>

using namespace std;

//우리가 대입해야 하는 2개의 상수
const int SIZE = 5;
const int FIRST = 0;

int x[SIZE][SIZE];

int y[SIZE];

int dfs(int current_value, int depth) {
  
  if (depth == SIZE - 1) return 1;
  
  int activation = 0;
  
  for (int i = 0; i < SIZE; i++) {
    int k = 1;
    for (int j = 0; j < depth; j++) {
      if (i == y[j]) k = 0;
    }
    if (k ==0) continue;
      
    if (x[current_value][i] == 1) {
      y[depth + 1] = i;
      activation = dfs(i, depth + 1);
    }
    if (activation == 1) return 1;
  }
  if (activation == 0) {
    y[depth] = -1;
  }
  return 0;
}

int main() {
  //여기에서 x에 정사각대칭행렬을 대입해야 함
  x[0][0] = 0;
  x[0][1] = 1;
  x[0][2] = 1;
  x[0][3] = 1;
  x[0][4] = 0;
  x[1][0] = 1;
  x[1][1] = 0;
  x[1][2] = 0;
  x[1][3] = 0;
  x[1][4] = 1;
  x[2][0] = 1;
  x[2][1] = 0;
  x[2][2] = 0;
  x[2][3] = 1;
  x[2][4] = 1;
  x[3][0] = 1;
  x[3][1] = 0;
  x[3][2] = 1;
  x[3][3] = 0;
  x[3][4] = 1;
  x[4][0] = 0;
  x[4][1] = 1;
  x[4][2] = 1;
  x[4][3] = 1;
  x[4][4] = 0;


  for (int i = 0; i < SIZE; i++) {
    y[i] = -1;
  }
  
  y[0] = FIRST;
  
  int result = dfs(FIRST, 0);
  
  if (result == 1) {
    for (int i = 0; i < SIZE; i++) {
      cout << y[i] << " ";
    }
  }
  else {
    cout << "No possible cases...";
  }
}
