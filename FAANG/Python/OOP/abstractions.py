from abc import ABC, abstractmethod

class Greet(ABC):

    @abstractmethod
    def say_hello(self):
        pass

class English(Greet):
    def say_hello(self):
        return "hello"
    
g = English()
print(g.say_hello())