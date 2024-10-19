import random

class Matrix:
    def __init__(self, m, n):
        self.row = m
        self.colum = n
        self.matrix = [[0 for _ in range(n)] for _ in range(m)]
    
    def init(self):
        for i in range(self.row):
            for j in range(self.colum):
                self.matrix[i][j] = 0

    def print(self):
        for i in range(self.row):
            for j in range(self.colum):
                print(self.matrix[i][j], end=" ")
            print()
        print()
    
    def fillrandom(self):
        for i in range(self.row):
            for j in range(self.colum):
                self.matrix[i][j] = random.randint(1, 10)

    def changeone(self,m,n):
        if m>self.row or n>self.colum :
            print("wehrt auserhalb der matrix") 
            return
        self.matrix[m-1][n-1] = int(input(f"Element at [{m}][{n}]: "))

    def changeall(self):
        for i in range(self.row):
            for j in range(self.colum):
                self.matrix[i][j] = int(input(f"Element at [{i+1}][{j+1}]: "))
    
    def add(self, M):
        if self.row != M.row or self.colum != M.colum :
            print("to add matixes u need the same n and m")
            return
        for i in range(self.row):
            for j in range(self.colum):
                self.matrix[i][j] += M.matrix[i][j]
    
    def mul(self, M):
        if self.colum != M.row:
            print("Matrices dimensions do not match for multiplication")
            return
        result = Matrix(self.row, M.colum)
        for i in range(self.row):
            for j in range(M.colum):
                for k in range(self.colum):
                    result.matrix[i][j] += self.matrix[i][k] * M.matrix[k][j]
        return result



m2 = Matrix(8,2)
m1 = Matrix(2,8)
m1.fillrandom()
m2.fillrandom()
m1.print()
m2.print()
m3 = m1.mul(m2)
m3.print()
"""
m1.init()
m1.print()
m1.fillrandom()
m1.print()
m1.changeall()
m1.print()
m1.changeone(1,2)
m1.print()
"""
