n= int(input("Enter no of jobs :: "))

jobs=[[0]*3]*n

print("Now, Enter job_id, deadline and profit : ")

for i in range(n):                                  # Take input in 2d array
    print("Enter for "+str(i)+" : ")
    a=[]
    for j in range(3):
        a.append(int(input()))
    jobs[i]=a


time_slots=int(input("Enter time slots ::  "))         # ask for time slots we have for sequencing


def jobSequencing(jobs,time_slots):

    n=len(jobs)

    for i in range(n):
        for j in range(n-i-1):
            if(jobs[j][2]<jobs[j+1][2]):                # sort the jobs on the basis of profit
                jobs[j],jobs[j+1]=jobs[j+1],jobs[j]
    
    free_time_slots=[False]*time_slots                  # initialize the time slot array 

    job_selected=[]                                     # this will contain job selected

    for i in range(n):

        for j in range(min(jobs[i][1]-1,time_slots-1),-1,-1):      # search for slots from deadline to start

            if(free_time_slots[j]==False):                      # if a slot is empty 
                free_time_slots[j]=True
                job_selected.append(jobs[i][0])                 #then that job sequenced for that time slot
                break

    return job_selected


jobs_selected=jobSequencing(jobs, time_slots)
print(jobs_selected)




