#include <memory>
using namespace std;

  template <class K, class V>
  struct node{
	K key;
	V value;
	shared_ptr<node<K,V>> next_;
};
template <class K, class V>
shared_ptr<linked_list<K,V> head_;

void move_to_front_if_exist(K key) 
  template<class K, class V>
  class map{
	size_t array_size_;
	size_t map_size_;
	shared_ptr<linked_list<node<K,V>> buckets_;
}
  public:
	map(){
		array_size_ = 10;
		map_size_ = 0;
		buckets_ = make_array(array_size);
	}
  shared_ptr<linked_list<K, V>> make_array(size_t requested_size) {
    return shared_ptr<linked_list<K, V>>(
      new linked_list<K, V>[requested_size],
      default_delete<linked_list<K, V>[]>()
    ); 
    
void set(k key, V value){
	hash<k> hasher;
	size_t index = hasher(key) % array_size;
	buckets_
}

v remove(k key){
	
}
