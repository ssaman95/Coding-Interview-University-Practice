class HashObject(object):
    def get_dummy_key():
        return '<Dummy>'
    
    def get_null_key():
        return '<Null>'
    
    def __init__(self):
        self.key_ = None
        self.value_ = None
        
    def set_key(self, key):
        self.key_= key
        
    def set_value(self, value):
        self.value_ = value
        
    def get_key(self):
        return self.key_
    
    def get_value(self):
        return self.value_
    
    def set_as_dummy(self):
        self.set_key(HashObject.get_dummy_key())
        self.set_value('')
        