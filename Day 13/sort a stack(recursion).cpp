void SortedStack :: sort()
{
   //Your code here
   stack<int> t;
   while(!s.empty())
   { 
      int temp=s.top();
      s.pop();
      while(!t.empty()&&t.top()>temp)
      {
          int x=t.top();
          t.pop();
          s.push(x);
      }
      t.push(temp);
   }
   s=t;
}
