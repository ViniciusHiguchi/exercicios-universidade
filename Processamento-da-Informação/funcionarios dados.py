def countAgeRange(funcionariosIdade):
    quant = 0
    for i in range(len(funcionariosIdade)):
        if (funcionariosIdade[i] >= 18 and funcionariosIdade[i] <= 23):
            quant = quant + 1
    return quant

def countAgeRange47(funcionariosIdade):
    quant = 0
    for i in range(len(funcionariosIdade)):
        if (funcionariosIdade[i] > 47):
            quant = quant + 1
    return quant

def mediaSal(funcionariosIdade, funcionariosSalario, idadeInput):
    quant = 0
    total = 0
    for i in range(len(funcionariosIdade)):
        if funcionariosIdade[i] > idadeInput:
            quant = quant + 1
            total = total + funcionariosSalario[i]
    if quant != 0:
        return (total/quant)
    else:
        return 0

def bonus(referencia, taxa, funcionariosSalario):
    total = 0
    for i in range(len(funcionariosSalario)):
        if funcionariosSalario[i] < referencia:
            total = total + funcionariosSalario[i]
    return (total*taxa)

funcionariosIdade = []
funcionariosSalario = []
for i in range(int(input())):
    while True:
        try:
            y = float(input())
        except:
            break
        if y >= 883 and y <= 24914:
            break
    funcionariosSalario.append(y)
    while True:
        try:
            y =float(input())
        except:
            break
        if y >= 18 and y <= 69:
            break
    funcionariosIdade.append(y)

print("{:<6}{:<7}".format('idade','salario'))
for idade, salario in zip(funcionariosIdade, funcionariosSalario):
    print("{:<6}{:<7}".format(int(idade),int(salario)))

print("\nmaior salario                             =",'%5d' % max(funcionariosSalario))
print("func. entre 18 e 23 anos                 = ",'%5d' %(countAgeRange(funcionariosIdade)))
print("func. com mais de 47 anos                = ",'%5d' %(countAgeRange47(funcionariosIdade)))
print("media dos sal. func. com mais de 47 anos = ",'%7.1f' %(mediaSal(funcionariosIdade, funcionariosSalario, 47)))
print("bonus total                              = ",'%7.1f' %(bonus(1944,0.16,funcionariosSalario)))

#algumas das implementações aqui não são ideais, mas por causa das limitações do enunciado do exercício elas foram necessárias
