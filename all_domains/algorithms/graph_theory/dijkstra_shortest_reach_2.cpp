#include <iostream>

#include <stdexcept>

#include <limits>

#include <vector>
#include <queue>

constexpr int kINF{std::numeric_limits<int>::max()/2};

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
  void RunDijkstra(int start) const noexcept;

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

void Graph::InsertEdge(int x, int y, int w, bool directed, bool weighted) noexcept {

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
      std::cout << '(' << edges_[i][j].first << ", " << edges_[i][j].second <<
        ") ";
    }
    std::cout << std::endl;
  }
}

void Graph::RunPrim(int start) noexcept {

  std::vector<bool> intree(num_nodes() + 1, false); // Is node i on the tree?
  // Vertex distance from start:
  std::vector<int> distance(num_nodes() + 1, kINF);
  std::vector<int> parent(num_nodes() + 1, -1); // Parenting relation.

  int v{};  // Current node to process.
  int w{};  // Candidate for next node.
  int weight{}; // Weight for candidate edge.
  int dist{}; // Shortest current distance.
  int cost{}; // Total cost of the MST.

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

void Graph::RunDijkstra(int start) const noexcept {

  std::vector<bool> intree(num_nodes() + 1, false); // Is node i on the tree?
  // Vertex distance from start:
  std::vector<int> distance(num_nodes() + 1, kINF);
  std::vector<int> parent(num_nodes() + 1, -1); // Parenting relation.

  int v{};  // Current node to process.
  int w{};  // Candidate for next node.
  int weight{}; // Weight for candidate edge.
  int dist{}; // Shortest current distance.

  v = start;
  distance[v] = 0;
  while (intree[v] == false) {
    intree[v] = true;

    for (int i = 0; i < degree_[v]; i++) {
      w = edges_[v][i].first;
      weight = edges_[v][i].second;
      if ((distance[v] + weight) < distance[w]) {
        distance[w] = distance[v] + weight;
        parent[w] = v;
      }
    }

    v = 1;
    dist = kINF;
    // For each node in the graph...
    for (int i = 1; i <= num_nodes(); i++) {
      if ((intree[i] == false) && (distance[i] < dist)) {
        dist = distance[i];
        v = i;
      }
    }
  }

  for (int ii = 1; ii <= num_nodes(); ++ii) {
    if (distance[ii] != 0) {
      std::cout << distance[ii] << ' ';
    }
  }
  std::cout << std::endl;
}

void ReadGraph(Graph &gg, bool directed, bool weighted) {

  int num_nodes{};  // Number of nodes.
  int num_edges{};  // Number of edges.

  std::cin >> num_nodes >> num_edges;

  gg.set_num_nodes(num_nodes);

  for (int i = 1; i <= num_edges; i++) {
    int v1{}; // Current first node.
    int v2{}; // Current second node.
    int weight{}; // Current weight for (v1,v2) edge.
    if (weighted) {
      std::cin >> v1 >> v2 >> weight;
    } else {
      std::cin >> v1 >> v2;
    }
    gg.InsertEdge(v1, v2, weight, directed, weighted);
  }
}

class Edges {
public:
  Edges();
  Edges(int end_node);
  void InsertWeight(int weight) noexcept;
  int ReturnSmallestWeight() noexcept;
private:
  std::priority_queue<int> weights_;
  int end_node_;
};

Edges::Edges(): weights_(), end_node_() {}

Edges::Edges(int end_node): weights_(), end_node_(end_node) {}

void Edges::InsertWeight(int weight) noexcept {

  weights_.push(weight);
}

int Edges::ReturnSmallestWeight() noexcept {

  return weights_.top();
}

class Multigraph {
public:
private:
  std::vector<std::vector<Edges>> adjacency_matrix_;
};

int main () {

  int tt{}; // Number of test cases.

  std::cin >> tt;

  for (int cc = 1; cc <= tt; cc++) {
    Graph gg; // Graph.
    ReadGraph(gg, false, true);
    int start{};
    std::cin >> start;
    gg.RunDijkstra(start);
  }
}
