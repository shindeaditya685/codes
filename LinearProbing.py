from Record import Record

class hashTable:
    #initialize hash Table
    def __init__(self):
        self.size = int (input("Enter the sie of the Hash Table:"))
        #initialize table with all elements 0
        self.table=list(None for i in range(self.size))
        self.elementCount= 0
        self.comparisons=0

    #method that check if hash Table is full or not
    def isFull(self):
        if self.elementCount==self.size:
            return True
        else:
            return False

    #method to insert element in the hah Table
    def insert(self,record):
        #checking if the table is full or not
        if self.isFull():
            print("Hash Table is full")
            return False
        isStored =False  

        position=self.hashFunction(record.get_number())

        #Checking if position is empty
        if self.table[position] == None:
            self.table[position] = record
            print("Phone number of "+record.get_name()+ " is at position "+ str(position))
            isStored = True
            self.elementCount += 1
            
            
        else:
            print("Collision has occured for " + record.get_name()+"'s phone number at position "+ str(position)+"finding new Position.")
            while self.table[position] != None:
                position +=1
                if position >= self.size:
                    position = 0

            self.table[position] = record
            print("Phone number of "+ record.get_name()+"is at position "+ str(position))
            isStored = True
            self.elementCount += 1
        return isStored


        def search(self, record):
            isFound = False
       
        position = self.hashFunction(record.get_number())
        self.comparisons += 1

        if(self.table[position] != None):
            if(self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number()):
                isFound = True
                print("Phone number found at position {} ".format(position) + " and total comparisons are " + str(1))
                return position
            
                
       
        # if element is not found at position returned hash function
        
            else:
                position += 1
                if position >= self.size-1:
                    position = 0
                while self.table[position] != None or self.comparisons <= self.size:
                   
                    if(self.table[position].get_name() == record.get_name() and self.table[position].get_number() == record.get_number()):
                        isFound = True
                        #i=0
                        i = self.comparisons + 1 
                        print("Phone number found at position {} ".format(position) + " and total comparisons are " + str(i) )
                        return position

                    position += 1
                    #print(position)
                    if position >= self.size-1:
                        position = 0

                    #print(position)
                    self.comparisons += 1
                    #print(self.comparisons)
                    
                if isFound == False:
                    print("Record not found")
                    return false
                        
                               
 
    # method to display the hash table
    def display(self):
        print("\n")
        for i in range(self.size):
            print("Hash Value: "+str(i) + "\t\t" + str(self.table[i]))
        print("The number of phonebook records in the Table are : " + str(self.elementCount))

