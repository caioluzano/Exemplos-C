import os
    

Todos = open ("Lote1(2497).txt","r")

#gerar = open (lido+".cnf","w")
i = 0


for linha in Todos:
    i = i + 1
    #print (linha[1:8]+".cnf")
    x = open (linha[0:linha.find("\n")]+".cnf","w")
    x.write("XXXXXXXXXX")
    x.write("1111111111")
    x.write("XXXXXXXXXX")
    x.write("2222222222")
    x.close()
    #if i == 10:
    #   break


