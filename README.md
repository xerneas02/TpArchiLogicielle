# TpArchiLogicielle
Tp d'architecture logicielle sur le sujet : Modèle Toy case SEIR(Susceptible, Exposed, Infected and Recovered) multi-agent

PRNG used : Mersenne Twister generator by Makoto Matsumoto :
http://www.math.sci.hiroshima-u.ac.jp/m-mat/MT/MT2002/emt19937ar.html

## Compilation : 

### Generate 100 files :

- Place yourself at the parent folder of `src`
- Don't forget to create a `bin` and `resultat` directory in the same folder as `src`

Fast Compilation :

```shell
g++ -O1 src/*.cpp ./src/betterCPP/*.c* -o bin/main.exe -Wall -Wextra
```
Opimized Compilation :

```shell
g++ -Ofast src/*.cpp ./src/betterCPP/*.c* -o bin/main.exe -Wall -Wextra
```

Run :

```shell
./bin/main.exe
```

Current Save file are stored at `resultat/11_octobre_contamination&deplacer/...`
This is hardcoded at file:line : `src/simulation.h:38`

### Generate the mean in one file :

Mathis made a python script to generate one file with the means of all the simulation.

You can use it like this :

```shell
py .\resultat\gen_mean.py

```

Then put the file name

```shell
Nom du dosier : 
11_octobre_contamination&deplacer
```

A `resultat_mean.csv` file will be created inside the folder. 

![Modèle épidémiologique SEIR](https://cdn.discordapp.com/attachments/751057885730963578/1165708275019415592/image.png)


The class diagram for the project look like :
![Le diagramme de classe](https://cdn.discordapp.com/attachments/751057885730963578/1165711737018925303/image.png)

Made by Mathis R. and Thomas T.

It take 2 minutes on my pc to generate 100 files. (over 1.2s/file) - Thomas.