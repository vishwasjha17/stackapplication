#include<iostream>
#include<stack>
using namespace std;
int main()
{

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
stack<int>s;
s.push(0);
int b[n];
for(int i=1;i<n;i++)
{
 if(s.empty())
   s.push(i);

 if(a[s.top()]>=a[i])
      s.push(i);
else
 {
   while(!s.empty()&&a[s.top()]<a[i])
      {
        b[s.top()]=i+1;
        s.pop();
      }
   s.push(i);

 }

}
while(!s.empty())
{
   b[s.top()]=-1;
  s.pop();
}

int c[n];
//second time find previous greater element
s.push(n-1);
for(int prev=n-2;prev>=0;prev--)
{
while(!s.empty())
{
if(a[s.top()]<a[prev])
{
int index = s.top();
c[index]=prev+1; //Position is 1-indexing
s.pop();
}
else
break;
}
s.push(prev);
}

while(!s.empty())
{
   c[s.top()]=-1;
  s.pop();
}




for(int i=0;i<n;i++)
cout<<b[i]<<" ";

cout<<endl;

for(int i=0;i<n;i++)
cout<<c[i]<<" ";


cout<<endl;
for(int i=0;i<n;i++)
cout<<b[i]+c[i]<<" ";

  return 0;
}
