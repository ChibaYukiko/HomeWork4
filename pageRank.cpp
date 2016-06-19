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

std::ifstream ifs("small_data.txt"); // file open
Vertex vertex[20];

void shokika(int ver_num){

  string str;
  
  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex[i].name = str;
    vertex[i].score = 100.0;
    vertex[i].kari_score = 0;  
  }
  
}

int search_vertex(string str,int edge_num){

  int num = 0;
  
  while(num < edge_num){
    if(vertex[num].name == str){
      break;
    }else{
      num++;
    }
  }

  return num;
  
}


void insert_neighbor(int edge_num){

  string str;

   for(int j = 0; j < edge_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;
    //std::cout << vertex1 << std::endl;

    getline(ifs,str);
    vertex2 = str;
    //std::cout << vertex2 << std::endl;


    int ver = 0, edge = 0 ;

    ver = search_vertex(vertex1, edge_num);

    edge = search_vertex(vertex2, edge_num);
    
    vertex[ver].neighbors.push_back(vertex[edge]);

    std::cout << vertex[ver].name << "->" << vertex[ver].neighbors.back().name << std::endl;

   }

}
 
int main(){

  string str;
  int ver_num = 0, edge_num = 0;


  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  getline(ifs, str); // vertex count
  ver_num = atoi(str.c_str());
  std::cout << ver_num << std::endl;

  shokika(ver_num);


  getline(ifs, str); //node count
  edge_num = atoi(str.c_str());

  insert_neighbor(edge_num);


  // 点数の計算
  int score = vertex[j].score / vertex[j].neighbors.size();

  for(int i = 0; i < vertex[j].neighbors.size(); i++){
    vertex[j].neighbors[i].kari_score += score;
  }

  vertex[j].score = vertex[j].kari_score;
    

  
  
  //fclose(ifs);
  return 0;
}
