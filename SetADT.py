set1 = []
set2 = []

def addElements():
	n = int(input("Enter the number of elemets to be accepted: "))
	for i in range(n):
		elements = int(input("Enter the elements: "))
		set1.append(elements)
	print(f"The Set1 is: {set1}")
	

def removeElement(set1):
	element = int(input("Enter the element to be removed from Set1: "))
	for i in set1:
		if (i == element):
			set1.remove(element)
			print(f"Displayed elements are: {set1}")
			break
	print(f"{element} is not present in set1.")
	

def containsElement(set1):
	element = int(input("Enter the element to check the set contains it or not: "))
	if element in set1:
		print(f"Set contains {element}.")
	else:
		print(f"{element} is present in the list.")
		

def sizeOfSet(set1):
	count = 0
	for i in set1:
		count += 1
	print(f"The size of set is: {count}")
	
def iterator(set1):
	iterate = iter(set1)
	print("The elemts in the set are: ")
	for i in range(len(set1)):
		print(next(iterate))
		
def intersection(set1, set2):
	intersectionSet = []
	for i in set1:
	    for j in set2:
		    if (i == j):
			    intersectionSet.append(i)
	print(f"The intersection of set is: {intersectionSet}")		    
    
	
def union(set1, set2):
	unionSet = []
	unionSet.extend(set1)
	for i in set2:
		if i not in set1:
			unionSet.append(i)
	print(f"Union of two sets is: {unionSet}")
	
def difference(set1, set2):
	differenceSet =[]
	for i in set1:
		if i not in set2:
			differenceSet.append(i)
	print(f"Set1 - Set2 = {differenceSet}")
	
def subset(set1, set2):
	subset = True
	for i in set2:
		if i not in set1:
			subset = False
	if subset == False:
		print("Set2 is not subset of Set1")
	else:
		print("Set2 is subset of Set1")
		

def main():
    n = int(input("Enter the number of elements in Set1: "))
    for i in range(n):
        set1.append(int(input("Enter the Set1 Elements: ")))
    ch = 0
    for i in range(7):
        print(" Set Operations")
        print(" 1. Accept element in a set")
        print(" 2. Remove element from a set")
        print(" 3. Search element ")
        print(" 4. Find size of set")
        print(" 5. Iterator function")
        print(" 6. Set operations")
        print(" 7. EXIT")
        ch = int(input("\nEnter your choice: "))
        while True:
            if ch == 1:
                addElements()
                break
            elif ch == 2:
                removeElement(set1,)
                break
            elif ch == 3:
                containsElement(set1)
                break
            elif ch == 4:
                sizeOfSet(set1)
                break
            elif ch == 5:
                iterator(set1)
                break
            elif ch == 6:
                a = int(input("Enter the number of elements in Set2: "))
                for i in range(a):
                    set2.append(int(input("Enter the Set2 elements: ")))
                for i in range(5):
                    print("**********Set Operations************* ")
                    print("1). Intersection of Sets")
                    print("2). Union of Sets")
                    print("3). Difference of Sets")
                    print("4). Subset of a Set")
                    print("5). Exit")
                    choice = int(input("Enter your choice: "))
                    while True:
                        if choice == 1:
                            intersection(set1, set2)
                            break

                        elif choice == 2:
                            union(set1, set2)
                            break

                        elif choice == 3:
                            difference(set1, set2)
                            break

                        elif choice == 4:
                            subset(set1, set2)
                            break

                        else:
                            
                            print("Exit")
                            exit()
                            break
            elif ch == 7:
                exit()
                

            else:
                    
                    print("---------EXIT----------")
                    exit()
                    break
            

main()
