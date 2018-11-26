from node import Node

class LinkedList(object):
    def __init__(self):
        self.head_ = None
        
    def set_head(self, head_node):
        self.head_ = head_node
        
    def __len__(self):
        count = 0;
        current = self.head_
        while current:
            count += 1
            current = current.get_next()
        return count
    
    def __str__(self):
        current = self.head_
        output = ""
        while current:
            output += str(current) + " -> "
            current = current.get_next()
        return output
    
    # Pops a node from the front of the list
    def pop(self):
        if self.head_:
            self.head_ = self.head_.get_next()
        else:
            raise IndexError("Empty List")
            
    # Returns true if the value is present in the list
    def contains(self, value):
        current = self.head_
        while current:
            if current.get_data() == value:
                return True
            else:
                current = current.get_next()
        return False
                
    # Deletes all instances of a given value in the list
    def delete(self, value):
        current = self.head_
        prev = None
        while current:
            if current.get_data() == value:
                temp = current
                if prev:
                    prev.set_next(current.get_next())
                else:
                    self.head_ = current.get_next()
                current = current.get_next()
                temp.set_next(None)
                continue
            prev = current
            current = current.get_next()
            
    # Pushes an item at the front of the list
    def push(self, value):
        node = Node(value)
        node.set_next(self.head_)
        self.set_head(node)
                
                
        