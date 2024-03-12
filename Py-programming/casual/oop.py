class persona:
    def __init__ (self, name, age, weight):
        self.name = name
        self.age = age
        self.weight = weight

    def saluta(self):
        print(f"ciao, io sono {self.name}, e ho {self.age} anni. Peso {self.weight} kili")


petru = persona("Petru", 18, 90.05)
petru.saluta()
