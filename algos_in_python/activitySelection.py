n=int(input("Enter no. of activities :: "))
activities=[]           # initialize a 2d array of n*2

print("Now, Enter start and finish time for activities :: ")
for i in range(n):
    print()
    a=[]
    for i in range(2):
        a.append(int(input()))              # input for start and finish times
    activities.append(a)



def activities_Selection(activities):
    n=len(activities)

    for i in range(n):
        for j in range(n-i-1):
            if(activities[j][1]>activities[j+1][1]):                        # sort array on the basis of finish time
                activities[j],activities[j+1]=activities[j+1],activities[j]
    print(activities)

    i=0
    print(" Following activities are selected :: ")
    print(activities[0])

    for j in range(1,n):                                                      #check if start of current is greater
        if(activities[j][0]>=activities[i][1]):                                #than previous's finish the activity selected
            print(activities[j])
            i=j

activities_Selection(activities)



