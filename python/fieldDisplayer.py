# Create a sample image
import matplotlib.pyplot as plt
import pylab as plt
import csv

class Graph3D:
    def __init__(self, name, coordinates):
        self.name = name
        self.coordinates = coordinates
    
    def generateGraph(self):
        # Reading coordinates
        with open('./csv/plantsCoordinates.csv', newline='') as csvfile:
             filereader = csv.reader(csvfile, delimiter=',')
             
             fig = plt.figure()
             ax = fig.gca(projection='3d')  # Affichage en 3D
        
             for row in filereader:
                 size = len(row)
                 i = 0
                 while i+2 <= size:
                     X = int(row[i+1])
                     Y = int(row[i+2])
                     Z = 1
                     ax.scatter(X, Y, Z, label=row[0] if i == 0 else "", marker='d')  # Tracé de la courbe 3D
                     i = i+2
             
        # Tracé du résultat en 3D      
        plt.title(self.name)
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        plt.gca().invert_yaxis()
        plt.show()
        
# DEBUT DU PROGRAMME

graph = Graph3D("Céleste","48.396591, 4.507757")
graph.generateGraph()