import random
#masalah di akhir (list ke98) "!" akan di decode menjadi "a"(list ke0)
alph = "q?elP53h4pfL_b:kQ/rZBmg9sj;HUvnXR=JNDEW8KoTG2iSMc67YI#xzFdaACVw-1!0tOyu."

def encode(kata, sandi=1):
	encode = ""
	test =""
	for i in range(len(kata)):
		xxx = random.randint(0,len(alph)-2)
		xxy = xxx % 6
		encode += alph[xxx]
		for ii in range(xxy):
			encode += alph[random.randint(0,len(alph)-2)]
		if kata[i] == " ":
			encode += "+"
		else:
			ang = 0
			for xx in range(len(alph)):
				if kata[i] == alph[xx]:
					ang = xx
			bng = len(alph)-ang-1
			cng = bng + xxy
			if cng > len(alph)-1:
				cng -= len(alph)-1
			
			encode += alph[cng]
			test += alph[cng]
	encode += "##"
	return encode,test

def decode(code):
	skr = 0
	kata = ""
	while skr < len(code)-2:
		lanjut = 0
		for a in range(len(alph)):
			if code[skr] == alph[a]:
				lanjut = a % 6
		skr += lanjut+1
		for xx in range(len(alph)):
			if code[skr] == alph[xx]:
				ang = xx
			elif code[skr] == "+":
				ang = 24802
		cng = ang - lanjut
		if cng < 0:
			cng += len(alph)-1
		bng = len(alph)-cng-1
		if ang == lanjut:
			bng =0
		if ang == 24802:
			kata += " "
		else:
			kata += alph[bng]
		skr+=1
	return kata
		

kata = input("=> ")
a, b = encode(kata)
print()
print("encode => "+a)
print("decode => "+decode(a))
print()
for x in range(10):
	a,b = (encode(kata))
	print("=> " + a+ "|| "+b )
	print("-----------------------------")
	print("decode => "+decode(a))
yya = input()
print(decode(yya))