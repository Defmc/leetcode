class Node:
    key: int = 0
    val: int = 0
    left: Self = None
    right: Self = None

    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
    
    def disconnect(self) -> None:
        left = self.left
        right = self.right
        if left != None:
            left.right = right
            self.left = None
        if right != None:
            right.left = left
            self.right = None
    
    def connect(self, r: Self) -> None:
        assert self.right == None
        assert r.left == None
        self.right = r
        r.left = self

class LRUCache:
    rels = {}
    len = 0
    max_len = 0
    cache = None
    cache_tail = None

    def __init__(self, capacity: int):
        self.max_len = capacity
        self.rels = {}
        self.len = 0
        self.cache = None
        self.cache_tail = None

    def remove(self, node: Node) -> None:
        if self.cache == node:
            self.cache = node.right
        if self.cache_tail == node:
            self.cache_tail = node.left
        node.disconnect()
        del self.rels[node.key]
        self.len -= 1
    
    def push(self, node: Node) -> None:
        if self.cache == None:
            self.cache = node
            self.cache_tail = node
        else:
            self.cache_tail.connect(node)
            self.cache_tail = node
        self.len += 1
        self.rels[node.key] = node
        if self.len > self.max_len:
            self.remove(self.cache)

    def get(self, key: int) -> int:
        if key in self.rels:
            node = self.rels[key]
            self.remove(node)
            self.push(node)
            return node.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.rels:
            node = self.rels[key]
            self.remove(node)
        node = Node(key, value)
        self.push(node)
        return None


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
