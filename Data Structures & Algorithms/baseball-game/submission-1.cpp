class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string x : operations) {
            if(x == "+") {
                int a = (int)st.top();
                st.pop();
                int b = (int)st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }
            else if(x == "D") {
                int num = st.top();
                st.push(2*num);
            }
            else if(x == "C") {
                st.pop();
            }
            else {
                st.push(stoi(x));
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};