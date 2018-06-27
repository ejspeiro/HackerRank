// Copyright 2018 Eduardo Sanchez
#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>
#include <queue>
#include <algorithm>

constexpr int kINF{std::numeric_limits<int>::max()};

typedef std::pair<int, int> Edge_t;

enum class Direction {UNDIRECTED, DIRECTED};

class StaticGraph {
 public:
  StaticGraph();
  StaticGraph(const StaticGraph &) = default;
  StaticGraph(StaticGraph &&) = default;
  explicit StaticGraph(int num_nodes,
                       int num_edges,
                       Direction dir = Direction::UNDIRECTED,
                       bool weighted = true);
  int num_nodes() const noexcept;
  int num_edges() const noexcept;
  void InsertEdge(int v1, int v2, int ww, bool directed = false);
  int GetEdgeWeight(int v1, int v2) const;
  void Print() const noexcept;

 private:
  std::vector<std::vector<Edge_t>> edges_;
  std::vector<int> degree_;
  int num_nodes_;
  int num_edges_;
  Direction direction_;
  bool is_weighted_;
};

StaticGraph::StaticGraph():
  edges_(),
  degree_(),
  num_nodes_(),
  num_edges_(),
  direction_(Direction::UNDIRECTED),
  is_weighted_(true) {}

StaticGraph::StaticGraph(int num_nodes,
                         int num_edges,
                         Direction dir,
                         bool weighted):
  edges_(num_nodes + 1),
  degree_(num_nodes + 1),
  num_nodes_(num_nodes),
  num_edges_(num_edges),
  direction_(dir),
  is_weighted_(weighted) {}

int StaticGraph::num_nodes() const noexcept {
  return num_nodes_;
}

int StaticGraph::num_edges() const noexcept {
  return num_edges_;
}

void StaticGraph::InsertEdge(int v1, int v2, int weight, bool directed) {
  if (v1 < 0 || v2 < 0) {
    throw std::invalid_argument("Vertices must be greater or equal to 0.");
  }
  if (v1 > edges_.size() || v2 > edges_.size()) {
    throw std::invalid_argument("No capacity to address given vertices.");
  }

  Edge_t edge;  // Edge to insert.

  edge.first = v2;
  if (is_weighted_) {
    edge.second = weight;
  } else {
    edge.second = 0;
  }
  try {
    edges_.at(v1).push_back(edge);
  } catch (const std::out_of_range &our_e) {
    std::cerr << v1 << " at edges_ with size " << edges_.size() << std::endl;
    std::cerr << our_e.what() << std::endl;
    return;
  }
  try {
    degree_.at(v1)++;
  } catch (const std::out_of_range &our_e) {
    std::cerr << v1 << " at degree_ with size " << degree_.size() << std::endl;
    std::cerr << our_e.what() << std::endl;
    return;
  }
  if (!directed) {
    InsertEdge(v2, v1, weight, true);
  }
}

int StaticGraph::GetEdgeWeight(int v1, int v2) const {
  if (v1 < 0 || v2 < 0) {
    throw std::invalid_argument("Vertices must be greater or equal to 0.");
  }
  if (v1 > edges_.size()) {
    throw std::invalid_argument("Vertice must be in range.");
  }

  for (auto rr : edges_[v1]) {
    if (rr.first == v2) {
      return rr.second;
    }
  }
  return -1;
}

void StaticGraph::Print() const noexcept {
  if (num_nodes() > 0) {
    for (int v1 = 1; v1 <= num_nodes(); ++v1) {
      std::cout << v1 << ": ";
      for (int v2 = 0; v2 < degree_.at(v1); ++v2) {
        std::cout << '(' << v1 << ", " << edges_[v1][v2].first << "; "
          << edges_[v1][v2].second << ") ";
      }
      std::cout << std::endl;
    }
  } else {
    std::cout << "Empty" << std::endl;
  }
}

