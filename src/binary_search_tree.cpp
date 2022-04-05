#include "assignment/binary_search_tree.hpp"

namespace assignment {

    BinarySearchTree::~BinarySearchTree() {
        BinarySearchTree::Clear();
    }

    void BinarySearchTree::Insert(int key, int value) {
        if(root_ == nullptr) {
            root_ = new Node(key, value);
            return;
        }
        insert(key, value, root_);
    }

    bool BinarySearchTree::Remove(int key) {
        if(root_ == nullptr) return false;
        return remove(key, root_);
    }

    void BinarySearchTree::Clear() {
        root_ = nullptr;
    }

    std::optional<int> BinarySearchTree::Find(int key) const {
        if(find(key, root_) != nullptr) return find(key, root_) -> value;
        return {};
    }

    bool BinarySearchTree::Contains(int key) const {
        if(find(key, root_) != nullptr) return true;
        else return false;
    }

    bool BinarySearchTree::IsEmpty() const {
        return root_ == nullptr;
    }

    std::optional<int> BinarySearchTree::FindMin() const {
        if(find_min(root_) != nullptr) return find_min(root_) -> value;
        return {};
    }

    std::optional<int> BinarySearchTree::FindMax() const {
      if(find_max(root_) != nullptr) return find_max(root_) -> value;
      return {};
    }

    Node* BinarySearchTree::root() const {
        return root_;
    }

    // вспомогательные методы

    void BinarySearchTree::insert(int key, int value, Node*& node) {
        if(node == nullptr) {
            node = new Node(key, value);
            return;
        }
        if(node -> key > key) {
            insert(key, value, node -> left);
            return;
        }
        if(node -> key < key) {
            insert(key, value, node -> right);
            return;
        }
    }

    bool BinarySearchTree::remove(int key, Node*& node) {
        if(node == nullptr) return false;
        if(node -> key > key) {
            return remove(key, node -> left);
        }
        if(node -> key < key) {
            return remove(key, node -> right);
        }
        if(node -> left == nullptr && node -> right == nullptr) {
            node = nullptr;
            return true;
        }
        if(node -> right == nullptr) {
            node = node -> left;
            return true;
        }
        if(node -> left == nullptr) {
            node = node -> right;
            return true;
        }
        Node *mn = find_min(node -> right);
        node -> key = mn -> key;
        node -> value = mn -> value;
        remove(node -> key, node -> right);
        return true;
    }

    void BinarySearchTree::clear(Node* node) {
        node = nullptr;
    }

    Node* BinarySearchTree::find(int key, Node* node) const {
        if(node == nullptr) return nullptr;
        if(node -> key > key) return find(key, node -> left);
        if(node -> key < key) return find(key, node -> right);
        return node;
    }

    Node* BinarySearchTree::find_min(Node* node) const {
        if(node == nullptr) return nullptr;
        if(node -> left == nullptr) return node;
        return find_min(node -> left);
    }

    Node* BinarySearchTree::find_max(Node* node) const {
      if(node == nullptr) return nullptr;
      if(node -> right == nullptr) return node;
      return find_max(node -> right);
    }

}  // namespace assignment