#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <typeinfo>
#include <list>

using namespace std;

//set <string> s;

map < string, int > vertex; // < vertex, score >
map < string, list<string> > node; // A -> B : < A,B > C -> A, C -> B : <C,[A,B]>
 
int main(){

  std::ifstream ifs("small_data.txt"); // file open
  string str;
  int ver_num = 0, node_num = 0;
  
  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  getline(ifs, str); // vertex count
  ver_num = atoi(str.c_str());

  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex.insert(pair<string, int>(str, 100));
    std::cout << str << ":" << vertex[str] << std::endl;
  }

  getline(ifs, str); //node count
  node_num = atoi(str.c_str());

  for(int j = 0; j < node_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;
    std::cout << vertex1 << std::endl;

    getline(ifs,str);
    vertex2 = str;
    std::cout << vertex2 << std::endl;

    if(node.find(vertex1) == node.end()){ // key != vertex1
      
    }else{ //vertex1 exist
      
    }
 
  }


 
  //fclose(ifs);
  return 0;
}
