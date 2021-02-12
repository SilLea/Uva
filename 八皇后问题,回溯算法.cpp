//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<vector>
//using namespace std;
//int vis[3][16];
//const int n = 8;
//vector<int>te;
//vector<vector<int>>ans;
//void eight_queen(int cur)
//{
//	if (cur == n) 	
//		ans.push_back(te);	
//	else	
//		for (int i = 0; i < n; i++)		
//			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n])
//			{
//				te.push_back(i);
//				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
//				eight_queen(cur + 1);
//				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
//				te.pop_back();
//			}	
//}
//int main()
//{
//	memset(vis, 0, sizeof(vis));
//	eight_queen(0);
//	return 0;
//}