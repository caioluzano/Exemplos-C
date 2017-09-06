import os


#gerar = open (lido+".cnf","w")
i = 0


test=os.listdir(".")

for item in test:
    if item.endswith(".cnf"):
        os.remove(item)


