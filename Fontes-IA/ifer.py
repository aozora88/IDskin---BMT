
def spaces(content):
	number=0
	for i in content:
		if i == " ":
			number+=1
		else:
			return number 

def ifer(line,number):
	resto = ""
	if line.split()[-1] == "patogenico":
		line = line[:-13]
		resto = "return false;".rjust(13+number+4)
	elif line.split()[-1] == "normal":
		line = line[:-9]
		resto = "return true;".rjust(11+number+4)
	elif line[-2] == ":":
		line=line[:-1]

	return line[:number] + "if("+line[number:-1]+"){"+"\n"+resto

def elser(line,number):
	resto = ""
	if line.split()[-1] == "patogenico":
		line = line[:-13]
		resto = "return false;".rjust(13+number+4)
	elif line.split()[-1] == "normal":
		line = line[:-9]
		resto = "return true;".rjust(11+number+4)
	return "\n"+"}else{\n".rjust(7+number)+resto

def closeBracket(line,number,last):
	times = int((last-number)/4)
	bracket = "\n"
	for i in range(0,times):
		bracket = bracket+"}".rjust(1+last)+"\n"
		last-=4
	if last == number:
		return bracket+elser(line,number)
	else:
		return bracket+ifer(line,number)

f = open("entradaifer.txt","r")
contents = f.readlines()

numbers=[]

finalContents=[]
numbers.append(spaces(contents[0]))
finalContents.append(ifer(contents[0],spaces(contents[0])))
for line in contents[1:]:
	number = spaces(line)
	if number == numbers[-1]:
		finalContents.append(elser(line,number)) 
		numbers.pop()
		numbers.append(number)
	if number > numbers[-1]:
		finalContents.append(ifer(line,number))
		numbers.append(number)
	if number < numbers[-1]:
		finalContents.append(closeBracket(line,number,numbers[-1]))
		times = int((numbers[-1]-number)/4)
		for x in range(0,times):
			numbers.pop()
		numbers.append(number)
last = numbers[-1]
times = int(last/4)
bracket = "\n"
for i in range(0,times):
	bracket = bracket+"}".rjust(1+last)+"\n"
	last-=4
finalContents.append(bracket+"}")
		
f.close()

f=open("TESTEIFER.txt","w")

f.write("".join(finalContents))