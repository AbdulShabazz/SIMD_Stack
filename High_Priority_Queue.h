#include <unordered_map>
#include <algorithm>

/**
AUTHOR: 
Seagat2011

DESCRIPTION:
A High_Priority_Queue has O(1) Sort-, Insert-, 
Search-, and removal- runtime complexity.
*/

template<typename T, std::size_t N>
class High_Priority_Queue {
public:
    High_Priority_Queue() noexcept {
        for(auto& vec : vectors) {
            vec.push_back(1);
        }
    }

    // Setters //
    T Push(const auto& vec)
    {
        
    }

    T Push_Front(const auto& vec)
    {
        
    }
    T Push_Back(const auto& vec)
    {
        
    }
    
    bool Insert(const T& value)
    {
        const idx = (value < value_0000 ? 0 : 1) + ... + (value < value_N ? 0 : 1);
        vectors[idx] = value;
    }
    
    T Emplace(const )
    {
        
    }

    // Deleters //
    bool Pop() const noexcept
    {
        
    }
    bool Pop_Back() const noexcept
    {
        
    }
    bool Pop_Front() const noexcept
    {
        
    }
    
    bool Empty() const {
        
    }
    
    bool Clear() const {
        
    }
    
    // Getters //
    std::vector<T>& operator[](std::size_t i) {
        return vectors[i];
    }
    
    const std::vector<T>& operator[](std::size_t i) const {
        return vectors[i];
    }
    
    T Top() const
    {
        
    }
    
    T Bottom() const
    {
        
    }
    
    T Front() const
    {
        
    }
    
    T Back() const
    {
        
    }
    
private:
    std::unordered_map<std::size_t, T> vector;
    
    void Sort()
    {
        
    }
    
};

int main ()
{
    return EXIT_SUCCESS;
}

/*
/ *Q:Bard, provide a c++20 algorithm to implement a custom std::priority_queue without a third party library.  * /

template <typename T, typename Compare = std::less<T>>
class custom_priority_queue {
    public:
    custom_priority_queue() = default;
    
    void push(const T& value)
    {
        queue.push_back(value);
        std::push_heap(queue,begin(), queue.end(), Compare());
    }
    
    void pop(){
        std::pop_heap(queue,begin(), queue.end(), Compare());
        queue.pop_back();
    }
    
    T top() const {
        return queue.front();
    }
    
    bool empty () {
        return queue::empty();
    }
    
    private:
    std::vector<T> queue;
}
*/




/*
/ *
Yes, it is possible to use copy-on-write to allow a std::priority_queue::push and std::priority_queue::top operation to achieve O(1) runtime complexity.

Copy-on-write is a technique that allows multiple processes to share the same memory without having to make a copy of it. This is done by creating a reference count for each piece of memory. When a process wants to modify a piece of memory, it increments the reference count. If another process also wants to modify the same piece of memory, it also increments the reference count. If the reference count reaches 2, then a copy of the memory is made and the two processes can now modify their own copies without affecting each other.

In the case of a std::priority_queue, we can use copy-on-write to allow multiple threads to push and pop elements without having to lock the queue. When a thread wants to push an element, it first checks to see if the reference count for the queue is 1. If it is, then it simply increments the reference count and pushes the element onto the queue. If the reference count is greater than 1, then the thread creates a copy of the queue and pushes the element onto the copy. The original queue is then left untouched.

This technique allows us to achieve O(1) runtime complexity for both the push and pop operations. The push operation only has to increment the reference count, which is a constant-time operation. The pop operation only has to check the reference count and then return the top element. If the reference count is 1, then the top element is simply returned. If the reference count is greater than 1, then the top element is copied from the original queue and returned.

Here is an example of how to implement copy-on-write for a std::priority_queue:
C++

#include <queue>

class CopyOnWritePriorityQueue {
public:
  CopyOnWritePriorityQueue() {}

  void push(int value) {
    if (reference_count == 1) {
      queue_.push(value);
    } else {
      queue_ = queue_.copy();
      queue_.push(value);
    }
    ++reference_count;
  }

  int top() {
    if (reference_count == 1) {
      return queue_.top();
    } else {
      return queue_.copy().top();
    }
  }

  void pop() {
    if (reference_count == 1) {
      queue_.pop();
    } else {
      queue_ = queue_.copy();
      queue_.pop();
    }
    --reference_count;
  }

private:
  std::queue<int> queue_;
  int reference_count = 1;
};

Use code with caution. Learn more

This implementation achieves O(1) runtime complexity for both the push and pop operations. The push operation only has to increment the reference count, which is a constant-time operation. The pop operation only has to check the reference count and then return the top element. If the reference count is 1, then the top element is simply returned. If the reference count is greater than 1, then the top element is copied from the original queue and returned.
* /
#include <queue>

class CopyOnWritePriorityQueue {
public:
  CopyOnWritePriorityQueue() {}

  void push(int value) {
    if (reference_count == 1) {
      queue_.push(value);
    } else {
      queue_ = queue_.copy();
      queue_.push(value);
    }
    ++reference_count;
  }

  int top() {
    if (reference_count == 1) {
      return queue_.top();
    } else {
      return queue_.copy().top();
    }
  }

  void pop() {
    if (reference_count == 1) {
      queue_.pop();
    } else {
      queue_ = queue_.copy();
      queue_.pop();
    }
    --reference_count;
  }

private:
  std::queue<int> queue_;
  int reference_count = 1;
};

*/
