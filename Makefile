all: dict1 dict2

dict1: common.h dict1.h dict1.c main1.c
	gcc -Wall dict1.c main1.c -o dict1
dict2: common.h dict2.h dict2.c main2.c
	gcc -Wall dict2.c main2.c -o dict2

clean:
	rm dict1 dict2