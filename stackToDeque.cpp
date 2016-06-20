/**
*Problem:
*用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*
*需要入队时，将数据压入stack1；出队时将stack1中所有数据装移到stack2，再让stack2出栈；
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res=stack2.top();
        stack2.pop(); 
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};