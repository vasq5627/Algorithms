
#include <memory>
using namespace std;

template <class K, class V>
struct node {
  K key;
  V value;
  shared_ptr<node<K, V>> next;
};

template <class K, class V>
class linked_list {
  shared_ptr<node<K, V>> head_;
  
  void move_to_front_if_exists(K key) {
    if (head_.get() == nullptr || head_->key == key) {
      return;
    }
    
    auto prev = head_;
    auto cur = head_->next;
    while (cur.get() != nullptr) {
      if (cur->key == key) {
        prev->next = cur->next;
        cur->next = head_;
        head_ = cur;
        break;
      }
      prev = prev->next;
      cur = cur->next;
    }
  }
  
 public:
  linked_list() {
    head_.reset();
  }
  
  V get(K key) {
    move_to_front_if_exists(key);
    return head_->value;
  }

  bool set(K key, V value) {
    move_to_front_if_exists(key);

    bool added = false;
    if (head_.get() == nullptr || head_->key != key) {
      shared_ptr<node<K, V>> new_node(new node<K, V>);
      new_node->key = key;
      new_node->next = head_;
      head_ = new_node;
      added = true;
    }
    head_->value = value;
  
    return added;
  }
  
  bool remove(K key) {
    move_to_front_if_exists(key);
    
    bool removed = false;
    if (head_.get() != nullptr && head_->key == key) {
      head_ = head_->next;
      removed = true;
    }
  
    return removed;
  }

  bool contains(K key) {
    move_to_front_if_exists(key);
    return head_.get() != nullptr && head_->key == key;
  }
};

template <class K, class V>
class map {
  size_t map_size_;
  size_t array_size_;
  shared_ptr<linked_list<K, V>> buckets_;
  
  shared_ptr<linked_list<K, V>> make_array(size_t requested_size) {
    return shared_ptr<linked_list<K, V>>(
      new linked_list<K, V>[requested_size],
      default_delete<linked_list<K, V>[]>()
    );
  }
  
  size_t get_bucket_index(K key) {
    hash<K> hasher;
    return hasher(key) % array_size_;
  }
  
 public:
  map() {
    map_size_ = 0;
    array_size_ = 10;
    buckets_ = make_array(array_size_);
  }

  size_t size() {
    return map_size_;
  }
  
  bool contains(K key) {
    size_t index = get_bucket_index(key);
    return buckets_.get()[index].contains(key);
  }

  V get(K key) {
    size_t index = get_bucket_index(key);
    return buckets_.get()[index].get(key);
  }

  void set(K key, V value) {
    size_t index = get_bucket_index(key);
    if (buckets_.get()[index].set(key, value)) {
      ++map_size_;
    }
  }

  void remove(K key) {
    size_t index = get_bucket_index(key);
    if (buckets_.get()[index].remove(key)) {
      --map_size_;
    }
  }
};

#include <iostream>
/*
int main(){ 
 map<char, int> m;
 m.set('A', 1);
 m.set('B', 3);
 cout << m.get('B');
 m.set('B', 4);
 cout << m.get('A');
 cout << m.get('B');
 return 0;
}


int main(){
	map<char, char> m;
	m.set('A','B');
	m.set('B','C');
	cout << m.get('A');
	cout << (m.contains('C') ? 'X' : 'Y');
	m.remove('B');
	cout << (m.contains('B') ? 'P' : 'Q');
	cout << m.get('A');
	return 0;
}
*/

