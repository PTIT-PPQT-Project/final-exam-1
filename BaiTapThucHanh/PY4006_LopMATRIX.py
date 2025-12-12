import math

class Matrix:
    def __init__(self, n, m, data):
        self.n = n
        self.m = m
        self.data = data

    def transpose(self):
        b_data = []
        for i in range(self.m):
            new_row = []
            for j in range(self.n):
                new_row.append(self.data[j][i])
            b_data.append(new_row)
        return Matrix(self.m, self.n, b_data)

    def multiply(self, other):
        c_data = []
        for i in range(self.n):
            new_row = []
            for j in range(other.m):
                sum_val = 0
                for k in range(self.m):
                    sum_val += self.data[i][k] * other.data[k][j]
                new_row.append(sum_val)
            c_data.append(new_row)
        return Matrix(self.n, other.m, c_data)

    def __str__(self):
        output = []
        for row in self.data:
            output.append(" ".join(map(str, row)))
        return "\n".join(output)

so_bo_test = int(input())

for _ in range(so_bo_test):
    n, m = map(int, input().split())
    
    a_data = []
    for i in range(n):
        row = list(map(int, input().split()))
        a_data.append(row)
        
    a = Matrix(n, m, a_data)
    
    a_transpose = a.transpose()
    
    ket_qua = a.multiply(a_transpose)
    
    print(ket_qua)