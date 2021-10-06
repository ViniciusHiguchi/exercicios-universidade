class Funcionario:

    def __init__ (self, salario, vendas, taxaComissao):
        self.nome = "Catherine Huff"
        self.salarioFixo = salario
        self.vendas = vendas
        self.taxaComissao = taxaComissao
    
    def GetComissao(self):
        return (self.vendas*self.taxaComissao)

    def GetSalarioFixo(self):
        return (self.salarioFixo)

    def GetSalario(self):
        return (self.GetComissao() + self.GetSalarioFixo())

    def GetNome(self):
        return self.nome

funcionario = Funcionario(float(input()), float(input()), 0.18)
print(funcionario.GetNome()+" deve receber R$ %.2f no final do mês"%funcionario.GetSalario())
