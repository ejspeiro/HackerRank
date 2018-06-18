// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>

constexpr int kINF{std::numeric_limits<int>::max()};

typedef std::pair<int, int> Edge;

class Graph {
 public:
  Graph();
  void set_num_nodes(int in) noexcept;
  int num_nodes() const noexcept;
  int cost_mst() const noexcept;
  void InsertEdge(int x, int y, int w, bool directed, bool weighted) noexcept;
  void Print() const noexcept;
  void RunPrim(int start) noexcept;

 private:
  std::vector<std::vector<Edge>> edges_;
  std::vector<int> degree_;
  int num_nodes_;
  int num_edges_;
  int cost_mst_;
};

Graph::Graph():
  edges_(),
  degree_(),
  num_nodes_(),
  num_edges_(),
  cost_mst_(-1)  {}

void Graph::set_num_nodes(int in) noexcept {
  if (in >= 0) {
    num_nodes_ = in;
  }
  degree_.resize(num_nodes_);
  edges_.resize(num_nodes_ + 1);
}

int Graph::num_nodes() const noexcept {
  return num_nodes_;
}

int Graph::cost_mst() const noexcept {
  return cost_mst_;
}

void Graph::InsertEdge(int x, int y, int w, bool directed, bool weighted)
    noexcept {
  Edge e;

  e.first = y;
  e.second = w;
  edges_[x].push_back(e);
  degree_[x]++;
  if (directed == false) {
    InsertEdge(y, x, w, true, weighted);
  } else {
    num_edges_++;
  }
}

void Graph::Print() const noexcept {
  int i;
  int j;

  for (i = 1; i <= num_nodes_; i++) {
    std::cout << i << ": ";
    for (j = 0; j < degree_[i]; j++) {
      std::cout << '(' << edges_[i][j].first << ", "
        << edges_[i][j].second << ") ";
    }
    std::cout << std::endl;
  }
}

void Graph::RunPrim(int start) noexcept {
  std::vector<bool> intree(num_nodes() + 1, false);  // Is node i on the tree?
  // Vertex distance from start:
  std::vector<int> distance(num_nodes() + 1, kINF);
  std::vector<int> parent(num_nodes() + 1, -1);  // Parenting relation.

  int v{};  // Current node to process.
  int w{};  // Candidate for next node.
  int weight{};  // Weight for candidate edge.
  int dist{};  // Shortest current distance.
  int cost{};  // Total cost of the MST.

  v = start;
  distance[v] = 0;
  // While there is some node to insert in the tree...
  while (intree[v] == false) {
    intree[v] = true;
    // For every adjacent node to v...
    for (int i = 0; i < degree_[v]; i++) {
      // Query candidates to the tree.
      // Describe parenthood of candidates.
      w = edges_[v][i].first;
      weight = edges_[v][i].second;
      if ((intree[w] == false) && (weight < distance[w])) {
        distance[w] = weight;
        parent[w] = v;
      }
    }
    // Choose the next candidate to be inserted on the tree.
    // Assume node 1 will be the next best thing, but query every node.
    v = 1;
    dist = kINF;
    // For each node in the graph...
    for (int i = 1; i <= num_nodes(); i++) {
      // Choose the next best candidate to be added to the tree.
      if ((intree[i] == false) && (distance[i] < dist)) {
        dist = distance[i];
        cost += dist;
        v = i;
      }
    }
  }
  cost_mst_ = cost;
}

void ReadGraph(Graph &gg, bool directed, bool weighted) {
  int nn{};  // Number of nodes.
  int mm{};  // Number of edges.

  std::cin >> nn >> mm;
  gg.set_num_nodes(nn);
  for (int i = 1; i <= mm; i++) {
    int xx{};  // Current first node.
    int yy{};  // Current second node.
    int ww{};  // Current weight for (xx,yy) edge.
    if (weighted) {
      std::cin >> xx >> yy >> ww;
    } else {
      std::cin >> xx >> yy;
    }
    gg.InsertEdge(xx, yy, ww, directed, weighted);
  }
}

int main() {
  bool directed{false};
  bool weighted{true};
  Graph gg;

  ReadGraph(gg, directed, weighted);
  int start{};
  std::cin >> start;
  gg.RunPrim(start);
  std::cout << gg.cost_mst() << std::endl;
}
