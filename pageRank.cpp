#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <typeinfo>

using namespace std;

//set <string> s;

map <string, int> vertex;

int main(){

  std::ifstream ifs("small_data.txt"); // file open
  char str[256];
  int ver_num = 0, node_num = 0;
  
  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  ifs.getline(str, 256 - 1);
  ver_num = (int)(str[0] - '0');

  for(int i = 0; i < ver_num; i++){
    ifs.getline(str, 256 - 1);
    vertex.insert(pair<string, int>(str, 100));
    std::cout << str << ":" << vertex[str] << std::endl;
  }

  ifs.getline(str, 256 - 1);
  int n = 0;
  while(str[n] != '\0'){
    //std::cout << "while loop" << std::endl;
  node_num = node_num * 10 + (int)(str[n] - '0');
  n++;
  }
  
  for(int j = 0; j < node_num; j++){
    ifs.getline(str, 256 - 1);
    std::cout << str << std::endl;
  }


 
  //fclose(ifs);
  return 0;
}
