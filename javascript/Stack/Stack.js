class Stack {
    constructor(){
        this.size = 0
        stack = []
    }
    pop = () => {
        this.size -=1
        stack.unshift()
    }
    push = () => {
        this.size +=1
        stack.unshift(this)
    }
}

//oh god I'm sorry for my bad code lol I just wanted a hacktoberfest shirt