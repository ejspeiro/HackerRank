#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <deque>
#include <map>

bool kVerbose{true};

class HRMLTag {
  public:
    HRMLTag(): tag_(), attributes_() {}
    explicit HRMLTag(const HRMLTag &tag): tag_(tag.tag_), attributes_(tag.attributes_) {}
    std::string tag_;
    std::map<std::string, std::string> attributes_;
};

class DOMTreeNode {
  public:
    DOMTreeNode(const HRMLTag &tag): data_(tag), children_() {};
    explicit DOMTreeNode(const DOMTreeNode &node): data_(node.data_), children_(node.children_) {};
    HRMLTag data_;
    std::vector<DOMTreeNode *> children_;
};

class DOMTree {
public:
  DOMTree();
  void insertChildOf(const std::string &target, const HRMLTag &tag);
  void insertChildOfAux(DOMTreeNode *root, const std::string &target, const HRMLTag &tag);
  void preOrderTraverse();
  void preOrderTraverseAux(DOMTreeNode *root, int depth);
  void assembleDOMTree(const std::string &sourceCode);
  std::string getAttributeVal(const std::deque<std::string> &domQuery);
  std::string getAttributeValAux(DOMTreeNode *root, const std::deque<std::string> &domQuery);

  DOMTreeNode *root_;
};

DOMTree::DOMTree() {
  HRMLTag tag;
  root_ = new DOMTreeNode(tag);
}

void DOMTree::insertChildOf(const std::string &target, const HRMLTag &tag) {

  insertChildOfAux(root_, target, tag);
}

void DOMTree::insertChildOfAux(DOMTreeNode *root, const std::string &target, const HRMLTag &tag) {

  std::string thisNodeTag{};

  if (root->data_.tag_.empty()) {
    thisNodeTag = "root";
  } else {
    thisNodeTag = root->data_.tag_;
  }

  // Tree is not empty. Check if we have found the target node.
  if (kVerbose) std::cout << "Checking " << thisNodeTag << std::endl;
  if (root->data_.tag_ == target) {
    // We have found requested parent node. Insert tag as a child node.
    DOMTreeNode *tmp = new DOMTreeNode(tag);
    root->children_.push_back(tmp);
    if (kVerbose) std::cout << "Inserted " << tag.tag_ << " as child of " << thisNodeTag << std::endl;
  } else {
    if (kVerbose) std::cout << "Checking among children of " << thisNodeTag << std::endl;
    // We have NOT found requested parent node. Search among the children.
    for (int ii = 0; ii < root->children_.size(); ++ii) {
      DOMTreeNode *currentChildren = root->children_.at(ii);
      insertChildOfAux(currentChildren, target, tag);
    }
  }
}

void DOMTree::preOrderTraverseAux(DOMTreeNode *root, int depth) {

  for (int ii = 0; ii < depth; ++ii) {
    if (kVerbose) std::cout << "  ";
  }
  if (root->data_.tag_.empty()) {
    if (kVerbose) std::cout << "root" << ' ';
  } else {
    if (kVerbose) std::cout << root->data_.tag_ << ' ';
  }
  for (const auto &att: root->data_.attributes_) {
    if (kVerbose) std::cout << att.first << " = " << att.second << ' ';
  }
  if (kVerbose) std::cout << std::endl;
  for (int ii = 0; ii < root->children_.size(); ++ii) {
    preOrderTraverseAux(root->children_.at(ii), depth + 1);
  }
}

void DOMTree::preOrderTraverse() {

  int depth{};

  preOrderTraverseAux(root_, depth);
}

