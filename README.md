# C++ STL Cheatsheet

### **1. Containers**

#### **1.1. `std::vector`**

- **Description:** Dynamic array that can resize itself automatically.
- **Header:** `<vector>`
- **Common Operations:**
  - **Create:** `std::vector<int> vec;`
  - **Add element:** `vec.push_back(10);`
  - **Access element:** `int x = vec[0];`
  - **Size:** `size_t s = vec.size();`
  - **Iterate:**
    ```cpp
    for (int val : vec) {
        // use val
    }
    ```
  - **Sort:** `std::sort(vec.begin(), vec.end());`

#### **1.2. `std::list`**

- **Description:** Doubly linked list.
- **Header:** `<list>`
- **Common Operations:**
  - **Create:** `std::list<int> lst;`
  - **Add element:** `lst.push_back(10); lst.push_front(5);`
  - **Access element:** `int x = lst.front();`
  - **Size:** `size_t s = lst.size();`
  - **Iterate:**
    ```cpp
    for (int val : lst) {
        // use val
    }
    ```
  - **Sort:** `lst.sort();`

#### **1.3. `std::deque`**

- **Description:** Double-ended queue with fast insertions/deletions at both ends.
- **Header:** `<deque>`
- **Common Operations:**
  - **Create:** `std::deque<int> dq;`
  - **Add element:** `dq.push_back(10); dq.push_front(5);`
  - **Access element:** `int x = dq.front();`
  - **Size:** `size_t s = dq.size();`
  - **Iterate:**
    ```cpp
    for (int val : dq) {
        // use val
    }
    ```

#### **1.4. `std::set`**

- **Description:** Ordered set of unique elements.
- **Header:** `<set>`
- **Common Operations:**
  - **Create:** `std::set<int> s;`
  - **Add element:** `s.insert(10);`
  - **Check if exists:** `bool exists = s.count(10);`
  - **Size:** `size_t sz = s.size();`
  - **Iterate:**
    ```cpp
    for (int val : s) {
        // use val
    }
    ```

#### **1.5. `std::unordered_set`**

- **Description:** Unordered set of unique elements with fast average insertion and lookup.
- **Header:** `<unordered_set>`
- **Common Operations:**
  - **Create:** `std::unordered_set<int> us;`
  - **Add element:** `us.insert(10);`
  - **Check if exists:** `bool exists = us.count(10);`
  - **Size:** `size_t sz = us.size();`
  - **Iterate:**
    ```cpp
    for (int val : us) {
        // use val
    }
    ```

#### **1.6. `std::map`**

- **Description:** Ordered key-value pairs.
- **Header:** `<map>`
- **Common Operations:**
  - **Create:** `std::map<int, std::string> m;`
  - **Add element:** `m[1] = "one";`
  - **Access element:** `std::string val = m[1];`
  - **Size:** `size_t sz = m.size();`
  - **Iterate:**
    ```cpp
    for (auto& [key, value] : m) {
        // use key and value
    }
    ```

#### **1.7. `std::unordered_map`**

- **Description:** Unordered key-value pairs with fast average insertion and lookup.
- **Header:** `<unordered_map>`
- **Common Operations:**
  - **Create:** `std::unordered_map<int, std::string> um;`
  - **Add element:** `um[1] = "one";`
  - **Access element:** `std::string val = um[1];`
  - **Size:** `size_t sz = um.size();`
  - **Iterate:**
    ```cpp
    for (auto& [key, value] : um) {
        // use key and value
    }
    ```

#### **1.8. `std::stack`**

- **Description:** LIFO stack.
- **Header:** `<stack>`
- **Common Operations:**
  - **Create:** `std::stack<int> st;`
  - **Push element:** `st.push(10);`
  - **Pop element:** `st.pop();`
  - **Top element:** `int top = st.top();`
  - **Size:** `size_t sz = st.size();`

#### **1.9. `std::queue`**

- **Description:** FIFO queue.
- **Header:** `<queue>`
- **Common Operations:**
  - **Create:** `std::queue<int> q;`
  - **Push element:** `q.push(10);`
  - **Pop element:** `q.pop();`
  - **Front element:** `int front = q.front();`
  - **Size:** `size_t sz = q.size();`

