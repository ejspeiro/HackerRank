// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <iomanip>
#include <utility>
#include <limits>
#include <vector>
#include <queue>

auto kINFINITY = static_cast<int>(std::numeric_limits<double>::infinity());

typedef std::pair<int, int> Edge;

enum class Direction {UNDIRECTED, DIRECTED};

class DenseGraphOfInt {
 public:
  DenseGraphOfInt();
  explicit DenseGraphOfInt(int num_nodes,
                           int num_edges,
                           Direction dir = Direction::UNDIRECTED);
  void InsertEdge(Edge ee, int weight = 1);
  int GetEdgeWeight(int v1, int v2) const noexcept;
  int NumNodes() const noexcept;
  int NumEdges() const noexcept;
  int DegreeOfNode(int node) const noexcept;

 private:
  Direction direction_;
  int default_weight_;
  int num_nodes_;
  int max_num_edges_;
  int num_edges_;
  std::vector<int> degree_;
  std::vector<std::vector<int>> dense_adj_matrix_;
};

DenseGraphOfInt::DenseGraphOfInt():
  direction_(Direction::UNDIRECTED),
  default_weight_(-1),
  num_nodes_(),
  max_num_edges_(),
  degree_(),
  dense_adj_matrix_() {}

DenseGraphOfInt::DenseGraphOfInt(int num_nodes, int num_edges, Direction dir):
  direction_(dir),
  default_weight_(-1),
  num_nodes_(num_nodes),
  max_num_edges_(num_edges),
  num_edges_(),
  degree_(num_nodes),
  dense_adj_matrix_(num_nodes) {
  for (int ii = 0; ii < num_nodes; ++ii) {
    dense_adj_matrix_.at(ii).resize(num_nodes, -1);
  }
}

void DenseGraphOfInt::InsertEdge(Edge ee, int weight) {
  int v1 = ee.first - 1;
  int v2 = ee.second - 1;

  if (dense_adj_matrix_[v1][v2] == default_weight_) {
    dense_adj_matrix_[v1][v2] = weight;
    if (direction_ == Direction::UNDIRECTED) {
      if (dense_adj_matrix_[v2][v1] == default_weight_) {
        dense_adj_matrix_[v2][v1] = weight;
        degree_[v1]++;
      }
    }
    degree_[v2]++;
    num_edges_++;
  }
}

int DenseGraphOfInt::GetEdgeWeight(int v1, int v2) const noexcept {
  if (v1 >= 0 && v2 >= 0 && v1 < NumNodes() && v2 < NumNodes()) {
    return dense_adj_matrix_[v1][v2];
  } else {
    return -1;
  }
}

int DenseGraphOfInt::NumNodes() const noexcept {
  return num_nodes_;
}

int DenseGraphOfInt::NumEdges() const noexcept {
  return num_edges_;
}

int DenseGraphOfInt::DegreeOfNode(int node) const noexcept {
  return degree_[node];
}

template <typename ProcessNode,
          typename ProcessEdge,
          typename ValidateEdge>
class BFSearcher {
 public:
  void operator() (const DenseGraphOfInt &gg, int start_node) noexcept;

  BFSearcher();
  explicit BFSearcher(int num_nodes);
  int GetShortestDistance(int start_node, int end_node) const noexcept;

 private:
  void AuxGetShortestDistance(int start_node,
                              int end_node,
                              int &distance) const noexcept;

  ProcessNode process_node_;
  ProcessEdge process_edge_;
  ValidateEdge valid_edge_;
  std::vector<bool> processed_;
  std::vector<bool> discovered_;
  std::vector<int> parent_;
};

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
void BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::operator() (
  const DenseGraphOfInt &gg,
  int start_node) noexcept {
  start_node--;

  std::queue<int> node_queue;   // Queue of nodes to process.

  node_queue.push(start_node);
  discovered_[start_node] = true;
  while (!node_queue.empty()) {
    int node = node_queue.front();
    node_queue.pop();
    process_node_(node);
    processed_[node] = true;
    for (int ii = 0; ii < gg.NumNodes(); ++ii) {
      if (gg.GetEdgeWeight(node, ii) != -1) {
        if (!discovered_[ii]) {
          node_queue.push(ii);
          discovered_[ii] = true;
          parent_[ii] = node;
        }
        if (!processed_[ii]) {
          process_edge_(std::make_pair(node, ii));
        }
      }
    }
  }
  // Assign infinite distance to those nodes that were not reached in the BFS.
  for (int ii = 0; ii < parent_.size(); ++ii) {
    if (ii != start_node && parent_[ii] == -1) {
      parent_[ii] = kINFINITY;
    }
  }
}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::BFSearcher():
  processed_(),
  discovered_(),
  parent_() {}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::BFSearcher(int num_nodes):
  processed_(num_nodes, false),
  discovered_(num_nodes, false),
  parent_(num_nodes, -1) {}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
void BFSearcher<ProcessNode,
                ProcessEdge,
                ValidateEdge>::AuxGetShortestDistance(int start_node,
                                                      int end_node,
                                                      int &distance) const
                                                                     noexcept {
  if (start_node == end_node || end_node == -1) {
    distance = 0;
  } else if (end_node == kINFINITY) {
    distance = kINFINITY;
  } else {
    AuxGetShortestDistance(start_node, parent_[end_node], distance);
    if (distance != kINFINITY) {
      distance += 6;
    }
  }
}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
int BFSearcher<ProcessNode,
               ProcessEdge,
               ValidateEdge>::GetShortestDistance(int start_node,
                                                  int end_node) const noexcept {
  int distance{};

  start_node--;
  end_node--;
  if (start_node != end_node) {
    AuxGetShortestDistance(start_node, end_node, distance);
    if (distance == kINFINITY) {
      distance = -1;
    }
  }
  return distance;
}

class NodeProcessor {
 public:
  void operator() (int node) const {
    // std::cout << node << ' ' << std::endl;
  }
};

class EdgeProcessor {
 public:
  void operator() (Edge edge) const {
    // std::cout << edge.first << ", " << edge.second << std::endl;
  }
};

class EdgeValidator {
 public:
  bool operator() (Edge edge) const {
    // Exclude the possibility of loops.
    return !(edge.first == edge.second);
  }
};

int main() {
  const int omnipresent_weight{6};  // Every edge will have a weight of 6.
  int qq{};  // Number of queries.

  std::cin >> qq;

  int num_nodes{};  // Number of nodes.
  int num_edges{};  // Number of edges.
  int start_node{};  // Index of the starting node for the BFS.

  // For each query...
  for (int ii = 1; ii <= qq; ++ii) {
    std::cin >> num_nodes >> num_edges;
    DenseGraphOfInt the_graph(num_nodes, num_edges);  // Graph to process.

    // Read all edges for this graph.
    for (int ee = 1; ee <= num_edges; ++ee) {
      int v1{};   // First component vertex of the edge to read.
      int v2{};   // Second component vertex of the edge to read.

      std::cin >> v1 >> v2;
      the_graph.InsertEdge(std::make_pair(v1, v2), omnipresent_weight);
    }
    std::cin >> start_node;
    // Initialize breadth-first search for current graph.
    BFSearcher<NodeProcessor,
               EdgeProcessor,
               EdgeValidator> bfsearcher(the_graph.NumNodes());
    bfsearcher(the_graph, start_node);
    for (int vv = 1; vv <= num_nodes; ++vv) {
      if (vv != start_node) {
        std::cout << bfsearcher.GetShortestDistance(start_node, vv) << ' ';
      }
    }
    std::cout << std::endl;
  }
}
