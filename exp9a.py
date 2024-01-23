# in python 90per of mistake happens in the space please take care of it 
#whenever number is present use range based loop
def add(m1,m2):
    return [[m1[i][j]+m2[i][j] for j in range(len(m1[0]))]for i in range(len(m1))]
def sub(m1,m2):
    return[[m1[i][j]-m2[i][j] for j in range(len(m1[0]))]for i in range(len(m1))]
def mul(m1,m2):
    result=[[0 for j in range(len(m2[0]))]for i in range(len(m1))]
    if (len(matrix1[0]) == len(matrix2)):
        for i in range(len(m1)):
            for j in range(len(m2[0])):
                for k in range(len(m1[0])):
                    result[i][j] += (m1[i][k])*(m2[k][j])# badhwe kar di nah glti yahi hota hai bete never repeat it in evr your cycle
    return result
def transpose(m1):
    transposed_matrix=[[m1[j][i] for j in range(len(m1)) ] for i in range(len(m1[0]))]
    return transposed_matrix
def fast_transpose(m1):
    res=[[0 for j in range(len(m1))]for i in range(len(m1[0])) ]
    rows=len(m1)
    cols=len(m1[0])
    for i in range(rows):
        for j in range(cols):
            res[j][i]=m1[i][j]

    return res
def display(m1):
    for row in m1:
        print(row)

rows=int(input("Enter the no. of rows of matrix1: "))
cols=int(input("Enter the no. of cols of matrix2: "))
matrix1=[]
matrix2=[]
#ultimate most important
for i in range(rows):
    row= list(map(int,input(f"enter the elemnts in row{i+1}(space sperated):").split()))
    if rows!=cols:
        print("invalid input")
    matrix1.append(row)
   
rows1=int(input("Enter the no. of rows of matrix2: "))
cols1=int(input("Enter the no. of cols of matrix2: "))

for i in range(rows1):
    
    row= list(map(int,input(f"enter the elemnts in row{i+1}(space sperated):").split()))
    if rows1!=cols1:
        print("invalid input")
    matrix2.append(row)
display(matrix1)
display(matrix2)
while True:
