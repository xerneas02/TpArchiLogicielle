result = [[0 for _ in range(4)] for _ in range(730)]

count_if_dis_dead = False
nGood = 0

folder = input("Nom du dosier : \n")


for i in range(1, 101):
    res_file = open(f"resultat/{folder}/resultat_{i}.csv", "r")
    res = res_file.read()
    res_file.close()

    res = res.split("\n")
    res.pop(0)
    try:
        if(count_if_dis_dead or int(res[700].split(";")[2]) != 0):
            nGood += 1
            for j in range(730):
                res[j] = res[j].split(";")
                
                for k in range(4):
                    result[j][k] += int(res[j][k])
    except:
        print(f"Erreur fichier {i} ligne {j}!")

scv = "Susceptible;Exposed;Infected;Recovered\n"
for i in range(1, 730):
    scv += f"{result[i][0]/nGood};{result[i][1]/nGood};{result[i][2]/nGood};{result[i][3]/nGood}\n"

print(f"Pourcentage de fichier valide : {nGood}%")




file_res = open(f"resultat/{folder}/resultat_mean.csv", "w")
file_res.write(scv.replace(".", ","))