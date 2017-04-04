#include <iostream>
#include <fstream>
#include <vector>
#include <iterator> // заголовочный файл итераторов
using namespace std;
 
int main(){
  int i, j;
  vector<int> array1[9][9];
  for (i = 0; i < 9; i++) 
    for(j = 0; j < 9; j++)
	  array1[i][j].insert(array1[i][j].end(), i*10+j);

// сама часть копирования идет отсюда
  ofstream fout("sudokuTemplate.txt", ios::binary);
  int a[94];
  a[0] = 0;
  
  for (i = 0; i < 9; i++) 
    for(j = 0; j < 9; j++)
	  a[0] = a[0] + array1[i][j][0];
	  
  a[0] = a[0] * 9;
  a[1] = 99;
  a[2] = 0; //81
  
  for (i = 0; i < 9; i++)
    for(j = 0; j < 9; j++)
      a[i*9+j+2] = array1[i][j][0];
      
  a[83] = 15;
  for(i = 0; i < 9; i ++)
    a[i+84] = i;
    
  fout.write ((char*)a,4*94); 
  fout.close();
   // копирование закончено
   
    // начать загрузку
  int p;
  ifstream fin ("sudokuTemplate.txt",ios::binary);
  fin.read((char*)&p,4);
  cout<<p<<endl; 
  fin.read((char*)&p,4);
  cout<<p<<endl;
  for (i = 0; i <9; i ++){  
    for(j = 0; j <9; j++){
      fin.read((char*)&p,4);
      cout<<p<<" ";
	}
  cout<<endl;
  };
  for (i = 0; i< 10; i++) {
    fin.read((char*)&p,4);
    cout<<p<<endl;
  }
// Загрузка завершена
  return 0;
}
