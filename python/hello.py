class person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def description(self):
        return f"{self.name} is {self.age} years old"

person1 = person("petru", 10)

print(person1.description())

