class Node:
    def _init_(self, data):
        self.data = data
        self.left = None
        self.right = None


class Binarytree:
    c = 0
    root = None

    def insert(self, data):
        n = Node()
        n._init_(data)

        if self.root is None:
            self.root = n
            print(self.c)
            return

        current = self.root

        while True:
            self.c += 1
            parent = current
            if data < current.data:
                current = current.left
                if current is None:
                    parent.left = n
                    break

            else:
                current = current.right
                if current is None:
                    parent.right = n
                    break

        print(self.c)
        return


tree = Binarytree()
num = int(input())
for i in range(num):
    tree.insert(int(input()))
