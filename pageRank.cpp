#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

#define SIZE 1000 // 頂点の数


class Vertex {
public:
  string name;  // このVertex
  double score;  // 点数
  vector<Vertex*> neighbors;  // 矢印の先の隣接Vertexたち
  double given_score;  // 与えられた点数を代入する
};

std::ifstream ifs("medium_data.txt"); // file open

Vertex vertex[SIZE];

void shokika(int ver_num){ // 初期化 ver_num は頂点の数

  string str;
  
  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex[i].name = str;
    vertex[i].score = 100.0;
    vertex[i].given_score = 0.0;
  }
  
}

int search_vertex(string str,int ver_num){ //頂点を探す 引数は(頂点の名前と, 頂点の数)->そのindexを返す

  int num = 0;
  
  while(num < ver_num){
    if(vertex[num].name == str){
      break;
    }else{
      num++;
    }
  }

  return num;
  
}


void insert_neighbor(int ver_num, int edge_num){ //　neighbors の代入 引数は(頂点の数, 矢印の数)

  string str;

   for(int j = 0; j < edge_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;

    getline(ifs,str);
    vertex2 = str;

    int ver = 0, edge = 0 ; // if A -> C then ver: A's index edge: C's index

    ver = search_vertex(vertex1, ver_num);

    edge = search_vertex(vertex2, ver_num);
    
    vertex[ver].neighbors.insert(vertex[ver].neighbors.begin(), &vertex[edge]);

   }

}

void pageRank(int ver_num){ // 点数配分の計算

  for(int i = 0; i < ver_num ; i++){

    int n = vertex[i].neighbors.size(); // お隣の頂点の数
    
    if(n != 0){ //お隣さんがいたら点数配分する
      double div_score = vertex[i].score / n; //自分の今の持ち点をつながっている矢印の数で割った点数

      for(int j = 0; j < n ; j++){
	vertex[i].neighbors[j]->given_score += div_score; // お隣さんに点数を与える
      }
    }else{
      vertex[i].score = 0;
    }
  }

  for(int k = 0; k < ver_num; k++){ //与えられた点数を自分の点数として代入してgiven_scoreはリセット
    vertex[k].score = vertex[k].given_score;
    vertex[k].given_score = 0.0;
    std::cout << vertex[k].name << " : " << vertex[k].score << std::endl;
  }
  
}

 
int main(){

  string str;
  int ver_num = 0, edge_num = 0;


  if (ifs.fail()){ // file open が失敗
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  getline(ifs, str); // vertex count
  ver_num = atoi(str.c_str());

  shokika(ver_num); //初期化


  getline(ifs, str); //node count
  edge_num = atoi(str.c_str());

  insert_neighbor(ver_num, edge_num); //お隣さんを追加


  for(int i = 0; i < ver_num+; i++){ //pageRank を実行
    std::cout << "for文 " << i+1 << " 回目"<< std::endl;
    pageRank(ver_num);
   
  }

  double max_score = vertex[0].score; //最高点
  string max_name = vertex[0].name; //最高点のvertexの名前
  int total_score = vertex[0].score; //　全ての点の合計点

  for(int j = 1; j < ver_num ; j++){ // 最高点を探す
    if(max_score < vertex[j].score){
      max_score = vertex[j].score;
      max_name = vertex[j].name;
    }
    total_score += vertex[j].score;
  }

  std::cout << "Max score is " << max_name << " : " << max_score << std::endl;
  cout << "Total score : " << total_score << endl;
  cout << "True value (Total score) : "<< 100.0*ver_num << endl;
  
  return 0;
}
