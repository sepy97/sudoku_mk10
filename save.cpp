#include <iostream>
#include <fstream>
#include <vector>
#include <iterator> // заголовочный файл итераторов
using namespace std;
 
int main(){
  int s = 0, i, j;
  ofstream fout;
  fout.open("sudokuTemplate.txt");
  vector<int> array1[9][9];
  for (i = 0; i < 9; i++) 
    for(j = 0; j < 9; j++)
	array1[i][j].insert(array1[i][j].end(), 1);
// сама часть копирования идет отсюда
  for (i = 0; i < 9; i++) 
    for(j = 0; j < 9; j++)
	s = s + array1[i][j][0];

  fout << s*9 << "\n" << 99 <<"\n" << 81 << "\n";

  for (i = 0; i < 9; i++){ 
    for(j = 0; j < 9; j++)
     copy( array1[i][j].begin(),
              array1[i][j].end(),
              ostream_iterator<int>(fout," ")
     );

    fout <<"\n";
  }
 int level = 15;
 fout << 15 << "\n";
  for(i = 0; i < 9; i ++)
    fout << i << "\n";
  return 0;
}
