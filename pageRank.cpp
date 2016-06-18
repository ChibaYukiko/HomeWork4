#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <typeinfo>
#include <list>
#include <vector>

using namespace std;


class Vertex {
public:
  std::string name;  // このVertex
  double score;  // 点数
  std::vector<Vertex> neighbors;  // 矢印の先の隣接Vertexたち
  double kari_score;  // もっと必要な情報があればここに入れる
};

 
int main(){

  string str;
  int ver_num = 0, node_num = 0;
  Vertex vertex[20];

  std::ifstream ifs("small_data.txt"); // file open
  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  getline(ifs, str); // vertex count
  ver_num = atoi(str.c_str());
  std::cout << ver_num << std::endl;


  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex[i].name = str;
    vertex[i].score = 100.0;
    vertex[i].kari_score = 0;
    //std::cout << vertex[i].name << ":" << vertex[i].score << std::endl;    
  }

  getline(ifs, str); //node count
  node_num = atoi(str.c_str());

  for(int j = 0; j < node_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;
    //std::cout << vertex1 << std::endl;

    getline(ifs,str);
    vertex2 = str;
    //std::cout << vertex2 << std::endl;


    int ver = 0, edge = 0 ;
    while( ver < ver_num ){
      if(vertex[ver].name == vertex1){
	break;
      }else{
	ver++;
      }
    }

    while( edge < ver_num ){
      if(vertex[edge].name == vertex2){
	break;
      }else{
	edge++;
      }
    }
    
    vertex[ver].neighbors.push_back(vertex[edge]);

    //std::cout << vertex[ver].name << "->" << vertex[ver].neighbors << std::endl;

   
   }

 
  //fclose(ifs);
  return 0;
}
