class Node:
    def __init__(self, key: int, value: int) -> None:
        self.key = key
        self.value = value
        self.next: Node | None = None
        self.prev: Node | None = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)

        self.head.next = self.tail
        self.tail.prev = self.head

    def _insert(self, node: Node) -> None:

        next_node = self.head.next

        assert next_node is not None

        self.head.next = node
        node.prev = self.head

        next_node.prev = node
        node.next = next_node

    def _delete(self, node: Node) -> None:
        prev_node = node.prev
        next_node = node.next

        assert prev_node is not None
        assert next_node is not None

        prev_node.next = next_node
        next_node.prev = prev_node

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self._delete(node)
            self._insert(node)
            return node.value

        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self._delete(self.cache[key])

        node = Node(key, value)
        self.cache[node.key] = node
        self._insert(node)

        if len(self.cache) > self.capacity:
            lru_node = self.tail.prev

            assert lru_node is not None

            self._delete(lru_node)
            del self.cache[lru_node.key]


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