class DynamicGraph {
 public:
  DynamicGraph();
  int num_nodes() const noexcept;
  void set_num_nodes(int num_nodes);
  int num_edges() const noexcept;
  void InsertEdge(int v1, int v2, int ww, bool directed = false);
  int GetEdgeWeight(int v1, int v2) const;
  void Print() const noexcept;
  void AdjustCC() noexcept;
  int GetPrimStartNode() const noexcept;
  void RunPrim(int start);
  int cost_mst() const noexcept;

 private:
  std::vector<std::vector<Edge_t>> edges_;
  std::vector<int> degree_;
  int num_nodes_;
  int num_edges_;
  Direction direction_;
  bool is_weighted_;
  int cost_mst_;
};

DynamicGraph::DynamicGraph():
  edges_(),
  degree_(),
  num_nodes_(),
  num_edges_(),
  direction_(Direction::UNDIRECTED),
  is_weighted_(true),
  cost_mst_(-1) {}

int DynamicGraph::num_nodes() const noexcept {
  return num_nodes_;
}

void DynamicGraph::set_num_nodes(int num_nodes) {
  if (num_nodes <= 0) {
    throw std::invalid_argument("Number of nodes must be greater than 0.");
  }
  num_nodes_ = num_nodes;
}

int DynamicGraph::num_edges() const noexcept {
  return num_edges_;
}

int DynamicGraph::cost_mst() const noexcept {
  return cost_mst_;
}

void DynamicGraph::InsertEdge(int v1, int v2, int weight, bool directed) {
  if (v1 < 0 || v2 < 0) {
    throw std::invalid_argument("Vertices must be greater or equal to 0.");
  }

  Edge_t edge;  // Edge to insert.

  edge.first = v2;
  if (is_weighted_) {
    edge.second = weight;
  } else {
    edge.second = 0;
  }
  if (v1 >= edges_.size()) {
    edges_.resize(v1 + 1);
  }
  try {
    edges_.at(v1).push_back(edge);
  } catch (const std::out_of_range &our_e) {
    std::cerr << v1 << " at edges_ with size " << edges_.size() << std::endl;
    std::cerr << our_e.what() << std::endl;
    return;
  }
  num_nodes_ = std::count_if(edges_.begin(), edges_.end(), [] (auto &row) {
    return row.size() > 0;
  });
  if (v1 >= degree_.size()) {
    degree_.resize(v1 + 1);
  }
  try {
    degree_.at(v1)++;
  } catch (const std::out_of_range &our_e) {
    std::cerr << v1 << " at degree_ with size " << degree_.size() << std::endl;
    std::cerr << our_e.what() << std::endl;
    return;
  }
  if (!directed) {
    InsertEdge(v2, v1, weight, true);
  }
  if (directed) {
    num_edges_++;
  }
}

int DynamicGraph::GetEdgeWeight(int v1, int v2) const {
  if (v1 < 0 || v2 < 0) {
    throw std::invalid_argument("Vertices must be greater or equal to 0.");
  }
  if (v1 > edges_.size()) {
    throw std::invalid_argument("Vertice must be in range.");
  }
  for (auto rr : edges_[v1]) {
    if (rr.first == v2) {
      return rr.second;
    }
  }
  return -1;
}

void DynamicGraph::Print() const noexcept {
  if (num_nodes() > 0) {
    for (int v1 = 1; v1 < edges_.size(); ++v1) {
      if (edges_.at(v1).size() > 0) {
        std::cout << v1 << ": ";
        for (int v2 = 0; v2 < degree_.at(v1); ++v2) {
          std::cout << '(' << v1 << ", " << edges_[v1][v2].first << "; "
            << edges_[v1][v2].second << ") ";
        }
        std::cout << std::endl;
      }
    }
  } else {
    std::cout << "Empty" << std::endl;
  }
}

