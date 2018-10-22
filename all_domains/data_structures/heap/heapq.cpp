#include <iostream>
#include <vector>
#include <unordered_multimap>
#include <algorithm>

enum class Query {NONE = 0, INSERT, REMOVE, TOP};

template <typename TT>
class Heap {
  public:
    Heap() {};
    ~Heap() {};
    void Insert(TT element) {
      std::cout << "Inserting " << element << std::endl;
      values_.push_back(element);
      int final_idx = Swim(values_.size() - 1);
      indexes_.insert({element, final_idx});
    }
    void Remove(TT element) {
      std::cout << "Removing " << element << std::endl;
      int posToDelete = indexes_.at(element);
      last--;
      Swap(posToDelete, last);
      Sink(posToDelete, last);
      Swim(posToDelete);
    }
    TT Top() const {
      return values_.back();
    }
  private:
    void Swap(int from, int to) {
      int temp = values_[from];
      values_[from] = values_[to];
      values_[to] = temp;
    }
    int Swim(int pos) {
      int parent = pos/2;
      while (parent > 0 && values_[pos] < values_[parent]) {
        Swap(parent, pos);
        pos = parent;
        parent = pos/2;
      }
      return pos;
    }
    void Sink(int pos) {
      int left = pos*2;
      int right = pos*2+1;
      int posToSwap = pos;
      if (left < last && values_[left] < values_[posToSwap]) {
        posToSwap = left;
      }
      if (right < last && values_[right] < values_[posToSwap]) {
        posToSwap = right;
      }
      if (pos == posToSwap) {
        return;
      }
      swap(values_, pos, posToSwap);
      sink(values_, posToSwap, last);
    }
    std::vector<TT> values_;
    std::unordered_multimap<TT, int> indexes_{};
};

int main() {
  int numQueries{};  // Number of queries.

  std::cin >> numQueries;

  Heap<int> theHeap;  // Actual heap to update.

  for (auto query = 1; query <= numQueries; ++query) {
    int typeQuery{};  // Type of query.

    std::cin >> typeQuery;
    switch (typeQuery) {
      case static_cast<int>(Query::INSERT): {
        int element{};  // Element to insert.

        std::cin >> element;

        theHeap.Insert(element);
        break;
      }
      case static_cast<int>(Query::REMOVE): {
        int element{};  // Element to remove.

        std::cin >> element;
        theHeap.Remove(element);
        break;
      }
      case static_cast<int>(Query::TOP): {
        std::cout << theHeap.Top() << std::endl;
        break;
      }
      default: {
        std::cerr << "Error: Incorrect query type: " << typeQuery << std::endl;
        break;
      }
    }
  }
}
