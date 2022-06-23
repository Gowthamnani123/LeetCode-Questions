class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
	{
		sort(courses.begin(), courses.end(),[](auto &a, auto &s){return a[1] < s[1];});
		priority_queue<int> pq;
		int time = 0;
		
		
		for(auto c : courses)
		{
			if(c[0] <= c[1])
			{
				if(c[0] + time <= c[1])
				{
					pq.push(c[0]);
					time +=  c[0];
				}
				else
				{
					if(pq.top() > c[0])
					{
						time -= pq.top();
						pq.pop();
						time += c[0];
						pq.push(c[0]);
					}
                    
				}
			}
		}
		return pq.size();
	}
};