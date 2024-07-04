class Position:

    def __init__ (self, xPos,yPos):
        self.x = xPos
        self.y = yPos

def calcula_distancia_Chebyshev(p1, p2):

    distance = Position(abs(p2.x - p1.x), abs(p2.y - p1.y))
    if distance.x > distance.y:
        return distance.x
    else:
        return distance.y
    
p1 = Position(-5, 7)
p2 = Position(float(input()), float(input()))
dist = calcula_distancia_Chebyshev(p1,p2)

print("distancia Chebyshev = %.2f" %round(dist,2))
