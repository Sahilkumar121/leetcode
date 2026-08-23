class Solution {
	public:
	const int INF = 1e8;
	void floydWarshall(vector<vector<int>> &dist) {
		// Code here
		
		int row = dist.size();
		int column = dist[0].size();
		
		for (int via = 0; via < column; via++)
			{
			for (int i = 0; i < row; i++)
				{
				for (int j = 0; j < column; j++)
					{
					if (dist[i][via] != INF && dist[via][j] != INF)
						{
						dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
					}
				}
			}
		}
		
	}
};
