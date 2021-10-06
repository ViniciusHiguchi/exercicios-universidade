def change(dir):
    if dir[0] == 1 and dir[1] == 0:
        dir[0] = 0
        dir[1] = 1
        return dir
    elif dir[0] == 0 and dir[1] == 1:
        dir[0] = -1
        dir[1] = 0
        return dir
    elif dir[0] == -1 and dir[1] == 0:
        dir[0] = 0
        dir[1] = -1
        return dir
    elif dir[0] == 0 and dir[1] == -1:
        dir[0] = 1
        dir[1] = 0
        return dir
    

def EscreverMatriz(m):
    for linha in m:
        print(*linha)
        
format = input()
linha = int(format[6])
coluna = int(format[len(format)-1])

matriz = [-1]*int(linha)
for i in range(len(matriz)):
    matriz[i] = [-1]*int(coluna)
pos = [0,0]
direction = [1,0]
end = False
cur = 0
matriz[pos[0]][pos[1]] = cur
while not end:
    try:
        if matriz[pos[0] + direction[0]][pos[1]+direction[1]] != -1:
            directon = change(direction)
    except:
        direction = change(direction)
    matriz[pos[0]][pos[1]] = cur
    cur += 1
    pos[0] += direction[0]
    pos[1] += direction[1]
    if cur > int(linha)*int(coluna) -1:
        end = True

print("Matriz espiral anti-horária passo 1:")
EscreverMatriz(matriz)
