def matrix_multiply(matrix1, matrix2):
    #both matrices are non-empty
    if not matrix1 or not matrix2:
        raise ValueError("Input matrices must not be empty")
    #is input a list-of-lists?
    if any(not isinstance(row, list) for row in matrix1):
        raise TypeError("Matrix1 must be a list of lists")
    if any(not isinstance(row, list) for row in matrix2):
        raise TypeError("Matrix2 must be a list of lists")
    #is there empty rows?
    if any(len(row) == 0 for row in matrix1):
        raise ValueError("Matrix1 contains empty row")
    if any(len(row) == 0 for row in matrix2):
        raise ValueError("Matrix2 contains empty row")

    m=len(matrix1)
    n=len(matrix1[0])
    p=len(matrix2[0])
    #are matrices multipliable?
    if n!=len(matrix2):
        raise ValueError("Incompatible matrix dimensions")
    #are matrices rectangular?
    if any(len(row) != n for row in matrix1):
        raise ValueError("Matrix1 is not rectangular")
    if any(len(row) != len(matrix2[0]) for row in matrix2):
        raise ValueError("Matrix2 is not rectangular")
    
    for i in matrix1:
        for j in i:
            #check boolean
            if isinstance(j,bool):
                raise TypeError("Matrix1 contains boolean value")
            #check number/not
            try:
                j+0
            except Exception:
                raise TypeError("Matrix1 contains non-numeric value")
    for i in matrix2:
        for j in i:
            #check boolean
            if isinstance(j,bool):
                raise TypeError("Matrix2 contains boolean value")
            #check number/not
            try:
                j+0
            except Exception:
                raise TypeError("Matrix2 contains non-numeric value")
    #actual loop
    matrix3=[[0 for _ in range(p)] for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j]
    return matrix3