void DynamicGraph::AdjustCC() noexcept {
  if (edges_.size() > 1 && edges_.at(1).size() == 0) {
    std::vector<std::vector<Edge_t>> adjusted_edges(1);

    int min_id{1};  // Minimum asummed value for a node ID.
    for (size_t ii = 1; ii < edges_.size(); ++ii) {
      if (edges_.at(ii).size() > 0) {
        min_id = ii;
        break;
      }
    }
    for (size_t ii = 1; ii < edges_.size(); ++ii) {
      if (edges_.at(ii).size() > 0) {
        for (auto &ee : edges_.at(ii)) {
          ee.first = ee.first - min_id + 1;
        }
        adjusted_edges.push_back(edges_.at(ii));
      }
    }
    edges_ = adjusted_edges;

    std::vector<int> adjusted_degree(1);  // New array for degrees.
    for (int ii = min_id; ii < degree_.size(); ++ii) {
      adjusted_degree.push_back(degree_.at(ii));
    }
    degree_ = adjusted_degree;
  }
}

int DynamicGraph::GetPrimStartNode() const noexcept {
  int start_node{1};  // Start node.
  while (start_node < edges_.size() && edges_.at(start_node).size() == 0) {
    start_node++;
  }
  if (start_node == edges_.size()) {
    return -1;
  }
  return start_node;
}

