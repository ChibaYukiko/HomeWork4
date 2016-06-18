#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <typeinfo>
#include <list>

using namespace std;

//set <string> s;

map < string, int > vertex; // < vertex, score >
map < string, std::list<string> > node; // A -> B : < A,B > C -> A, C -> B : <C,[A,B]>
 
int main(){

  std::ifstream ifs("small_data.txt"); // file open
  char str[256];
  int ver_num = 0, node_num = 0;
  
  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  ifs.getline(str, 256 - 1); // vertex count
  int pos1 = 0;
  while(str[pos1] != '\0'){
  ver_num = ver_num * 10 + (int)(str[pos1] - '0');
  pos1++;
  }

  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    ifs.getline(str, 256 - 1);
    vertex.insert(pair<string, int>(str, 100));
    std::cout << str << ":" << vertex[str] << std::endl;
  }

  ifs.getline(str, 256 - 1); //node count
  int pos2 = 0;
  while(str[pos2] != '\0'){
  node_num = node_num * 10 + (int)(str[pos2] - '0');
  pos2++;
  }
  
  for(int j = 0; j < node_num; j++){
    ifs.getline(str, 256 - 1);
    string vertex, node;
    int pos2 = 0;
    /*while(str[pos2] != ' '){
      vertex = vertex + str[pos2];
      pos2++;
    }
    pos2++;
    while(str[pos2] != '\0'){
      vertex = vertex + str[pos2];
      pos2++;
    }
    node.insert(pair<string,string>(vertex, node));*/
    std::cout << str << std::endl;
  }


 
  //fclose(ifs);
  return 0;
}
