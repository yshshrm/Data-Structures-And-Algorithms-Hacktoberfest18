/**
 * https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/
 * Tracking maximum element in stack at any time in O(1) operation
 * 
 * Description:
 * This works by keeping a temp stack and making sure that has the highest element on top always.
 */

/**
 * Input : 4 19 7 14 20
Output : Max Values in stack are 
         4 19 19 19 20

Input : 40 19 7 14 20 5
Output :  Max Values in stack are 
         40 40 40 40 40 40
 */

class Stack {
    constructor(items) {
        this.items = items || [];
        this.temp = [];
    }

    pop() {
        this.items.pop();
        this.temp.pop();
    }

    push(item) {
        this.items.push(item);
        const lastItemInTemp = this.temp[this.temp.length - 1];
        if (lastItemInTemp > item) {
            this.temp.push(lastItemInTemp);
        } else {
            this.temp.push(item);
        }
    }

    getMaxElement() {
        return this.temp[this.temp.length - 1];
    }
}

/**
 * Usage
 */

const stack = new Stack([1, 2]);

stack.push(10);
stack.push(20);
stack.push(5);
stack.push(2);

stack.getMaxElement(); // Returns 20
stack.pop();
stack.getMaxElement(); // Returns 20
stack.pop();
stack.getMaxElement(); // Returns 20
stack.pop();
stack.getMaxElement(); // Returns 10