void DynamicGraph::RunPrim(int start) {
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

typedef std::vector<DynamicGraph> VectorDGraph_t;

template <class ProcessNode, class ProcessEdge, class ValidateEdge>
class BFSearcher {
 public:
  void TraverseBFS(const StaticGraph &gg, int start_node) noexcept;

  BFSearcher();
  BFSearcher(const BFSearcher &) = delete;
  explicit BFSearcher(int num_nodes);
  std::vector<DynamicGraph> ConnectedComponentsOf(const StaticGraph &gg);

 private:
  ProcessNode process_node_;
  ProcessEdge process_edge_;
  ValidateEdge valid_edge_;
  std::vector<DynamicGraph> connected_components_;
  std::vector<bool> processed_;
  std::vector<bool> discovered_;
  std::vector<int> parent_;
};

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
void BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::TraverseBFS(
  const StaticGraph &gg,
  int start_node) noexcept {
  std::queue<int> node_queue;   // Queue of nodes to process.

  node_queue.push(start_node);
  int num_discovered{};  // Number of nodes discovered.
  discovered_[start_node] = true;
  num_discovered++;
  while (!node_queue.empty()) {
    int node = node_queue.front();
    node_queue.pop();
    process_node_(node);
    processed_[node] = true;
    for (int ii = 1; ii <= gg.num_nodes(); ++ii) {
      int current_weight = gg.GetEdgeWeight(node, ii);
      if (current_weight != -1) {
        if (!discovered_[ii]) {
          node_queue.push(ii);
          discovered_[ii] = true;
          num_discovered++;
          parent_[ii] = node;
        }
        if (!processed_[ii]) {
          process_edge_(std::make_pair(node, ii), current_weight, connected_components_);
        }
      }
    }
  }
  // Assign infinite distance to those nodes that were not reached in the BFS.
  for (int ii = 1; ii <= parent_.size(); ++ii) {
    if (ii != start_node && parent_[ii] == -1) {
      parent_[ii] = kINF;
    }
  }
  if (num_discovered == 1) {
    // This connected component has only one node and no edges.
    int current_num_nodes = connected_components_.at(connected_components_.size() - 1).num_nodes();
    connected_components_.at(connected_components_.size() - 1).set_num_nodes(current_num_nodes + 1);
  }
}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::BFSearcher():
  connected_components_(),
  processed_(),
  discovered_(),
  parent_() {}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::BFSearcher(int num_nodes):
  connected_components_(),
  processed_(num_nodes + 1, false),
  discovered_(num_nodes + 1, false),
  parent_(num_nodes + 1, -1) {}

template <typename ProcessNode, typename ProcessEdge, typename ValidateEdge>
std::vector<DynamicGraph>
BFSearcher<ProcessNode, ProcessEdge, ValidateEdge>::ConnectedComponentsOf(const StaticGraph &gg) {
  if (processed_.size() == 0 || discovered_.size() == 0 || parent_.size() == 0) {
    processed_.resize(gg.num_nodes());
    discovered_.resize(gg.num_nodes());
    parent_.resize(gg.num_nodes());
  }
  for (int sv = 1; sv <= gg.num_nodes(); ++sv) {
    if (!discovered_.at(sv)) {
      DynamicGraph cc;
      connected_components_.push_back(cc);
      TraverseBFS(gg, sv);
    }
  }

  for (auto &gg : connected_components_) {
    gg.AdjustCC();
  }

  return connected_components_;
}

class NodeProcessor {
 public:
  void operator() (int node) const noexcept {
    // std::cout << node << ' ' << std::endl;
  }
};

class DynamicNodeProcessor {
 public:
  void operator() (int node, std::vector<DynamicGraph> &ccs) const noexcept {
    // std::cout << node << ' ' << std::endl;
    int current_num_nodes = ccs.at(ccs.size() - 1).num_nodes();
    ccs.at(ccs.size() - 1).set_num_nodes(current_num_nodes + 1);
  }
};

class EdgeProcessor {
 public:
  void operator() (Edge_t edge,
                   int ww,
                   std::vector<StaticGraph> &ccs) const noexcept {
    ccs.at(ccs.size() - 1).InsertEdge(edge.first, edge.second, ww);
  }
};

class DynamicEdgeProcessor {
 public:
  void operator() (Edge_t edge,
                   int ww,
                   std::vector<DynamicGraph> &ccs) const noexcept {
    ccs.at(ccs.size() - 1).InsertEdge(edge.first, edge.second, ww);
  }
};

class EdgeValidator {
 public:
  bool operator() (Edge_t edge) const noexcept {
    // Exclude the possibility of loops.
    return !(edge.first == edge.second);
  }
};

typedef BFSearcher<NodeProcessor,
                   DynamicEdgeProcessor,
                   EdgeValidator> BFSearcher_t;

int main() {
  int qq{};  // Number of queries.

  std::cin >> qq;
  int num_nodes{};  // Number of nodes.
  int num_edges{};  // Number of edges.
  int cost_lib{};  // Cost of building a library.
  int cost_road{};  // Cost of building a road.

  for (int ii = 1; ii <= qq; ++ii) {
    std::cin >> num_nodes >> num_edges >> cost_lib >> cost_road;

    StaticGraph the_graph(num_nodes, num_edges);  // StaticGraph to process.

    // Read all edges for this graph.
    for (int ee = 1; ee <= num_edges; ++ee) {
      int v1{};  // First component vertex of the edge to read.
      int v2{};  // Second component vertex of the edge to read.

      std::cin >> v1 >> v2;
      the_graph.InsertEdge(v1, v2, cost_road);
    }

    int cost_lib_all_cities{num_nodes*cost_lib};  // Cost library in all cities.

    // Initialize depth-first search for current graph.
    BFSearcher_t bfsearcher(the_graph.num_nodes());

    VectorDGraph_t con_comps = bfsearcher.ConnectedComponentsOf(the_graph);
    int num_con_comps{static_cast<int>(con_comps.size())};  // Num con comps.
    int cost_req_libs{num_con_comps*cost_lib};  // Cost of required libraries.
    int min_cost_road{};  // Minimum cost for roads.
    for (auto &gg : con_comps) {
      int start_node = gg.GetPrimStartNode();
      gg.RunPrim(start_node);
      min_cost_road += gg.cost_mst();
    }
    int total_min_cost{cost_req_libs + min_cost_road};  // Total min cost.
    if (total_min_cost < cost_lib_all_cities) {
      std::cout << total_min_cost << std::endl;
    } else {
      std::cout << cost_lib_all_cities << std::endl;
    }
  }
}