#### **1.10. `std::priority_queue`**

- **Description:** Priority queue (max-heap by default).
- **Header:** `<queue>`
- **Common Operations:**
  - **Create:** `std::priority_queue<int> pq;`
  - **Push element:** `pq.push(10);`
  - **Pop element:** `pq.pop();`
  - **Top element:** `int top = pq.top();`
  - **Size:** `size_t sz = pq.size();`

---

### **2. Algorithms and Functions**

#### **2.1. `std::accumulate`**

- **Header:** `<numeric>`
- **Use:** Calculate the sum of a range.
- **Example:**
  ```cpp
  int sum = std::accumulate(vec.begin(), vec.end(), 0);
  ```

#### **2.2. `std::count`**

- **Header:** `<algorithm>`
- **Use:** Count occurrences of a value in a range.
- **Example:**
  ```cpp
  int count = std::count(vec.begin(), vec.end(), 10);
  ```

#### **2.3. `std::find`**

- **Header:** `<algorithm>`
- **Use:** Find the first occurrence of a value in a range.
- **Example:**
  ```cpp
  auto it = std::find(vec.begin(), vec.end(), 10);
  ```

#### **2.4. `std::sort`**

- **Header:** `<algorithm>`
- **Use:** Sort elements in a range.
- **Example:**
  ```cpp
  std::sort(vec.begin(), vec.end());
  ```

#### **2.5. `std::reverse`**

- **Header:** `<algorithm>`
- **Use:** Reverse the order of elements in a range.
- **Example:**
  ```cpp
  std::reverse(vec.begin(), vec.end());
  ```

#### **2.6. `std::copy`**

- **Header:** `<algorithm>`
- **Use:** Copy elements from one range to another.
- **Example:**
  ```cpp
  std::copy(vec.begin(), vec.end(), anotherVec.begin());
  ```

#### **2.7. `std::transform`**

- **Header:** `<algorithm>`
- **Use:** Apply a function to a range and store the result.
- **Example:**
  ```cpp
  std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });
  ```

#### **2.8. `std::remove`**

- **Header:** `<algorithm>`
- **Use:** Remove elements with a specific value from a range.
- **Example:**
  ```cpp
  auto newEnd = std::remove(vec.begin(), vec.end(), 10);
  vec.erase(newEnd, vec.end());
  ```

#### **2.9. `std::unique`**

- **Header:** `<algorithm>`
- **Use:** Remove consecutive duplicates from a range.
- **Example:**
  ```cpp
  auto newEnd = std::unique(vec.begin(), vec.end());
  vec.erase(newEnd, vec.end());
  ```

#### **2.10. `std::max_element`**

- **Header:** `<algorithm>`
- **Use:** Find the maximum element in a range.
- **Example:**
  ```cpp
  auto maxIt = std::max_element(vec.begin(), vec.end());
  ```

#### **2.11. `std::min_element`**

- **Header:** `<algorithm>`
- **Use:** Find the minimum element in a range.
- **Example:**
  ```cpp
  auto minIt = std::min_element(vec.begin(), vec.end());
  ```

#### **2.12. `std::for_each`**

- **Header:** `<algorithm>`
- **Use:** Apply a function to each element in a range.
- **Example:**
  ```cpp
  std::for_each(vec.begin(), vec.end(), [](int& x) { x *= 2; });
  ```

#### **2.13. `std::partition`**

- **Header:** `<algorithm>`
- **Use:** Reorder elements in a range so that all elements satisfying a condition precede those that do not.
- **Example:**
  ```cpp
  auto it = std::partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
  ```

#### **2.14. `std::iota`**

- **Header:** `<numeric>`
- **Use:** Fill a range with sequentially increasing values.
- **Example:**
  ```cpp
  std::iota(vec.begin(), vec.end(), 1);
  ```

#### Backtracking

General Steps:
1. Check the current cell:
        Is it out of bounds?
        Is it a wall?
        Is it already visited?
2. If it’s the end position, return the current path/cost.
3. Mark the cell as visited.
4. Explore all possible moves (up, down, left, right):
5. Recursively move to the next cell.
6. Unmark the cell as unvisited after exploring to allow other paths.