void DOMTree::assembleDOMTree(const std::string &sourceCode) {

  std::stack<std::string> recentlyInsertedTags{};

  // Traverse complete source code to create document tag hierarchy.
  for (int cc = 0; cc < sourceCode.length(); ++cc) {
    char traversingChar = sourceCode.at(cc);
    switch (traversingChar) {
      case '<': {
        // Beginning of tag. Check if opening or closing tag.
        HRMLTag tag;

        char tagFirstChar = sourceCode.at(cc + 1);
        if (tagFirstChar != '/') {
          // Opening tag.
          cc++;
          while (sourceCode.at(cc) != ' ' && sourceCode.at(cc) != '>') {
            tag.tag_.push_back(sourceCode.at(cc));
            cc++;
          }
          if (kVerbose) std::cout << "Open tag: " << tag.tag_ << std::endl;

          // Check if tag has attributes.
          std::map<std::string, std::string> tagAttributes;

          if (sourceCode.at(cc) == ' ') {
            // Tag has attributes. For all attributes you can find, extract each attribute.
            while (sourceCode.at(cc) != '>') {
              // Skip blank space before first attribute.
              cc++;
              // Extract the name of the attribute.
              std::string nextAttributeName = "";
              while (sourceCode.at(cc) != ' ') {
                nextAttributeName.push_back(sourceCode.at(cc));
                cc++;
              }
              // Extract the value of the attribute.
              std::string nextAttributeValue = "";
              // Skip three spaces for " = ".
              cc += 3;
              while (sourceCode.at(cc) != ' ' && sourceCode.at(cc) != '>') {
                nextAttributeValue.push_back(sourceCode.at(cc));
                cc++;
              }
              if (kVerbose) std::cout << "Attribute: " << nextAttributeName << " = " << nextAttributeValue << std::endl;
              tagAttributes.insert(std::map<std::string, std::string>::value_type(nextAttributeName, nextAttributeValue));
            }
          }
          tag.attributes_ = tagAttributes;
          // Insert tag in the tree to preserve the hierarchy.
          std::string currentTagParent{};

          if (!recentlyInsertedTags.empty()) {
            currentTagParent = recentlyInsertedTags.top();
          }
          insertChildOf(currentTagParent, tag);
          recentlyInsertedTags.push(tag.tag_);
        } else {
          // Closing tag.
          cc += 2;
          while (sourceCode.at(cc) != '>') {
            tag.tag_.push_back(sourceCode.at(cc));
            cc++;
          }
          if (kVerbose) std::cout << "Close tag: </" << tag.tag_ << ">" << std::endl;
          if (!recentlyInsertedTags.empty()) {
            recentlyInsertedTags.pop();
          }
        }
        break;
      }
      case '>': {
        if (kVerbose) std::cout << ">" << std::endl;
        break;
      }
      default: {
        break;
      }
    }
  }
}

std::string DOMTree::getAttributeValAux(DOMTreeNode *root, const std::deque<std::string> &domQuery) {

  
}

std::string DOMTree::getAttributeVal(const std::deque<std::string> &domQuery) {

  return getAttributeValAux(root_, domQuery);
}

void createDOMQuery(const std::string &queryStr, std::deque<std::string> &domQuery) {

  std::string currentTag{};
  for (int cc = 0; cc < queryStr.size(); ++cc) {
    char traversingChar = queryStr.at(cc);
    if (traversingChar != '.' && traversingChar != '~') {
      currentTag.push_back(traversingChar);
    } else {
      domQuery.push_back(currentTag);
      currentTag.clear();
    }
  }
  domQuery.push_back(currentTag);
}

int main () {

  int nn{};
  int qq{};
  std::string sourceCode{};

  std::cin >> nn >> qq;

  for (int ii = 0; ii <= nn; ++ii) {
    std::string sourceCodeLine{};
    std::getline(std::cin, sourceCodeLine);
    sourceCode += sourceCodeLine;
  }

  DOMTree domTree;

  domTree.assembleDOMTree(sourceCode);
  domTree.preOrderTraverse();

  for (int ii = 1; ii <= qq; ++ii) {
    std::string query{};
    std::getline(std::cin, query);
    std::cout << "Prepare: " << query << std::endl;
    std::deque<std::string> domQuery{};
    createDOMQuery(query, domQuery);
    for (int jj = 0; jj < domQuery.size() && kVerbose; ++jj) {
      std::cout << domQuery.at(jj) << std::endl;
    }
    std::string attVal{domTree.getAttributeVal(domQuery)};
    std::cout << attVal << std::endl;
  }
}
