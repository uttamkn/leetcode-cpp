# 146. LRU Cache

**Difficulty**: Medium

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the `LRUCache` class:

- `LRUCache(int capacity)`: Initializes the LRU cache with positive size `capacity`.
- `int get(int key)`: Returns the value of the `key` if the key exists, otherwise returns `-1`.
- `void put(int key, int value)`: Updates the value of the `key` if the key exists. Otherwise, adds the key-value pair to the cache. If the number of keys exceeds `capacity` from this operation, evicts the least recently used key.

The functions `get` and `put` must each run in **O(1)** average time complexity.

### Example 1

```plaintext
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
```

**Explanation**

```plaintext
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

### Constraints

- \(1 \leq \text{capacity} \leq 3000\)
- \(0 \leq \text{key} \leq 10^4\)
- \(0 \leq \text{value} \leq 10^5\)
- At most \(2 \times 10^5\) calls will be made to `get` and `put`.
